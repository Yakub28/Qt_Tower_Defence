#ifndef GAME_H
#define GAME_H

#include "Tower.h"

#include <QGraphicsView>
#include <QMouseEvent>
#include <QGraphicsPixmapItem>

class Game:public QGraphicsView{
public:
    Game();

    void setCursor(QString filename);
    void mouseMoveEvent(QMouseEvent* event);
    void mousePressEvent(QMouseEvent *event);

    QGraphicsScene* scene;
    QGraphicsPixmapItem *cursor;
    Tower* build;

};

#endif // GAME_H
