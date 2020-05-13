#ifndef CATEGORIE_H
#define CATEGORIE_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class categorie
{
public:
    categorie();
    categorie(int,QString);
    int get_id_categorie();
    QString get_nom_categorie();
    bool ajoutercat();
    bool modifiercat(int);
    QSqlQueryModel * recherchecat(const QString &id);
    QSqlQueryModel * affichercat();
     QSqlQueryModel * affichertri();

    bool supprimercat(int);
private:
    int id_categorie;
    QString nom_categorie;


};

#endif // CATEGORIE_H
