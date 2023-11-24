#include "Bullet.h"
#include <QPixmap>
#include <QTimer>
#include <qmath.h>

double Bullet::getDistanceTraveled() const
{
    return distanceTraveled;
}

void Bullet::setDistanceTraveled(double newDistanceTraveled)
{
    distanceTraveled = newDistanceTraveled;
}

double Bullet::getMaxRange() const
{
    return maxRange;
}

void Bullet::setMaxRange(double newMaxRange)
{
    maxRange = newMaxRange;
}

Bullet::Bullet(QGraphicsItem *parent)
{
    // set graphics
    setPixmap(QPixmap(":images/resources/i2.png"));

    //connect a timer to move()
    QTimer *move_timer=new QTimer(this);
    connect(move_timer,SIGNAL(timeout()),this,SLOT(move()));
    move_timer->start(50);

    maxRange=100;
    distanceTraveled=0;
}

void Bullet::move()
{
    int STEP_SIZE=30;
    double theta=rotation();//degrees
    double dy=STEP_SIZE*qSin(qDegreesToRadians(theta));
    double dx=STEP_SIZE*qCos(qDegreesToRadians(theta));

    setPos(x()+dx,y()+dy);
}
