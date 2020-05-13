#include "chambre.h"
#include <QDebug>
#include <QSqlQuery>
#include <QTableView>
chambre::chambre()
{
numchambre=0;
type="";
disponibilite="";
prix="";
idservice="";
image="";
}

chambre::chambre(int numchambre,QString type,QString disponibilite,QString prix,QString idservice,QString image)
{
  this->numchambre=numchambre;
  this->type=type;
  this->disponibilite=disponibilite;
  this->prix=prix;
  this->idservice=idservice;
  this->image=image;
}
QString chambre::get_type(){return  type;}
QString chambre::get_disponibilite(){return disponibilite;}
QString chambre::get_prix(){return  prix;}
QString chambre::get_image(){return  image;}

int chambre::get_numchambre(){return  numchambre;}
QString chambre::get_idservice(){return  idservice;}


bool chambre::ajouter()
{
QSqlQuery query;
QString res= QString::number(numchambre);
query.prepare("INSERT INTO chambre (NUMCHAMBRE, TYPE, DISPONIBILITE,PRIX,IDSERVICE,IMAGE) "
                    "VALUES (:numchambre, :type, :disponibilite, :prix, :idservice, :image)");
query.bindValue(":numchambre", res);
query.bindValue(":type", type);
query.bindValue(":disponibilite", disponibilite);
query.bindValue(":prix", prix);
query.bindValue(":idservice", idservice);
query.bindValue(":image", image);

return    query.exec();
}

QSqlQueryModel * chambre::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from chambre");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("numchambre"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("type"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("disponibilite"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("prix"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("idservice"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("image"));
    return model;
}

bool chambre::supprimer(int idd)
{
QSqlQuery query;
QString res= QString::number(idd);
query.prepare("Delete from chambre where NUMCHAMBRE = :numchambre ");
query.bindValue(":numchambre", res);
return    query.exec();
}

bool chambre::modifier(int idd)
{
    QSqlQuery query;
    QString res= QString::number(idd);
    query.prepare("UPDATE chambre SET TYPE=:type,  DISPONIBILITE=:disponibilite, PRIX=:prix, IDSERVICE=:idservice, IMAGE=:image WHERE NUMCHAMBRE=:numchambre");
    query.bindValue(":numchambre", res);
    query.bindValue(":type", type);
    query.bindValue(":disponibilite", disponibilite);
    query.bindValue(":prix", prix);
    query.bindValue(":idservice", idservice);
      query.bindValue(":image", image);

    return    query.exec();
}

QSqlQueryModel * chambre::recherche(const QString &numchambre)
{

    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("select * from chambre where(NUMCHAMBRE LIKE '"+numchambre+"')");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("NUMCHAMBRE"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("type "));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("disponibilite"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("prix"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("idservice"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("image"));


        return model;
}

/*************/ //dagde

void chambre::clearTable(QTableView *table){
    QSqlQueryModel *model=new QSqlQueryModel();
    model->clear();
    table->setModel(model);}

void chambre::searchRegexp(QTableView *table, int x){
   QSqlQueryModel *model=new QSqlQueryModel();
   QSqlQuery *query =new QSqlQuery;
   query->prepare("select * from chambre where regexp_like(numchambre,:numchambre);");
   query->bindValue(":numchambre",x);

   if(x==0){qDebug("tawa 0");

   query->prepare("select * from chambre;");   }
   query->exec();
   model->setQuery(*query);
   table->setModel(model);
   table->show();
}
