#ifndef CHAMBRE_H
#define CHAMBRE_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QTableView>
class chambre
{public:
    chambre();
    chambre(int, QString, QString, QString, QString,QString );
    QString get_type();
    QString get_disponibilite();
    QString get_prix();
    QString get_image();

    int get_numchambre();
    QString get_idservice();

    bool ajouter();
    bool modifier(int);
    QSqlQueryModel * recherche(const QString &numchambre);
    QSqlQueryModel * afficher();

    void clearTable(QTableView*);
    void searchRegexp(QTableView*,int);
    bool supprimer(int);
private:
    QString type,disponibilite,prix,image,idservice;
    int numchambre;
};

#endif // chambre_H
