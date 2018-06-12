#include "game.h"
#include <QGraphicsTextItem>
#include <QFont>
#include <QImage>
#include "button.h"

game::game(QWidget *parent)
{
    scene=new QGraphicsScene();
    scene->setSceneRect(0,0,500,320);

    setBackgroundBrush(QBrush(QImage(":/imagen/fondo4.jpg")));



    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(500,320);



    //sonido
    QMediaPlayer *musica=new QMediaPlayer();
//    musica->setMedia(QUrl("qrc:/sounds/FondomusicRock.mp3"));
//    musica->play();

//    show();

}

void game::start()
{
    scene->clear();
//    scene=new QGraphicsScene();
    scene->setSceneRect(0,0,900,600);

    setBackgroundBrush(QBrush(QImage(":/imagen/fondo1C.jpg")));



    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(900,600);

    capucho=new MyRect();
    capucho->setPos(0,scene->height()-capucho->pixmap().height());
    capucho->setFlag(QGraphicsItem::ItemIsFocusable);
    capucho->setFocus();

    scene->addItem(capucho);  //agregamos a el personaje

    //score
    score=new Score();
    scene->addItem(score);
    help=new Ayudas();
    help->setPos(help->x()+750,help->y());
    scene->addItem(help);

    timeSMAD=new QTimer;
    QObject::connect(timeSMAD,SIGNAL(timeout()),capucho,SLOT(spawn()));
    timeSMAD->start(velocidaestandar);//Tiempo para nuevo SMAD

}

void game::restartGame()
{
    scene->clear();
    start();
}

void game::drawPanel(int x, int y,int weidth, int height, QColor color, double opacity)
{
 QGraphicsRectItem * panel=new QGraphicsRectItem(x,y,weidth,height);
 QBrush brush;
 brush.setStyle(Qt::SolidPattern);
 brush.setColor(color);
 panel->setBrush(brush);
 panel->setOpacity(opacity);
 scene->addItem(panel);
}

void game::displayMainMenu()
{

    QGraphicsTextItem *Title=new QGraphicsTextItem(QString("Disturbio en Barrientos"));
    Title->setDefaultTextColor(Qt::yellow);
    QFont titlefont("comic sans",30);
    Title->setFont(titlefont);

    int txPos=this->width()/2 -Title->boundingRect().width()/2;
    int tyPos= 10;
    Title->setPos(txPos,tyPos);
    scene->addItem(Title);

    Button * playbutton=new Button(QString("Play"));
    int bxPos=this->width()/2 -playbutton->boundingRect().width()/2;
    int byPos= 130;
    playbutton->setPos(bxPos,byPos);
    QObject::connect(playbutton,SIGNAL(clicked()),this,SLOT(start()));
    scene->addItem(playbutton);

    Button * salir=new Button(QString("Salir"));
    int ExPos=this->width()/2 -salir->boundingRect().width()/2;
    int EyPos= 200;
    salir->setPos(ExPos,EyPos);
    connect(salir,SIGNAL(clicked()),this,SLOT(close()));
    scene->addItem(salir);



}

void game::displayGameOverWindow(QString TExtoDisplay)
{
    drawPanel(0,0,1024,768,Qt::black,0.65);
    drawPanel(350,130,250,215,Qt::lightGray,0.75);

    Button *playAgain=new Button(QString("Play again"));
    playAgain->setPos(374,190);
    scene->addItem(playAgain);
    connect(playAgain,SIGNAL(clicked()),this,SLOT(restartGame()));

    Button *exit=new Button(QString("Exit"));
    exit->setPos(374,270);
    scene->addItem(exit);
    connect(exit,SIGNAL(clicked()),this,SLOT(close()));

//    QGraphicsTextItem *overTExt=new QGraphicsTextItem(TExtoDisplay);
//    overTExt->setPos(384,130);
//    scene->addItem(overTExt);
    QGraphicsTextItem *Title=new QGraphicsTextItem(TExtoDisplay);
    Title->setDefaultTextColor(Qt::yellow);
    QFont titlefont("comic sans",20);
    Title->setFont(titlefont);

    int txPos=this->width()/2 -Title->boundingRect().width()/2  +20;
    int tyPos= 135;
    Title->setPos(txPos,tyPos);
    scene->addItem(Title);

}

void game::Gameover()
{
//  scene->clear();
  int puntuacion1;
  QString messege;
  if(capucho->salud()<=0){
  messege="Perdiste";
  }
  else
    messege= "Ganaste!" ;


  displayGameOverWindow(messege);
}

void game::aumentConst()
{
    if(velocidaestandar>2000){
//            qDebug()<<"++";
            velocidaestandar-=velocidadaunmenta*2;
    }
    else
        Gameover();
}

void game::desconectar()
{
    disconnect(timeSMAD);
}

