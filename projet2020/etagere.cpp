#include "etagere.h"

Etagere::Etagere()
{
id=0;
quantite=0;
etat="";
}
Etagere::Etagere(int id,int quantite,QString etat)
{
  this->id=id;
  this->quantite=quantite;
  this->etat=etat;
}
int Etagere::get_id(){return id;}
int Etagere::get_quantite(){return quantite;}
QString Etagere::get_etat(){return  etat;}

bool Etagere::ajouter_2()
{
QSqlQuery query;
QString res= QString::number(id);
QString re= QString::number(quantite);
query.prepare("INSERT INTO etagere (ID, QUANTITE, ETAT) "
                    "VALUES (:id, :quantite, :etat)");
query.bindValue(":id", res);
query.bindValue(":quantite", re);
query.bindValue(":etat", etat);

return    query.exec();
}

QSqlQueryModel * Etagere::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from etagere");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Quantite"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Etat"));
    return model;
}

bool Etagere::supprimer_2(int idd)
{
QSqlQuery query;
QString res= QString::number(idd);
query.prepare("Delete from etagere where ID = :id ");
query.bindValue(":id", res);
return    query.exec();
}

bool Etagere::modifier_4(int idd)
{
    QSqlQuery query;
    QString res= QString::number(idd);
    query.prepare("UPDATE etagere SET QUANTITE=:quantite,  ETAT=:etat WHERE ID=:id");
    query.bindValue(":id", res);
    query.bindValue(":quantite", quantite);
    query.bindValue(":etat", etat);

    return    query.exec();
}

QSqlQueryModel * Etagere::modifier_5(const QString &id)
{

    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("select * from etagere where(ID LIKE '"+id+"')");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Quantite "));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Etat"));

        return model;
}
