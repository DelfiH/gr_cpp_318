#ifndef SQUARE_H
#define SQUARE_H

#include <QObject>
#include <QGraphicsItem>
#include <QPainter>
#include <QTimer>
#include <QPointF>

class Square : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    explicit Square(QObject *parent = 0);
    ~Square();
    // �㭪�� ��� ��⠭���� callback �㭪樨
    void setCallbackFunc(void (*func) (QPointF point));

signals:

public slots:

protected:
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

private:
    QTimer *timer;  // ��஢�� ⠩���
    // �����⥫� �� callback �㭪��
    void (*callbackFunc)(QPointF point);

private slots:
    void slotTimer();   // ᫮� ��஢��� ⠩���

};

#endif // SQUARE_H
