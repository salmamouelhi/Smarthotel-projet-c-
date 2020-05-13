#include "client.h"

client::client()
{
CIN=0;

nom="";
prenom="";
date_naissance="";
sexe="";
s_familiale="";
id_reservation="";
id_promo="";
}
client::client(int CIN,QString nom,QString prenom,QString date_naissance,QString sexe,QString s_familiale,QString id_reservation,QString id_promo)
{
  this->CIN=CIN;
  this->nom=nom;
  this->prenom=prenom;
  this->date_naissance=date_naissance;
  this->sexe=sexe;
  this->s_familiale=s_familiale;
  this->id_reservation=id_reservation;
  this->id_promo=id_promo;
}
int client::get_CIN(){return CIN;}
QString client::get_nom(){return  nom;}
QString client::get_prenom(){return  prenom;}
QString client::get_date_naissance(){return  date_naissance;}
QString client::get_sexe(){return  sexe;}
QString client::get_s_familiale(){return  s_familiale;}
QString client::get_id_reservation(){return  id_reservation;}
QString client::get_id_promo(){return id_promo;}

bool client::ajouter_2()
{
QSqlQuery query;
QString res= QString::number(CIN);



query.prepare("INSERT INTO client(CIN, nom, prenom, date_naissance, sexe, s_familiale, id_reservation, id_promo) "
                    "VALUES (:CIN, :nom, :prenom, :date_naissance, :sexe, :s_familiale, :id_reservation, :id_promo)");
query.bindValue(":CIN",res);

query.bindValue(":nom", nom);
query.bindValue(":prenom", prenom);
query.bindValue(":date_naissance", date_naissance);
query.bindValue(":sexe", sexe);
query.bindValue(":s_familiale", s_familiale);
query.bindValue(":id_reservation", id_reservation);
query.bindValue(":id_promo", id_promo);




return    query.exec();
}

QSqlQueryModel * client::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from client");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("CIN"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("date_naissance"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("sexe"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("s_familiale"));
model->setHeaderData(6, Qt::Horizontal, QObject::tr("id_reservation"));
model->setHeaderData(7, Qt::Horizontal, QObject::tr("id_promo"));
    return model;
}

bool client::supprimer_2(int cin)
{
QSqlQuery query;
QString res= QString::number(cin);
query.prepare("Delete from client where CIN = :cin ");
query.bindValue(":cin", res);
return    query.exec();
}



bool client::modifier_4(int CIN)
{
    QSqlQuery query;
    QString res= QString::number(CIN);


    query.prepare("UPDATE client SET CIN=:CIN,  NOM=:nom , PRENOM=:prenom, DATE_NAISSANCE=:date_naissance, SEXE=:sexe, S_FAMILIALE=:s_familiale, ID_RESERVATION=:id_reservation, ID_PROMO=:id_promo WHERE CIN=:CIN");
    query.bindValue(":CIN", res);

    query.bindValue(":nom", nom);
    query.bindValue(":prenom", prenom);
    query.bindValue(":date_naissance", date_naissance);
    query.bindValue(":sexe", sexe);
    query.bindValue(":s_familiale", s_familiale);
    query.bindValue(":id_reservation", id_reservation);
    query.bindValue(":id_promo", id_promo);

    return    query.exec();
}

QSqlQueryModel * client::triclient()
 {QSqlQueryModel * model= new QSqlQueryModel();
 model->setQuery("select * FROM client ORDER BY CIN ASC");
 model->setHeaderData(0, Qt::Horizontal, QObject::tr("CIN"));
 model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom "));
 model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prenom"));
 model->setHeaderData(3, Qt::Horizontal, QObject::tr("date_naissance"));
  model->setHeaderData(4, Qt::Horizontal, QObject::tr("sexe"));
 model->setHeaderData(5, Qt::Horizontal, QObject::tr("s_familiale"));
  model->setHeaderData(6, Qt::Horizontal, QObject::tr("id_reservation"));
   model->setHeaderData(7, Qt::Horizontal, QObject::tr("id_promo"));
     return model;
 }
