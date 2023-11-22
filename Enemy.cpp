#include "Enemy.h"

#include <QPixmap>
#include <QPointF>
#include <QPixmap>
#include <QTimer>
#include <qmath.h>
#include <QDebug>

Enemy::Enemy(QGraphicsItem *parent)
{
    setPixmap(QPixmap(":/images/resources/i3.png"));

    points<<QPointF(200,200)<<QPointF(400,200);//move  down right than right
    point_index=0;
    dest = points[0];
    rotateToPoint(dest);

    QTimer *timer=new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move_forward()));
    timer->start(150);
}

void Enemy::rotateToPoint(QPointF p)
{
    QLineF ln(pos(),p);
    setRotation(-1*ln.angle());

}

void Enemy::move_forward()
{
    //if close to dest, rotate to next dest
    QLineF ln(pos(),dest);
    if(ln.length()<5){
//        if(points.size()<point_index)
//        {
            point_index++;
            dest=points[point_index];
            rotateToPoint(dest);
//        }
        //qDebug()<<"Final dest reached";
    }

    int STEP_SIZE=5;
    double theta=rotation();//degrees
    double dy=STEP_SIZE*qSin(qDegreesToRadians(theta));
    double dx=STEP_SIZE*qCos(qDegreesToRadians(theta));

    setPos(x()+dx,y()+dy);

}
