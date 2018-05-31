#ifndef SCORE_H
#define SCORE_H

#include<QGraphicsTextItem>

class Score:public QGraphicsTextItem{
public:
    Score(QGraphicsItem *personaje=0);
    void aumenta();
    int getscore();

private:
    int score;

};

#endif // SCORE_H
