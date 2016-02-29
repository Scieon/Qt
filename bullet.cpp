#include "bullet.h"
#include "enemy.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <QDebug>
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

    //If bullet hits enemy destroy bullet and enemy
    QList<QGraphicsItem *> colliding_items =  collidingItems(); //List of all colliding items
    for(int i=0, n = colliding_items.size(); i<n; ++i){
        if(typeid(*(colliding_items[i])) == typeid(Enemy)){
            //remove both
            scene()->removeItem(colliding_items[i]); //remove enemy
            scene()->removeItem(this); //remove bullet

            //Objects still occupy memory on the heap
            //delete both
            delete colliding_items[i];
            delete this;
            return;
        }
    }



    //Move Bullet up
    setPos(x(),y()-10);

    //Delete bullet if it leaves scene
    if(pos().y() + rect().height() < 0){
        scene()->removeItem(this);
        delete this;
       // qDebug() << "Bullet deleted";
    }
}
