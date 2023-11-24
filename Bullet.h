#ifndef BULLET_H
#define BULLET_H

#include <QGraphicsPixmapItem>
#include <QObject>

class Bullet:public QObject, public QGraphicsPixmapItem{
    Q_OBJECT

    double maxRange;
    double distanceTraveled;
public:
    Bullet(QGraphicsItem* parent=0);
    double getDistanceTraveled() const;
    void setDistanceTraveled(double newDistanceTraveled);

    double getMaxRange() const;
    void setMaxRange(double newMaxRange);

public slots:
    void move();
};


#endif // BULLET_H
