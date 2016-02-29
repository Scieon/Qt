#include "enemy.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QDebug>
#include <stdlib.h> //rand() -> really large int


Enemy::Enemy(){

    //Set random position
    int random_number = rand() % 700;
    setPos(random_number,0);
    //Draw Enemy
    setRect(0,0,100,100);

    //Connect
    QTimer *timer = new QTimer();


    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    timer->start(50); //Every 50 ms signal will trigger
    //Each bullet is independent object

}
void Enemy::move(){

    //Move Enemy Down
    setPos(x(),y()+5);

    //Delete bullet if it leaves scene
    if(pos().y() + rect().height() < 0){
        scene()->removeItem(this);
        delete this;
        // qDebug() << "Bullet deleted";
    }
}
