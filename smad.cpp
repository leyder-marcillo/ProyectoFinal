#include "smad.h"
#include "game.h"
#include<stdlib.h>
#include<bullet.h>
extern game *Game;
SMAD::SMAD()
{
    //random posicion
    int random_number=250+ rand() % 251;
    setPos(870,random_number);
    //dibujamos el rect
//    setRect(0,0,30,100);

    QPixmap uno=QPixmap(":/imagen/sol4.png");
    QPixmap Dos=QPixmap(":/imagen/sol5.png");
    QPixmap Tres=QPixmap(":/imagen/sol3.png");
    QPixmap Cuatro=QPixmap(":/imagen/sol1.png");

    walksmad.push_back(uno);
    walksmad.push_back(Dos);
    walksmad.push_back(Tres);
    walksmad.push_back(Cuatro);

    setPixmap(walksmad[paso]);
    //se conecta para moverlo
    QTimer *mitiempo= new QTimer();
    connect(mitiempo,SIGNAL(timeout()),this,SLOT(move()));

    mitiempo->start(100); //Velocidad del SMAD
    QTimer *timefire= new QTimer();
    connect(timefire,SIGNAL(timeout()),this,SLOT(fire()));

    mitiempo->start(100);
    timefire->start(1500);
}

void SMAD::move()
{
    if(paso>3)
        paso=0;
    setPixmap(walksmad[paso]);
    paso++;

    //moviendo enemigo
    setPos(x()-5,y());
    if(pos().x()<0){
        Game->help->disminuye();
        scene()->removeItem(this);
        delete this;
        qDebug() <<"Enemigo borrado";
    }
}

void SMAD::fire()
{
    Bullet *mibala;
    mibala=new Bullet();
    qDebug()<<"Disparando!!!";
    mibala->setPos(x()+15,y()+10);
    scene()->addItem(mibala);
}
