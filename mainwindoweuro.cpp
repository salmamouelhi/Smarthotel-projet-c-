#include "mainwindoweuro.h"
#include "ui_mainwindoweuro.h"
#include "euro.h"

mainwindoweuro::mainwindoweuro(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::mainwindoweuro)
{
    ui->setupUi(this);
}

mainwindoweuro::~mainwindoweuro()
{
    delete ui;
}

void mainwindoweuro::on_pushButton208_clicked()
{
    euro *x = new euro;

    x->show();
    this->hide();

}
