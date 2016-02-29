#ifndef ENEMY_H
#define ENEMY_H

#include <QGraphicsRectItem>
#include <QObject>

class Enemy : public QObject, public QGraphicsRectItem{

    Q_OBJECT //QObject Macro
public:
    Enemy();
    //Slot member functions reacts to a signal

public slots:
    void move();


};


#endif // ENEMY_H
