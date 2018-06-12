#ifndef SMAD_H
#define SMAD_H

#include<QGraphicsRectItem>
#include<QGraphicsScene>
#include<QGraphicsPixmapItem>
#include<QPixmap>
#include<QGraphicsItem>
#include <QObject>
#include <QTimer>
#include <QDebug>
#include <vector>
#include <QMediaPlayer>
using namespace std;

class SMAD: public QObject,
        public QGraphicsPixmapItem{
    Q_OBJECT
    vector <QPixmap > walksmad;
    QMediaPlayer *disparo;
public:
    int paso=0;
    SMAD();

    void eliminar();
public slots:
    void move();
    void fire();

};
#endif // SMAD_H
