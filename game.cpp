#include "game.h"
#include <QGraphicsTextItem>
#include <QFont>

game::game(QWidget *parent)
{
    scene=new QGraphicsScene();
    scene->setSceneRect(0,0,900,600);

    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(900,600);

    capucho=new MyRect();
    capucho->setPos(0,scene->height()-capucho->pixmap().height());
    capucho->setFlag(QGraphicsItem::ItemIsFocusable);
    capucho->setFocus();

    scene->addItem(capucho);

    //score
    score=new Score();
    scene->addItem(score);
    help=new Ayudas();
    help->setPos(help->x()+750,help->y());
    scene->addItem(help);

    QTimer *timeSMAD=new QTimer;
    QObject::connect(timeSMAD,SIGNAL(timeout()),capucho,SLOT(spawn()));
    timeSMAD->start(2000);

    //sonido
    QMediaPlayer *musica=new QMediaPlayer();
    musica->setMedia(QUrl("qrc:/sounds/fondo.mp3"));
    musica->play();

    show();

}
