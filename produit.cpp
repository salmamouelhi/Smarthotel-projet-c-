#include "produit.h"

#include <QDebug>

produit::produit()
{
id_produit=0;
quantite="";
etat="";
nom="";
prix_achat="";
id_categorie="";
id_four="";

}

produit::produit(int id_produit,QString quantite, QString etat , QString nom , QString prix_achat, QString id_categorie, QString id_four)
{
    this->id_produit=id_produit;
    this->quantite=quantite;
    this->etat=etat;
    this->nom=nom;
    this->prix_achat=prix_achat;
this->id_categorie=id_categorie;
    this->id_four=id_four;
}

int produit::get_id_produit(){return id_produit;}
QString produit::get_quantite(){return quantite;}
QString produit::get_etat(){return etat;}
QString produit::get_nom(){return nom;}
QString produit::get_prix_achat(){return prix_achat;}
QString produit::get_id_categorie(){return id_categorie;}
QString produit::get_id_four(){return id_four;}







bool produit::ajouterprod()
{

QSqlQuery query;
QString res= QString::number(id_produit);

query.prepare("INSERT INTO produit (id_produit,quantite,etat,nom,prix_achat,id_categorie,id_four)"
                    "VALUES (:id_produit, :quantite ,:etat ,:nom , :prix_achat , :id_categorie , :id_four)");
query.bindValue(":id_produit", res);
query.bindValue(":quantite", quantite);
query.bindValue(":etat", etat);
query.bindValue(":nom", nom);
query.bindValue(":prix_achat", prix_achat);
query.bindValue(":id_categorie", id_categorie);
query.bindValue(":id_four", id_four);


return    query.exec();
}


QSqlQueryModel * produit::afficherprod()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from produit");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("id_prod"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("quantite"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("etat"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("nom"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("prix_achat"));

model->setHeaderData(5, Qt::Horizontal, QObject::tr("categorie"));

model->setHeaderData(6, Qt::Horizontal, QObject::tr("fournisseur"));
 return model;
}



bool produit::supprimerprod(int idd)
{
QSqlQuery query;
QString res= QString::number(idd);
query.prepare("Delete from produit where id_produit = :id ");
query.bindValue(":id", res);
return    query.exec();
}




bool produit::modifierprod(int id_produit)
{
    QSqlQuery query;
   QString res= QString::number(id_produit);
    query.prepare("UPDATE produit SET quantite=:quantite , etat=:etat , nom=:nom , prix_achat=:prix_achat ,id_categorie=:id_categorie , id_four=:id_four "
                  " WHERE id_produit=:id_produit");
    query.bindValue(":id_produit", res);
    query.bindValue(":quantite", quantite);
    query.bindValue(":etat", etat);
    query.bindValue(":nom", nom);
    query.bindValue(":prix_achat", prix_achat);
    query.bindValue(":id_categorie", id_categorie);
    query.bindValue(":id_four", id_four);



    return    query.exec();
}

QSqlQueryModel * produit::rechercheprod(const QString &id)
{

    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("select * from produit where(id_produit LIKE '"+id+"') or (nom LIKE '"+id+"') or (quantite LIKE '"+id+"') or (id_four LIKE '"+id+"') or (id_categorie LIKE '"+id+"') or(prix_achat LIKE '"+id+"')");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id_prod"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("quantite"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("etat"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("prix_achat"));

    model->setHeaderData(5, Qt::Horizontal, QObject::tr("id_categorie"));

    model->setHeaderData(6, Qt::Horizontal, QObject::tr("id_four"));


        return model;
}




QString test_tri2(int c)
{
    if (c==0)
    {
        return "ress" ;
    }
    else if (c==1)
    {
        return "id_produit";
    }
else if (c==2)
    {
        return "nom";
    }
    else if (c==3)
    {
        return "etat";
    }

    return "NULL";
}
QSqlQueryModel* produit::triprod2(int i)
{

    QString col = test_tri2(i);
    QSqlQueryModel *model = new QSqlQueryModel() ;

    QString header = "SELECT * FROM produit ORDER BY "+col;
    model->setQuery(header);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id_prod"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("quantite"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("etat"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("prix_achat"));

    model->setHeaderData(5, Qt::Horizontal, QObject::tr("id_categorie"));

    model->setHeaderData(6, Qt::Horizontal, QObject::tr("id_four"));
    return model;
}

