#include "bullet.h"

#define delta 0.1
#define g 10
#define PI 3.14159265358979323846

//extern game *Game;
Bullet::Bullet()
{
    setPixmap(QPixmap(":/imagen/balapruebai.png"));
    //se conecta para mover la bala
    QTimer *mitiempo= new QTimer();
    connect(mitiempo,SIGNAL(timeout()),this,SLOT(move()));

    mitiempo->start(50);

}

Bullet::Bullet(int capucho)
{
    setPixmap(QPixmap(":/imagen/papabomba.png"));
    //se conecta para mover la papa
    QTimer *mitiempo2= new QTimer();
    connect(mitiempo2,SIGNAL(timeout()),this,SLOT(dele()));

    mitiempo2->start(50);
     r=10;
     masa=600;
     viniX=290;
     viniY=-100;
     aX=0;
     aY=0;
     angulo=0;
     v=0;
     vX=0;
     vY=0;
     piso=Game->capucho->pos().y()+100;

}

void Bullet::move()
{
    //si le pega
    QList <QGraphicsItem *> balazos=collidingItems();
    for(int i=0;i<balazos.size();i++){
        if(typeid(*(balazos[i]))==typeid(MyRect)){//Decir contra que hace efecto la bala
            Game->score->aumenta();
            scene()->removeItem(this);//remover la bala
            delete this;      //borrar la bala
            if(Game->capucho->vivir()){
                Game->capucho->vidas--;
                Game->capucho->vivir();
                Game->help->disminuye();
            }
            return;
        }
    }
    //moviendo la bala
    setPos(x()-20,y());
        if(pos().x()>900 || pos().x()<0){
            scene()->removeItem(this);
            delete this;
//            qDebug() <<"Bala borrada";
        }
}

void Bullet::dele()
{

    QList <QGraphicsItem *> pepazos=collidingItems();
    for(int i=0;i<pepazos.size();i++){
        if(typeid(*(pepazos[i]))==typeid(SMAD)){
            if(aunnoexplota==0){
                viniX=-0.5*vX;
                v=sqrt(pow(viniX,2)+pow(viniY,2));
                angulo=atan2(viniY,viniX);
                enx=enx+(vY*delta)+((aY*delta*delta)/2);
                enx=enx-4;
                if(Explotar>0){
                     setPos(enx,eny);
                     Explotar--;
                }
                aunnoexplota=1;

                return;
            }
            if(aunnoexplota>20){
                Game->score->aumenta();
                scene()->removeItem(pepazos[i]);//remueve el smad
                delete pepazos[i];
                return;
            }
            aunnoexplota++;
        }
    }
    //moviendo la bala

    v=sqrt(pow(viniX,2)+pow(viniY,2));

    if(viniX==0){
        viniX=1;
    }
    angulo=atan2(viniY,viniX);

    aX=(-0.01*(pow(v,2)*pow(10,2))/masa)*cos(angulo);
    aY=(-0.01*(pow(v,2)*pow(10,2))/masa)*sin(angulo)+100;

    vX=viniX+(aX*delta);
    vY=viniY+(aY*delta);
    viniX=vX;
    viniY=vY;

    enx=enx+(vX*delta)+((aX*delta*delta)/2);
    eny=eny+(vY*delta)+((aY*delta*delta)/2);

    //colision contra el piso
    if(eny+r>piso || eny<r){
        viniY=-1*vY;
        v=sqrt(pow(viniX,2)+pow(viniY,2));
        angulo=atan2(viniY,viniX);
        eny=eny+(vY*delta)+((aY*delta*delta)/2);
        eny=piso-10;
        Explotar--;
   }
    if(Explotar==0){
        soundbomba= new QMediaPlayer();
        soundbomba->setMedia(QUrl("qrc:/sounds/papaexplota.mp3"));
        if(soundbomba->state()==QMediaPlayer::PlayingState)
            soundbomba->setPosition(0);
        if(soundbomba->state()==QMediaPlayer::StoppedState)
            soundbomba->play();
        setPixmap(QPixmap(":/imagen/fire3.png"));
        setPos(x()-30,y()-120);
        QTimer *humo= new QTimer();
        connect(humo,SIGNAL(timeout()),this,SLOT(elimifuego()));
        humo->start(8500); //duracion de la llama
        Explotar--;
    }
   if(Explotar>0)
        setPos(enx,eny);

    if(pos().x()>900 || pos().x()<0){
        scene()->removeItem(this);
        delete this;
//        qDebug() <<"Bala borrada";
    }

}

void Bullet::elimifuego()
{

    scene()->removeItem(this);
    delete this;
//    qDebug() <<"Bala borrada";
}


