#ifndef PROMO_H
#define PROMO_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class promo
{
public:
    promo();
    promo(int, QString, QString, int );
    QString get_datedebut();
    QString get_datefin();


    int get_idpromo();
    int get_pourcentage();

    bool ajouter();
    bool modifier(int);
    QSqlQueryModel * recherche(const QString &idpromo);
    QSqlQueryModel * afficher();

    bool supprimer(int);
private:
    QString datedebut,datefin;
    int idpromo,pourcentage;
};

#endif // PROMO_H
