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

class MyRect:public QObject,
        public QGraphicsPixmapItem{
    Q_OBJECT
public:
     MyRect(QGraphicsItem *parent=0);
    void keyPressEvent(QKeyEvent *event);
public slots:
    void spawn();
private:
    QMediaPlayer *soundtiro;
};

#endif // MYRECT_H
