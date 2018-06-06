#ifndef PAPABOMBA_H
#define PAPABOMBA_H

#include<math.h>

#include <QPainter>

#include<QGraphicsRectItem>
#include<QGraphicsScene>
#include<QGraphicsPixmapItem>
#include<QPixmap>
#include<QGraphicsItem>
#include <QObject>
#include <QTimer>
#include <QDebug>
#include <QList>
#include"smad.h"
#include"game.h"

class PapaBomba:public QGraphicsItem,
        public QObject{
Q_OBJECT
private:
    double vX,vY,v,r;
    double viniX,viniY;
    double x,y;
    double angulo;
    double aX,aY;
    double masa,A;
    double K,e;
public:
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,QWidget *widget);
    PapaBomba();
    PapaBomba(double v_iniX,double v_iniY,double _x, double _y, double _m,double radio,double _e,double _K);
        void CalVelocidad();
        void CalAceleracion();
        void ActualizarPos();
public slots:
        void move();
};

#endif // PAPABOMBA_H
