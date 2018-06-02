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
    setPixmap(QPixmap(":/imagen/enemigo.png"));
    //se conecta para moverlo
    QTimer *mitiempo= new QTimer();
    connect(mitiempo,SIGNAL(timeout()),this,SLOT(move()));

    mitiempo->start(50);

}

void SMAD::move()
{
    //moviendo enemigo
        setPos(x()-5,y());
        if(pos().x()<0){
            Game->help->disminuye();
            scene()->removeItem(this);
            delete this;
            qDebug() <<"Enemigo borrado";
        }
}
