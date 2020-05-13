#ifndef PRODUIT_H
#define PRODUIT_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>


class produit
{
public:
    produit();
    produit(int,QString,QString,QString,QString,QString,QString);
    int get_id_produit();
    QString get_quantite();
    QString get_etat();
    QString get_nom();
    QString get_prix_achat();
    QString get_id_categorie();
    QString get_id_four();
    bool ajouterprod();
    bool modifierprod(int);
    QSqlQueryModel * rechercheprod(const QString &id);
    QSqlQueryModel * afficherprod();
    QSqlQueryModel* triprod2(int);
    bool supprimerprod(int);

private:
int id_produit;
    QString nom,etat,quantite,prix_achat,id_categorie,id_four;

};

#endif // PRODUIT_H
