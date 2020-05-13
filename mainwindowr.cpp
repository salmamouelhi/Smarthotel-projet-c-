#include "mainwindowr.h"
#include "ui_mainwindowr.h"
#include "client.h"
#include "promo.h"
#include "dash.h"
#include <QMessageBox>

#include "QTextDocument "
#include <QtPrintSupport/QPrinter>
#include <QtPrintSupport/QPrintDialog>
#include <QTextStream>
#include <QFile>
#include <QDataStream>

#include <QFileDialog>
#include <QPixmap>

mainwindowR::mainwindowR(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::mainwindowR)
{
    ui->setupUi(this);
    ui->tabclient->setModel(tmpclient.afficher());
    ui->tabpromo->setModel(tmppromo.afficher());
}

mainwindowR::~mainwindowR()
{
    delete ui;
}


void mainwindowR::on_ajouterclient_clicked()
{
    int CIN = ui->lineEditCIN->text().toInt();
   QString nom = ui->lineEdit_2->text();
   QString prenom = ui->lineEdit_3->text();
    QString date_naissance = ui->lineEdit_4->text();
   QString sexe = ui->comboBox->currentText();
   QString s_familiale = ui->lineEdit_5->text();
   QString id_reservation=ui->lineEdit_6->text();
   QString id_promo=ui->lineEdit_7->text();



  client c (CIN,nom,prenom,date_naissance,sexe,s_familiale,id_reservation,id_promo);
  bool test=c.ajouter_2();
  if(test)
{ui->tabclient->setModel(tmpclient.afficher());//refresh
QMessageBox::information(nullptr, QObject::tr("Ajouter un client"),
                  QObject::tr("client ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter un client"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
/***********************************/

void mainwindowR::on_ajouterpromo_clicked()
{
    int idpromo = ui->lineEditCIN_2->text().toInt();
   QString datedebut = ui->lineEditCIN_3->text();
   QString datefin = ui->lineEditCIN_4->text();
    int pourcentage = ui->lineEditCIN_5->text().toInt();


  promo p (idpromo,datedebut,datefin,pourcentage);
  bool test=p.ajouter();
  if(test)
{ui->tabpromo->setModel(tmppromo.afficher());//refresh
QMessageBox::information(nullptr, QObject::tr("Ajouter une promo"),
                  QObject::tr("promo ajoutée.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter une promo"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}


/***********************************/

void mainwindowR::on_supprimerclient_clicked()
{
    int CIN = ui->lineEditCIN->text().toInt();
    bool test=tmpclient.supprimer_2(CIN);
    if(test)
    {ui->tabclient->setModel(tmpclient.afficher());//refresh
        QMessageBox::information(nullptr, QObject::tr("Supprimer un client"),
                    QObject::tr("Client supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer un client"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);


}

/***********************************/
void mainwindowR::on_supprimerpromo_clicked()
{
    int id_promo = ui->lineEditCIN_2->text().toInt();
    bool test=tmppromo.supprimer(id_promo);
    if(test)
    {ui->tabpromo->setModel(tmppromo.afficher());//refresh
        QMessageBox::information(nullptr, QObject::tr("Supprimer une promo"),
                    QObject::tr("Promo supprimée.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer une promo"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}

/***********************************/

void mainwindowR::on_modifierclient_clicked()
{

    int CIN = ui->lineEditCIN->text().toInt();
   QString nom = ui->lineEdit_2->text();
   QString prenom = ui->lineEdit_3->text();
    QString date_naissance = ui->lineEdit_4->text();
   QString sexe = ui->comboBox->currentText();
   QString s_familiale = ui->lineEdit_5->text();
QString id_reservation=ui->lineEdit_6->text();
QString id_promo=ui->lineEdit_7->text();

  client c (CIN,nom,prenom,date_naissance,sexe,s_familiale,id_reservation,id_promo);
  bool test=c.modifier_4(CIN);
  if(test)
{ui->tabclient->setModel(tmpclient.afficher());//refresh
QMessageBox::information(nullptr, QObject::tr("Modifier un client"),
                  QObject::tr("Client modifiée.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Modifier client"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);


}

/**********************************/
void mainwindowR::on_modifierpromo_clicked()
{

        int idpromo = ui->lineEditCIN_2->text().toInt();
       QString datedebut = ui->lineEditCIN_3->text();
       QString datefin = ui->lineEditCIN_4->text();
        int pourcentage = ui->lineEditCIN_5->text().toInt();


      promo p (idpromo,datedebut,datefin,pourcentage);
      bool test=p.modifier(idpromo);
      if(test)
    {ui->tabpromo->setModel(tmppromo.afficher());//refresh
    QMessageBox::information(nullptr, QObject::tr("Modifier un client"),
                      QObject::tr("Client modifiée.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);

    }
      else
          QMessageBox::critical(nullptr, QObject::tr("Modifier client"),
                      QObject::tr("Erreur !.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);




}
/*************************************/


/*void MainWindow::on_pb_rechercher_clicked()
{

    QString str=ui->lineEdit_id->text();
    ui->tabclient->setModel(tmpclient.recherche(str));
}
*/

/*******************************/





void mainwindowR::on_tabclient_activated(const QModelIndex &index)
{
    QString val=ui->tabclient->model()->data(index).toString();
    QSqlQuery qry;
    qry.prepare("select * from client where CIN='"+val+"' or NOM='"+val+"' or PRENOM='"+val+"' or DATE_NAISSANCE='"+val+"' or SEXE='"+val+"' or S_FAMILIALE='"+val+"'");

     if (qry.exec())
        {

        while (qry.next())
        {

                  ui->lineEditCIN->setText(qry.value(0).toString());
                  ui->lineEdit_2->setText(qry.value(1).toString());
                  ui->lineEdit_3->setText(qry.value(2).toString());
                    ui->lineEdit_4->setText(qry.value(3).toString());

                        ui->comboBox->setCurrentText(qry.value(4).toString());
                         ui->lineEdit_5->setText(qry.value(5).toString());

        }
    }
    else
    {
       // QMessageBox::critical(this,tr("error"),qry.lastError().text());
    }
      }


/***************************/




void mainwindowR::on_tabpromo_activated(const QModelIndex &index)
{
    QString val=ui->tabpromo->model()->data(index).toString();
    QSqlQuery qry;
    qry.prepare("select * from promo where IDPROMO='"+val+"' or DATEDEBUT='"+val+"' or DATEFIN='"+val+"' or POURCENTAGE='"+val+"'");

     if (qry.exec())
        {

        while (qry.next())
        {

                  ui->lineEditCIN_2->setText(qry.value(0).toString());
                  ui->lineEditCIN_3->setText(qry.value(1).toString());
                  ui->lineEditCIN_4->setText(qry.value(2).toString());
                    ui->lineEditCIN_5->setText(qry.value(3).toString());


        }
    }
    else
    {
       // QMessageBox::critical(this,tr("error"),qry.lastError().text());
    }
      }


void mainwindowR::on_pushButton_2_clicked()
{



            int idpromo = ui->lineEditCIN_2->text().toInt();
           QString datedebut = ui->lineEditCIN_3->text();
           QString datefin = ui->lineEditCIN_4->text();
            int pourcentage = ui->lineEditCIN_5->text().toInt();


          promo p (idpromo,datedebut,datefin,pourcentage);
          bool test=p.modifier(idpromo);
          if(test)
        {ui->tabpromo->setModel(tmppromo.afficher());//refresh
        QMessageBox::information(nullptr, QObject::tr("Modifier un client"),
                          QObject::tr("Client modifiée.\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);

        }
          else
              QMessageBox::critical(nullptr, QObject::tr("Modifier client"),
                          QObject::tr("Erreur !.\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);





}

void mainwindowR::on_pushButton_clicked()
{
    int idpromo = ui->lineEditCIN_2->text().toInt();
    bool test=tmppromo.supprimer(idpromo);
    if(test)
    {ui->tabpromo->setModel(tmppromo.afficher());//refresh
        QMessageBox::information(nullptr, QObject::tr("Supprimer une Chambre"),
                    QObject::tr("Chambre supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer une Chambre"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);


}

void mainwindowR::on_pdf_clicked()
{
    /*  QPrinter printer;
              QString doc;
              printer.setPrinterName("printer1");
              QPrintDialog print_dialog(&printer,this);
             if(print_dialog.exec()== QDialog::Rejected) return ;
               ui->text_id-> */
        QString strStream;
        QTextStream out(&strStream);
        const int rowCount = ui->tabclient->model()->rowCount();
        const int columnCount = ui->tabclient->model()->columnCount();
        out <<  "<html>\n"
                "<head>\n"
                "<meta Content=\"Text/html; charset=Windows-1251\">\n"
             <<  QString("<title>%1</title>\n").arg("col1")
              <<  "</head>\n"
                  "  <h1>Gestion des clients PDF</h1>"
                  "<body bgcolor=#ac9976  link=#5000A0>\n"
                  "<table border=1 cellspacing=0 cellpadding=2 >\n";
        // headers
        out << "<thead><tr bgcolor=#aa0000>";
        for (int column = 0; column < columnCount; column++)
            if (!ui->tabclient->isColumnHidden(column))
                out << QString("<th>%1</th>").arg(ui->tabclient->model()->headerData(column, Qt::Horizontal).toString());
        out << "</tr></thead>\n";
        // data table
        for (int row = 0; row < rowCount; row++) {
            out << "<tr>";
            for (int column = 0; column < columnCount; column++) {
                if (!ui->tabclient->isColumnHidden(column)) {
                    QString data = ui->tabclient->model()->data(ui->tabclient->model()->index(row, column)).toString().simplified();
                    out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                }
            }
            out << "</tr>\n";
        }
        out <<  "</table>\n"
                "</body>\n"
                "</html>\n";
        QTextDocument *document = new QTextDocument();
        document->setHtml(strStream);
        QPrinter printer;
        QPrintDialog *dialog = new QPrintDialog(&printer, NULL);
        if (dialog->exec() == QDialog::Accepted) {
            document->print(&printer);
        }
        delete document;
}

void mainwindowR::on_recherchepromo_clicked()
{
    QString str=ui->lineEditCIN_2->text();
       ui->tabpromo->setModel(tmppromo.recherche(str));
}

void mainwindowR::on_photo_clicked()
{
    QString imageFile = QFileDialog ::getOpenFileName(0,"Select Image","/home/","Image Files (*.jpg)");
           QFileInfo info(imageFile);
           QPixmap image (imageFile);
           ui->label_9->setPixmap(image);
           ui->label_9->show();
           ui->photo->setText(imageFile);
           ui->label_9->setPixmap(image);
}



void mainwindowR::on_pb_tri_clicked()
{
    ui->tabclient->setModel(tmpclient.triclient());
}

void mainwindowR::on_pushButton_3_clicked()
{
    dash *x = new dash;

    x->show();
    this->hide();
}
