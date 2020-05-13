#include "Schambre.h"
#include <QSqlQuery>
#include <QTableView>

Schambre::Schambre()
{
id=0;
type="";
dispo="";
prix="";
}
Schambre::Schambre(int id, QString type, QString dispo, QString prix)
{
  this->id=id;
  this->type=type;
  this->dispo=dispo;
  this->prix=prix;
}
int Schambre::get_id(){return id;}
QString Schambre::get_type(){return  type;}
QString Schambre::get_dispo(){return  dispo;}
QString Schambre::get_prix(){return  prix;}

bool Schambre::ajouter_2()
{
QSqlQuery query;
QString res= QString::number(id);
query.prepare("INSERT INTO servicech (ID, TYPE, DISPO,PRIX) "
                    "VALUES (:id, :type, :dispo, :prix)");
query.bindValue(":id", res);
query.bindValue(":type", type);
query.bindValue(":dispo", dispo);
query.bindValue(":prix", prix);


return    query.exec();
}

QSqlQueryModel * Schambre::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from servicech");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("type"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("dispo"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("prix"));
    return model;
}

bool Schambre::supprimer_2(int idd)
{
QSqlQuery query;
QString res= QString::number(idd);
query.prepare("Delete from servicech where ID = :id ");
query.bindValue(":id", res);
return    query.exec();
}

bool Schambre::modifier_4(int idd)
{
    QSqlQuery query;
    QString res= QString::number(idd);
    query.prepare("UPDATE servicech SET TYPE=:type,  DISPO=:dispo, PRIX=:prix WHERE ID=:id");
    query.bindValue(":id", res);
    query.bindValue(":type", type);
    query.bindValue(":dispo", dispo);
     query.bindValue(":prix", prix);


    return    query.exec();
}

QSqlQueryModel * Schambre::modifier_5(const QString &id)
{

    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("select * from servicech where(ID LIKE '"+id+"')");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("type"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("dispo"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("prix"));
        return model;
}


void Schambre::clearTable(QTableView *table){
    QSqlQueryModel *model=new QSqlQueryModel();
    model->clear();
    table->setModel(model);}

void Schambre::searchRegexp(QTableView *table, int x){
   QSqlQueryModel *model=new QSqlQueryModel();
   QSqlQuery *query =new QSqlQuery;
   query->prepare("select * from servicech where regexp_like(ID,:ID);");
   query->bindValue(":ID",x);

   if(x==0){qDebug("tawa 0");

   query->prepare("select * from servicech;");   }
   query->exec();
   model->setQuery(*query);
   table->setModel(model);
   table->show();
}

