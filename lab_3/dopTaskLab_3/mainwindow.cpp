/*
 * ������ୠ� ࠡ�� �3.2
 * ����: "�८�ࠧ������ ⨯�� ������, ��䬥��᪨� ����樨 �++, �ਫ������ Qt Widgets � IDE (��⥣�஢����� �।� ࠧࠡ�⪨) Qt Creator"
 * ���ࠡ��稪: ��ᨭ ��ࣥ�
 * ��㯯�: gr_cpp318
 * OS: Windows
 * locale (����஢��): ibm866
 */

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPushButton>
#include <QKeyEvent>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , displayString("")
    , currentAction('\0') // �ᯮ��㥬 '\0' ��� ������祭�� ������⢨� ����樨
    , firstValue("")
    , secondValue("") {
    ui->setupUi(this);

    // ��⠭�������� 䮪�� �� ������ ��� ��ࠡ�⪨ ������
    setFocusPolicy(Qt::StrongFocus);
    setFocus();

    // ������塞 ᨣ���� � ᫮�� ��� ��� � �窨
    connectDigitButtons();
    // ������塞 ᨣ���� � ᫮�� ��� ����権
    connectOperationButtons();
    // ������砥� ������ ���⪨
    connect(ui->btnClear, &QPushButton::clicked, this, &MainWindow::clearDisplay);
    // ������砥� ������ १����
    connect(ui->result, &QPushButton::clicked, this, &MainWindow::calculateResult);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent *event) {
    QString text = event->text();

    if (text.length() == 1) {
        QChar ch = text.at(0);

        if (ch.isDigit() || ch == '.') {
            inputDigit(text);
        } else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            setOperation(text);
        } else if (event->key() == Qt::Key_Return || event->key() == Qt::Key_Enter) {
            calculateResult();
        } else if (event->key() == Qt::Key_Escape) {
            clearDisplay();
        }
    }
}

void MainWindow::connectDigitButtons() {
    // �ﬡ��-�㭪�� ��� ��饭�� ������祭�� ��஢�� ������
    auto connectDigit = [this](QPushButton* button, const QString& digit) {
        connect(button, &QPushButton::clicked, [this, digit](){ inputDigit(digit); });
    };

    connectDigit(ui->btn1, "1");
    connectDigit(ui->btn2, "2");
    connectDigit(ui->btn3, "3");
    connectDigit(ui->btn4, "4");
    connectDigit(ui->btn5, "5");
    connectDigit(ui->btn6, "6");
    connectDigit(ui->btn7, "7");
    connectDigit(ui->btn8, "8");
    connectDigit(ui->btn9, "9");
    connectDigit(ui->btn0, "0");
    connectDigit(ui->btnDot, ".");
}

void MainWindow::connectOperationButtons() {
    // �ﬡ��-�㭪�� ��� ��饭�� ������祭�� ������ ����権
    auto connectOperation = [this](QPushButton* button, const QString& operation) {
        connect(button, &QPushButton::clicked, [this, operation](){ setOperation(operation); });
    };

    connectOperation(ui->btnPlus, "+");
    connectOperation(ui->btnMinus, "-");
    connectOperation(ui->btnMultiply, "*");
    connectOperation(ui->btnDivide, "/");
}

void MainWindow::calculateResult() {
    if (firstValue.isEmpty() || secondValue.isEmpty() || currentAction == '\0') {
        // �᫨ ��-� �� ������, ��祣� �� ������
        return;
    }

    bool ok1, ok2;
    double val1 = firstValue.toDouble(&ok1);
    double val2 = secondValue.toDouble(&ok2);

    if (!ok1 || !ok2) {
        showError("�����४�� ���� �ᥫ!");
        return;
    }

    double result = 0.0;

    switch (currentAction) {
    case '+': result = val1 + val2; break;
    case '-': result = val1 - val2; break;
    case '*': result = val1 * val2; break;
    case '/':
        if (val2 == 0) {
            showError("Error!");
            return;
        }
        result = val1 / val2;
        break;
    default:
        showError("�������⭠� ������!");
        return;
    }

    displayResult(result);
}

void MainWindow::displayResult(double result) {
    displayString = QString::number(result);
    firstValue = displayString;
    secondValue = "";
    currentAction = '\0';
    updateDisplay();
}

void MainWindow::inputDigit(const QString& digit) {
    if (digit == "." && displayString.contains(".")) {
        return; // �� ������塞 ����� ����� �窨
    }

    displayString += digit;
    secondValue += digit;
    updateDisplay();
}

void MainWindow::setOperation(const QString& operation) {
    if (operation.isEmpty()) return;

    // �᫨ �।���� ������ �� �����襭�, ����塞 १����
    if (!firstValue.isEmpty() && !secondValue.isEmpty()) {
        calculateResult();
    } else if (firstValue.isEmpty() && !secondValue.isEmpty()) {
      firstValue = secondValue;
      secondValue = "";
    } else {
        firstValue = displayString; // ���࠭塞 ��ࢮ� ���祭��
        secondValue = "";
    }

    currentAction = operation.at(0).toLatin1();
    displayString += currentAction;
    updateDisplay();
}

void MainWindow::clearDisplay() {
    displayString = "";
    firstValue = "";
    secondValue = "";
    currentAction = '\0';
    updateDisplay();
}

void MainWindow::updateDisplay() {
    ui->lineEdit->setText(displayString);
}

void MainWindow::showError(const QString& message) {
    QMessageBox::warning(this, "�訡��", message);
    clearDisplay();
}
