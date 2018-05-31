#include "myrect.h"
#include "bullet.h"
#include <QKeyEvent>
#include <QGraphicsScene>
#include <QDebug>
#include "smad.h"

MyRect::MyRect(QGraphicsItem *parent):QGraphicsPixmapItem(parent)
{
    soundtiro= new QMediaPlayer();
    soundtiro->setMedia(QUrl("qrc:/sounds/bala.mp3"));
//    setPos(80,400);
//     setRect(0,0,30,80);
//    setPixmap(QPixmap(":/imagen/enemigo.png"));
    setPixmap(QPixmap(":/imagen/CAPUCHO2.png"));
}

void MyRect::keyPressEvent(QKeyEvent *event)
{
//    qDebug()<<"MyRect knows that you pressed a key";
    if(event->key()==Qt::Key_Left){
        if(x()>0)
       setPos(x()-10,y());
    }
    if(event->key()==Qt::Key_Right){
       if(x()<430)
        setPos(x()+10,y());
    }
    if(event->key()==Qt::Key_Up){
       if(y()>250 )
        setPos(x(),y()-10);
    }
    if(event->key()==Qt::Key_Down){
       if(y()<474)
       setPos(x(),y()+10);
    }
    if(event->key()==Qt::Key_Space){
        //Creamos la bala
        Bullet *mibala;
        mibala=new Bullet();
        qDebug()<<"Disparando!!!";
        mibala->setPos(x()+70,y()+37);
        scene()->addItem(mibala);
        if(soundtiro->state()==QMediaPlayer::PlayingState)
            soundtiro->setPosition(0);
        if(soundtiro->state()==QMediaPlayer::StoppedState)
            soundtiro->play();
    }
}


void MyRect::spawn()
{
    //Crear SMAD
    SMAD *enemigo=new SMAD();
    scene()->addItem(enemigo);
}
