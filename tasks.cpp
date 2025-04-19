#include "tasks.h"
#include <QObject>
#include <QRunnable>
#include <QThread>
#include <QDebug>

class Task : public QObject, public QRunnable {
    Q_OBJECT // Это необходимо для использования сигналов и слотов
public:
    Task() {} // Конструктор
    void run() override { // Здесь выполняется Ваша длительная задача
        // Длительная операция
        qDebug() << "Выполняется длительная операция в потоке" << QThread::currentThread();
        QThread::sleep(5); // Имитация длительной операции (5 секунд)
        qDebug() << "Длительная операция завершена";
        emit finished(); // Отправляем сигнал о завершении задачи
    }

signals:
    void finished(); // Сигнал, который будет отправлен после завершения задачи
};
