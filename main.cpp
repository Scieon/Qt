#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsRectItem>

#include <myrect.h>
#include <QGraphicsView>
#include <QTimer>



/*Tutorial:
QGraphicsScene: world, player (Inivisble ~concept)
QGraphicsItem(QGraphicsRectitem): goes into scene
QGraphicsView:
*/
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //Create a scene
    QGraphicsScene *scene  = new QGraphicsScene();

    //Create an item to put into the scene
    MyRect *rect = new MyRect();

    rect->setRect(0,0,100,100); //(x,y,width,height)

    //Add item to the Scene
    scene->addItem(rect);

    //Make Rect focusable
    rect->setFlag(QGraphicsItem::ItemIsFocusable); //Only one focused item at a time
                                                   //Allowing rect to be focusable
    rect->setFocus(); //Setting rect item to focus

    //Add a view
    QGraphicsView *view = new QGraphicsView(scene); //Initializing in constructor
    //view->setScene(scene); alternative

    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    view->show();

    view->setFixedSize(800,600);
    scene->setSceneRect(0,0,800,600);

    rect->setPos(view->width()/2,view->height() - rect->rect().height());

    //Spawn Enemies
    QTimer *timer = new QTimer();
    QObject::connect(timer,SIGNAL(timeout()),rect,SLOT(spawn()));
    timer->start(2000);

    return a.exec();
}
