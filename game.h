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
    Q_OBJECT
public:
    game(QWidget * parent=NULL);

    QGraphicsScene *scene;
    MyRect * capucho;
    Score * score;
    Ayudas *help;
    int velocidadaunmenta=30;
    int velocidaestandar=5000;
    void displayMainMenu();
    void displayGameOverWindow(QString TExtoDisplay);
    void Gameover();
    void aumentConst();
    void desconectar();
public slots:
    void start();
    void restartGame();
private:
    QTimer *timeSMAD;
    void drawPanel(int x, int y, int weidth, int height, QColor color, double opacity);

};

#endif // GAME_H
