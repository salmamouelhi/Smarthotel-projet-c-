#include "mainwindowa.h"
#include "ui_mainwindowa.h"
#include "livre.h"
#include "dash.h"
#include <QMessageBox>
#include <QFileDialog>
#include <QPixmap>

mainwindowA::mainwindowA(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::mainwindowA)
{
    ui->setupUi(this);
    ui->tabpost->setModel(tmppost.afficher());
}

mainwindowA::~mainwindowA()
{
    delete ui;
}

void mainwindowA::on_pb_ajouter_clicked()
{
    int id = ui->lineEdit_id->text().toInt();
    QString grade= ui->lineEdit_grade->text();
    QString salaire= ui->lineEdit_salaire->text();
    QString competences= ui->lineEdit_competences->text();
    QString mission= ui->lineEdit_mission->text();

    Post l(id,grade,salaire,competences,mission);
    bool test=l.ajouter();
   if ((test)&&(id != 0)&&(salaire != "") && (grade != "")&& (competences !="") && (mission !=""))
    {ui->tabpost->setModel(tmppost.afficher());//refresh
        QMessageBox::information(nullptr, QObject::tr("Ajouter un post"),
                                 QObject::tr("post ajouté.\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);

    }
   if (id == 0)
   {

                   ui->label_16->setText(" erreur" );
   }

   if (salaire == "")
   {

                   ui->label_17->setText(" erreur" );
   }

   if (grade == "")
   {

                   ui->label_18->setText(" erreur" );
   }

   if (competences == "")
   {

       ui->label_19->setText(" erreur" );
   }

   if(mission == "")
   {


     ui->label_20->setText(" erreur" );

   }

}

void mainwindowA::on_pb_supprimer_clicked()
{
    int id = ui->lineEdit_id->text().toInt();
    bool test=tmppost.supprimer(id);
    if(test)
    {ui->tabpost->setModel(tmppost.afficher());//refresh
        QMessageBox::information(nullptr, QObject::tr("Supprimer un post"),
                                 QObject::tr("post supprimé.\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer un post"),
                              QObject::tr("Erreur !.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);


}

void mainwindowA::on_pb_ajouter_2_clicked()
{



    int cin = ui->lineEdit_cin->text().toInt();
    QString nom= ui->lineEdit_nom_2->text();
    QString prenom= ui->lineEdit_prenom_2->text();
    QString daten= ui->lineEdit_daten->text();
    QString civilite= ui->lineEdit_civilite->text();
    QString email= ui->lineEdit_email->text();
    int tel = ui->lineEdit_tel->text().toInt();
    QString adresse= ui->lineEdit_adresse->text();
    QString photo= ui->lineEdit_photo->text();

    personnel e(cin,nom,prenom,daten,civilite,email,tel,adresse,photo);


    bool test=e.ajouter_2();
    if ( (test) && (cin != 0) && (nom != "") && (prenom != "") && (daten != 0) && (civilite != "") && (email != "") && (tel != 0) && (adresse !="") && (photo != "") )
    {ui->tabperso->setModel(tmpperso.afficher());//refresh
        QMessageBox::information(nullptr, QObject::tr("Ajouter un perso"),
                                 QObject::tr("perso ajoutée.\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);

    }
    if (cin == 0)
    {
        ui->label_21->setText(" erreur" );
    }
    if (nom == "")
    {

                    ui->label_22->setText(" erreur" );
    }

    if (prenom  == "")
    {

                    ui->label_23->setText(" erreur" );
    }

    if (daten == "")
    {

                    ui->label_24->setText(" erreur" );
    }

    if (civilite == "")
    {

        ui->label_25->setText(" erreur" );
    }

    if(email == "")
    {


      ui->label_26->setText(" erreur" );

    }

    if (tel == 0)
    {
       ui->label_27->setText(" erreur" );

    }
    if (adresse == "")
    {
        ui->label_28->setText(" erreur" );
    }

    if (photo == "")
    {
        ui->label_29->setText(" erreur" );
    }

}

/*******************************/
void mainwindowA::on_pb_supprimer_2_clicked()
{
    int cin = ui->lineEdit_cin->text().toInt();
    bool test=tmpperso.supprimer_2(cin);
    if(test)
    {ui->tabperso->setModel(tmpperso.afficher());//refresh
        QMessageBox::information(nullptr, QObject::tr("Supprimer une perso"),
                                 QObject::tr("perso supprimée.\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer une perso"),
                              QObject::tr("Erreur !.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
}
/************************************/

void mainwindowA::on_pb_modifier_clicked()
{

    int id = ui->lineEdit_id->text().toInt();
    QString grade= ui->lineEdit_grade->text();
    QString salaire= ui->lineEdit_salaire->text();
    QString competences= ui->lineEdit_competences->text();
    QString mission= ui->lineEdit_mission->text();

    Post l(id,grade,salaire,competences,mission);
    bool test=l.modifier(id);
    if(test)
    {ui->tabpost->setModel(tmppost.afficher());//refresh
        QMessageBox::information(nullptr, QObject::tr("Modifier un post"),
                                 QObject::tr("post modifié.\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Modifier post"),
                              QObject::tr("Erreur !.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);


}


void mainwindowA::on_pb_modifier_2_clicked()
{
    int cin = ui->lineEdit_cin->text().toInt();
    QString nom= ui->lineEdit_nom_2->text();
    QString prenom= ui->lineEdit_prenom_2->text();
    QString daten= ui->lineEdit_daten->text();
    QString civilite= ui->lineEdit_civilite->text();
    QString email= ui->lineEdit_email->text();
    int tel = ui->lineEdit_tel->text().toInt();
    QString adresse= ui->lineEdit_adresse->text();
    QString photo= ui->lineEdit_photo->text();

    personnel e(cin,nom,prenom,daten,civilite,email,tel,adresse,photo);


    bool test=e.modifier(cin);
    if(test)
    {ui->tabperso->setModel(tmpperso.afficher());//refresh
        QMessageBox::information(nullptr, QObject::tr("Modifier une perso"),
                                 QObject::tr("perso modifiée.\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Modifier perso"),
                              QObject::tr("Erreur !.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);


}

void mainwindowA::on_pb_rechercher_clicked()
{

    QString str=ui->lineEdit_id->text();
    ui->tabpost->setModel(tmppost.recherche(str));
}



/*
void MainWindow::on_pb_modifier_5_clicked()
{
    QString str=ui->lineEdit_cin->text();
    ui->tabperso->setModel(tmpperso.modifier_5(str));
}
*/
void mainwindowA::on_tablivre_activated(const QModelIndex &index)
{
    QString val=ui->tabpost->model()->data(index).toString();
    QSqlQuery qry;
    qry.prepare("select * from post where ID='"+val+"' or GRADE='"+val+"' or SALAIRE='"+val+"' or COMPETENCES='"+val+"' or MISSION_PRINCIPALE='"+val+"' ");

    if (qry.exec())
    {

        while (qry.next())
        {

            ui->lineEdit_id->setText(qry.value(0).toString());
            ui->lineEdit_grade->setText(qry.value(1).toString());
            ui->lineEdit_salaire->setText(qry.value(2).toString());
            ui->lineEdit_competences->setText(qry.value(3).toString());
            ui->lineEdit_mission->setText(qry.value(4).toString());



        }
    }
    else
    {
        // QMessageBox::critical(this,tr("error"),qry.lastError().text());
    }
}


void mainwindowA::on_pushButton_clicked()
{
    ui->lineEdit_id->setText("");

    ui->lineEdit_grade->setText("");
    ui->lineEdit_salaire->setText("");
    ui->lineEdit_competences->setText("");
    ui->lineEdit_mission->setText("");
}

void mainwindowA::on_pushButton_2_clicked()
{
    //QString col=test_tri(i);
    QSqlQueryModel * model = new QSqlQueryModel();

    model->setQuery("SELECT * FROM POST ORDER BY id ASC");
    model->setHeaderData(0, Qt::Vertical, QObject::tr("id"));
    model->setHeaderData(1, Qt::Vertical, QObject::tr("grade"));
    model->setHeaderData(2, Qt::Vertical, QObject::tr("salaire"));
    model->setHeaderData(3, Qt::Vertical, QObject::tr("competence"));
    model->setHeaderData(4, Qt::Vertical, QObject::tr("mission"));

    ui->tabpost->setModel(model);
    ui->tabpost->show();
}

void mainwindowA::on_pushButton_3_clicked()
{
    {
        QString imageFile = QFileDialog ::getOpenFileName(0,"Select Image","/home/","Image Files (*.jpg)");

        QFileInfo info(imageFile);

        QPixmap image (imageFile);

        ui->lblBkImge->setPixmap(image);
        ui->lblBkImge->show();
        ui->lineEdit->setText(imageFile);
        ui->lblBkImge->setPixmap(image);
    }
}


void mainwindowA::on_pushButton_5_clicked()
{




    ui->lineEdit_cin->setText("");
    ui->lineEdit_nom_2->setText("");
    ui->lineEdit_prenom_2->setText("");
    ui->lineEdit_daten->setText("");
    ui->lineEdit_civilite->setText("");
    ui->lineEdit_email->setText("");
    ui->lineEdit_tel->setText("");
    ui->lineEdit_adresse->setText("");
    ui->lineEdit_photo->setText("");
}

void mainwindowA::on_pushButton_4_clicked()
{
    //QString col=test_tri(i);
    QSqlQueryModel * model = new QSqlQueryModel();

    model->setQuery("SELECT * FROM POST ORDER BY cin ASC");
    model->setHeaderData(0, Qt::Vertical, QObject::tr("cin"));
    model->setHeaderData(1, Qt::Vertical, QObject::tr("nom"));
    model->setHeaderData(2, Qt::Vertical, QObject::tr("prenom"));
    model->setHeaderData(3, Qt::Vertical, QObject::tr("daten"));
    model->setHeaderData(4, Qt::Vertical, QObject::tr("civilite"));
    model->setHeaderData(5, Qt::Vertical, QObject::tr("email"));
    model->setHeaderData(6, Qt::Vertical, QObject::tr("tel"));
    model->setHeaderData(7, Qt::Vertical, QObject::tr("adresse"));
    model->setHeaderData(8, Qt::Vertical, QObject::tr("photo"));

    ui->tabperso->setModel(model);
    ui->tabperso->show();
}


void mainwindowA::on_pushButton_6_clicked()
{
    {
        QString imageFile = QFileDialog ::getOpenFileName(0,"Select Image","/home/","Image Files (*.jpg)");

        QFileInfo info(imageFile);

        QPixmap image (imageFile);

        ui->lblBkImge_2->setPixmap(image);
        ui->lblBkImge_2->show();
        ui->lineEdit->setText(imageFile);
        ui->lblBkImge_2->setPixmap(image);
    }
}



void mainwindowA::on_pushButton_7_clicked()
{
    dash *x = new dash;

    x->show();
    this->hide();
}

void mainwindowA::on_pushButton_8_clicked()
{

}
