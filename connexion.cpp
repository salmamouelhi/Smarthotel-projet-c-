#include "connexion.h"
Connexion::Connexion(){
                      }
bool Connexion::ouvrirConnexion()
{bool test=false;
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("test");
    db.setUserName("Issam");//inserer nom de l'utilisateur
    db.setPassword("winners95");//inserer mot de passe de cet utilisateur

    if (db.open())
    test=true;





        return  test;
}

