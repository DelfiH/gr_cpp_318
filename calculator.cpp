#include "calculator.h"

Calculator::Calculator(QWidget *parent) : QWidget(parent) {
    display = new QLineEdit(this);
    display->setReadOnly(true);
    display->setStyleSheet("font-size: 55px; padding: 10px;");

    QGridLayout *layout = new QGridLayout(this);
    layout->addWidget(display, 0, 0, 1, 4);

    const QStringList buttons = {
        "7", "8", "9", "/",
        "4", "5", "6", "*",
        "1", "2", "3", "-",
        "0", "C", "=", "+"
    };

    int pos = 1;
    for (const QString &buttonText : buttons) {
        QPushButton *button = new QPushButton(buttonText, this);
        button->setStyleSheet("font-size: 16px; padding: 20px;");
        layout->addWidget(button, pos / 4 + 1, pos % 4);
        connect(button, &QPushButton::clicked, this, &Calculator::onButtonClicked);
        pos++;
    }

    setLayout(layout);
    setWindowTitle("Calculator");
    resize(500, 550);
}

void Calculator::keyPressEvent(QKeyEvent *event) {
    QString keyText = event->text();
    if (keyText.length() == 1) { // Обрабатываем одиночные символы
        if (keyText[0].isDigit() || keyText[0] == '+' || keyText[0] == '-' ||
            keyText[0] == '*' || keyText[0] == '/' || keyText[0] == '.') {
            display->insert(keyText);
        }
    } else if (keyText == "C") {
        display->clear();
    } else if (keyText == "Return") {
        QString expression = display->text();
        bool ok;
        double result = eval(expression, &ok);
        if (ok) {
            display->setText(QString::number(result)); // Показываем результат в поле
        } else {
            QMessageBox::warning(this, "Error", "Invalid expression");
            display->clear();
        }
    }
}

void Calculator::onButtonClicked() {
    QPushButton *button = qobject_cast<QPushButton *>(sender());
    if (!button)
        return;

    const QString clickedButtonText = button->text();

    if (clickedButtonText == "C") {
        display->clear();
    } else if (clickedButtonText == "=") {
        QString expression = display->text();
        bool ok;
        double result = eval(expression, &ok);
        if (ok) {
            display->setText(QString::number(result)); // Показываем результат в поле
        } else {
            QMessageBox::warning(this, "Error", "Invalid expression");
            display->clear();
        }
    } else {
        display->insert(clickedButtonText);
    }
}

double Calculator::eval(const QString &expression, bool *ok) {
    QScriptEngine engine;
    QScriptValue result = engine.evaluate(expression);
    *ok = !result.isError();
    return result.toNumber();
}
