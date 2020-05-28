#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "reservation.h"
#include <QMessageBox>
#include "reglement.h"
#include <QPixmap>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include<QPainter>
#include<QPdfWriter>
#include<QtWidgets>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    QPixmap pix("C:/Users/ISSAM/Desktop/app.png");
    int w =ui->pic->width();
    int h =ui->pic->height();
      ui->pic->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
     ui->tableView->setModel(tmpr.afficher());
     ui->tableView_3->setModel(abc.afficher2());


}

MainWindow::~MainWindow()
{

    delete ui;
}

void MainWindow::on_pushButton_clicked()
{


    int id = ui->lineEdit_3->text().toInt();
    int nbr_nuit = ui->lineEdit->text().toInt();
    QString type_chambre = ui->comboBox->currentText();
    QString type_reservation = ui->comboBox_2->currentText();
    int nbr_chambre=ui->lineEdit_2->text().toInt() ;
    QDate date_arrive = ui->dateEdit_2->date() ;
    QDate date_sortie = ui->dateEdit->date() ;
    QDate date3=QDate::currentDate();
    QRegExp regex1 ("[a-z]$");
    QRegExp regex2 ("^[a-z]");
    QRegExp regex3 ("^[0-9]*$");
    QString msg_id="id invalide";
    QString msg_nbr_nuit="nbr_nuit invlaide";
    QString msg_date_arrive="date arrivee invlide";
    QString msg_date_sortie="date sortie invlaide";
    QString msg_nbr_chbre="nbr chbr invlaide";
    QString msg_vide="";
    Reservation a ;

    if ((id == NULL) || (id<1))
    {
        ui->lineEdit_3->setStyleSheet("QLineEdit { color: red;}");
    ui->txt_id->setText(msg_id);
    ui->txt_id->setStyleSheet("QLabel { background-color : transparent; color : red; }");
    a.setValide();

    }
    else
    {ui->lineEdit_3->setStyleSheet("QLineEdit { color: black;}");
        ui->txt_id->setText(msg_vide);
    }
    if (( nbr_chambre== NULL) || (nbr_chambre<1))
    {
        ui->lineEdit_2->setStyleSheet("QLineEdit { color: red;}");
    ui->txt_nbrch->setText(msg_nbr_chbre);
    ui->txt_nbrch->setStyleSheet("QLabel { background-color : transparent; color : red; }");
    a.setValide();

    }
    else

    {ui->lineEdit_2->setStyleSheet("QLineEdit { color: black;}");
        ui->txt_nbrch->setText(msg_vide);

    }
    if ((nbr_nuit == NULL) || (nbr_nuit<1))
    {
        ui->lineEdit->setStyleSheet("QLineEdit { color: red;}");
    ui->txt_nbrn->setText(msg_nbr_nuit);
    ui->txt_nbrn->setStyleSheet("QLabel { background-color : transparent; color : red; }");
    a.setValide();

    }
    else
    {ui->lineEdit->setStyleSheet("QLineEdit { color: black;}");
        ui->txt_nbrn->setText(msg_vide);

    }
    if ((date_arrive<date3))
       {
        ui->dateEdit_2->setStyleSheet("QLineEdit { color: red;}");
           ui->txt_a->setText(msg_date_arrive);
           ui->txt_a->setStyleSheet("QLabel { background-color : transparent; color : red; }");
           a.setValide();

       }
       else {
        ui->dateEdit_2->setStyleSheet("QLineEdit { color: black;}");
           ui->txt_a->setText(msg_vide);

       }
    if ((date_sortie<date_arrive))
       {
        ui->dateEdit->setStyleSheet("QLineEdit { color: red;}");
           ui->txt_s->setText(msg_date_sortie);
           ui->txt_s->setStyleSheet("QLabel { background-color : transparent; color : red; }");
           a.setValide();

       }
       else {
        ui->dateEdit->setStyleSheet("QLineEdit { color: black;}");
           ui->txt_s->setText(msg_vide);

       }
    Reservation r(id,nbr_nuit,nbr_chambre,date_arrive,date_sortie,type_chambre,type_reservation);
   if (a.getValide()==0)
   {
       bool test = r.ajouter();

                   ui->lineEdit_3->setStyleSheet("QLineEdit { color: green;}");
                   ui->lineEdit_2->setStyleSheet("QLineEdit { color: green;}");
                   ui->lineEdit->setStyleSheet("QLineEdit { color: green;}");
                   ui->dateEdit_2->setStyleSheet("QDateEdit { color: green;}");
                   ui->dateEdit->setStyleSheet("QDateEdit { color: green;}");
        QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;
        notifyIcon->show();
        notifyIcon->setIcon(QIcon("icone.png"));

        notifyIcon->showMessage("GESTION RESERVATION ","reservation  ajouté",QSystemTrayIcon::Information,15000);
  QMessageBox::information(nullptr, QObject::tr("Ajouter une reservation"),
                    QObject::tr("reservation ajouté.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

   }
    else {
        QMessageBox::critical(nullptr, QObject::tr("Ajouter une reservation"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
 }
    ui->tableView->setModel(tmpr.afficher());

}

void MainWindow::on_pushButton_3_clicked()
{
    int id = ui->lineEdit_3->text().toInt() ;

    bool test=tmpr.supprimer(id);
    if(test)
    {
        QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;
        notifyIcon->show();
        notifyIcon->setIcon(QIcon("icone.png"));

        notifyIcon->showMessage("GESTION RESERVATION ","reservation supprimé",QSystemTrayIcon::Information,15000);
        QMessageBox::information(nullptr, QObject::tr("Supprimer une reservation"),
                    QObject::tr("reservation supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("Supprimer une reservation"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    }
     ui->tableView->setModel(tmpr.afficher());
}

void MainWindow::on_pushButton_2_clicked()
{
    int id = ui->lineEdit_3->text().toInt();
    int nbr_nuit = ui->lineEdit->text().toInt();
    QString type_chambre = ui->comboBox->currentText();
    QString type_reservation = ui->comboBox_2->currentText();
    int nbr_chambre=ui->lineEdit_2->text().toInt() ;
    QDate date_arrive = ui->dateEdit_2->date() ;
    QDate date_sortie = ui->dateEdit->date() ;
    QDate date3=QDate::currentDate();


    QRegExp regex1 ("[a-z]$");
    QRegExp regex2 ("^[a-z]");
    QRegExp regex3 ("^[0-9]*$");
    QString msg_id="id invalide";
    QString msg_nbr_nuit="nbr_nuit invlaide";
    QString msg_date_arrive="date arrivee invlide";
    QString msg_date_sortie="date sortie invlaide";
    QString msg_nbr_chbre="nbr chbr invlaide";
    QString msg_vide="";
    Reservation a ;

    if ((id == NULL) || (id<1))
    {
        ui->lineEdit_3->setStyleSheet("QLineEdit { color: red;}");

    ui->txt_id->setText(msg_id);
    ui->txt_id->setStyleSheet("QLabel { background-color : transparent; color : red; }");

    a.setValide();

    }
    else
    {ui->txt_id->setText(msg_vide);
        ui->lineEdit_3->setStyleSheet("QLineEdit { color: black;}");

    }
    if (( nbr_chambre== NULL) || (nbr_chambre<1))
    {
        ui->lineEdit_2->setStyleSheet("QLineEdit { color: red;}");

    ui->txt_nbrch->setText(msg_nbr_chbre);
    ui->txt_nbrch->setStyleSheet("QLabel { background-color : transparent; color : red; }");

    a.setValide();

    }
    else
    {ui->txt_nbrch->setText(msg_vide);
        ui->lineEdit_2->setStyleSheet("QLineEdit { color: black;}");

    }
    if ((nbr_nuit == NULL) || (nbr_nuit<1))
    {
        ui->lineEdit->setStyleSheet("QLineEdit { color: red;}");

    ui->txt_nbrn->setText(msg_nbr_nuit);
    ui->txt_nbrn->setStyleSheet("QLabel { background-color : transparent; color : red; }");

    a.setValide();

    }
    else
    {ui->txt_nbrn->setText(msg_vide);
        ui->lineEdit->setStyleSheet("QLineEdit { color: black;}");

    }
    if ((date_arrive<date3))
       {
        ui->dateEdit_2->setStyleSheet("QLineEdit { color: red;}");

           ui->txt_a->setText(msg_date_arrive);
           ui->txt_a->setStyleSheet("QLabel { background-color : transparent; color : red; }");

           a.setValide();

       }
       else {
           ui->txt_a->setText(msg_vide);
           ui->dateEdit_2->setStyleSheet("QLineEdit { color: black;}");

       }
    if ((date_sortie<date_arrive))
       {         ui->dateEdit->setStyleSheet("QLineEdit { color: red;}");

           ui->txt_s->setText(msg_date_sortie);
           ui->txt_s->setStyleSheet("QLabel { background-color : transparent; color : red; }");

           a.setValide();

       }
       else {
           ui->txt_s->setText(msg_vide);
           ui->dateEdit->setStyleSheet("QLineEdit { color: black;}");

       }
    Reservation r;
    if (a.getValide()==0){
    bool test=r.modifier(id,nbr_nuit,nbr_chambre,date_arrive,date_sortie,type_chambre,type_reservation);
    ui->lineEdit_3->setStyleSheet("QLineEdit { color: green;}");
    ui->lineEdit_2->setStyleSheet("QLineEdit { color: green;}");
    ui->lineEdit->setStyleSheet("QLineEdit { color: green;}");
    ui->dateEdit_2->setStyleSheet("QDateEdit { color: green;}");
    ui->dateEdit->setStyleSheet("QDateEdit { color: green;}");
        QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;
        notifyIcon->show();
        notifyIcon->setIcon(QIcon("icone.png"));

        notifyIcon->showMessage("GESTION RESERVATION ","reservation modifié",QSystemTrayIcon::Information,15000);
        ui->tableView->setModel(tmpr.afficher());



        QMessageBox::information(nullptr, QObject::tr("Modifier reservation"),
                    QObject::tr("reservation Modifié.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("modifier resrvation"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    }



}
void MainWindow::on_pushButton_5_clicked()
{
    QString str=ui->lineEdit_4->text();
     ui->tableView_2->setModel(tmpr.recherche_1(str));
}

void MainWindow::on_tabafficher_activated(const QModelIndex &index)
{
    QString val=ui->tableView->model()->data(index).toString();
        QSqlQuery qry;
        qry.prepare("select * from RESERVATION where ID='"+val+"'or TYPE_CHAMBRE='"+val+"'or TYPE_RESERVATION='"+val+"' or NBR_NUIT='"+val+"' or NBR_CHAMBRE='"+val+"' or DATE_ARRIVE='"+val+"' or DATE_SORTIE='"+val+"'");
         if (qry.exec())
            {
            while (qry.next())
            {
                      ui->lineEdit_3->setText(qry.value(0).toString());
                      ui->lineEdit->setText(qry.value(0).toString());
                      ui->lineEdit_2->setText(qry.value(0).toString());




            }
        }
        else
        {
           // QMessageBox::critical(this,tr("error"),qry.lastError().text());
        }
}

void MainWindow::on_pushButton_4_clicked()
{
    if (ui->radioButton->isChecked()){
    ui->tableView->setModel(tmpr.afficher());
    ui->tableView->setModel(tmpr.trier());
    }
    else
        if (ui->radioButton_2->isChecked())
        {
            ui->tableView->setModel(tmpr.afficher());
            ui->tableView->setModel(tmpr.trier3());
}
}




void MainWindow::on_pushButton_6_clicked()
{

     int id_facture = ui->lineEdit_5->text().toInt();

     int prix = ui->lineEdit_6->text().toInt() ;
     QString type_paiment= ui->comboBox_3->currentText() ;
     QRegExp regex1 ("[a-z]$");
     QRegExp regex2 ("^[a-z]");
     QRegExp regex3 ("^[0-9]*$");
     QString msg_id_facture="id_facture invalide";
     QString msg_prix="prix invlaide";
     QString msg_vide="";
     Reglement a ;

     if ((id_facture == NULL) || (id_facture<1))
     {
         ui->lineEdit_5->setStyleSheet("QLineEdit { color: red;}");
     ui->txtfac->setText(msg_id_facture);
     ui->txtfac->setStyleSheet("QLabel { background-color : transparent; color : red; }");
     a.setValide();

     }
     else
     {ui->lineEdit_5->setStyleSheet("QLineEdit { color: black;}");
         ui->txtfac->setText(msg_vide);
     }
     if (( prix== NULL) || (prix<1))
     {
         ui->lineEdit_6->setStyleSheet("QLineEdit { color: red;}");
     ui->txtprix->setText(msg_prix);
     ui->txtprix->setStyleSheet("QLabel { background-color : transparent; color : red; }");
     a.setValide();

     }
     else

     {ui->lineEdit_6->setStyleSheet("QLineEdit { color: black;}");
         ui->txtprix->setText(msg_vide);

     }

     Reglement r(id_facture,prix,type_paiment);
     if (a.getValide()==0)
     {
         bool test = r.ajouter2();

                     ui->lineEdit_5->setStyleSheet("QLineEdit { color: green;}");
                     ui->lineEdit_6->setStyleSheet("QLineEdit { color: green;}");


   QMessageBox::information(nullptr, QObject::tr("Ajouter une reglement"),
                     QObject::tr("reglement ajouté.\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);
   }
     else {
         QMessageBox::critical(nullptr, QObject::tr("Ajouter une reglement"),
                     QObject::tr("Erreur !.\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);

     ui->tableView_3->setModel(abc.afficher2());
}
 }


void MainWindow::on_tableView_activated(const QModelIndex &index)
{
    QString val=ui->tableView->model()->data(index).toString();
        QSqlQuery qry;
        qry.prepare("select * from RESERVATION where ID='"+val+"'");
        if(qry.exec())
        {
            while(qry.next())
            {

                ui->lineEdit_3->setText(qry.value(0).toString());
                ui->lineEdit->setText(qry.value(1).toString());
                ui->lineEdit_2->setText(qry.value(2).toString());
                ui->dateEdit_2->setDate(qry.value(3).toDate());
                ui->dateEdit->setDate(qry.value(4).toDate());
               ui->comboBox->setCurrentText(qry.value(5).toString());
                ui->comboBox_2->setCurrentText(qry.value(6).toString());




}

}
        else
            QMessageBox::critical(nullptr, QObject::tr("Ajouter une reglement"),
                        QObject::tr("Erreur !.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);


}



void MainWindow::on_pushButton_12_clicked()
{
    //QDateTime datecreation = date.currentDateTime();
            //QString afficheDC = "Date de Creation PDF : " + datecreation.toString() ;
                   QPdfWriter pdf("C:/Users/ISSAM/Desktop/facture.pdf");
                   QPainter painter(&pdf);
                  int i = 4000;
                       painter.setPen(Qt::blue);
                       painter.setFont(QFont("Arial", 30));
                       painter.drawText(1100,1200,"FACTURE");
                       painter.setPen(Qt::black);
                       painter.setFont(QFont("Arial", 15));
                      // painter.drawText(1100,2000,afficheDC);
                       painter.drawRect(100,100,7300,2600);
                       //painter.drawPixmap(QRect(7600,70,2000,2600),QPixmap("C:/Users/RH/Desktop/projecpp/image/logopdf.png"));
                       painter.drawRect(0,3000,9600,500);
                       painter.setFont(QFont("Arial", 9));
                       painter.drawText(200,3300,"ID_FACTURE");
                       painter.drawText(1300,3300,"PRIX");
                       painter.drawText(2100,3300,"TYPE_PAIMENT");


                       QSqlQuery query;
                       query.prepare("  select * from REGLEMENT");
                       query.exec();
                       while (query.next())
                       {
                           painter.drawText(200,i,query.value(0).toString());
                           painter.drawText(1300,i,query.value(1).toString());
                           painter.drawText(2200,i,query.value(2).toString());


                          i = i + 500;
                       }
                       int reponse = QMessageBox::question(this, "Génerer PDF", "<PDF Enregistré>...Vous Voulez Affichez Le PDF ?", QMessageBox::Yes |  QMessageBox::No);
                           if (reponse == QMessageBox::Yes)
                           {
                               QMessageBox::information(nullptr, QObject::tr("Ajouter une facture"),
                                                 QObject::tr("facture ajouté.\n"
                                                             "Click Cancel to exit."), QMessageBox::Cancel);
                               painter.end();
                           }
                           if (reponse == QMessageBox::No)
                           {
                                painter.end();
                           }
}

void MainWindow::on_pushButton_9_clicked()
{

       int id_facture = ui->lineEdit_5->text().toInt();
       int prix= ui->lineEdit_6->text().toInt();
       QString type_paiment = ui->comboBox_3->currentText();

       QRegExp regex1 ("[a-z]$");
       QRegExp regex2 ("^[a-z]");
       QRegExp regex3 ("^[0-9]*$");
       QString msg_id_facture="id_facture invalide";
       QString msg_prix="prix invlaide";
       QString msg_vide="";
       Reglement a ;
       if ((id_facture == NULL) || (id_facture<1))
       {
           ui->lineEdit_5->setStyleSheet("QLineEdit { color: red;}");
       ui->txtfac->setText(msg_id_facture);
       ui->txtfac->setStyleSheet("QLabel { background-color : transparent; color : red; }");
       a.setValide();

       }
       else
       {ui->lineEdit_5->setStyleSheet("QLineEdit { color: black;}");
           ui->txtfac->setText(msg_vide);
       }
       if (( prix== NULL) || (prix<1))
       {
           ui->lineEdit_6->setStyleSheet("QLineEdit { color: red;}");
       ui->txtprix->setText(msg_prix);
       ui->txtprix->setStyleSheet("QLabel { background-color : transparent; color : red; }");
       a.setValide();

       }
       else

       {ui->lineEdit_6->setStyleSheet("QLineEdit { color: black;}");
           ui->txtprix->setText(msg_vide);

       }
       Reglement r;
 if (a.getValide()==0)       {
           bool test=r.modifier2(id_facture,prix,type_paiment);
           ui->lineEdit_5->setStyleSheet("QLineEdit { color: green;}");
           ui->lineEdit_6->setStyleSheet("QLineEdit { color: green;}");
   ui->tableView_3->setModel(abc.afficher2());



           QMessageBox::information(nullptr, QObject::tr("Modifier facture"),
                       QObject::tr("facture Modifié.\n"
                                   "Click Cancel to exit."), QMessageBox::Cancel);

       }
       else
       {
           QMessageBox::critical(nullptr, QObject::tr("modifier facture"),
                       QObject::tr("Erreur !.\n"
                                   "Click Cancel to exit."), QMessageBox::Cancel);
       }



}

void MainWindow::on_pushButton_8_clicked()
{
    ui->tableView_3->setModel(abc.afficher2());
    ui->tableView_3->setModel(abc.trier2());
}

void MainWindow::on_pushButton_10_clicked()
{
    QString str=ui->lineEdit_7->text();
     ui->tableView_4->setModel(abc.recherchee_2(str));
}

void MainWindow::on_pushButton_7_clicked()
{
    int id_facture = ui->lineEdit_5->text().toInt() ;

    bool test=abc.supprimer2(id_facture);
    if(test)
    {
        QMessageBox::information(nullptr, QObject::tr("Supprimer une facture"),
                    QObject::tr("facture supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("Supprimer une facture"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    }
     ui->tableView_3->setModel(abc.afficher2());
}

void MainWindow::on_tableView_3_activated(const QModelIndex &index)
{
    QString val=ui->tableView_3->model()->data(index).toString();
        QSqlQuery qry;
        qry.prepare("select * from REGLEMENT where ID_FACTURE='"+val+"'");
        if(qry.exec())
        {
            while(qry.next())
            {

                ui->lineEdit_5->setText(qry.value(0).toString());
                ui->lineEdit_6->setText(qry.value(1).toString());
                ui->comboBox_3->setCurrentText(qry.value(6).toString());




}

}
        else
            QMessageBox::critical(nullptr, QObject::tr("Ajouter une reglement"),
                        QObject::tr("Erreur !.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);


}

void MainWindow::on_pushButton_11_clicked()
{
    //QDateTime datecreation = date.currentDateTime();
            //QString afficheDC = "Date de Creation PDF : " + datecreation.toString() ;
                   QPdfWriter pdf("C:/Users/ISSAM/Desktop/reservation.pdf");
                   QPainter painter(&pdf);
                  int i = 4000;
                       painter.setPen(Qt::blue);
                       painter.setFont(QFont("Arial", 30));
                       painter.drawText(1100,1200,"RESERVATION");
                       painter.setPen(Qt::black);
                       painter.setFont(QFont("Arial", 15));
                      // painter.drawText(1100,2000,afficheDC);
                       painter.drawRect(100,100,7300,2600);
                       //painter.drawPixmap(QRect(7600,70,2000,2600),QPixmap("C:/Users/RH/Desktop/projecpp/image/logopdf.png"));
                       painter.drawRect(0,3000,9600,500);
                       painter.setFont(QFont("Arial", 9));
                       painter.drawText(200,3300,"ID");
                       painter.drawText(900,3300,"NBR_NUIT");
                       painter.drawText(1700,3300,"NBR_CHAMBRE");
                       painter.drawText(3000,3300,"DATE_ARRIVEE");
                       painter.drawText(4300,3300,"DATE_SORTIE");
                       painter.drawText(5500,3300,"TYPE_CHAMBRE");
                       painter.drawText(7100,3300,"TYPE_RESERVATION");




                       QSqlQuery query;
                       query.prepare("  select * from RESERVATION");
                       query.exec();
                       while (query.next())
                       {
                           painter.drawText(200,i,query.value(0).toString());
                           painter.drawText(900,i,query.value(1).toString());
                           painter.drawText(1700,i,query.value(2).toString());
                           painter.drawText(3000,i,query.value(3).toString());
                           painter.drawText(4300,i,query.value(4).toString());
                           painter.drawText(5500,i,query.value(5).toString());
                           painter.drawText(7100,i,query.value(6).toString());



                          i = i + 500;
                       }
                       int reponse = QMessageBox::question(this, "Génerer PDF", "<PDF Enregistré>...Vous Voulez Affichez Le PDF ?", QMessageBox::Yes |  QMessageBox::No);
                           if (reponse == QMessageBox::Yes)
                           {
                               QMessageBox::information(nullptr, QObject::tr("Ajouter une reservation"),
                                                 QObject::tr("reservation ajouté.\n"
                                                             "Click Cancel to exit."), QMessageBox::Cancel);
                               painter.end();
                           }
                           if (reponse == QMessageBox::No)
                           {
                                painter.end();
                           }
}

void MainWindow::on_pushButton_13_clicked()
{
    ui->tableView_3->setModel(abc.afficher2());
}

void MainWindow::on_pushButton_14_clicked()
{
    ui->tableView->setModel(tmpr.afficher());

}
