#ifndef ACTIVITE_H
#define ACTIVITE_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
class activite
{
public:
    activite();
    activite(int ,QString ,QString ,QString ,QString);
    int get_id_activite();
    QString get_type();
    QString get_duree();
    QString get_lieux();
    QString get_responsable();
    bool ajouter();
    bool modifier(int);
    QSqlQueryModel * recherche(const QString &id_activite);
    QSqlQueryModel * afficher();

    bool supprimer(int);
private:
    QString type,duree,lieux,responsable;
    int id_activite;
};


#endif // ACTIVITE_H
