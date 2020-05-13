#ifndef FOURNISSEUR_H
#define FOURNISSEUR_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class fournisseur
{
public:
    fournisseur();
    fournisseur(int,QString,QString,QString,int,QString,QString);
    int get_id_four();
    QString get_nom();
    QString get_prenom();
    QString get_adresse();
      int get_tel();
    QString get_mail();
    QString get_facture();
    bool ajouterfour();
    bool modifierfour(int);
    QSqlQueryModel * recherchefour(const QString &id);
    QSqlQueryModel * afficherfour();
    QSqlQueryModel * triprod1(int);

    bool supprimerfour(int);
private:
    int id_four,tel;
    QString nom,prenom,adresse,mail,facture;
};

#endif // FOURNISSEUR_H
