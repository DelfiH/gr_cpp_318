#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>

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
    ~MainWindow() override;

protected:
    void keyPressEvent(QKeyEvent *event) override;

private slots:
    void btnDigitClicked(const QString& digit);
    void btnOperationClicked(const QString& operation);
    void btnClearClicked();
    void resultClicked();

private:
    Ui::MainWindow *ui;
    QString sDisplay;
    char cAction;
    QString sValue1;
    QString sValue2;
};
#endif // MAINWINDOW_H
