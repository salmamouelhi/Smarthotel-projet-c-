#ifndef LIVRE_H
#define LIVRE_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class Post
{public:
    Post();
    Post(int,QString,QString,QString,QString);
    QString get_grade();
    QString get_salaire();
    QString get_competences();
    QString get_mission();
    int get_id();
    bool ajouter();
    bool modifier(int);
    QSqlQueryModel * recherche(const QString &id);
    QSqlQueryModel * afficher();

    bool supprimer(int);
private:
    QString grade,salaire,competences,mission;
    int id;
};
#endif // LIVRE_H
