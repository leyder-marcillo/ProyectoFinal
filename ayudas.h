#ifndef AYUDAS_H
#define AYUDAS_H

#include<QGraphicsTextItem>

class Ayudas:public QGraphicsTextItem{
public:
    Ayudas(QGraphicsItem *personaje=0);
    void disminuye();
    int getcomodin();

private:
    int vidas;

};
#endif // AYUDAS_H
