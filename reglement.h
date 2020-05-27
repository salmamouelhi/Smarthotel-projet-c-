#ifndef REGLEMENT_H
#define REGLEMENT_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
class Reglement
{
public:
    Reglement();
    Reglement(int,int,QString);
    QString get_type_paiment();
    int get_id_facture();
    int get_prix();
    bool ajouter2();
    bool supprimer2(int);
    QSqlQueryModel * afficher2();
    bool recherche2(int x);
    QSqlQueryModel * recherchee_2(const QString &id_facture);
    bool modifier2(int,int,QString);
    QSqlQueryModel * trier2();
    int getValide() ;
    void setValide();
private:
    QString type_paiment;
    int id_facture,prix,valide=0;

};


#endif // REGLEMENT_H
