#include "bullet.h"

extern game *Game;
Bullet::Bullet()
{
    //dibujamos el rect
//    setRect(30,20,6,3);
    setPixmap(QPixmap(":/imagen/balapruebai.png"));
    //se conecta para moverlo
    QTimer *mitiempo= new QTimer();
    connect(mitiempo,SIGNAL(timeout()),this,SLOT(move()));

    mitiempo->start(50);

}

void Bullet::move()
{
    //si le pega
    QList <QGraphicsItem *> balazos=collidingItems();
    for(int i=0;i<balazos.size();i++){
        if(typeid(*(balazos[i]))==typeid(SMAD)){
            Game->score->aumenta();
            scene()->removeItem(balazos[i]);
            scene()->removeItem(this);

            delete balazos[i];
            delete this;
            return;
        }
    }
    //moviendo la bala
        setPos(x()+20,y());
        if(pos().x()>900 || pos().x()<0){
            scene()->removeItem(this);
            delete this;
            qDebug() <<"Bala borrada";
        }
}
