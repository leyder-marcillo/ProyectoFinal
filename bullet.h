#ifndef BULLET_H
#define BULLET_H

#include<QGraphicsRectItem>
#include<QGraphicsScene>
#include<QGraphicsPixmapItem>
#include<QPixmap>
#include<QGraphicsItem>
#include <QObject>
#include <QTimer>
#include <QDebug>
#include <QList>
#include<math.h>
#include <QPainter>
#include <QMediaPlayer>

#include"smad.h"
#include"game.h"

extern game *Game;
class Bullet: public QObject,
        public QGraphicsPixmapItem{
    Q_OBJECT
private:
    double piso;
    double r, masa,viniX, viniY, aX,aY, angulo,v;
    double vX, vY;
    double enx=Game->capucho->pos().x()+5;
    double eny=Game->capucho->pos().y()-10;
    int Explotar=3;
    QGraphicsPixmapItem *fuego;
    QMediaPlayer *soundbomba;

public:
    Bullet(); //bala esmad
    Bullet(int capucho); //papita
    int aunnoexplota=0;
public slots:
    void move(); //mueve el smad
    void dele(); //elimina el esmad y la bala
    void elimifuego();
};
#endif // BULLET_H
