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
#include"smad.h"
#include"game.h"

class Bullet: public QObject,
        public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Bullet();
    Bullet(int capucho);
public slots:
    void move();
    void dele();
};
#endif // BULLET_H
