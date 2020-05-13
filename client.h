#ifndef CLIENT_H
#define CLIENT_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>


class client
{
public:
    client();
    client(int,QString,QString,QString,QString,QString,QString,QString);
    int get_CIN();

    QString get_nom();
    QString get_prenom();
    QString get_date_naissance();
    QString get_sexe();
    QString get_s_familiale();
    QString get_id_reservation();
    QString get_id_promo();
    bool ajouter_2();
    bool modifier_4(int);

    QSqlQueryModel * afficher();
    bool supprimer_2(int);
    QSqlQueryModel * triclient();
private:
    QString nom,prenom,sexe,s_familiale,date_naissance,id_reservation,id_promo;

    int CIN;




};

#endif // CLIENT_H
