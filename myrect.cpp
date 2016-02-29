#include "MyRect.h"
#include <QDebug>
#include "bullet.h"
#include <QGraphicsScene>
#include <QKeyEvent>

void MyRect::keyPressEvent(QKeyEvent *event){
    //qDebug() << "Test";
    //Key pressed stored inside event

    if (event->key() == Qt::Key_Left){
        setPos(x()-10,y()); //Move left 10 units
    }

    else if(event->key() == Qt::Key_Right){
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
