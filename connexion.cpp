#include "connexion.h"
#include <QSqlError>
Connexion::Connexion(){
                      }
bool Connexion::ouvrirConnexion()
{bool test=false;
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
                           db.setDatabaseName("projet_c++");
                           db.setUserName("farouk");//inserer nom de l'utilisateur
                           db.setPassword("esprit20");//inserer mot de passe de cet utilisateur

if (db.open())
    test=true;


return  test;
}
void Connexion::fermerConnexion()
{db.close();}
