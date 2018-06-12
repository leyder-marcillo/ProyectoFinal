#ifndef MYRECT_H
#define MYRECT_H

#include<QGraphicsRectItem>
#include<QGraphicsPixmapItem>
#include<QPixmap>
#include<QGraphicsItem>
#include<QGraphicsScene>
#include<QObject>
//#include<QPainter>
//#include<QPixmap>
#include<QMediaPlayer>
#include<QTimer>
#include <vector>
#include "smad.h"
//#include<iostream>
using namespace std;

class MyRect:public QObject,
        public QGraphicsPixmapItem{
    Q_OBJECT
public:
    bool defensa=true; //Indica si la defensa esta arriba
    bool tiropermitido=true;
    int vidas=3;       //numero de vidas
    int salud();       //Retorna las vidas
     MyRect(QGraphicsItem *parent=0);
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);
    bool vivir();
    SMAD *enemigo;
public slots:
    void spawn();  //agrega un objeto tipo smad
    void lapsotiro();
private:
    vector <QPixmap > caminando; //efecto de caminar
    vector <QPixmap > lanzando;  //EFecto de regresar
    int stoper=0; //Recorre el vector caminando
    int stopp=0;
    int balafail=0;  //Corrige el problema con la imagen lanzar.png(size)

    QMediaPlayer *soundtiro;
};

#endif // MYRECT_H
