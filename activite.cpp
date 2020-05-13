#include "activite.h"
#include <QDebug>
activite::activite()
{
id_activite=0;
type=responsable=duree=lieux="";
}
activite::activite(int id_activite,QString type,QString duree,QString lieux,QString responsable)
{
this->id_activite=id_activite;
this->responsable=responsable;
this->duree=duree;
this->lieux=lieux;
this->type=type;
}
int activite::get_id_activite(){return id_activite;}
QString activite::get_type(){return type;}
QString activite::get_duree(){return duree;}
QString activite::get_lieux(){return lieux;}
QString activite::get_responsable(){return responsable;}

bool activite::ajouter()
{
QSqlQuery query;
QString res= QString::number(id_activite);

query.prepare("INSERT INTO activite (ID_ACTIVITE, TYPE, DUREE, LIEUX, RESPONSABLE ) "
                    "VALUES (:id_activite, :type, :duree, :lieux, :responsable)");
query.bindValue(":id_activite", res);
query.bindValue(":type", type);
query.bindValue(":duree", duree);
query.bindValue(":lieux", lieux);
query.bindValue(":responsable", responsable);

return    query.exec();
}

QSqlQueryModel * activite::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from activite");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("id_activite"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("type"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("duree"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("lieux"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("responsable"));

    return model;
}

bool activite::supprimer(int idd)
{
QSqlQuery query;
QString res= QString::number(idd);
query.prepare("Delete from activite where ID_activite = :id_activite ");
query.bindValue(":id_activite", res);
return    query.exec();
}

bool activite::modifier(int idd)
{
    QSqlQuery query;
    QString res= QString::number(idd);
    query.prepare("UPDATE activite SET TYPE=:type, DUREE=:duree, LIEUX=:lieux,  RESPONSABLE=:responsable WHERE ID_activite=:id_activite");
    query.bindValue(":id_activite", res);
    query.bindValue(":type", type);
    query.bindValue(":duree", duree);
    query.bindValue(":lieux", lieux);
    query.bindValue(":responsable", responsable);

    return    query.exec();
}

/*QSqlQueryModel * activite::modifier_5(const QString &id_activite)
{

    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("select * from activite where(ID_activite LIKE '"+id_activite+"')");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_activite"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("TYPE"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("DUREE"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("LIEUX"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("RESPONSABLE"));

        return model;
}*/
QSqlQueryModel * activite::recherche(const QString &id_activite)
{

    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("select * from activite where(ID_ACTIVITE LIKE '"+id_activite+"')");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_activite"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("TYPE"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("DUREE"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("LIEUX"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("RESPONSABLE"));

        return model;
}
