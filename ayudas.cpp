#include "ayudas.h"
#include <QFont>
Ayudas::Ayudas(QGraphicsItem *personaje):QGraphicsTextItem(personaje)
{
 comodin=3;

 setPlainText(QString("Comodin: ")+QString::number(comodin));
 setDefaultTextColor(Qt::red);
 setFont(QFont("tiempo",16));
}

void Ayudas::disminuye()
{
    comodin--;
    setPlainText(QString("Comodin: ")+QString::number(comodin));
}

int Ayudas::getcomodin()
{
    return comodin;
}
