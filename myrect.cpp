#include "MyRect.h"
#include <QDebug>
#include "bullet.h"
#include "enemy.h"
#include <QGraphicsScene>
#include <QKeyEvent>

void MyRect::keyPressEvent(QKeyEvent *event){
    //qDebug() << "Test";
    //Key pressed stored inside event

    if (event->key() == Qt::Key_Left){
        if(pos().x() > 0) //Cannot leave left side of screen
            setPos(x()-10,y()); //Move left 10 units
    }

    else if(event->key() == Qt::Key_Right){

        if(pos().x()+100<800) //Only move right if not leaving screen
            setPos(x()+10,y());
    }

    else if(event->key() == Qt::Key_Up){
        setPos(x(),y()-10);
    }
    else if(event->key() == Qt::Key_Down){
        setPos(x(),y()+10);
    }

    else if(event->key() == Qt::Key_Space){
        //Create bullet
        Bullet *bullet = new Bullet();//Not added to scene yet

        //qDebug() << "Bullet created1";
        bullet->setPos(x(),y());
        scene()->addItem(bullet);


    }
}

void MyRect::spawn(){

    //Create an enemy
    Enemy *enemy =  new Enemy();
    scene()->addItem(enemy); //Scene is global method returning pointer to scene


}
