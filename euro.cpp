#include "euro.h"
#include "ui_euro.h"
#include "mainwindoweuro.h"

euro::euro(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::euro)
{
    ui->setupUi(this);
}

euro::~euro()
{
    delete ui;
}

void euro::on_pushButton_2222_clicked()
{
    mainwindoweuro *x = new mainwindoweuro;

    x->show();
    this->hide();
}

void euro::on_pushButton100_clicked()
{

    int a=ui->lineEdit->text().toInt();

 double b= a * 3.15 ;
QString valueAsString = QString::number(b);

  ui->lineEdit_2->setText(valueAsString);




/*
  int c=ui->lineEdit_2->text().toInt();

double d= c / 3.15 ;
QString valueAsStringe = QString::number(d);

ui->lineEdit->setText(valueAsStringe);
*/

}
