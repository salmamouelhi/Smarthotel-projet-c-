#ifndef ETAGERE_H
#define ETAGERE_H


#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class personnel
{
public:
    personnel();
    personnel(int,QString,QString,QString,QString,QString,int,QString,QString);
    int get_cin();
    int get_tel();
    QString get_nom();
    QString get_prenom();
    QString get_daten();
    QString get_civilite();
    QString get_email();
    QString get_adresse();
    QString get_photo();
    bool ajouter_2();
  //  bool modifier_4(int);
    bool modifier(int );
    QSqlQueryModel * modifier_5(const QString &cin);
    QSqlQueryModel * recherche(const QString &cin);
    QSqlQueryModel * afficher();
    bool supprimer_2(int);
private:
    QString nom,prenom,daten,civilite,email,adresse,photo;
    int cin,tel;
};

#endif // ETAGERE_H



