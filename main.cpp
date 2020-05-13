#include "login.h"
#include <QApplication>
#include <QMessageBox>
#include "connexion.h"
#include <QtDebug>
#include<QSplashScreen>
#include <QTimer>
#include <QMediaPlayer>
#include<qthread.h>

int main(int argc, char *argv[])
{  QApplication a(argc, argv);

    Connexion c;

  bool test=c.ouvrirConnexion();

  QSplashScreen *splash=new QSplashScreen;
  splash->setPixmap(QPixmap("C:/Users/hp/Desktop/to work on/New backup 4 +interface/MALEK/malek/36.jpg"));
  splash->show();



  login w;
  if(test)
  {   QTimer::singleShot(2500,splash,SLOT(close()));
      QTimer::singleShot(2500,&w,SLOT(show()));
     // w.show();

      QMessageBox::information(nullptr, QObject::tr("database is  open"),
                  QObject::tr("connection avec succés.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

 /******************************************/




     /**********************/

  }
  else
      QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                  QObject::tr("connection failed.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

    return a.exec();}
