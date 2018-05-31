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

class SMAD: public QObject,
        public QGraphicsPixmapItem{
    Q_OBJECT
public:
    SMAD();
public slots:
    void move();
};
#endif // SMAD_H
