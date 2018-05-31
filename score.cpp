#include "score.h"
#include <QFont>
Score::Score(QGraphicsItem *personaje):QGraphicsTextItem(personaje)
{
 score=0;

 setPlainText(QString("Puntaje: ")+QString::number(score));
 setDefaultTextColor(Qt::green);
 setFont(QFont("tiempo",16));
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
