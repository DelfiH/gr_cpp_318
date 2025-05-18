#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
    void keyPressEvent(QKeyEvent *event) override;

private slots:
    void inputDigit(const QString& digit);
    void setOperation(const QString& operation);
    void calculateResult();
    void clearDisplay();

private:
    Ui::MainWindow *ui;
    QString displayString;
    char currentAction;
    QString firstValue;
    QString secondValue;

    void connectDigitButtons();
    void connectOperationButtons();
    void updateDisplay();
    void showError(const QString& message);
    void displayResult(double result);
};
#endif // MAINWINDOW_H
