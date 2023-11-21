#include "Game.h"
#include <QGraphicsScene>
#include "Tower.h"
#include <memory>
Game::Game()
{
    //create a scene
    scene=new QGraphicsScene(this);

    //set the scene
    setScene(scene);

    //create a tower
    Tower* t=new Tower();


    scene->addItem(t);

    setFixedSize(800,600);
}
