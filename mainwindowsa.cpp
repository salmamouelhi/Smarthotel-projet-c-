#include "mainwindowsa.h"
#include "ui_mainwindowsa.h"
#include "categorie.h"
#include "fournisseur.h"
#include "produit.h"
#include <QMessageBox>
#include <QPrinter>
#include <QPrintDialog>
#include <QTextDocument>
#include <QTextStream>
#include <QVariant>
#include <QFileDialog>
#include <QTextBrowser>
#include <QPixmap>
#include <QLabel>
#include <QDesktopServices>
#include "statistiquessalma.h"
#include "dash.h"

mainwindowsa::mainwindowsa(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::mainwindowsa)
{
    ui->setupUi(this);
    ui->tabcat->setModel(tmpcat.affichercat());
    ui->tabprod->setModel(tmpprod.afficherprod());
    ui->tabfour->setModel(tmpfour.afficherfour());


    QSqlQueryModel *model2 = new QSqlQueryModel();
        model2->setQuery("select nom from fournisseur");
    ui->comboBox_2->setModel(model2);

    QSqlQueryModel *model = new QSqlQueryModel();
      model->setQuery("select nom_categorie from categorie");
    ui->comboBox->setModel(model);



    QSqlQuery query,query1,query2;

    int i =0;
      // set dark background gradient:
      QLinearGradient gradient(0, 0, 0, 400);
      gradient.setColorAt(0, QColor(255,255,255));
      gradient.setColorAt(0.38, QColor(255,255,255));
      gradient.setColorAt(1, QColor(255,255,255));
      ui->widget->setBackground(QBrush(gradient));
    QCPBars *fossil = new QCPBars(ui->widget->xAxis, ui->widget->yAxis);
     QCPBars *nuclear = new QCPBars(ui->widget->xAxis, ui->widget->yAxis);

    fossil->setPen(QPen(QColor(0, 0, 255).lighter(190)));
    fossil->setBrush(QColor(255, 0, 0));

    nuclear->setPen(QPen(QColor(250, 170, 20).lighter(150)));
    nuclear->setBrush(QColor(250, 170, 20));
    nuclear->moveAbove(fossil);

      // prepare x axis with country labels:
      QVector<double> ticks,ticks2;
      QVector<QString> labels;
        QVector<double> fossilData,nuclearData;
      query.prepare("SELECT DISTINCT id_produit FROM produit");
      query.exec();


      while(query.next())
      {
       labels.append(query.value(0).toString());
       i++;
       ticks.append(i);

       query1.prepare("SELECT quantite FROM produit where id_produit = '"+query.value(0).toString()+"' ");
       query1.exec();
       while (query1.next()) {
         fossilData.append(query1.value(0).toDouble());
       }
       query2.prepare("SELECT prix_achat FROM produit where id_produit = '"+query.value(0).toString()+"' ");
       query2.exec();
       while (query2.next()) {
         nuclearData.append(query2.value(0).toDouble());
    }

      }



      //ticks << 1 << 2 << 3 ;
    //  labels << "5000" << "10000" << "15000" ;
      QSharedPointer<QCPAxisTickerText> textTicker(new QCPAxisTickerText);
      textTicker->addTicks(ticks, labels);
      ui->widget->xAxis->setTicker(textTicker);
      ui->widget->xAxis->setTickLabelRotation(60);
      ui->widget->xAxis->setSubTicks(false);
      ui->widget->xAxis->setTickLength(0, 4);
      ui->widget->xAxis->setRange(0, 8);
      ui->widget->xAxis->setBasePen(QPen(Qt::black));
      ui->widget->xAxis->setTickPen(QPen(Qt::black));
      ui->widget->xAxis->grid()->setVisible(true);
      ui->widget->xAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));
      ui->widget->xAxis->setTickLabelColor(Qt::black);
      ui->widget->xAxis->setLabelColor(Qt::black);

      // prepare y axis:
      ui->widget->yAxis->setRange(0, 500);
      ui->widget->yAxis->setPadding(5); // a bit more space to the left border
      ui->widget->yAxis->setLabel("statistique ");
      ui->widget->yAxis->setBasePen(QPen(Qt::black));
      ui->widget->yAxis->setTickPen(QPen(Qt::black));
      ui->widget->yAxis->setSubTickPen(QPen(Qt::black));
      ui->widget->yAxis->grid()->setSubGridVisible(true);
      ui->widget->yAxis->setTickLabelColor(Qt::black);
      ui->widget->yAxis->setLabelColor(Qt::black);
      ui->widget->yAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::SolidLine));
      ui->widget->yAxis->grid()->setSubGridPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));

      // Add data:



     fossil->setData(ticks, fossilData);

     nuclear->setData(ticks, nuclearData);


      // setup legend:

}

mainwindowsa::~mainwindowsa()
{
    delete ui;
}


void mainwindowsa::on_pb_ajouter_clicked()
{
    int id_categorie = ui->lineEdit_id->text().toInt();
    QString nom_categorie= ui->lineEdit_titre->text();

 categorie c (id_categorie,nom_categorie);
 if (ui->lineEdit_id->text().isEmpty())
                              {

 ui->label_18->setText("<font color='red'>champ vide</font>");
                                 ui->lineEdit_id->setObjectName("myObject");
                                  ui->lineEdit_id->setStyleSheet("#myObject {border: 2px solid #ff0000;"
                                                                   "font: 8pt 'MS Shell Dlg 2';"
                                                                   "border-radius: 11px;"
                                                                   "padding: 5px }");
                              }
  else
  {
       ui->label_18->setText("");
     ui->lineEdit_id->setObjectName("myObject");
      ui->lineEdit_id->setStyleSheet("#myObject {border: 2px solid #aa0000;"
                                        "font: 8pt 'MS Shell Dlg 2';"
                                        "border-radius: 11px;"
                                        "padding: 5px }");
      if(ui->lineEdit_titre->text().isEmpty())
                                   {

      ui->label_19->setText("<font color='red'>champ vide</font>");
                                      ui->lineEdit_titre->setObjectName("myObject");
                                       ui->lineEdit_titre->setStyleSheet("#myObject {border: 2px solid #ff0000;"
                                                                        "font: 8pt 'MS Shell Dlg 2';"
                                                                        "border-radius: 11px;"
                                                                        "padding: 5px }");
                                   }
       else
       {
            ui->label_19->setText("");
          ui->lineEdit_titre->setObjectName("myObject");
           ui->lineEdit_titre->setStyleSheet("#myObject {border: 2px solid #aa0000;"
                                             "font: 8pt 'MS Shell Dlg 2';"
                                             "border-radius: 11px;"
                                             "padding: 5px }");
  bool test=c.ajoutercat();
  if(test)
{ui->tabcat->setModel(tmpcat.affichercat());//refresh
QMessageBox::information(nullptr, QObject::tr("Ajouter une categorie"),
                  QObject::tr("Categorie ajoutée.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter une categorie"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);


}
 }
}

void mainwindowsa::on_pb_supprimer_clicked()
{
int id_categorie = ui->lineEdit_id->text().toInt();
bool test=tmpcat.supprimercat(id_categorie);
if(test)
{ui->tabcat->setModel(tmpcat.affichercat());//refresh
    QMessageBox::information(nullptr, QObject::tr("Supprimer une categorie"),
                QObject::tr("catégorie supprimé.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);

}
else
    QMessageBox::critical(nullptr, QObject::tr("Supprimer une categorie"),
                QObject::tr("Erreur !.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);


}

void mainwindowsa::on_pb_ajouter_3_clicked()
{




    int id_four = ui->lineEdit_id_3->text().toInt();
    int tel = ui->lineEdit_id_8->text().toInt();
    QString nom= ui->lineEdit_id_4->text();
    QString prenom= ui->lineEdit_id_6->text();
    QString adresse= ui->lineEdit_id_7->text();
    QString mail= ui->lineEdit_id_9->text();
    QString facture= ui->lineEdit_id_10->text();

 fournisseur f (id_four,nom,prenom,adresse,tel,mail,facture);
 if(ui->lineEdit_id_3->text().isEmpty())
                             {

ui->label_24->setText("<font color='red'>champ vide</font>");
                                ui->lineEdit_id_3->setObjectName("myObject");
                                 ui->lineEdit_id_3->setStyleSheet("#myObject {border: 2px solid #ff0000;"
                                                                  "font: 8pt 'MS Shell Dlg 2';"
                                                                  "border-radius: 11px;"
                                                                  "padding: 5px }");
                             }
 else
 {
      ui->label_24->setText("");
    ui->lineEdit_id_3->setObjectName("myObject");
     ui->lineEdit_id_3->setStyleSheet("#myObject {border: 2px solid #aa0000;"
                                       "font: 8pt 'MS Shell Dlg 2';"
                                       "border-radius: 11px;"
                                       "padding: 5px }");
 if(ui->lineEdit_id_4->text().isEmpty())
                             {

ui->label_25->setText("<font color='red'>champ vide</font>");
                                ui->lineEdit_id_4->setObjectName("myObject");
                                 ui->lineEdit_id_4->setStyleSheet("#myObject {border: 2px solid #ff0000;"
                                                                  "font: 8pt 'MS Shell Dlg 2';"
                                                                  "border-radius: 11px;"
                                                                  "padding: 5px }");
                             }
 else
 {
      ui->label_25->setText("");
    ui->lineEdit_id_4->setObjectName("myObject");
     ui->lineEdit_id_4->setStyleSheet("#myObject {border: 2px solid #aa0000;"
                                       "font: 8pt 'MS Shell Dlg 2';"
                                       "border-radius: 11px;"
                                       "padding: 5px }");
 if(ui->lineEdit_id_6->text().isEmpty())
                             {

ui->label_26->setText("<font color='red'>champ vide</font>");
                                ui->lineEdit_id_6->setObjectName("myObject");
                                 ui->lineEdit_id_6->setStyleSheet("#myObject {border: 2px solid #ff0000;"
                                                                  "font: 8pt 'MS Shell Dlg 2';"
                                                                  "border-radius: 11px;"
                                                                  "padding: 5px }");
                             }
 else
 {
      ui->label_26->setText("");
    ui->lineEdit_id_6->setObjectName("myObject");
     ui->lineEdit_id_6->setStyleSheet("#myObject {border: 2px solid #aa0000;"
                                       "font: 8pt 'MS Shell Dlg 2';"
                                       "border-radius: 11px;"
                                       "padding: 5px }");
 if(ui->lineEdit_id_7->text().isEmpty())
                             {

ui->label_27->setText("<font color='red'>champ vide</font>");
                                ui->lineEdit_id_7->setObjectName("myObject");
                                 ui->lineEdit_id_7->setStyleSheet("#myObject {border: 2px solid #ff0000;"
                                                                  "font: 8pt 'MS Shell Dlg 2';"
                                                                  "border-radius: 11px;"
                                                                  "padding: 5px }");
                             }
 else
 {
      ui->label_27->setText("");
    ui->lineEdit_id_7->setObjectName("myObject");
     ui->lineEdit_id_7->setStyleSheet("#myObject {border: 2px solid #aa0000;"
                                       "font: 8pt 'MS Shell Dlg 2';"
                                       "border-radius: 11px;"
                                       "padding: 5px }");
 if(ui->lineEdit_id_8->text().isEmpty())
                             {

ui->label_28->setText("<font color='red'>champ vide</font>");
                                ui->lineEdit_id_8->setObjectName("myObject");
                                 ui->lineEdit_id_8->setStyleSheet("#myObject {border: 2px solid #ff0000;"
                                                                  "font: 8pt 'MS Shell Dlg 2';"
                                                                  "border-radius: 11px;"
                                                                  "padding: 5px }");
                             }
 else
 {
      ui->label_28->setText("");
    ui->lineEdit_id_8->setObjectName("myObject");
     ui->lineEdit_id_8->setStyleSheet("#myObject {border: 2px solid #aa0000;"
                                       "font: 8pt 'MS Shell Dlg 2';"
                                       "border-radius: 11px;"
                                       "padding: 5px }");
 if(ui->lineEdit_id_9->text().isEmpty())
                             {

ui->label_29->setText("<font color='red'>champ vide</font>");
                                ui->lineEdit_id_9->setObjectName("myObject");
                                 ui->lineEdit_id_9->setStyleSheet("#myObject {border: 2px solid #ff0000;"
                                                                  "font: 8pt 'MS Shell Dlg 2';"
                                                                  "border-radius: 11px;"
                                                                  "padding: 5px }");
                             }
 else
 {
      ui->label_29->setText("");
    ui->lineEdit_id_9->setObjectName("myObject");
     ui->lineEdit_id_9->setStyleSheet("#myObject {border: 2px solid #aa0000;"
                                       "font: 8pt 'MS Shell Dlg 2';"
                                       "border-radius: 11px;"
                                       "padding: 5px }");

  if(ui->lineEdit_id_10->text().isEmpty())
                              {

 ui->label_30->setText("<font color='red'>champ vide</font>");
                                 ui->lineEdit_id_10->setObjectName("myObject");
                                  ui->lineEdit_id_10->setStyleSheet("#myObject {border: 2px solid #ff0000;"
                                                                   "font: 8pt 'MS Shell Dlg 2';"
                                                                   "border-radius: 11px;"
                                                                   "padding: 5px }");
                              }
  else
  {
       ui->label_30->setText("");
     ui->lineEdit_id_10->setObjectName("myObject");
      ui->lineEdit_id_10->setStyleSheet("#myObject {border: 2px solid #aa0000;"
                                        "font: 8pt 'MS Shell Dlg 2';"
                                        "border-radius: 11px;"
                                        "padding: 5px }");

  bool test=f.ajouterfour();
  if(test)
{ui->tabfour->setModel(tmpfour.afficherfour());//refresh
QMessageBox::information(nullptr, QObject::tr("Ajouter un fournisseur"),
                  QObject::tr("fournisseur ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
  {QMessageBox::critical(nullptr, QObject::tr("Ajouter un fournisseur"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
}
}
 }
 }
 }
 }
 }
}

void mainwindowsa::on_pb_supprimer_3_clicked()
{
    int id_four = ui->lineEdit_id_3->text().toInt();

    bool test=tmpfour.supprimerfour(id_four);
    if(test)
    {ui->tabfour->setModel(tmpfour.afficherfour());//refresh
        QMessageBox::information(nullptr, QObject::tr("Supprimer un forunisseur"),
                    QObject::tr("fournisseur supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer un frounisseur"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}

void mainwindowsa::on_pb_modifier_clicked()
{
    int id_categorie = ui->lineEdit_id->text().toInt();
    QString nom_categorie= ui->lineEdit_titre->text();


  categorie c (id_categorie,nom_categorie);
  bool test=c.modifiercat(id_categorie);
  if(test)
{ui->tabcat->setModel(tmpcat.affichercat());//refresh
QMessageBox::information(nullptr, QObject::tr("Modifier une categorie"),
                  QObject::tr("categorie modifié.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Modifier categorie"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);


}


void mainwindowsa::on_pb_modifier_3_clicked()
{

    int id_four = ui->lineEdit_id_3->text().toInt();
    int tel = ui->lineEdit_id_8->text().toInt();
    QString nom= ui->lineEdit_id_4->text();
    QString prenom= ui->lineEdit_id_6->text();
    QString adresse= ui->lineEdit_id_7->text();
    QString mail= ui->lineEdit_id_9->text();
    QString facture= ui->lineEdit_id_10->text();

 fournisseur f (id_four,nom,prenom,adresse,tel,mail,facture);
  bool test=f.modifierfour(id_four);
  if(test)
{ui->tabfour->setModel(tmpfour.afficherfour());//refresh
QMessageBox::information(nullptr, QObject::tr("Modifier un fournisseur"),
                  QObject::tr("fournisseur modifiée.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Modifier fournisseur"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);


}

void mainwindowsa::on_pb_rechercher_clicked()
{

    QString str=ui->lineEdit_id->text();
    ui->tabcat->setModel(tmpcat.recherchecat(str));
}

void mainwindowsa::on_pb_rechercher_3_clicked()
{

    QString str=ui->lineEdit_id_3->text();
    ui->tabfour->setModel(tmpfour.recherchefour(str));
}



void mainwindowsa::on_tabcat_activated(const QModelIndex &index)
{
    QString val=ui->tabcat->model()->data(index).toString();
    QSqlQuery qry;
    qry.prepare("select * from categorie where ID_CATEGORIE='"+val+"' or NOM_CATEGORIE='"+val+"'");

     if (qry.exec())
        {

        while (qry.next())
        {

                  ui->lineEdit_id->setText(qry.value(0).toString());
                  ui->lineEdit_titre->setText(qry.value(1).toString());

        }
    }
    else
    {
       // QMessageBox::critical(this,tr("error"),qry.lastError().text());
    }
      }



void mainwindowsa::on_tabfour_activated(const QModelIndex &index)
{
    QString val=ui->tabfour->model()->data(index).toString();
       QSqlQuery qry;
       qry.prepare("select * from fournisseur where ID_FOUR='"+val+"' or NOM='"+val+"' or PRENOM='"+val+"'  or ADRESSE='"+val+"' or TEL='"+val+"' or MAIL='"+val+"' or FACTURE='"+val+"'");

        if (qry.exec())
           {

           while (qry.next())
           {

                     ui->lineEdit_id_3->setText(qry.value(0).toString());
                     ui->lineEdit_id_4->setText(qry.value(1).toString());
                     ui->lineEdit_id_6->setText(qry.value(3).toString());
                     ui->lineEdit_id_7->setText(qry.value(2).toString());

                     ui->lineEdit_id_8->setText(qry.value(4).toString());
                             ui->lineEdit_id_9->setText(qry.value(5).toString());
                                     ui->lineEdit_id_10->setText(qry.value(6).toString());








           }
       }
       else
       {
          // QMessageBox::critical(this,tr("error"),qry.lastError().text());
       }
         }














void mainwindowsa::on_Trier_cat_clicked()
{

    bool test=true;
    if(test)
{
        ui->tabcat->setModel(tmpcat.affichertri());
       QMessageBox::information(nullptr, QObject::tr("Trier categorie"),
        QObject::tr("categorie tries.\n"
        "Voulez-vous enregistrer les modifications ?"),
        QMessageBox::Save
        |QMessageBox::Cancel,
        QMessageBox::Save);
    }
    else
    QMessageBox::critical(nullptr, QObject::tr("trier categorie"),
    QObject::tr("Erreur !.\n"
    "Click Cancel to exit."), QMessageBox::Cancel);
}


void mainwindowsa::on_PDFcat_clicked()
{
    /*  QPrinter printer;
      QString doc;

      printer.setPrinterName("printer1");
      QPrintDialog print_dialog(&printer,this);
     if(print_dialog.exec()== QDialog::Rejected) return ;

       ui->text_id-> */


      QString strStream;
      QTextStream out(&strStream);

      const int rowCount = ui->tabcat->model()->rowCount();
      const int columnCount = ui->tabcat->model()->columnCount();

      out <<  "<html>\n"
          "<head>\n"
          "<meta Content=\"Text/html; charset=Windows-1251\">\n"
          <<  QString("<title>%1</title>\n").arg("col1")
          <<  "</head>\n"
          "<body bgcolor=#FF0000 link=#5000A0>\n"
              "<h1> salma </h1>"
          "<table border=1 cellspacing=0 cellpadding=2>\n";

      // headers
      out << "<thead><tr bgcolor=#ff0000>";
      for (int column = 0; column < columnCount; column++)
          if (!ui->tabcat->isColumnHidden(column))
              out << QString("<th>%1</th>").arg(ui->tabcat->model()->headerData(column, Qt::Horizontal).toString());
      out << "</tr></thead>\n";

      // data table
      for (int row = 0; row < rowCount; row++) {
          out << "<tr>";
          for (int column = 0; column < columnCount; column++) {
              if (!ui->tabcat->isColumnHidden(column)) {
                  QString data = ui->tabcat->model()->data(ui->tabcat->model()->index(row, column)).toString().simplified();
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


}

void mainwindowsa::on_pb_ajouter_2_clicked()
{
    int id_produit = ui->lineEdit_id_2->text().toInt();
    QString quantite=ui->lineEdit_q->text();
    QString etat=ui->comboBox_3->currentText();
    QString nom=ui->lineEdit_id_5->text();
    QString prix_achat=ui->lineEdit_p->text();

    QString id_categorie=ui->comboBox->currentText();

    QSqlQueryModel *model = new QSqlQueryModel();
        model->setQuery("select nom_categorie from categorie");
    ui->comboBox->setModel(model);


    QString id_four=ui->comboBox_2->currentText();



    QSqlQueryModel *model2 = new QSqlQueryModel();
        model2->setQuery("select nom from fournisseur");
  ui->comboBox_2->setModel(model2);




 produit p (id_produit,quantite,etat,nom,prix_achat,id_categorie,id_four);
 if(ui->lineEdit_id_2->text().isEmpty())
                             {

ui->label_20->setText("<font color='red'>champ vide</font>");
                                ui->lineEdit_id_2->setObjectName("myObject");
                                 ui->lineEdit_id_2->setStyleSheet("#myObject {border: 2px solid #ff0000;"
                                                                  "font: 8pt 'MS Shell Dlg 2';"
                                                                  "border-radius: 11px;"
                                                                  "padding: 5px }");
                             }
 else
 {
      ui->label_20->setText("");
    ui->lineEdit_id_2->setObjectName("myObject");
     ui->lineEdit_id_2->setStyleSheet("#myObject {border: 2px solid #aa0000;"
                                       "font: 8pt 'MS Shell Dlg 2';"
                                       "border-radius: 11px;"
                                       "padding: 5px }");

 if(ui->lineEdit_q->text().isEmpty())
                             {
                               ui->label_21->setText("<font color='red'>champ vide</font>");

                                ui->lineEdit_q->setObjectName("myObject");
                                 ui->lineEdit_q->setStyleSheet("#myObject {border: 2px solid #ff0000;"
                                                                  "font: 8pt 'MS Shell Dlg 2';"
                                                                  "border-radius: 11px;"
                                                                  "padding: 5px }");
                             }
 else
 {
     ui->label_21->setText("");
    ui->lineEdit_q->setObjectName("myObject");
     ui->lineEdit_q->setStyleSheet("#myObject {border: 2px solid #aa0000;"
                                       "font: 8pt 'MS Shell Dlg 2';"
                                       "border-radius: 11px;"
                                       "padding: 5px }");

 if(ui->lineEdit_id_5->text().isEmpty())
                             {
                                ui->label_23->setText("<font color='red'>champ vide</font>");

                                ui->lineEdit_id_5->setObjectName("myObject");
                                 ui->lineEdit_id_5->setStyleSheet("#myObject {border: 2px solid #ff0000;"
                                                                  "font: 8pt 'MS Shell Dlg 2';"
                                                                  "border-radius: 11px;"
                                                                  "padding: 5px }");
                             }
 else
 {
     ui->label_23->setText("");
    ui->lineEdit_id_5->setObjectName("myObject");
     ui->lineEdit_id_5->setStyleSheet("#myObject {border: 2px solid #aa0000;"
                                       "font: 8pt 'MS Shell Dlg 2';"
                                       "border-radius: 11px;"
                                       "padding: 5px }");


 if(ui->lineEdit_p->text().isEmpty())
                             {
                                 ui->label_22->setText("<font color='red'>champ vide</font>");

                                ui->lineEdit_p->setObjectName("myObject");
                                 ui->lineEdit_p->setStyleSheet("#myObject {border: 2px solid #ff0000;"
                                                                  "font: 8pt 'MS Shell Dlg 2';"
                                                                  "border-radius: 11px;"
                                                                  "padding: 5px }");
                             }
 else
 {
     ui->label_22->setText("");
     ui->lineEdit_p->setObjectName("myObject");
      ui->lineEdit_p->setStyleSheet("#myObject {border: 2px solid #aa0000;"
                                       "font: 8pt 'MS Shell Dlg 2';"
                                       "border-radius: 11px;"
                                       "padding: 5px }");

     bool test=p.ajouterprod();
  if(test)
{ui->tabprod->setModel(tmpprod.afficherprod());//refresh
QMessageBox::information(nullptr, QObject::tr("Ajouter un produit"),
                  QObject::tr("Produit ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
  {
      QMessageBox::critical(nullptr, QObject::tr("Ajouter un produit"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

  }

}
}
}
}



}
void mainwindowsa::on_pb_supprimer_2_clicked()
{
    int id_produit = ui->lineEdit_id_2->text().toInt();

    bool test=tmpprod.supprimerprod(id_produit);
    if(test)
    {ui->tabprod->setModel(tmpprod.afficherprod());//refresh
        QMessageBox::information(nullptr, QObject::tr("Supprimer un produit"),
                    QObject::tr("Produit supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer un produit"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}


void mainwindowsa::on_pb_modifier_2_clicked()
{
    int id_produit = ui->lineEdit_id_2->text().toInt();
    QString quantite=ui->lineEdit_q->text();
    QString etat=ui->comboBox_3->currentText();
    QString nom=ui->lineEdit_id_5->text();
    QString prix_achat=ui->lineEdit_p->text();

    QString id_categorie=ui->comboBox->currentText();

    QSqlQueryModel *model = new QSqlQueryModel();
        model->setQuery("select nom_categorie from categorie");
    ui->comboBox->setModel(model);


    QString id_four=ui->comboBox_2->currentText();



    QSqlQueryModel *model2 = new QSqlQueryModel();
        model2->setQuery("select nom from fournisseur");
  ui->comboBox_2->setModel(model2);




 produit p (id_produit,quantite,etat,nom,prix_achat,id_categorie,id_four);
 bool test=p.modifierprod(id_produit);
 if(test)
{ui->tabprod->setModel(tmpprod.afficherprod());//refresh
QMessageBox::information(nullptr, QObject::tr("Modifier un produit"),
                 QObject::tr("Produit modifié.\n"
                             "Click Cancel to exit."), QMessageBox::Cancel);

}
 else
     QMessageBox::critical(nullptr, QObject::tr("Modifier produit"),
                 QObject::tr("Erreur !.\n"
                             "Click Cancel to exit."), QMessageBox::Cancel);


}



void mainwindowsa::on_pb_rechercher_2_clicked()
{
    QString str=ui->lineEdit_id_2->text();
    ui->tabprod->setModel(tmpprod.rechercheprod(str));
}






void mainwindowsa::on_tabprod_activated(const QModelIndex &index)
{
    QString val=ui->tabprod->model()->data(index).toString();
       QSqlQuery qry;
       qry.prepare("select * from produit where ID_PRODUIT='"+val+"' or QUANTITE='"+val+"' or ETAT='"+val+"'  or NOM='"+val+"' or PRIX_ACHAT='"+val+"' or ID_CATEGORIE='"+val+"' or ID_FOUR='"+val+"'");

        if (qry.exec())
           {

           while (qry.next())
           {

                     ui->lineEdit_id_2->setText(qry.value(0).toString());
                     ui->lineEdit_q->setText(qry.value(1).toString());
                     ui->comboBox_3->setCurrentText(qry.value(2).toString());
                     ui->lineEdit_id_5->setText(qry.value(3).toString());
                     ui->lineEdit_p->setText(qry.value(4).toString());
                     ui->comboBox->setCurrentText(qry.value(5).toString());
                     ui->comboBox_2->setCurrentText(qry.value(6).toString());






           }
       }
       else
       {
          // QMessageBox::critical(this,tr("error"),qry.lastError().text());
       }
         }


void mainwindowsa::on_loadprod_clicked()
{
    QSqlQueryModel * modal=new QSqlQueryModel();
    QSqlQuery query;
    query.prepare("select * from produit");
  query.exec();
 modal->setQuery(query);
    ui->tabprod->setModel(modal);



}



void mainwindowsa::on_loadcat_clicked()
{
    QSqlQueryModel * modal=new QSqlQueryModel();
    QSqlQuery query;
    query.prepare("select * from categorie");
    query.exec();
    modal->setQuery(query);
    ui->tabcat->setModel(modal);



}


void mainwindowsa::on_loadfour_clicked()
{
    QSqlQueryModel * modal=new QSqlQueryModel();
    QSqlQuery query;
    query.prepare("select * from fournisseur");
    query.exec();
    modal->setQuery(query);
    ui->tabfour->setModel(modal);



}

void mainwindowsa::on_PDFfour_clicked()
{
    /*  QPrinter printer;
      QString doc;

      printer.setPrinterName("printer1");
      QPrintDialog print_dialog(&printer,this);
     if(print_dialog.exec()== QDialog::Rejected) return ;

       ui->text_id-> */


      QString strStream;
      QTextStream out(&strStream);

      const int rowCount = ui->tabfour->model()->rowCount();
      const int columnCount = ui->tabfour->model()->columnCount();

      out <<  "<html>\n"
          "<head>\n"
          "<meta Content=\"Text/html; charset=Windows-1251\">\n"
          <<  QString("<title>%1</title>\n").arg("col1")
          <<  "</head>\n"
          "<body bgcolor=#ffffff link=#5000A0>\n"
          "<table border=1 cellspacing=0 cellpadding=2>\n";

      // headers
      out << "<thead><tr bgcolor=#f0f0f0>";
      for (int column = 0; column < columnCount; column++)
          if (!ui->tabfour->isColumnHidden(column))
              out << QString("<th>%1</th>").arg(ui->tabfour->model()->headerData(column, Qt::Horizontal).toString());
      out << "</tr></thead>\n";

      // data table
      for (int row = 0; row < rowCount; row++) {
          out << "<tr>";
          for (int column = 0; column < columnCount; column++) {
              if (!ui->tabfour->isColumnHidden(column)) {
                  QString data = ui->tabfour->model()->data(ui->tabfour->model()->index(row, column)).toString().simplified();
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


}


void mainwindowsa::on_PDFprod_clicked()
{
    /*  QPrinter printer;
      QString doc;

      printer.setPrinterName("printer1");
      QPrintDialog print_dialog(&printer,this);
     if(print_dialog.exec()== QDialog::Rejected) return ;

       ui->text_id-> */


      QString strStream;
      QTextStream out(&strStream);

      const int rowCount = ui->tabprod->model()->rowCount();
      const int columnCount = ui->tabprod->model()->columnCount();

      out <<  "<html>\n"
          "<head>\n"
          "<meta Content=\"Text/html; charset=Windows-1251\">\n"
          <<  QString("<title>%1</title>\n").arg("col1")
          <<  "</head>\n"
          "<body bgcolor=#ffffff link=#5000A0>\n"
          "<table border=1 cellspacing=0 cellpadding=2>\n";

      // headers
      out << "<thead><tr bgcolor=#f0f0f0>";
      for (int column = 0; column < columnCount; column++)
          if (!ui->tabprod->isColumnHidden(column))
              out << QString("<th>%1</th>").arg(ui->tabprod->model()->headerData(column, Qt::Horizontal).toString());
      out << "</tr></thead>\n";

      // data table
      for (int row = 0; row < rowCount; row++) {
          out << "<tr>";
          for (int column = 0; column < columnCount; column++) {
              if (!ui->tabprod->isColumnHidden(column)) {
                  QString data = ui->tabprod->model()->data(ui->tabprod->model()->index(row, column)).toString().simplified();
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


}

void mainwindowsa::on_btnChse_clicked()
{
QString imageFile = QFileDialog ::getOpenFileName(0,"Select Image","/home/","Image Files (*.jpg)");

  QFileInfo info(imageFile);
    //QString salma = info.fileName();
  QPixmap image (imageFile);
  ui->lblBkImge->setPixmap(image);
  ui->lblBkImge->show();
  ui->lineEdit_id_10->setText(imageFile);

}

void mainwindowsa::on_pushButton_4_clicked()
{
    QString filename=QFileDialog::getOpenFileName(
                this,
                tr("Open File"),
                "C://",
                "All files (.);;Text File (.txt);;Pdf File (.pdf);;Music file(*.mp3)"


                );
    QDesktopServices::openUrl(QUrl("file:///"+filename,QUrl::TolerantMode));
   // QMessageBox::information(this,tr("File Name"),filename);
}







void mainwindowsa::on_comboBox_4_currentIndexChanged(int index)
{
    if (index==0)
        {
              ui->tabfour->setModel(tmpfour.afficherfour());
        }
        else
        {
              ui->tabfour->setModel(tmpfour.triprod1(index));
        }
}

void mainwindowsa::on_comboBox_5_currentIndexChanged(int index)
{
    if (index==0)
        {
              ui->tabprod->setModel(tmpprod.afficherprod());
        }
        else
        {
              ui->tabprod->setModel(tmpprod.triprod2(index));
        }
}

void mainwindowsa::on_pushButton_clicked()
{
    statistiquessalma s;
          s.show();
           s.exec();
}

void mainwindowsa::on_lineEdit_textChanged(const QString &arg1)
{
    if (arg1=="")
    {
     ui->tabprod->setModel(tmpprod.afficherprod());
    }
    else
    {
    ui->tabprod->setModel(tmpprod.rechercheprod(arg1));
    }
}

void mainwindowsa::on_pushButton_2_clicked()
{
    ui->setupUi(this);

    ui->tabprod->setModel(tmpprod.afficherprod());


    QSqlQueryModel *model2 = new QSqlQueryModel();
        model2->setQuery("select nom from fournisseur");
    ui->comboBox_2->setModel(model2);

    QSqlQueryModel *model = new QSqlQueryModel();
      model->setQuery("select nom_categorie from categorie");
    ui->comboBox->setModel(model);

  QSqlQuery query,query1,query2;

  int i =0;
    // set dark background gradient:
    QLinearGradient gradient(0, 0, 0, 400);
    gradient.setColorAt(0, QColor(255,255,255));
    gradient.setColorAt(0.38, QColor(255,255,255));
    gradient.setColorAt(1, QColor(255,255,255));
    ui->widget->setBackground(QBrush(gradient));
  QCPBars *fossil = new QCPBars(ui->widget->xAxis, ui->widget->yAxis);
   QCPBars *nuclear = new QCPBars(ui->widget->xAxis, ui->widget->yAxis);

  fossil->setPen(QPen(QColor(0, 0, 255).lighter(190)));
  fossil->setBrush(QColor(255, 0, 0));

  nuclear->setPen(QPen(QColor(250, 170, 20).lighter(150)));
  nuclear->setBrush(QColor(250, 170, 20));
  nuclear->moveAbove(fossil);

    // prepare x axis with country labels:
    QVector<double> ticks,ticks2;
    QVector<QString> labels;
      QVector<double> fossilData,nuclearData;
    query.prepare("SELECT DISTINCT id_produit FROM produit");
    query.exec();


    while(query.next())
    {
     labels.append(query.value(0).toString());
     i++;
     ticks.append(i);

     query1.prepare("SELECT quantite FROM produit where id_produit = '"+query.value(0).toString()+"' ");
     query1.exec();
     while (query1.next()) {
       fossilData.append(query1.value(0).toDouble());
     }
     query2.prepare("SELECT prix_achat FROM produit where id_produit = '"+query.value(0).toString()+"' ");
     query2.exec();
     while (query2.next()) {
       nuclearData.append(query2.value(0).toDouble());
  }

    }



    //ticks << 1 << 2 << 3 ;
  //  labels << "5000" << "10000" << "15000" ;
    QSharedPointer<QCPAxisTickerText> textTicker(new QCPAxisTickerText);
    textTicker->addTicks(ticks, labels);
    ui->widget->xAxis->setTicker(textTicker);
    ui->widget->xAxis->setTickLabelRotation(60);
    ui->widget->xAxis->setSubTicks(false);
    ui->widget->xAxis->setTickLength(0, 4);
    ui->widget->xAxis->setRange(0, 8);
    ui->widget->xAxis->setBasePen(QPen(Qt::black));
    ui->widget->xAxis->setTickPen(QPen(Qt::black));
    ui->widget->xAxis->grid()->setVisible(true);
    ui->widget->xAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));
    ui->widget->xAxis->setTickLabelColor(Qt::black);
    ui->widget->xAxis->setLabelColor(Qt::black);

    // prepare y axis:
    ui->widget->yAxis->setRange(0, 500);
    ui->widget->yAxis->setPadding(5); // a bit more space to the left border
    ui->widget->yAxis->setLabel("statistiques");
    ui->widget->yAxis->setBasePen(QPen(Qt::black));
    ui->widget->yAxis->setTickPen(QPen(Qt::black));
    ui->widget->yAxis->setSubTickPen(QPen(Qt::black));
    ui->widget->yAxis->grid()->setSubGridVisible(true);
    ui->widget->yAxis->setTickLabelColor(Qt::black);
    ui->widget->yAxis->setLabelColor(Qt::black);
    ui->widget->yAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::SolidLine));
    ui->widget->yAxis->grid()->setSubGridPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));

    // Add data:



   fossil->setData(ticks, fossilData);

   nuclear->setData(ticks, nuclearData);


    // setup legend:


}


void mainwindowsa::on_lineEdit_id_2_textChanged(const QString &arg1)
{
    if (arg1=="")
    {

        ui->label_20->setText("<font color='red'>champ vide</</font>");
       ui->lineEdit_id_2->setObjectName("myObject");
        ui->lineEdit_id_2->setStyleSheet("#myObject {border: 2px solid #ff0000;"
                                         "font: 8pt 'MS Shell Dlg 2';"
                                         "border-radius: 11px;"
                                         "padding: 5px }");
    }
    else
    {
         ui->label_20->setText("");
        ui->lineEdit_id_2->setObjectName("myObject");
         ui->lineEdit_id_2->setStyleSheet("#myObject {border: 2px solid #aa0000;"
                                          "font: 8pt 'MS Shell Dlg 2';"
                                          "border-radius: 11px;"
                                          "padding: 5px }");
}
}

void mainwindowsa::on_lineEdit_q_textChanged(const QString &arg1)
{
    if (arg1=="")
    {

        ui->label_21->setText("<font color='red'>champ vide</</font>");
       ui->lineEdit_q->setObjectName("myObject");
        ui->lineEdit_q->setStyleSheet("#myObject {border: 2px solid #ff0000;"
                                         "font: 8pt 'MS Shell Dlg 2';"
                                         "border-radius: 11px;"
                                         "padding: 5px }");
    }
    else
    {
         ui->label_21->setText("");
        ui->lineEdit_q->setObjectName("myObject");
         ui->lineEdit_q->setStyleSheet("#myObject {border: 2px solid #aa0000;"
                                          "font: 8pt 'MS Shell Dlg 2';"
                                          "border-radius: 11px;"
                                          "padding: 5px }");
}
}

void mainwindowsa::on_lineEdit_p_textChanged(const QString &arg1)
{
    if (arg1=="")
    {

        ui->label_22->setText("<font color='red'>champ vide</</font>");
       ui->lineEdit_p->setObjectName("myObject");
        ui->lineEdit_p->setStyleSheet("#myObject {border: 2px solid #ff0000;"
                                         "font: 8pt 'MS Shell Dlg 2';"
                                         "border-radius: 11px;"
                                         "padding: 5px }");
    }
    else
    {
         ui->label_22->setText("");
        ui->lineEdit_p->setObjectName("myObject");
         ui->lineEdit_p->setStyleSheet("#myObject {border: 2px solid #aa0000;"
                                          "font: 8pt 'MS Shell Dlg 2';"
                                          "border-radius: 11px;"
                                          "padding: 5px }");
}
}


void mainwindowsa::on_lineEdit_id_5_textChanged(const QString &arg1)
{
    if (arg1=="")
    {

        ui->label_23->setText("<font color='red'>champ vide</font>");
       ui->lineEdit_id_5->setObjectName("myObject");
        ui->lineEdit_id_5->setStyleSheet("#myObject {border: 2px solid #ff0000;"
                                         "font: 8pt 'MS Shell Dlg 2';"
                                         "border-radius: 11px;"
                                         "padding: 5px }");
    }
    else
    {
         ui->label_23->setText("");
        ui->lineEdit_id_5->setObjectName("myObject");
         ui->lineEdit_id_5->setStyleSheet("#myObject {border: 2px solid #aa0000;"
                                          "font: 8pt 'MS Shell Dlg 2';"
                                          "border-radius: 11px;"
                                          "padding: 5px }");
}
}

void mainwindowsa::on_lineEdit_id_3_textChanged(const QString &arg1)
{
    if (arg1=="")
    {

        ui->label_24->setText("<font color='red'>champ vide</font>");
       ui->lineEdit_id_3->setObjectName("myObject");
        ui->lineEdit_id_3->setStyleSheet("#myObject {border: 2px solid #ff0000;"
                                         "font: 8pt 'MS Shell Dlg 2';"
                                         "border-radius: 11px;"
                                         "padding: 5px }");
    }
    else
    {
         ui->label_24->setText("");
        ui->lineEdit_id_3->setObjectName("myObject");
         ui->lineEdit_id_3->setStyleSheet("#myObject {border: 2px solid #aa0000;"
                                          "font: 8pt 'MS Shell Dlg 2';"
                                          "border-radius: 11px;"
                                          "padding: 5px }");
}
}

void mainwindowsa::on_lineEdit_id_4_textChanged(const QString &arg1)
{
    if (arg1=="")
    {

        ui->label_25->setText("<font color='red'>champ vide</font>");
       ui->lineEdit_id_4->setObjectName("myObject");
        ui->lineEdit_id_4->setStyleSheet("#myObject {border: 2px solid #ff0000;"
                                         "font: 8pt 'MS Shell Dlg 2';"
                                         "border-radius: 11px;"
                                         "padding: 5px }");
    }
    else
    {
         ui->label_25->setText("");
        ui->lineEdit_id_4->setObjectName("myObject");
         ui->lineEdit_id_4->setStyleSheet("#myObject {border: 2px solid #aa0000;"
                                          "font: 8pt 'MS Shell Dlg 2';"
                                          "border-radius: 11px;"
                                          "padding: 5px }");
}
}

void mainwindowsa::on_lineEdit_id_6_textChanged(const QString &arg1)
{
    if (arg1=="")
    {

        ui->label_26->setText("<font color='red'>champ vide</font>");
       ui->lineEdit_id_6->setObjectName("myObject");
        ui->lineEdit_id_6->setStyleSheet("#myObject {border: 2px solid #ff0000;"
                                         "font: 8pt 'MS Shell Dlg 2';"
                                         "border-radius: 11px;"
                                         "padding: 5px }");
    }
    else
    {
         ui->label_26->setText("");
        ui->lineEdit_id_6->setObjectName("myObject");
         ui->lineEdit_id_6->setStyleSheet("#myObject {border: 2px solid #aa0000;"
                                          "font: 8pt 'MS Shell Dlg 2';"
                                          "border-radius: 11px;"
                                          "padding: 5px }");
}
}

void mainwindowsa::on_lineEdit_id_7_textChanged(const QString &arg1)
{
    if (arg1=="")
    {

        ui->label_27->setText("<font color='red'>champ vide</font>");
       ui->lineEdit_id_7->setObjectName("myObject");
        ui->lineEdit_id_7->setStyleSheet("#myObject {border: 2px solid #ff0000;"
                                         "font: 8pt 'MS Shell Dlg 2';"
                                         "border-radius: 11px;"
                                         "padding: 5px }");
    }
    else
    {
         ui->label_27->setText("");
        ui->lineEdit_id_7->setObjectName("myObject");
         ui->lineEdit_id_7->setStyleSheet("#myObject {border: 2px solid #aa0000;"
                                          "font: 8pt 'MS Shell Dlg 2';"
                                          "border-radius: 11px;"
                                          "padding: 5px }");
}
}

void mainwindowsa::on_lineEdit_id_8_textChanged(const QString &arg1)
{
    if (arg1=="")
    {

        ui->label_28->setText("<font color='red'>champ vide</font>");
       ui->lineEdit_id_8->setObjectName("myObject");
        ui->lineEdit_id_8->setStyleSheet("#myObject {border: 2px solid #ff0000;"
                                         "font: 8pt 'MS Shell Dlg 2';"
                                         "border-radius: 11px;"
                                         "padding: 5px }");
    }
    else
    {
         ui->label_28->setText("");
        ui->lineEdit_id_8->setObjectName("myObject");
         ui->lineEdit_id_8->setStyleSheet("#myObject {border: 2px solid #aa0000;"
                                          "font: 8pt 'MS Shell Dlg 2';"
                                          "border-radius: 11px;"
                                          "padding: 5px }");
}
}

void mainwindowsa::on_lineEdit_id_9_textChanged(const QString &arg1)
{
    if (arg1=="")
    {

        ui->label_29->setText("<font color='red'>champ vide</font>");
       ui->lineEdit_id_9->setObjectName("myObject");
        ui->lineEdit_id_9->setStyleSheet("#myObject {border: 2px solid #ff0000;"
                                         "font: 8pt 'MS Shell Dlg 2';"
                                         "border-radius: 11px;"
                                         "padding: 5px }");
    }
    else
    {
         ui->label_29->setText("");
        ui->lineEdit_id_9->setObjectName("myObject");
         ui->lineEdit_id_9->setStyleSheet("#myObject {border: 2px solid #aa0000;"
                                          "font: 8pt 'MS Shell Dlg 2';"
                                          "border-radius: 11px;"
                                          "padding: 5px }");
}
}

void mainwindowsa::on_lineEdit_id_10_textChanged(const QString &arg1)
{
    if (arg1=="")
    {

        ui->label_30->setText("<font color='red'>champ vide</font>");
       ui->lineEdit_id_10->setObjectName("myObject");
        ui->lineEdit_id_10->setStyleSheet("#myObject {border: 2px solid #ff0000;"
                                         "font: 8pt 'MS Shell Dlg 2';"
                                         "border-radius: 11px;"
                                         "padding: 5px }");
    }
    else
    {
         ui->label_30->setText("");
        ui->lineEdit_id_10->setObjectName("myObject");
         ui->lineEdit_id_10->setStyleSheet("#myObject {border: 2px solid #aa0000;"
                                          "font: 8pt 'MS Shell Dlg 2';"
                                          "border-radius: 11px;"
                                          "padding: 5px }");
}
}

void mainwindowsa::on_lineEdit_id_textChanged(const QString &arg1)
{
    if (arg1=="")
    {

        ui->label_18->setText("<font color='red'>champ vide</font>");
       ui->lineEdit_id->setObjectName("myObject");
        ui->lineEdit_id->setStyleSheet("#myObject {border: 2px solid #ff0000;"
                                         "font: 8pt 'MS Shell Dlg 2';"
                                         "border-radius: 11px;"
                                         "padding: 5px }");
    }
    else
    {
         ui->label_18->setText("");
        ui->lineEdit_id->setObjectName("myObject");
         ui->lineEdit_id->setStyleSheet("#myObject {border: 2px solid #aa0000;"
                                          "font: 8pt 'MS Shell Dlg 2';"
                                          "border-radius: 11px;"
                                          "padding: 5px }");
}
}

void mainwindowsa::on_lineEdit_titre_textChanged(const QString &arg1)
{
    if (arg1=="")
    {

        ui->label_19->setText("<font color='red'>champ vide</font>");
       ui->lineEdit_titre->setObjectName("myObject");
        ui->lineEdit_titre->setStyleSheet("#myObject {border: 2px solid #ff0000;"
                                         "font: 8pt 'MS Shell Dlg 2';"
                                         "border-radius: 11px;"
                                         "padding: 5px }");
    }
    else
    {
         ui->label_19->setText("");
        ui->lineEdit_titre->setObjectName("myObject");
         ui->lineEdit_titre->setStyleSheet("#myObject {border: 2px solid #aa0000;"
                                          "font: 8pt 'MS Shell Dlg 2';"
                                          "border-radius: 11px;"
                                          "padding: 5px }");
}
}

void mainwindowsa::on_pushButton_3_clicked()
{
    dash *x = new dash;

    x->show();
    this->hide();
}
