#include "BrownTower.h"
#include <QTimer>
#include "Bullet.h"
#include "Game.h"
#include "Tower.h"

extern Game * game;

BrownTower::BrownTower(QGraphicsItem *parent){
    // connect a timer to aquire_target
    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(aquire_target()));
    timer->start(1000);
}

void BrownTower::fire(){
    Bullet* bullet=new Bullet();
    bullet->setPos(x()+30,y()+39.5);

    QLineF ln(QPointF(x()+30,y()+39.5),attack_dest);
    int angle=-1*ln.angle();

    bullet->setRotation(angle);
    game->scene->addItem(bullet);
}

BrownTower::~BrownTower()
{

}

void BrownTower::aquire_target(){
    Tower::aquire_target();
}
