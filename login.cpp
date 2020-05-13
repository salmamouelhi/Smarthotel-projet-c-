#include "login.h"
#include "dash.h"
#include "ui_dash.h"
#include "ui_login.h"
#include <QMessageBox>
#include <QDebug>
#include <QFile>
#include <QMediaPlayer>
#include<qthread.h>


login::login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
}

login::~login()
{
    delete ui;
}

void login::on_pushButton_clicked()
{


    dash *x = new dash;
if(ui->user->text()=="malek" && ui->pass->text()=="1234")
{
/*
    QMediaPlayer* player;
player= new QMediaPlayer;
player->setMedia(QUrl::fromLocalFile("C:/Users/hp/Desktop/to work on/New backup 4 +interface/MALEK/welcome.mp3"));
player->play();
qDebug()<<player->errorString();
QThread::sleep(1);
*/
    x->show();
    this->hide();


}

else {
    if (ui->user->text()!="malek")
    {
        ui->user->setStyleSheet(" border-radius:9px; border: 2px solid #b50000;  background:red");
         ui->label_logi->setText("*Username INVALIDE!!");
    }

    if (ui->pass->text()!="1234")
    {
        ui->pass->setStyleSheet(" border-radius:9px; border: 2px solid #b50000;  background:red");
         ui->label_mdp->setText("*Password INVALIDE!!");
    }

    if ((ui->user->text()!="malek") && (ui->pass->text()!="1234") )
    {

   ui->user->setStyleSheet(" border-radius:9px; border: 2px solid #b50000;  background:red");
   ui->pass->setStyleSheet(" border-radius:9px; border: 2px solid #b50000;  background:red");
      ui->label_logi->setText("*Username INVALIDE!!");
       ui->label_mdp->setText("*Password INVALIDE!!");

}
}
}



void login::on_show_password_pressed()
{
ui->pass->setEchoMode(QLineEdit::Normal);
}

void login::on_show_password_released()
{
ui->pass->setEchoMode(QLineEdit::Password);
}

void login::on_pushButton_2_clicked()
{

}

void login::on_pushButton_3_clicked()
{
    ui->user->setStyleSheet(" border-radius:9px; border: 2px solid #b50000;background: qradialgradient(cx: 0.3, cy: -0.4,fx: 0.0, fy: -0.0,radius: 1.89, stop: 0 #ffffff, stop: 1 #999);");
    ui->pass->setStyleSheet(" border-radius:9px; border: 2px solid #b50000;background: qradialgradient(cx: 0.3, cy: -0.4,fx: 0.0, fy: -0.0,radius: 1.89, stop: 0 #ffffff, stop: 1 #999);");

    ui->label_logi->setText("");
     ui->label_mdp->setText("");
}
