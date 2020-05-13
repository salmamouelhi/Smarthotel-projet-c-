#include "dash.h"
#include "ui_dash.h"
#include "login.h"
#include "ui_login.h"
#include "mainwindow.h"
#include "chambre.h"
#include "ui_mainwindow.h"
#include "qsound.h"
#include<qthread.h>
#include <QMediaPlayer>
#include <QVideoWidget>
#include <QDebug>
//#include "widget.h"
#include "webcam.h"
#include "settings.h"
#include "ui_settings.h"
#include "mainwindowf.h"
#include "mainwindowr.h"
#include "ui_mainwindow.h"
#include "mainwindowa.h"
#include "mainwindowsa.h"

dash::dash(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dash)
{
    ui->setupUi(this);
}

dash::~dash()
{
    delete ui;
}

void dash::on_pushButton_clicked()
{


  /*  QMediaPlayer* player;
player= new QMediaPlayer;
player->setMedia(QUrl::fromLocalFile("C:/Users/hp/Desktop/to work on/New backup 4 +interface/MALEK/welcome.mp3"));
player->play();
qDebug()<<player->errorString();
QThread::sleep(1);
*/







    MainWindow *x = new MainWindow;

    x->show();
    this->hide();




}

void dash::on_pushButton_2_clicked()
{
    login *x = new login;

    x->show();
    this->hide();
}

void dash::on_pushButton_3_clicked()
{
    //Play Video
    QMediaPlayer* player = new QMediaPlayer;
    QVideoWidget* vw= new QVideoWidget;
    player->setVideoOutput(vw);
    player->setMedia(QUrl::fromLocalFile("C:/Users/hp/Desktop/abccc.mpg"));
    vw->setGeometry(234,38,788,788);


    vw->show();
    player->play();
    qDebug() <<player->state();



   // Play video Music
    //QMediaPlayer* player;
    // QMediaPlayer* player = new QMediaPlayer;
player= new QMediaPlayer;
player->setMedia(QUrl::fromLocalFile("C:/Users/hp/Desktop/vid.m4a"));
player->play();
qDebug()<<player->errorString();
QThread::sleep(1);


}



void dash::on_pushButton_4_clicked()
{

    settings *x = new settings;

    x->show();
//    this->hide()

}

void dash::on_Mode_jour_clicked()
{
    QPixmap pix("C:/Users/hp/Desktop/to work on/New backup 4 +interface/MALEK/malek/az.png");


    ui->label_mask->setPixmap(pix.scaled(215,215,Qt::KeepAspectRatio));
}

void dash::on_Mode_nuit_clicked()
{
    QPixmap pix("C:/Users/hp/Desktop/to work on/New backup 4 +interface/MALEK/malek/mask.png");


    ui->label_mask->setPixmap(pix.scaled(1800,1800,Qt::KeepAspectRatio));
}

void dash::on_pushButton_5_clicked()
{
    on_Mode_jour_clicked();

}

void dash::on_pushButton_6_clicked()
{
    on_Mode_nuit_clicked();

}

void dash::on_pushButton_7_clicked()
{
      mainwindowf *x = new mainwindowf;

    x->show();
    this->hide();
}

void dash::on_pushButton_8_clicked()
{
    mainwindowR *x = new mainwindowR;

  x->show();
  this->hide();
}

void dash::on_pushButton_9_clicked()
{


    mainwindowsa *x= new mainwindowsa;

   x->show();
   this->hide();

}




void dash::on_pushButton_11_clicked()
{
    mainwindowA *x = new mainwindowA;

  x->show();
  this->hide();
}
