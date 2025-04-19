#include "tasks.h"
#include <QObject>
#include <QRunnable>
#include <QThread>
#include <QDebug>

class Task : public QObject, public QRunnable {
    Q_OBJECT // �� ����室��� ��� �ᯮ�짮����� ᨣ����� � ᫮⮢
public:
    Task() {} // ���������
    void run() override { // ����� �믮������ ��� ���⥫쭠� �����
        // ���⥫쭠� ������
        qDebug() << "�믮������ ���⥫쭠� ������ � ��⮪�" << QThread::currentThread();
        QThread::sleep(5); // ������ ���⥫쭮� ����樨 (5 ᥪ㭤)
        qDebug() << "���⥫쭠� ������ �����襭�";
        emit finished(); // ��ࠢ�塞 ᨣ��� � �����襭�� �����
    }

signals:
    void finished(); // ������, ����� �㤥� ��ࠢ��� ��᫥ �����襭�� �����
};
