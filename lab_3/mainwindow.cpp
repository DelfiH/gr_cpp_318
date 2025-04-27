/*
 * Лабораторная работа №3.2
 * Тема: "Преобразование типов данных, арифметические операции С++, приложение Qt Widgets в IDE (интегрированной среде разработки) Qt Creator"
 * Разработчик: Васин Сергей
 * Группа: gr_cpp318
 * OS: Windows
 * locale (кодировка): ibm866
 */

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPushButton>
#include <QKeyEvent>
#include <QMessageBox> // Для вывода сообщений об ошибках

void MainWindow::keyPressEvent(QKeyEvent *event) {
    QString text = event->text(); // Получаем текст введенного символа

    if (text.length() == 1) {
        QChar ch = text.at(0);

        if (ch.isDigit() || ch == '.') {
            // Если это цифра или точка, добавляем ее в дисплей
            btnDigitClicked(text);
        } else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            // Если это оператор, вызываем соответствующий слот
            btnOperationClicked(text);
        } else if (event->key() == Qt::Key_Return || event->key() == Qt::Key_Enter) {
            // Если нажата клавиша Enter, вычисляем результат
            resultClicked();
        } else if (event->key() == Qt::Key_Escape) {
            // Если нажата клавиша Esc, очищаем дисплей
            btnClearClicked();
        }
    }
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , sDisplay("")
    , cAction(' ')
    , sValue1("")
    , sValue2("") {
    ui->setupUi(this);

    // Устанавливаем фокус на виджет
    setFocusPolicy(Qt::StrongFocus);
    setFocus();

    // Соединяем сигналы и слоты кнопок с цифрами, используя лямбда-выражения
    connect(ui->btn1, &QPushButton::clicked, [this](){ btnDigitClicked("1"); });
    connect(ui->btn2, &QPushButton::clicked, [this](){ btnDigitClicked("2"); });
    connect(ui->btn3, &QPushButton::clicked, [this](){ btnDigitClicked("3"); });
    connect(ui->btn4, &QPushButton::clicked, [this](){ btnDigitClicked("4"); });
    connect(ui->btn5, &QPushButton::clicked, [this](){ btnDigitClicked("5"); });
    connect(ui->btn6, &QPushButton::clicked, [this](){ btnDigitClicked("6"); });
    connect(ui->btn7, &QPushButton::clicked, [this](){ btnDigitClicked("7"); });
    connect(ui->btn8, &QPushButton::clicked, [this](){ btnDigitClicked("8"); });
    connect(ui->btn9, &QPushButton::clicked, [this](){ btnDigitClicked("9"); });
    connect(ui->btn0, &QPushButton::clicked, [this](){ btnDigitClicked("0"); });
    connect(ui->btnDot, &QPushButton::clicked, [this](){ btnDigitClicked("."); });

    // Соединяем сигналы и слоты кнопок операций
    connect(ui->btnPlus, &QPushButton::clicked, [this](){ btnOperationClicked("+"); });
    connect(ui->btnMinus, &QPushButton::clicked, [this](){ btnOperationClicked("-"); });
    connect(ui->btnMultiply, &QPushButton::clicked, [this](){ btnOperationClicked("*"); });
    connect(ui->btnDivide, &QPushButton::clicked, [this](){ btnOperationClicked("/"); });

    // Соединяем сигнал и слот кнопки Clear
    connect(ui->btnClear, &QPushButton::clicked, this, &MainWindow::btnClearClicked);

    // Соединяем сигнал и слот кнопки Result
    connect(ui->result, &QPushButton::clicked, this, &MainWindow::resultClicked);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::resultClicked() {
    bool ok1, ok2; // Для проверки успешности преобразования
    double dValue1 = sValue1.toDouble(&ok1); // Преобразуем строку в double
    double dValue2 = sValue2.toDouble(&ok2); // Преобразуем строку в double
    double dResult = 0;

    // Проверка успешности преобразования
    if (!ok1 || !ok2) {
        QMessageBox::warning(this, "Ошибка", "Некорректный ввод чисел!");
        btnClearClicked();
        return;
    }

    // Выявляем, какую операцию необходимо выполнить
    switch (cAction) {
    case '+':
        dResult = dValue1 + dValue2;
        break;
    case '-':
        dResult = dValue1 - dValue2;
        break;
    case '*':
        dResult = dValue1 * dValue2;
        break;
    case '/':
        if (dValue2 == 0) {
            QMessageBox::critical(this, "Ошибка", "Деление на ноль!");
            btnClearClicked();
            return;
        }
        dResult = dValue1 / dValue2;
        break;
    default:
        QMessageBox::warning(this, "Ошибка", "Не выбрана операция!");
        btnClearClicked();
        return;
    }

    sDisplay = QString::number(dResult, 'g', 15); // Форматируем результат
    ui->lineEdit->setText(sDisplay); // Выводим текст с полученным результатом
    sValue1 = sDisplay; // Сохраняем результат для дальнейших операций
    sValue2 = "";
    cAction = ' '; // Сбрасываем операцию
}

void MainWindow::btnDigitClicked(const QString& digit) {
    // Ограничиваем ввод только одной точки
    if (digit == "." && sDisplay.contains(".")) {
        return;
    }

    sDisplay += digit;
    sValue2 += digit;
    ui->lineEdit->setText(sDisplay); // Вывод строки в окно ввода (lineEdit)
}

void MainWindow::btnOperationClicked(const QString& operation) {
    if (operation.isEmpty()) return;

    // Если предыдущая операция не завершена, вычисляем результат
    if (!sValue1.isEmpty() && !sValue2.isEmpty()) {
        resultClicked();
    }

    if (!sDisplay.isEmpty()) {
        sValue1 = sDisplay; // Сохраняем первое значение
    }

    cAction = operation.at(0).toLatin1(); // Устанавливаем символ операции
    sDisplay += cAction;
    sValue2 = "";
    ui->lineEdit->setText(sDisplay); // Вывод строки в окно ввода (lineEdit)
}

void MainWindow::btnClearClicked() {
    sDisplay = ""; // Clear value
    ui->lineEdit->setText(""); // Clear окно ввода (lineEdit)
    sValue1 = ""; // Clear value
    sValue2 = ""; // Clear value
    cAction = ' '; // Clear action
}
