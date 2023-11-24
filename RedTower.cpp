#include "RedTower.h"
#include <QTimer>
#include "Bullet.h"
#include "Game.h"

extern Game * game;

RedTower::RedTower(QGraphicsItem *parent){
    // connect a timer to aquire_target
    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(aquire_target()));
    timer->start(1000);
}

void RedTower::fire(){
    Bullet * bullet = new Bullet();
    bullet->setPixmap(QPixmap(":images/resources/i7.png"));
    bullet->setPos(x()+30,y()+39.5);

    QLineF ln(QPointF(x()+30,y()+39.5),attack_dest);
    int angle = -1 * ln.angle();

    bullet->setRotation(angle);
    game->scene->addItem(bullet);
}

void RedTower::aquire_target(){
    Tower::aquire_target();
}
