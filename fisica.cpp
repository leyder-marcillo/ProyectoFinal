
#include "fisica.h"
#include <QDebug>
#include <QPixmap>

extern game *Game;

#define delta 0.1
#define g 10
#define PI 3.14159265358979323846


//QRectF fisica::boundingRect() const
//{
//    return QRectF(-r,-r,2*r,2*r);
//}

//void fisica::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
//{
//      QPixmap pixmap(":/imagen/papabomba.png");
//      painter->drawPixmap(-r,-r,2*r,2*r,pixmap);
//    painter->setBrush(Qt::darkMagenta);
//      //    painter->drawEllipse(-r,-r,2*r,2*r);
//}



Fisica::Fisica(double v_iniX, double v_iniY, double _x, double _y, double _m, double radio, double _e, double _K)
{
    A=PI*pow(radio,2);
    r=radio;
    x=_x;
    y=_y;
    masa=_m;
    viniX=v_iniX;
    viniY=v_iniY;
    aX=0;
    aY=0;
    angulo=0;
    v=0;
    K=_K;
    e=_e;
    vX=0;
    vY=0;
//    setPos(x,y);
    setPixmap(QPixmap(":/imagen/papabomba.png"));
    //se conecta para moverlo
    QTimer *mitiempo= new QTimer();
    connect(mitiempo,SIGNAL(timeout()),this,SLOT(move()));

    mitiempo->start(50);
}


void Fisica::CalAceleracion()
{
    if(viniX==0){
        viniX=1;
    }
    angulo=atan2(viniY,viniX);
    aX=(-K*(pow(v,2)*pow(r,2))/masa)*cos(angulo);
    aY=(-K*(pow(v,2)*pow(r,2))/masa)*sin(angulo)-g;
    //    aDx=(-1/(2*masa))*p*v*CD*A*cos(angulo);}
    //    aDy=(-1/(2*masa))*p*v*CD*A*sin(angulo);
}
void Fisica::CalVelocidad()
{
    vX=viniX+(aX*delta);
    vY=viniY+(aY*delta);
    viniX=vX;
    viniY=vY;
}
void Fisica::ActualizarPos()
{
    v=sqrt(pow(viniX,2)+pow(viniY,2));
    CalAceleracion();
    CalVelocidad();
    x=x+(vX*delta)+((aX*delta*delta)/2);
    y=y+(vY*delta)+((aY*delta*delta)/2);
    //colisiones
    if(x+r>=900.0 || x<r){
        viniX=-e*vX;
        v=sqrt(pow(viniX,2)+pow(viniY,2));
        angulo=atan2(viniY,viniX);
        x=x+(vX*delta)+((aX*delta*delta)/2);

        if(x+r>900)
            x=900-r;
        else
            x=r;
//        while(x+r>=1000.0 || x<r){
//            v=sqrt(pow(viniX,2)+pow(viniY,2));
//            CalAceleracion();
//            CalVelocidad();
//            x=x+(vX*delta)+((aX*delta*delta)/2);
//        }
    }
    if(y+r>500.0 || y<r){
        viniY=-e*vY;
        v=sqrt(pow(viniX,2)+pow(viniY,2));
        angulo=atan2(viniY,viniX);
        y=y+(vY*delta)+((aY*delta*delta)/2);

        if(y+r>500)
            y=500-r;
        else
            y=r;
   }

//        while(y+r>=500.0 || y+r<r){
//            v=sqrt(pow(viniX,2)+pow(viniY,2));
//            CalAceleracion();
//            CalVelocidad();

//            y=y+(vY*delta)+((aY*delta*delta)/2);
//        }
//    }
//    if(y<r)
//        y=r;

//    qDebug()<<"posx= "<< x <<"posy= "<< y << endl;

    setPos(x,-y);

}
void Fisica::choque()
{
    v=-e*v;
    CalAceleracion();
    CalVelocidad();
    x=x+(vX*delta)+((aX*delta*delta)/2);
    y=y+(vY*delta)+((aY*delta*delta)/2);
}




void Fisica::move()
{
    QList <QGraphicsItem *> balazos=collidingItems();
    for(int i=0;i<balazos.size();i++){
        if(typeid(*(balazos[i]))==typeid(SMAD)){//Decir contra que hace efecto la bala
            Game->score->aumenta();
            scene()->removeItem(balazos[i]);//borrar la bala
            scene()->removeItem(this);//borrar el ebjeto impactado

            delete balazos[i];
            delete this;
            return;
        }
    }
    //moviendo la bala
    this->ActualizarPos();
        if(pos().x()>900 || pos().x()<0){
            scene()->removeItem(this);
            delete this;
            qDebug() <<"Bala borrada";
        }
}



