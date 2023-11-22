#ifndef TOWER_H
#define TOWER_H

#include <QGraphicsPixmapItem>
#include <QGraphicsPolygonItem>
#include <QGraphicsItem>
#include <QPointF>
#include <QObject>

class Tower:public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Tower(QGraphicsItem *parent=0);
private:
    QGraphicsPolygonItem* attack_area;
    QPointF attack_dest;
public slots:
    void attack_target();
};

#endif // TOWER_H
