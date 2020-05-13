#ifndef Schambre_H
#define Schambre_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QTableView>

class Schambre
{
public:
    Schambre();
    Schambre(int, QString , QString , QString );
    int get_id();
    QString get_type();
    QString get_dispo();
    QString get_prix();

    bool ajouter_2();
    bool modifier_4(int);
    QSqlQueryModel * modifier_5(const QString &id);
    QSqlQueryModel * afficher();
    void clearTable(QTableView*);
    void searchRegexp(QTableView*,int);
    bool supprimer_2(int);
private:
    QString type,dispo,prix;
    int id;
};

#endif // Schambre_H
