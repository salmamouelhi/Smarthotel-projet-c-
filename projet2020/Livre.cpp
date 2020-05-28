#include "Livre.h"
#include <QDebug>
Post::Post()
{
id=0;
grade="";
salaire="";
competences="";
mission="";
}
Post::Post(int id,QString grade,QString salaire,QString competences,QString mission)
{
  this->id=id;
  this->grade=grade;
  this->salaire=salaire;
  this->competences=competences;
  this->mission=mission;
}
QString Post::get_grade(){return  grade;}
QString Post::get_salaire(){return  salaire;}
QString Post::get_competences(){return  competences;}
QString Post::get_mission(){return mission;}
int Post::get_id(){return  id;}

bool Post::ajouter()
{
QSqlQuery query;
QString res= QString::number(id);
query.prepare("INSERT INTO post (ID, GRADE, SALAIRE,COMPETENCES,MISSION_PRINCIPALE) "
                    "VALUES (:id, :grade, :salaire, :competences, :mission)");
query.bindValue(":id", res);
query.bindValue(":grade", grade);
query.bindValue(":salaire", salaire);
query.bindValue(":competences", competences);
query.bindValue(":mission", mission);

return    query.exec();
}

QSqlQueryModel * Post::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from post");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("grade"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("salaire"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("competences"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("mission"));
    return model;
}

bool Post::supprimer(int idd)
{
QSqlQuery query;
QString res= QString::number(idd);
query.prepare("Delete from post where ID = :id ");
query.bindValue(":id", res);
return    query.exec();
}

bool Post::modifier(int idd)
{
    QSqlQuery query;
    QString res= QString::number(idd);
    query.prepare("UPDATE post SET GRADE=:grade,  SALAIRE=:salaire, COMPETENCES=:competences , MISSION_PRINCIPALE=:mission WHERE ID=:id");
    query.bindValue(":id", res);
    query.bindValue(":grade", grade);
    query.bindValue(":salaire", salaire);
    query.bindValue(":competences", competences);
    query.bindValue(":mission", mission);


    return    query.exec();
}

QSqlQueryModel * Post::recherche(const QString &id)
{

    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("select * from post where(ID LIKE '"+id+"')");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("grade "));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("salaire"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("competences"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("mission"));

        return model;
}

