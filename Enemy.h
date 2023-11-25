#ifndef ENEMY_H
#define ENEMY_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QList>
#include <QPointF>

class Enemy:public QObject, public QGraphicsPixmapItem{
    Q_OBJECT

    QList<QPointF> points;
    QPointF dest;
    int point_index;
public:
    Enemy(QList<QPointF>pointsToFollow,QGraphicsItem *parent=0);
    void rotateToPoint(QPointF p);
public slots:
    void move_forward();
};


#endif // ENEMY_H
