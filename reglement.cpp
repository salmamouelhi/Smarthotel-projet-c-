#include "reglement.h"

#include <QDebug>
/*#include "connexion.h"*/
Reglement::Reglement()
{
   id_facture=0;
   prix=0;
   type_paiment="";

}
Reglement::Reglement(int id_facture,int prix,QString type_paiment)
{
  this->id_facture=id_facture;
  this->prix=prix;
  this->type_paiment=type_paiment;

}

int Reglement::get_id_facture(){return  id_facture;}
int Reglement::get_prix(){return  prix;}
QString Reglement::get_type_paiment(){return  type_paiment;}

int Reglement::getValide()
{
    return valide;
}
void Reglement::setValide()
{
valide = 1;
}




bool Reglement::ajouter2()
{
QSqlQuery query;
QString res1= QString::number(id_facture);
QString res2= QString::number(prix);
query.prepare("INSERT INTO REGLEMENT (ID_FACTURE,PRIX,TYPE_PAIMENT) "
                    "VALUES (:id_facture,:prix,:type_paiment)");

query.bindValue(":id_facture", res1);

query.bindValue(":prix", res2);
query.bindValue(":type_paiment", type_paiment);



return    query.exec();
}

QSqlQueryModel * Reglement::afficher2()
{
QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from REGLEMENT");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_FACTURE"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("PRIX "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("TYPE_PAIMENT"));



    return model;
}

bool Reglement::supprimer2(int id_facture)
{
QSqlQuery query;
QString res= QString::number(id_facture);
if(recherche2(id_facture))
{
query.prepare(" delete from REGLEMENT where ID_FACTURE = :id_facture ");
query.bindValue(":id_facture", res);
}
else{}
return    query.exec();
}


bool Reglement::recherche2(int x){
    QSqlQuery query;
    query.prepare("select * from REGLEMENT where ID_FACTURE = :id_facture;");
    query.bindValue(":id_facture",x);
    query.exec();
     if(query.first()){return true;}
     else{return false;}
}


bool Reglement::modifier2(int idd,int prix,QString type_paiment){
    QSqlQuery query;
    QString res= QString::number(idd);
    QString res1= QString::number(prix);
    query.prepare("update REGLEMENT set PRIX=:prix ,TYPE_PAIMENT=:type_paiment   where ID_FACTURE = :id_facture");
    query.bindValue(":id_facture",res);
    query.bindValue(":prix", res1);
    query.bindValue(":type_paiment", type_paiment);

    return query.exec();
}



QSqlQueryModel * Reglement :: trier2()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * from REGLEMENT ORDER BY ID_FACTURE");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_FACTURE"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("PRIX "));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("TYPE_PAIMENT"));


        return model;
}
QSqlQueryModel * Reglement::recherchee_2(const QString &id_facture)
{
    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("select * from REGLEMENT where(ID_FACTURE LIKE '"+id_facture+"')");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_FACTURE"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRIX"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("TYPE_PAIMENT"));

        return model;
}
