#include "myrect.h"
#include "bullet.h"
#include <QKeyEvent>
#include <QGraphicsScene>
#include <QDebug>
#include "smad.h"
#include <windows.h>
#include<time.h>

MyRect::MyRect(QGraphicsItem *parent):QGraphicsPixmapItem(parent)
{
    soundtiro= new QMediaPlayer();
    soundtiro->setMedia(QUrl("qrc:/sounds/bala.mp3"));
//    setPos(80,400);
//     setRect(0,0,30,80);
    setPixmap(QPixmap(":/imagen/movi1.png"));
    QPixmap uno=QPixmap(":/imagen/movi1.png");
    QPixmap Dos=QPixmap(":/imagen/movi2.png");
    QPixmap Tres=QPixmap(":/imagen/movi3.png");
    QPixmap Cuatro=QPixmap(":/imagen/movi4.png");
    QPixmap cinco=QPixmap(":/imagen/movi5.png");
    QPixmap seis=QPixmap(":/imagen/movi6.png");
    QPixmap siete=QPixmap(":/imagen/movi7.png");

    caminando.push_back(uno);
    caminando.push_back(Dos);
    caminando.push_back(Tres);
    caminando.push_back(Cuatro);
    caminando.push_back(cinco);
    caminando.push_back(seis);
    caminando.push_back(siete);


    QPixmap Cu=QPixmap(":/imagen/movi4.png");
    QPixmap Ci=QPixmap(":/imagen/movi5.png");
    QPixmap pege=QPixmap(":/imagen/lanzar.png");

    lanzando.push_back(Cu);
    lanzando.push_back(Ci);
    lanzando.push_back(pege);

}

void MyRect::keyPressEvent(QKeyEvent *event)
{

//    qDebug()<<"MyRect knows that you pressed a key";
    if(event->key()==Qt::Key_Left){
        balafail=0;
        setPixmap(caminando[stoper]);
        stoper--;
        if(stoper<0)
            stoper=6;
        if(x()>0)
       setPos(x()-5,y());
    }
    if(event->key()==Qt::Key_Right){
        balafail=0;
        setPixmap(caminando[stoper]);
        stoper++;
        if(stoper>6)
            stoper=0;
       if(x()<430)
        setPos(x()+5,y());
    }
    if(event->key()==Qt::Key_Up){
        balafail=0;
        setPixmap(caminando[stoper]);
        stoper++;
        if(stoper>6)
            stoper=0;
       if(y()>250 )
        setPos(x(),y()-10);
    }
    if(event->key()==Qt::Key_Down){
        balafail=0;
        setPixmap(caminando[stoper]);
        stoper++;
        if(stoper>6)
            stoper=0;
       if(y()<474)
       setPos(x(),y()+10);
    }
    if(event->key()==Qt::Key_Space){
        setPixmap(lanzando[2]);
        //if(stopp==2){
        if(balafail==0){
            setPos(x(),y()-15);
            balafail=1;
        }
            Bullet *mibala;
            mibala=new Bullet();
            qDebug()<<"Disparando!!!";
            mibala->setPos(x()+30,y()+20);
            scene()->addItem(mibala);
            if(soundtiro->state()==QMediaPlayer::PlayingState)
                soundtiro->setPosition(0);
            if(soundtiro->state()==QMediaPlayer::StoppedState)
                soundtiro->play();  
        //}
        stopp++;
        if(stopp>2)
            stopp=0;
    }
}

void MyRect::QTest(int ms)
{
    if(ms > 0)
        Sleep(ms);
    struct timespec ts = { ms / 1000, (ms % 1000) * 1000 * 1000 };

    nanosleep(&ts, NULL);
}


void MyRect::spawn()
{
    //Crear SMAD
    SMAD *enemigo=new SMAD();
    scene()->addItem(enemigo);
}
