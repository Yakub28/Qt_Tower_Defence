#include "Tower.h"
#include "Bullet.h"
#include "Game.h"

#include <QPixmap>
#include <QVector>
#include <QPointF>
#include <QPolygonF>
#include <QLine>
#include <QTimer>

extern Game* game;

Tower::Tower(QGraphicsItem *parent):QObject(),QGraphicsPixmapItem(parent)
{
    setPixmap(QPixmap(":/images/resources/i1.png"));

    QVector<QPointF> points;
    points<<QPoint(1,0)<<QPoint(2,0)
           <<QPoint(3,1)<<QPoint(3,2)
           <<QPoint(2,3)<<QPoint(1,3)
           <<QPoint(0,2)<<QPoint(0,1);

    //scale points
    int SCALE_FACTOR=65;
    for(auto i=0;i<points.size();i++){
        points[i]*=SCALE_FACTOR;
    }

    attack_area=new QGraphicsPolygonItem(QPolygonF(points),this);

    //move the polygon
    QPointF poly_center(1.5,1.5);
    poly_center*=SCALE_FACTOR;
    poly_center=mapToScene(poly_center);
    QPointF tower_center(x()+30,y()+39.5);//dimensions of the image/2
    QLineF ln(poly_center,tower_center);
    attack_area->setPos(x()+ln.dx(),y()+ln.dy());

    //connect a timer to attack_target
    QTimer *timer=new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(attack_target()));
    timer->start(1000);

    attack_dest=QPointF(800,0);
}

void Tower::attack_target()
{
    Bullet* bullet=new Bullet();
    bullet->setPos(x()+30,y()+39.5);

    QLineF ln(QPointF(x()+30,y()+39.5),attack_dest);
    int angle=-1*ln.angle();

    bullet->setRotation(angle);
    game->scene->addItem(bullet);
}
