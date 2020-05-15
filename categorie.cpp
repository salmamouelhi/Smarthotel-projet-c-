#include "categorie.h"
#include <QDebug>

categorie::categorie()
{
    id_categorie=0;
    nom_categorie="";
}

categorie::categorie(int id_categorie,QString nom_categorie)
{
    this->id_categorie=id_categorie;
    this->nom_categorie=nom_categorie;
}
int categorie::get_id_categorie(){return id_categorie;}
QString categorie::get_nom_categorie(){return  nom_categorie;}



bool categorie::ajoutercat()
{
QSqlQuery query;
QString res= QString::number(id_categorie);
query.prepare("INSERT INTO categorie (id_categorie,nom_categorie ) "
                    "VALUES (:id_categorie, :nom_categorie)");
query.bindValue(":id_categorie", res);
query.bindValue(":nom_categorie", nom_categorie);


return    query.exec();
}



QSqlQueryModel * categorie::affichercat()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from categorie");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("id_categorie"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom_categorie"));
 return model;
}


bool categorie::supprimercat(int idd)
{
QSqlQuery query;
QString res= QString::number(idd);
query.prepare("Delete from categorie where id_categorie = :id ");
query.bindValue(":id", res);
return    query.exec();
}


bool categorie::modifiercat(int idd)
{
    QSqlQuery query;
    QString res= QString::number(idd);
    query.prepare("UPDATE categorie SET nom_categorie=:nom_categorie WHERE id_categorie=:id");
    query.bindValue(":id", res);
    query.bindValue(":nom_categorie", nom_categorie);


    return    query.exec();
}

QSqlQueryModel * categorie::recherchecat(const QString &id)
{

    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("select * from categorie where(id_categorie LIKE '"+id+"')  or (nom_categorie LIKE '"+id+"')");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id_categorie"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom_categorie"));


        return model;
}

QSqlQueryModel * categorie :: affichertri()
{
    QSqlQueryModel * model= new QSqlQueryModel();
  QString ress=QString::number(id_categorie);
    model->setQuery("select * from categorie ORDER BY id_categorie");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("nom_categorie"));


    return model;
}
