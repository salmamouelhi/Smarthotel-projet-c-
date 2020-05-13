#ifndef EVENEMENT_H
#define EVENEMENT_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class evenement
{
public:
    evenement();
    evenement(int ,QString ,QString ,int ,int ,QString ,QString );
    int get_id_evenement();
    QString get_type();
    QString get_date();
    int get_salle();
    int get_nombre_personnes();
    QString get_prix();
    QString get_disponibilite();
    bool ajouter_2();
    bool modifier_2(int);
    QSqlQueryModel * rechercher_2(const QString &id_evenement);
    QSqlQueryModel * afficher();
  //  QSqlQueryModel *trierevenement(QString);
    QSqlQueryModel * tri_pub_2(int );
    QSqlQueryModel * tri_pub_3(int );
    QSqlQueryModel * tri_pub_4(int );
    QSqlQueryModel * tri_pub_5(int );
    QSqlQueryModel * tri_pub_6(int );
    QSqlQueryModel * tri_pub_7(int );



    bool supprimer_2(int);
    private:
        QString type,date_,disponibilite,prix;
        int id_evenement,salle,nombre_personnes;
    };


#endif // EVENEMENT_H

