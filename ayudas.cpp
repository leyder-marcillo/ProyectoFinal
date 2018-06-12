#include "ayudas.h"
#include <QFont>
Ayudas::Ayudas(QGraphicsItem *personaje):QGraphicsTextItem(personaje)
{
 vidas=3;

 setPlainText(QString("Vidas: ")+QString::number(vidas));
 setDefaultTextColor(Qt::yellow);
 setFont(QFont("tiempo",20));
}

void Ayudas::disminuye()
{
    vidas--;
    setPlainText(QString("Vidas: ")+QString::number(vidas));
}

int Ayudas::getcomodin()
{
    return vidas;
}
