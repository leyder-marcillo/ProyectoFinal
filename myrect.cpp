#include "myrect.h"
#include "bullet.h"
#include <QKeyEvent>
#include <QGraphicsScene>
#include <QDebug>

#include <windows.h>
#include<time.h>
//#include "papabomba.h"

int MyRect::salud()
{
    return vidas;
}

MyRect::MyRect(QGraphicsItem *parent):QGraphicsPixmapItem(parent)
{
//    soundtiro= new QMediaPlayer();
//    soundtiro->setMedia(QUrl("qrc:/sounds/bala.mp3"));

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
    if(vidas>0){

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
           if(y()>350 )
            setPos(x(),y()-25 );
        }
        if(event->key()==Qt::Key_Down){
            balafail=0;
            setPixmap(caminando[stoper]);
            stoper++;
            if(stoper>6)
                stoper=0;
           if(y()<474)
           setPos(x(),y()+25);
        }
        if(event->key()==Qt::Key_Space){
            if(balafail==0){
                setPos(x(),y()-15);
                balafail=1;
            }

            if(tiropermitido){
            setPixmap(QPixmap(":/imagen/lanzar.png"));
            Bullet *mipapa;
            int capo=100;
            mipapa=new Bullet(capo);
            mipapa->setPos(x()+20,y()-20);
            qDebug()<<"Disparando!!!";

            scene()->addItem(mipapa);
//            if(soundtiro->state()==QMediaPlayer::PlayingState)
//                soundtiro->setPosition(0);
//            if(soundtiro->state()==QMediaPlayer::StoppedState)
//                soundtiro->play();
            tiropermitido=false;
            QTimer *permitetiro= new QTimer();
            connect(permitetiro,SIGNAL(timeout()),this,SLOT(lapsotiro()));
            permitetiro->start(5000); //tiempo para nuevo lanzamiento
            }

        }
        if(event->key()==Qt::Key_B){
        setPixmap(QPixmap(":/imagen/defenderse.png"));
        defensa=false; //La defensa esta arriba
        }
    }
}

void MyRect::keyReleaseEvent(QKeyEvent *event)
{
    if(vidas>0){
        if(event->key()==Qt::Key_B){
        setPixmap(QPixmap(":/imagen/movi1.png"));
        defensa=true;
        }
        if(event->key()==Qt::Key_Space){
        if(balafail!=1)
            setPos(x(),y()+15);
        setPixmap(QPixmap(":/imagen/movi1.png"));
        }
    }
}
bool MyRect::vivir()
{
    if (vidas==0){
        setPos(x(),y()+60);
        setPixmap(QPixmap(":/imagen/RIP.png"));
//        vidas--;
    }
    if(salud()==0){
//        qDebug()<<"EntroAQui tambie";
//        disconnect(timeSMAD);
        Game->desconectar();
        Game->Gameover();
    }
    return defensa;
}


void MyRect::spawn()
{
    //Crear SMAD
    enemigo=new SMAD();
    scene()->addItem(enemigo);
    Game->aumentConst();
}

void MyRect::lapsotiro()
{
    tiropermitido=true;
}
