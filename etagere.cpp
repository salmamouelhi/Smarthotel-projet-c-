#include "etagere.h"

personnel::personnel()
{
cin=0;
nom="";
prenom="";
daten="";
civilite="";
email="";
tel=0;
adresse="";
photo="";
}
personnel::personnel(int cin,QString nom,QString prenom,QString daten,QString civilite,QString email,int tel,QString adresse,QString photo)
{
  this->cin=cin;
  this->nom=nom;
  this->prenom=prenom;
  this->daten=daten;
  this->civilite=civilite;
    this->email=email;
    this->tel=tel;
    this->adresse=adresse;
    this->photo=photo;
}
int personnel::get_cin(){return cin;}
int personnel::get_tel(){return tel;}
QString personnel::get_nom(){return  nom;}
QString personnel::get_prenom(){return  prenom;}
QString personnel::get_daten(){return  daten;}
QString personnel::get_civilite(){return  civilite;}
QString personnel::get_email(){return  email;}
QString personnel::get_adresse(){return  adresse;}
QString personnel::get_photo(){return  photo;}


bool personnel::ajouter_2()
{
    QSqlQuery query;
    QString res= QString::number(cin);

    query.prepare("INSERT INTO personnel (CIN, NOM, PRENOM,DATEN,CIVILITE,EMAIL,TEL,ADRESSE,PHOTO) "
                        "VALUES (:cin, :nom, :prenom, :daten, :civilite, :email, :tel , :adresse, :photo )");
    query.bindValue(":cin", res);
    query.bindValue(":nom", nom);
    query.bindValue(":prenom", prenom);
    query.bindValue(":daten", daten);
    query.bindValue(":civilite", civilite);
    query.bindValue(":email", email);
    query.bindValue(":tel", tel);
    query.bindValue(":adresse", adresse);
    query.bindValue(":photo", photo);

return    query.exec();
}

QSqlQueryModel * personnel::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from personnel");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("cin"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("daten"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("civilite"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("email"));
model->setHeaderData(6, Qt::Horizontal, QObject::tr("tel"));
model->setHeaderData(7, Qt::Horizontal, QObject::tr("adresse"));
model->setHeaderData(8, Qt::Horizontal, QObject::tr("photo"));
    return model;
}

bool personnel::supprimer_2(int cin)
{
QSqlQuery query;
QString res= QString::number(cin);
query.prepare("Delete from personnel where CIN = :cin ");
query.bindValue(":cin", res);
return    query.exec();
}
/*
bool personnel::modifier_4(int cin)
{
    QSqlQuery query;
    //QString res= QString::number(cin);
    query.prepare("UPDATE personnel SET NOM=:nom,  PRENOM=:prenom, DATEN=:daten , CIVILITE=:civilite, EMAIL=:email, TEL=:tel , ADRESSE=:adresse , PHOTO=:photo WHERE CIN=:cin");
    query.bindValue(":cin", cin);
    query.bindValue(":nom", nom);
    query.bindValue(":prenom", prenom);
    query.bindValue(":daten", daten);
    query.bindValue(":civilite", civilite);
    query.bindValue(":email", email);
    query.bindValue(":tel", tel);
    query.bindValue(":adresse", adresse);
    query.bindValue(":photo", photo);




    return    query.exec();
}

QSqlQueryModel * personnel::modifier_5(const QString &cin)
{

    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("select * from personnel where(CIN LIKE '"+cin+"')");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("cin"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("daten"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("civilite"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("email"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("tel"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("adresse"));
    model->setHeaderData(8, Qt::Horizontal, QObject::tr("photo"));

        return model;
}
*/

bool personnel::modifier(int cin)
{
    QSqlQuery query;
    QString res= QString::number(cin);
    query.prepare("UPDATE personnel SET NOM=:nom,  PRENOM=:prenom, DATEN=:daten , CIVILITE=:civilite, EMAIL=:email, TEL=:tel , ADRESSE=:adresse , PHOTO=:photo WHERE CIN=:cin");
    query.bindValue(":cin", res);
    query.bindValue(":nom", nom);
    query.bindValue(":prenom", prenom);
    query.bindValue(":daten", daten);
    query.bindValue(":civilite", civilite);
        query.bindValue(":email", email);
        query.bindValue(":tel", tel);
        query.bindValue(":adresse", adresse);
        query.bindValue(":photo", photo);


    return    query.exec();
}

QSqlQueryModel * personnel::recherche(const QString &cin)
{

    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("select * from personnel where(CIN LIKE '"+cin+"')");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("cin"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("daten"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("civilite"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("email"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("tel"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("adresse"));
    model->setHeaderData(8, Qt::Horizontal, QObject::tr("photo"));
        return model;
}
