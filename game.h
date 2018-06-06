#ifndef GAME_H
#define GAME_H

#include<QGraphicsView>
#include<QGraphicsScene>
#include<QGraphicsPixmapItem>
#include <QMediaPlayer>
#include <QWidget>
#include <QTimer>
#include <QDebug>
#include <QList>
#include"smad.h"
#include "myrect.h"
#include "score.h"
#include "ayudas.h"
class game: public QGraphicsView{
public:
    game(QWidget * parent=0);

    QGraphicsScene *scene;
    MyRect * capucho;
//    MyRect *capucho;
    Score * score;
    Ayudas *help;

};

#endif // GAME_H
