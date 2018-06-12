#include "score.h"
#include <QFont>
Score::Score(QGraphicsItem *personaje):QGraphicsTextItem(personaje)
{
 score=0;

 setPlainText(QString("Puntaje: ")+QString::number(score));
 setDefaultTextColor(Qt::yellow);
 setFont(QFont("tiempo",20));
}

void Score::aumenta()
{
    score++;
    setPlainText(QString("Puntaje: ")+QString::number(score));
}

int Score::getscore()
{
    return score;
}

void Score::dismi()
{
    score-=5;
}
