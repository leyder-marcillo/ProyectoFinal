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
//#include<iostream>
using namespace std;

class MyRect:public QObject,
        public QGraphicsPixmapItem{
    Q_OBJECT
public:
     MyRect(QGraphicsItem *parent=0);
    void keyPressEvent(QKeyEvent *event);
    void QTest(int ms);
public slots:
    void spawn();
private:
    vector <QPixmap > caminando;
    vector <QPixmap > reveresee;
    vector <QPixmap > lanzando;
    int stoper=0;
    int stopp=0;
    int balafail=0;
    QMediaPlayer *soundtiro;
};

#endif // MYRECT_H
