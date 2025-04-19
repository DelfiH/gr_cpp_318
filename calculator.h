#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QGridLayout>
#include <QMessageBox>
#include <QKeyEvent>
#include <QScriptEngine>

class Calculator : public QWidget {
    Q_OBJECT

public:
    explicit Calculator(QWidget *parent = nullptr);

protected:
    void keyPressEvent(QKeyEvent *event) override; // Обработка клавиатурных событий

private slots:
    void onButtonClicked();

private:
    QLineEdit *display;
    double eval(const QString &expression, bool *ok);
};

#endif // CALCULATOR_H
