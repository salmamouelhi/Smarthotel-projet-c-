#include "fournisseur.h"
#include <QDebug>

fournisseur::fournisseur()
{
  id_four=0;
  nom="";
  prenom="";
  adresse="";
  tel=0;
  mail="";
  facture="";
}

fournisseur::fournisseur(int id_four , QString nom ,QString prenom, QString adresse,int tel ,QString mail,QString facture)
{
  this->id_four=id_four;
  this->nom=nom;
  this->prenom=prenom;
  this->adresse=adresse;
  this->tel=tel;
  this->mail=mail;
  this->facture=facture;
}

int fournisseur::get_id_four(){return id_four;}
QString fournisseur::get_nom(){return nom;}
QString fournisseur::get_prenom(){return prenom;}
QString fournisseur::get_adresse(){return adresse;}
int fournisseur::get_tel(){return tel;}
QString fournisseur::get_mail(){return mail;}
QString fournisseur::get_facture(){return facture;}

bool fournisseur::ajouterfour()
{
QSqlQuery query;
QString res= QString::number(id_four);
QString ress=QString::number(tel);
query.prepare("INSERT INTO fournisseur (id_four,nom,prenom,adresse,tel,mail,facture ) "
                    "VALUES (:id_four, :nom ,:prenom ,:adresse , :tel , :mail , :facture)");
query.bindValue(":id_four", res);
query.bindValue(":nom", nom);
query.bindValue(":prenom", prenom);
query.bindValue(":adresse", adresse);
query.bindValue(":tel", ress);
query.bindValue(":mail", mail);
query.bindValue(":facture", facture);

return    query.exec();
}

QSqlQueryModel * fournisseur::afficherfour()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from fournisseur");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("id_four"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("adresse"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("tel"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("mail"));
model->setHeaderData(6, Qt::Horizontal, QObject::tr("facture"));
 return model;
}

bool fournisseur::supprimerfour(int idd)
{
QSqlQuery query;
QString res= QString::number(idd);
query.prepare("Delete from fournisseur where id_four = :id ");
query.bindValue(":id", res);
return    query.exec();
}


bool fournisseur::modifierfour(int idd)
{
    QSqlQuery query;
    QString res= QString::number(idd);
    QString ress=QString::number(tel);
    query.prepare("UPDATE fournisseur SET nom=:nom , prenom=:prenom , adresse=:adresse , tel=:tel ,mail=:mail , facture=:facture "
                  " WHERE id_four=:id");
    query.bindValue(":id", res);
    query.bindValue(":nom", nom);
    query.bindValue(":prenom", prenom);
    query.bindValue(":adresse", adresse);
    query.bindValue(":tel",ress);
    query.bindValue(":mail", mail);
    query.bindValue(":facture", facture);


    return    query.exec();
}

QSqlQueryModel * fournisseur::recherchefour(const QString &id)
{

    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("select * from fournisseur where(id_four LIKE '"+id+"')  or (nom LIKE '"+id+"')  or (prenom LIKE '"+id+"')  or (adresse LIKE '"+id+"') or (tel LIKE '"+id+"') or (mail LIKE '"+id+"')");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id_four"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("adresse"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("tel"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("mail"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("facture"));


        return model;
}




QString test_tri(int c)
{
    if (c==0)
    {
        return "ress" ;
    }
    else if (c==1)
    {
        return "id_four";
    }
else if (c==2)
    {
        return "nom";
    }
    else if (c==3)
    {
        return "prenom";
    }


    return "NULL";
}
QSqlQueryModel* fournisseur::triprod1(int i)
{

    QString col = test_tri(i);
    QSqlQueryModel *model = new QSqlQueryModel() ;

    QString header = "SELECT * FROM fournisseur ORDER BY "+col;
    model->setQuery(header);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id_four"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("adresse"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("tel"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("mail"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("facture"));

    return model ;
}
