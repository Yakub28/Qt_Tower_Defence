#include "BuildGreenTowerIcon.h"
#include "Game.h"
#include "GreenTower.h"

extern Game * game;

BuildGreenTowerIcon::BuildGreenTowerIcon(QGraphicsItem *parent): QGraphicsPixmapItem(parent){
    setPixmap(QPixmap(":images/resources/i6.png"));
}

void BuildGreenTowerIcon::mousePressEvent(QGraphicsSceneMouseEvent *event){
    if (!game->building){
        game->building =new GreenTower();
        game->setCursor(QString(":images/resources/i6.png"));
    }
}
