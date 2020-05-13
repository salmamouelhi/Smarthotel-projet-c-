#include "promo.h"
#include <QDebug>
promo::promo()
{
idpromo=0;
datedebut="";
datefin="";
pourcentage=0;

}

promo::promo(int idpromo,QString datedebut,QString datefin ,int pourcentage)
{
  this->idpromo=idpromo;
  this->datedebut=datedebut;
  this->datefin=datefin;
  this->pourcentage=pourcentage;

}
QString promo::get_datedebut(){return  datedebut;}
QString promo::get_datefin(){return datefin;}


int promo::get_idpromo(){return  idpromo;}
int promo::get_pourcentage(){return  pourcentage;}


bool promo::ajouter()
{
QSqlQuery query;
QString res= QString::number(idpromo);
query.prepare("INSERT INTO promo (IDPROMO, DATEDEBUT, DATEFIN, POURCENTAGE) "
                    "VALUES (:idpromo, :datedebut, :datefin, :pourcentage)");

query.bindValue(":idpromo", res);
query.bindValue(":datedebut", datedebut);
query.bindValue(":datefin", datefin);
query.bindValue(":pourcentage", pourcentage);


return    query.exec();
}

QSqlQueryModel * promo::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from promo");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("idpromo"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("datedebut"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("datefin"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("pourcentage"));

    return model;
}

bool promo::supprimer(int idpromo)
{
QSqlQuery query;
QString res= QString::number(idpromo);
query.prepare("Delete from promo where IDPROMO = :idpromo ");
query.bindValue(":idpromo", res);
return    query.exec();
}

bool promo::modifier(int idpromo)
{
    QSqlQuery query;
    QString res= QString::number(idpromo);
    query.prepare("UPDATE promo SET  DATEDEBUT=:datedebut, DATEFIN=:datefin, POURCENTAGE=:pourcentage WHERE IDPROMO=:idpromo");
    query.bindValue(":idpromo", res);
    query.bindValue(":datedebut", datedebut);
    query.bindValue(":datefin", datefin);
    query.bindValue(":pourcentage", pourcentage);


    return    query.exec();
}

QSqlQueryModel * promo::recherche(const QString &idpromo)
{

    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("select * from promo where(IDPROMO LIKE '"+idpromo+"')");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("idpromo"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("datedebut "));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("datefin"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("pourcentage"));


        return model;
}

