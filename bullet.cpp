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

Bullet::Bullet(int capucho)
{
    setPixmap(QPixmap(":/imagen/papabomba.png"));
    //se conecta para moverlo
    QTimer *mitiempo2= new QTimer();
    connect(mitiempo2,SIGNAL(timeout()),this,SLOT(dele()));

    mitiempo2->start(50);
}

void Bullet::move()
{
    //si le pega
    QList <QGraphicsItem *> balazos=collidingItems();
    for(int i=0;i<balazos.size();i++){
        if(typeid(*(balazos[i]))==typeid(MyRect)){//Decir contra que hace efecto la bala
            Game->score->aumenta();
//            scene()->removeItem(balazos[i]);//borrar la bala
//            scene()->removeItem(this);//borrar el ebjeto impactado

//            delete balazos[i];
            delete this;
            return;
        }
    }
    //moviendo la bala
    setPos(x()-20,y());
        if(pos().x()>900 || pos().x()<0){
            scene()->removeItem(this);
            delete this;
            qDebug() <<"Bala borrada";
        }
}

void Bullet::dele()
{
    QList <QGraphicsItem *> pepazos=collidingItems();
    for(int i=0;i<pepazos.size();i++){
        if(typeid(*(pepazos[i]))==typeid(SMAD)){//Decir contra que hace efecto la bala
            Game->score->aumenta();
            scene()->removeItem(pepazos[i]);//borrar la bala
            scene()->removeItem(this);//borrar el ebjeto impactado

            delete pepazos[i];
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
