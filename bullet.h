#ifndef BULLET_H
#define BULLET_H

#include <QGraphicsRectItem>
#include <QObject>

class Bullet : public QObject, public QGraphicsRectItem{

    Q_OBJECT //QObject Macro
public:
    Bullet();
    //Slot member functions reacts to a signal

public slots:
    void move();


};

#endif // BULLET_H
