#include "Tower.h"
#include <QPixmap>
#include <QVector>
#include <QPointF>
#include <QPolygonF>

Tower::Tower(QGraphicsItem *parent)
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

}
