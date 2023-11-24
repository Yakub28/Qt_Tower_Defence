#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QMouseEvent>
#include <QGraphicsPixmapItem>
#include "Tower.h"


class Game: public QGraphicsView{
public:
    Game();
    void setCursor(QString filename);
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);

    QGraphicsScene * scene;
    QGraphicsPixmapItem * cursor;
    Tower * building;
};

#endif // GAME_H
