    #ifndef BUILDBROWNTOWER_H
    #define BUILDBROWNTOWER_H

    #include "Tower.h"
#include "Bullet.h"

class BrownTower:public Tower{
    Q_OBJECT
public:
    BrownTower(QGraphicsItem *parent=0);
    void fire();
    virtual ~BrownTower();
public slots:
    void aquire_target();
};

#endif // BUILDBROWNTOWER_H
