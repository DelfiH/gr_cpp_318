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
#include <QMessageBox> // ��� �뢮�� ᮮ�饭�� �� �訡���

void MainWindow::keyPressEvent(QKeyEvent *event) {
    QString text = event->text(); // ����砥� ⥪�� ���������� ᨬ����

    if (text.length() == 1) {
        QChar ch = text.at(0);

        if (ch.isDigit() || ch == '.') {
            // �᫨ �� ��� ��� �窠, ������塞 �� � ��ᯫ��
            btnDigitClicked(text);
        } else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            // �᫨ �� ������, ��뢠�� ᮮ⢥�����騩 ᫮�
            btnOperationClicked(text);
        } else if (event->key() == Qt::Key_Return || event->key() == Qt::Key_Enter) {
            // �᫨ ����� ������ Enter, ����塞 १����
            resultClicked();
        } else if (event->key() == Qt::Key_Escape) {
            // �᫨ ����� ������ Esc, ��頥� ��ᯫ��
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

    // ��⠭�������� 䮪�� �� ������
    setFocusPolicy(Qt::StrongFocus);
    setFocus();

    // ������塞 ᨣ���� � ᫮�� ������ � ��ࠬ�, �ᯮ���� �ﬡ��-��ࠦ����
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

    // ������塞 ᨣ���� � ᫮�� ������ ����権
    connect(ui->btnPlus, &QPushButton::clicked, [this](){ btnOperationClicked("+"); });
    connect(ui->btnMinus, &QPushButton::clicked, [this](){ btnOperationClicked("-"); });
    connect(ui->btnMultiply, &QPushButton::clicked, [this](){ btnOperationClicked("*"); });
    connect(ui->btnDivide, &QPushButton::clicked, [this](){ btnOperationClicked("/"); });

    // ������塞 ᨣ��� � ᫮� ������ Clear
    connect(ui->btnClear, &QPushButton::clicked, this, &MainWindow::btnClearClicked);

    // ������塞 ᨣ��� � ᫮� ������ Result
    connect(ui->result, &QPushButton::clicked, this, &MainWindow::resultClicked);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::resultClicked() {
    bool ok1, ok2; // ��� �஢�ન �ᯥ譮�� �८�ࠧ������
    double dValue1 = sValue1.toDouble(&ok1); // �८�ࠧ㥬 ��ப� � double
    double dValue2 = sValue2.toDouble(&ok2); // �८�ࠧ㥬 ��ப� � double
    double dResult = 0;

    // �஢�ઠ �ᯥ譮�� �८�ࠧ������
    if (!ok1 || !ok2) {
        QMessageBox::warning(this, "�訡��", "�����४�� ���� �ᥫ!");
        btnClearClicked();
        return;
    }

    // ��塞, ����� ������ ����室��� �믮�����
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
            QMessageBox::critical(this, "�訡��", "������� �� ����!");
            btnClearClicked();
            return;
        }
        dResult = dValue1 / dValue2;
        break;
    default:
        QMessageBox::warning(this, "�訡��", "�� ��࠭� ������!");
        btnClearClicked();
        return;
    }

    sDisplay = QString::number(dResult, 'g', 15); // ��ଠ��㥬 १����
    ui->lineEdit->setText(sDisplay); // �뢮��� ⥪�� � ����祭�� १���⮬
    sValue1 = sDisplay; // ���࠭塞 १���� ��� ���쭥��� ����権
    sValue2 = "";
    cAction = ' '; // ����뢠�� ������
}

void MainWindow::btnDigitClicked(const QString& digit) {
    // ��࠭�稢��� ���� ⮫쪮 ����� �窨
    if (digit == "." && sDisplay.contains(".")) {
        return;
    }

    sDisplay += digit;
    sValue2 += digit;
    ui->lineEdit->setText(sDisplay); // �뢮� ��ப� � ���� ����� (lineEdit)
}

void MainWindow::btnOperationClicked(const QString& operation) {
    if (operation.isEmpty()) return;

    // �᫨ �।���� ������ �� �����襭�, ����塞 १����
    if (!sValue1.isEmpty() && !sValue2.isEmpty()) {
        resultClicked();
    }

    if (!sDisplay.isEmpty()) {
        sValue1 = sDisplay; // ���࠭塞 ��ࢮ� ���祭��
    }

    cAction = operation.at(0).toLatin1(); // ��⠭�������� ᨬ��� ����樨
    sDisplay += cAction;
    sValue2 = "";
    ui->lineEdit->setText(sDisplay); // �뢮� ��ப� � ���� ����� (lineEdit)
}

void MainWindow::btnClearClicked() {
    sDisplay = ""; // Clear value
    ui->lineEdit->setText(""); // Clear ���� ����� (lineEdit)
    sValue1 = ""; // Clear value
    sValue2 = ""; // Clear value
    cAction = ' '; // Clear action
}
