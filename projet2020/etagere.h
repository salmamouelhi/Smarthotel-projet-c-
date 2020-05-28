#ifndef ETAGERE_H
#define ETAGERE_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class Etagere
{
public:
    Etagere();
    Etagere(int,int,QString);
    int get_id();
    int get_quantite();
    QString get_etat();
    bool ajouter_2();
    bool modifier_4(int);
    QSqlQueryModel * modifier_5(const QString &id);
    QSqlQueryModel * afficher();
    bool supprimer_2(int);
private:
    QString etat;
    int id,quantite;
};

#endif // ETAGERE_H
