#include "bullet.h"
#include <QTimer>

Bullet::Bullet(){

    //Draw bullet
    setRect(0,0,10,50);

    //Connect
    QTimer *timer = new QTimer();


    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    timer->start(50); //Every 50 ms signal will trigger
                      //Each bullet is independent object



}

void Bullet::move(){

    //Move Bullet up
    setPos(x(),y()-10);
}
