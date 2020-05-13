#include "evenement.h"
#include <QDebug>
evenement::evenement()
{
    id_evenement=salle=nombre_personnes=0;
    disponibilite=type=date_=prix="";
}
evenement::evenement(int id_evenement,QString type,QString date_,int salle,int nombre_personnes,QString prix,QString disponibilite)
{
this->id_evenement=id_evenement;
    this->salle=salle;
    this->nombre_personnes=nombre_personnes;
    this->prix=prix;
    this->disponibilite=disponibilite;
    this->type=type;
    this->date_=date_;
}
int evenement::get_id_evenement(){return id_evenement;}
QString evenement::get_type(){return type;}
QString evenement::get_date(){return date_;}
int evenement::get_salle(){return salle;}
int evenement::get_nombre_personnes(){return nombre_personnes;}
QString evenement::get_prix(){return prix;}
QString evenement::get_disponibilite(){return disponibilite;}

bool evenement::ajouter_2()
{
QSqlQuery query;
QString res= QString::number(id_evenement);

QString re= QString::number(salle);
QString r= QString::number(nombre_personnes);
//QString strprix = QString::number(prix, 'f', 3);

query.prepare("INSERT INTO evenement (ID_EVENEMENT, TYPE, DATE_, SALLE, NOMBRE_PERSONNES, PRIX, DISPONIBILITE ) "
                    "VALUES (:id_evenement, :type, :date_, :salle, :nombre_personnes, :prix, :disponibilite)");
query.bindValue(":id_evenement", res);
query.bindValue(":type", type);
query.bindValue(":date_", date_);
query.bindValue(":salle", re);
query.bindValue(":nombre_personnes", r);
query.bindValue(":prix", prix);
query.bindValue(":disponibilite", disponibilite);
return    query.exec();
}

QSqlQueryModel * evenement::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from evenement");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id_evenement"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("type"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("date_"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("salle"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("nombre_personnes"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("prix"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("disponibilite"));

    return model;
}

bool evenement::supprimer_2(int idd)
{
QSqlQuery query;
QString res= QString::number(idd);
query.prepare("Delete from evenement where ID_EVENEMENT = :id_evenement ");
query.bindValue(":id_evenement", res);
return    query.exec();
}

bool evenement::modifier_2(int idd)
{
    QSqlQuery query;
    QString res= QString::number(idd);
    query.prepare("UPDATE evenement SET TYPE=:type, DATE_=:date_, SALLE=:salle,  NOMBRE_PERSONNES=:nombre_personnes, PRIX=:prix, DISPONIBILITE=:disponibilite WHERE ID_EVENEMENT=:id_evenement");
    query.bindValue(":id_evenement", res);
    query.bindValue(":type", type);
    query.bindValue(":date_", date_);
    query.bindValue(":salle", salle);
    query.bindValue(":nombre_personnes", nombre_personnes);
    query.bindValue(":prix", prix);
    query.bindValue(":disponibilite", disponibilite);

    return    query.exec();
}

/*QSqlQueryModel * evenement::modifier_5(const QString &id_evenement)
{

    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("select * from evenement where(ID_evenement LIKE '"+id_evenement+"')");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_evenement"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("TYPE"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("DUREE"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("LIEUX"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("RESPONSABLE"));

        return model;
}*/

QSqlQueryModel * evenement::rechercher_2(const QString &id_evenement)
{

    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("select * from evenement where(ID_EVENEMENT LIKE '"+id_evenement+"')");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_EVENEMENT"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("TYPE"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("DATE_"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("SALLE"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("NOMBRE_PERSONNES"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("PRIX"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("DISPONIBILITE"));
        return model;
}

/*QSqlQueryModel *evenement::trierevenement(QString col )
{
    QSqlQueryModel *model= new QSqlQueryModel() ;
    model->setQuery("select  id_evenement,type,date_,salle,nombre_personnes,prix,disponibilite from evenement order by "+col+" ASC ");
   return model ;
}*/
QString test_tri1(int c)
{
    if (c==0){
        return "id_evenement" ;
    }else if (c==1){
        return "type";
    }else if (c==2){
     return "date_" ;
    }else if (c==3){
        return "salle" ;
       }else if (c==4){
        return "nombre_personnes";
    }else if (c==5){
        return "prix";
    }
    return "NULL";
}

QSqlQueryModel * evenement::tri_pub_2(int i){
    QString col = test_tri1(i);
    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM evenement order by id_evenement ASC");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_EVENEMENT"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("TYPE"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("DATE_"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("SALLE"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("NOMBRE_PERSONNES"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("PRIX"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("DISPONIBILITE"));


        return model;
    }

QSqlQueryModel * evenement::tri_pub_3(int i){
    QString col = test_tri1(i);
    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM evenement order by type ASC");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_EVENEMENT"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("TYPE"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("DATE_"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("SALLE"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("NOMBRE_PERSONNES"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("PRIX"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("DISPONIBILITE"));


        return model;
    }
QSqlQueryModel * evenement::tri_pub_4(int i){
    QString col = test_tri1(i);
    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM evenement order by date_ ASC");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_EVENEMENT"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("TYPE"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("DATE_"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("SALLE"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("NOMBRE_PERSONNES"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("PRIX"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("DISPONIBILITE"));


        return model;
    }
QSqlQueryModel * evenement::tri_pub_5(int i){
    QString col = test_tri1(i);
    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM evenement order by salle ASC");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_EVENEMENT"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("TYPE"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("DATE_"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("SALLE"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("NOMBRE_PERSONNES"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("PRIX"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("DISPONIBILITE"));


        return model;
    }
QSqlQueryModel * evenement::tri_pub_6(int i){
    QString col = test_tri1(i);
    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM evenement order by nombre_personnes ASC");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_EVENEMENT"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("TYPE"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("DATE_"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("SALLE"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("NOMBRE_PERSONNES"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("PRIX"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("DISPONIBILITE"));


        return model;
    }
QSqlQueryModel * evenement::tri_pub_7(int i){
    QString col = test_tri1(i);
    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM evenement order by prix ASC");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_EVENEMENT"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("TYPE"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("DATE_"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("SALLE"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("NOMBRE_PERSONNES"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("PRIX"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("DISPONIBILITE"));


        return model;
    }

