#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "login.h"
#include "ui_login.h"
#include "dash.h"
#include "ui_dash.h"
#include "statistiques.h"
//#include "ui_statistiques.h"
#include "chambre.h"
#include "dash.h"
#include <QMessageBox>
#include <QPrinter>
#include <QPrintDialog>
#include <QTextDocument>
#include <QTextStream>
#include <QTextBrowser>
#include <QPixmap>
#include <QTimer>
#include <QDateTime>
#include <QVariant>
#include <QLabel>
#include <QFileDialog>
#include <QDesktopServices>
#include<QUrl>
#include <QSqlQueryModel>
#include "qsound.h"
#include <QPixmap>
#include <QLabel>
#include "statistiques.h"
#include "webcam.h"
#include "settings.h"
#include "ui_settings.h"
#include "mainwindoweuro.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tabchambre->setModel(tmpchambre.afficher());
    QTimer *timer=new QTimer(this);
    connect(timer ,SIGNAL(timeout()),this,SLOT(showTime()));
    timer->start();



    QSqlQueryModel * modal2=new QSqlQueryModel();
    QSqlQuery query;
    query.prepare("select * from chambre");
    query.exec();
    modal2->setQuery(query);
    ui->tabchambre->setModel(modal2);

    QSqlQueryModel * modal=new QSqlQueryModel();
    //QSqlQuery query;
    query.prepare("select * from servicech");
    query.exec();
    modal->setQuery(query);
    ui->tabservicech->setModel(modal);


    QSqlQueryModel * modal3=new QSqlQueryModel();

    query.prepare("select type from servicech");
    query.exec();
    modal3->setQuery(query);

    ui->comboBox->setModel(modal3);





    QSqlQuery query3,query1,query2;

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
    query3.prepare("SELECT DISTINCT numchambre FROM chambre");
    query3.exec();


    while(query3.next())
    {
        labels.append(query3.value(0).toString());
        i++;
        ticks.append(i);

        query1.prepare("SELECT numchambre FROM chambre where numchambre = '"+query3.value(0).toString()+"' ");
        query1.exec();
        while (query1.next()) {
            fossilData.append(query1.value(0).toDouble());
        }
        query2.prepare("SELECT prix FROM chambre where numchambre= '"+query3.value(0).toString()+"' ");
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
    ui->widget->yAxis->setLabel("Statistique ");
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

void MainWindow::showTime()
{
    QTime time=QTime::currentTime();
    QString time_text=time.toString("hh : mm : ss");
    ui->Digital_clock->setText(time_text);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pb_ajouter_clicked()
{
    int numchambre = ui->lineEdit_num->text().toInt();
    QString type= ui->lineEdit_type->text();
    QString prix= ui->lineEdit_prix->text();
    QString disponibilite= ui->lineEdit_disponibilite->text();
    QString idservice = ui->comboBox->currentText();
    QString image = ui->lineEdit_3->text();


    chambre l(numchambre,type,disponibilite,prix,idservice,image);
    if ((numchambre != 0) && (prix != "") && (type != "") && (disponibilite != "") )
    {
        bool test=l.ajouter();
        if(test )
        {ui->tabchambre->setModel(tmpchambre.afficher());//refresh
            QMessageBox::information(nullptr, QObject::tr("Ajouter une Chambre"),
                                     QObject::tr("Chambre ajouté.\n"
                                                 "Click Cancel to exit."), QMessageBox::Cancel);

            ui->lineEdit_num->setText("");
            ui->lineEdit_type->setText("");
            ui->lineEdit_prix->setText("");
            ui->lineEdit_disponibilite->setText("");
            ui->comboBox->setCurrentText("");
            ui->lineEdit_3->setText("");
            ui->lblBkImge2->clear();
            ui->lineEdit_4->setText("");

        }
    }
    else
    {


        if (numchambre == 0)
        {
           // ui->label_12->setText("*Numero de Chambre INVALIDE!!");
            ui->lineEdit_num->setStyleSheet(" border-radius:9px; border: 2px solid #b50000;  background:red");
            QPixmap pix("C:/Users/hp/Desktop/to work on/New backup 4 +interface/MALEK/malek/image2.png");


            ui->label_22->setPixmap(pix.scaled(215,215,Qt::KeepAspectRatio));


        }

        if (prix == "")
        {
            // ui->label_20->setText("*Prix INVALIDE!!");
            ui->lineEdit_prix->setStyleSheet(" border-radius:9px; border: 2px solid #b50000;  background:red");
            QPixmap pix("C:/Users/hp/Desktop/to work on/New backup 4 +interface/MALEK/malek/prix.png");
            ui->label_20->setPixmap(pix.scaled(215,215,Qt::KeepAspectRatio));


            QPixmap pix1("C:/Users/hp/Desktop/to work on/New backup 4 +interface/MALEK/malek/cross.png");

            ui->label_26->setPixmap(pix1.scaled(215,215,Qt::KeepAspectRatio));





        }

        if (disponibilite == "")
        {
            // ui->label_21->setText("*Disponibilite INVALIDE!!");
            QPixmap pix("C:/Users/hp/Desktop/to work on/New backup 4 +interface/MALEK/malek/dispo.png");
            ui->label_21->setPixmap(pix.scaled(215,215,Qt::KeepAspectRatio));

             //ui->lineEdit_num->setStyleSheet(" border-radius:9px; border: 2px solid #b50000;  background:red");
        }



    }
}

void MainWindow::on_pb_supprimer_clicked()
{
    int numerochambre = ui->lineEdit_num->text().toInt();
    bool test=tmpchambre.supprimer(numerochambre);
    if(test)
    {ui->tabchambre->setModel(tmpchambre.afficher());//refresh
        QMessageBox::information(nullptr, QObject::tr("Supprimer une Chambre"),
                                 QObject::tr("Chambre supprimé.\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);

        ui->lineEdit_num->setText("");
        ui->lineEdit_type->setText("");
        ui->lineEdit_prix->setText("");
        ui->lineEdit_disponibilite->setText("");
        ui->comboBox->setCurrentText("");
        ui->lineEdit_3->setText("");
        ui->lblBkImge2->clear();
        ui->lineEdit_4->setText("");

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer une Chambre"),
                              QObject::tr("Erreur !.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);


}

void MainWindow::on_pb_ajouter_2_clicked()
{
    int id = ui->lineEdit_id_3->text().toInt();
    QString type= ui->lineEdit_type2->text();
    QString dispo= ui->lineEdit_dispo->text();
    QString prix= ui->lineEdit_prix_2->text();

    Schambre e(id,type,dispo,prix);
      if ((id != 0) && (type != "") && (dispo != "") && (prix != "") )
      {
    bool test=e.ajouter_2();
    if(test)
    {ui->tabservicech->setModel(tmpservicech.afficher());//refresh
        QMessageBox::information(nullptr, QObject::tr("Ajouter un Service_chambre"),
                                 QObject::tr("Service_chambre ajoutée.\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);

    }
      }
    else

      {

          if (id == 0)
          {
             // ui->label_12->setText("*Numero de Chambre INVALIDE!!");
              ui->lineEdit_id_3->setStyleSheet(" border-radius:9px; border: 2px solid #b50000;  background:red");



          }

          if (type == "")
          {
              // ui->label_20->setText("*Prix INVALIDE!!");
              ui->lineEdit_type2->setStyleSheet(" border-radius:9px; border: 2px solid #b50000;  background:red");





          }

          if (dispo == "")
          {


               ui->lineEdit_dispo->setStyleSheet(" border-radius:9px; border: 2px solid #b50000;  background:red");
          }

          if (prix == "")
          {


               ui->lineEdit_prix_2->setStyleSheet(" border-radius:9px; border: 2px solid #b50000;  background:red");
          }


      }
}

void MainWindow::on_pb_supprimer_2_clicked()
{
    int id = ui->lineEdit_id_3->text().toInt();
    bool test=tmpservicech.supprimer_2(id);
    if(test)
    {ui->tabservicech->setModel(tmpservicech.afficher());//refresh
        QMessageBox::information(nullptr, QObject::tr("Supprimer un Service_chambre"),
                                 QObject::tr("Service_chambre supprimée.\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer un Service_chambre"),
                              QObject::tr("Erreur !.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_pb_modifier_clicked()
{ 
    int numchambre = ui->lineEdit_num->text().toInt();
    QString type= ui->lineEdit_type->text();
    QString prix= ui->lineEdit_prix->text();
    QString disponibilite= ui->lineEdit_disponibilite->text();
    QString idservice = ui->comboBox->currentText();
    QString image= ui->lineEdit_3->text();



    chambre l(numchambre,type,disponibilite,prix,idservice,image);
    bool test=l.modifier(numchambre);
    if(test)
    {ui->tabchambre->setModel(tmpchambre.afficher());//refresh
        QMessageBox::information(nullptr, QObject::tr("Modifier une Chambre"),
                                 QObject::tr("Chambre modifié.\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);

        ui->lineEdit_num->setText("");
        ui->lineEdit_type->setText("");
        ui->lineEdit_prix->setText("");
        ui->lineEdit_disponibilite->setText("");
        ui->comboBox->setCurrentText("");
        ui->lineEdit_3->setText("");
        ui->lblBkImge2->clear();
        ui->lineEdit_4->setText("");

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Modifier une Chambre"),
                              QObject::tr("Erreur !.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);


}


void MainWindow::on_pb_modifier_4_clicked()
{

    int id = ui->lineEdit_id_3->text().toInt();
    QString type= ui->lineEdit_type2->text();
    QString dispo= ui->lineEdit_dispo->text();
    QString prix= ui->lineEdit_prix_2->text();




    Schambre e(id,type,dispo,prix);
    bool test=e.modifier_4(id);
    if(test)
    {ui->tabservicech->setModel(tmpservicech.afficher());//refresh
        QMessageBox::information(nullptr, QObject::tr("Modifier un Service_chambre"),
                                 QObject::tr("Service_chambre modifiée.\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Modifier Service_chambre"),
                              QObject::tr("Erreur !.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);


}

void MainWindow::on_pb_rechercher_clicked()
{

    QString str=ui->lineEdit_num->text();
    ui->tabchambre->setModel(tmpchambre.recherche(str));
}




void MainWindow::on_pb_modifier_5_clicked()
{
    QString str=ui->lineEdit_id_3->text();
    ui->tabservicech->setModel(tmpservicech.modifier_5(str));
}

void MainWindow::on_pushButton_11_clicked()
{
    QSqlQueryModel * modal=new QSqlQueryModel();
    QSqlQuery query;
    query.prepare("select * from chambre");
    query.exec();
    modal->setQuery(query);
    ui->tabchambre->setModel(modal);





}


void MainWindow::on_tabchambre_activated(const QModelIndex &index)
{
    QString val=ui->tabchambre->model()->data(index).toString();
    QSqlQuery qry;
    qry.prepare("select * from CHAMBRE where NUMCHAMBRE='"+val+"' or TYPE='"+val+"' or DISPONIBILITE='"+val+"'  or PRIX='"+val+"' or IDSERVICE='"+val+"' or IMAGE='"+val+"' ");

    if (qry.exec())
    {

        while (qry.next())
        {

            ui->lineEdit_num->setText(qry.value(0).toString());
            ui->lineEdit_type->setText(qry.value(1).toString());
            ui->lineEdit_disponibilite->setText(qry.value(2).toString());
            ui->lineEdit_prix->setText(qry.value(3).toString());
            ui->comboBox->setCurrentText(qry.value(4).toString());
            ui->lineEdit_3->setText(qry.value(5).toString());
            // ui->chemin->setText(modquery1->value("IMAGE").toString());

            QPixmap pix(ui->lineEdit_3->text());
            int w =ui->lblBkImge2->width();
            int h =ui->lblBkImge2->height();
            ui->lblBkImge2->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));



        }


    }
    else
    {
        // QMessageBox::critical(this,tr("error"),qry.lastError().text());
    }
}






void MainWindow::on_radioFemelle_clicked()
{
    ui->lineEdit_disponibilite->setText("non");
}

void MainWindow::on_radioMale_clicked()
{
    ui->lineEdit_disponibilite->setText("oui");
}

void MainWindow::on_tabservicech_activated(const QModelIndex &index)
{

    QString val=ui->tabservicech->model()->data(index).toString();
    QSqlQuery qry;
    qry.prepare("select * from servicech where ID='"+val+"' or DISPO='"+val+"' or PRIX='"+val+"' or TYPE='"+val+"'  ");

    if (qry.exec())
    {

        while (qry.next())
        {

            ui->lineEdit_id_3->setText(qry.value(0).toString());
            ui->lineEdit_type2->setText(qry.value(3).toString());
            ui->lineEdit_dispo->setText(qry.value(1).toString());
            ui->lineEdit_prix_2->setText(qry.value(2).toString());





        }


    }
    else
    {
        // QMessageBox::critical(this,tr("error"),qry.lastError().text());
    }

}

void MainWindow::on_radioMale_2_clicked()
{
    ui->lineEdit_dispo->setText("oui");
}

void MainWindow::on_radioFemelle_2_clicked()
{
    ui->lineEdit_dispo->setText("non");
}

void MainWindow::on_pushButton_clicked()
{
    /*  QPrinter printer;
          QString doc;

          printer.setPrinterName("printer1");
          QPrintDialog print_dialog(&printer,this);
         if(print_dialog.exec()== QDialog::Rejected) return ;

           ui->text_id-> */


    QString strStream;
    QTextStream out(&strStream);

    const int rowCount = ui->tabchambre->model()->rowCount();
    const int columnCount = ui->tabchambre->model()->columnCount();

    out <<  "<html>\n"
            "<head>\n"
            "<meta Content=\"Text/html; charset=Windows-1251\">\n"

         <<  QString("<title>%1</title>\n").arg("col1")
          <<  "</head>\n"
              "  <h1>Gestion des Chambres PDF</h1>"
              "<body bgcolor=#ac9976  link=#5000A0>\n"
              "<table border=1 cellspacing=0 cellpadding=2 >\n";

    // headers
    out << "<thead><tr bgcolor=#aa0000>";
    for (int column = 0; column < columnCount; column++)
        if (!ui->tabchambre->isColumnHidden(column))
            out << QString("<th>%1</th>").arg(ui->tabchambre->model()->headerData(column, Qt::Horizontal).toString());
    out << "</tr></thead>\n";

    // data table
    for (int row = 0; row < rowCount; row++) {
        out << "<tr>";
        for (int column = 0; column < columnCount; column++) {
            if (!ui->tabchambre->isColumnHidden(column)) {
                QString data = ui->tabchambre->model()->data(ui->tabchambre->model()->index(row, column)).toString().simplified();
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

void MainWindow::on_pushButton_2_clicked()
{

}

void MainWindow::on_pushButton_2_released()
{

    ui->lineEdit_num->setText("");
    ui->lineEdit_type->setText("");
    ui->lineEdit_prix->setText("");
    ui->lineEdit_disponibilite->setText("");
    ui->comboBox->setCurrentText("");
    ui->lineEdit_3->setText("");
    ui->lblBkImge2->clear();
    ui->lineEdit_4->setText("");
}

/*
void MainWindow::on_pushButton_3_clicked()
{
    dash *x = new dash;

    x->show();
    this->hide();
}
*/

void MainWindow::on_pushButton_4_clicked()
{
    QString filename=QFileDialog::getOpenFileName(
                this,
                tr("Open File"),
                "C://",
                "All files (*.*);;Text File (*.txt);;Pdf File (*.pdf);;Music file(*.mp3)"


                );
    QDesktopServices::openUrl(QUrl("file:///"+filename,QUrl::TolerantMode));
    // QMessageBox::information(this,tr("File Name"),filename);
}

void MainWindow::on_pushButton_5_clicked()
{
    QString link="www.movenpick.com/fr/africa/tunisia/tunis/hotel-du-lac-tunis/rooms/";
    QDesktopServices::openUrl(QUrl(link));
}

/*
QString test_tri (int c)
{
    if (c==0)
    {
        return "numchambre";
    }
    else if (c==1)
    {
        return  "type";
    }
    else if (c==2)
    {
        return  "disponibilite";
    }
    return "NULL";
}
*/

void MainWindow::on_pushButton_6_released()
{
    //QString col=test_tri(i);
    QSqlQueryModel * model = new QSqlQueryModel();

    model->setQuery("SELECT * FROM CHAMBRE ORDER BY numchambre ASC");
    model->setHeaderData(0, Qt::Vertical, QObject::tr("numchambre"));
    model->setHeaderData(1, Qt::Vertical, QObject::tr("type"));
    model->setHeaderData(2, Qt::Vertical, QObject::tr("disponibilite"));
    model->setHeaderData(3, Qt::Vertical, QObject::tr("prix"));
    model->setHeaderData(4, Qt::Vertical, QObject::tr("image"));
    ui->tabchambre->setModel(model);
    ui->tabchambre->show();

}

void MainWindow::on_pushButton_7_clicked()
{
    ui->lineEdit_id_3->setText("");
    ui->lineEdit_type2->setText("");
    ui->lineEdit_prix_2->setText("");
    ui->lineEdit_dispo->setText("");

}


void MainWindow::on_pushButton_8_clicked()
{
    /*  QPrinter printer;
      QString doc;

      printer.setPrinterName("printer1");
      QPrintDialog print_dialog(&printer,this);
     if(print_dialog.exec()== QDialog::Rejected) return ;

       ui->text_id-> */


    QString strStream;
    QTextStream out(&strStream);

    const int rowCount = ui->tabservicech->model()->rowCount();
    const int columnCount = ui->tabservicech->model()->columnCount();

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
        if (!ui->tabservicech->isColumnHidden(column))
            out << QString("<th>%1</th>").arg(ui->tabservicech->model()->headerData(column, Qt::Horizontal).toString());
    out << "</tr></thead>\n";

    // data table
    for (int row = 0; row < rowCount; row++) {
        out << "<tr>";
        for (int column = 0; column < columnCount; column++) {
            if (!ui->tabservicech->isColumnHidden(column)) {
                QString data = ui->tabservicech->model()->data(ui->tabservicech->model()->index(row, column)).toString().simplified();
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

void MainWindow::on_pushButton_9_clicked()
{
    QString filename=QFileDialog::getOpenFileName(
                this,
                tr("Open File"),
                "C://",
                "All files (*.*);;Text File (*.txt);;Pdf File (*.pdf);;Music file(*.mp3)"


                );
    QDesktopServices::openUrl(QUrl("file:///"+filename,QUrl::TolerantMode));
    // QMessageBox::information(this,tr("File Name"),filename);
}



void MainWindow::on_pushButton_10_released()
{
    QSqlQueryModel * model = new QSqlQueryModel();

    model->setQuery("SELECT * FROM SERVICECH ORDER BY id ASC");
    model->setHeaderData(0, Qt::Vertical, QObject::tr("id"));
    model->setHeaderData(1, Qt::Vertical, QObject::tr("dispo"));
    model->setHeaderData(2, Qt::Vertical, QObject::tr("prix"));
    model->setHeaderData(3, Qt::Vertical, QObject::tr("type"));

    ui->tabservicech->setModel(model);
    ui->tabservicech->show();
}











void MainWindow::on_pushButton_12_clicked()
{
   /* QSqlQueryModel * modal2=new QSqlQueryModel();
    QSqlQuery query;
    query.prepare("select * from chambre");
    query.exec();
    modal2->setQuery(query);
    ui->tabchambre->setModel(modal2);

    QSqlQueryModel * modal=new QSqlQueryModel();
    //QSqlQuery query;
    query.prepare("select * from servicech");
    query.exec();
    modal->setQuery(query);
    ui->tabservicech->setModel(modal);


    QSqlQueryModel * modal3=new QSqlQueryModel();

    query.prepare("select type from servicech");
    query.exec();
    modal3->setQuery(query);

    ui->comboBox->setModel(modal3);
*/


}





void MainWindow::on_comboBox_currentIndexChanged(const QString &arg1)
{
    /*
    QString val=ui->comboBox->currentText();




    //QSqlQueryModel * modal=new QSqlQueryModel();
      QSqlQuery query;
      query.prepare("select type from servicech where type= '"+val+"' ");

    if(query.exec())
    {
        while (query.next())
        {
            ui->lineEdit_idservice->setText(val);
        }
    }
*/

}


void MainWindow::on_pushButton_13_clicked()
{
    QString imageFile = QFileDialog ::getOpenFileName(0,"Select Image","/home/","Image Files (*.jpg)");

    QFileInfo info(imageFile);
    //QString salma = info.fileName();
    QPixmap image (imageFile);

    ui->lblBkImge->setPixmap(image);
    ui->lblBkImge->show();
    ui->lineEdit->setText(imageFile);
    ui->lblBkImge->setPixmap(image);
}

void MainWindow::on_pushButton_14_clicked()
{
    QString imageFile = QFileDialog ::getOpenFileName(0,"Select Image","/home/","Image Files (*.jpg)");

    QFileInfo info(imageFile);
    //QString salma = info.fileName();
    QPixmap image (imageFile);

    ui->lblBkImge1->setPixmap(image);
    ui->lblBkImge1->show();
    ui->lineEdit_2->setText(imageFile);
    ui->lblBkImge1->setPixmap(image);
}

void MainWindow::on_pushButton_15_clicked()
{

    QString imageFile = QFileDialog ::getOpenFileName(0,"Select Image","/home/","Image Files (*.jpg)");

    QFileInfo info(imageFile);
    //QString salma = info.fileName();
    QPixmap image (imageFile);

    ui->lblBkImge2->setPixmap(image);
    ui->lblBkImge2->show();
    ui->lineEdit_3->setText(imageFile);
    ui->lblBkImge2->setPixmap(image);
}





void MainWindow::on_radioButton_clicked()
{
    on_pushButton_6_released();
}



void MainWindow::on_pushButton_16_released()
{
    //QString col=test_tri(i);
    QSqlQueryModel * model = new QSqlQueryModel();

    model->setQuery("SELECT * FROM CHAMBRE ORDER BY prix asc");
    model->setHeaderData(0, Qt::Vertical, QObject::tr("numchambre"));
    model->setHeaderData(1, Qt::Vertical, QObject::tr("type"));
    model->setHeaderData(2, Qt::Vertical, QObject::tr("disponibilite"));
    model->setHeaderData(3, Qt::Vertical, QObject::tr("prix"));
    model->setHeaderData(4, Qt::Vertical, QObject::tr("image"));

    ui->tabchambre->setModel(model);
    ui->tabchambre->show();
}

void MainWindow::on_radioButton_2_clicked()
{
    on_pushButton_16_released();
}




/*
void MainWindow::on_comboBox_2_currentIndexChanged(const QString &arg1)
{

    QSqlQueryModel * modal1=new QSqlQueryModel();
 QSqlQuery query;
   query.prepare("select type from chambre");
   query.exec();
   modal1->setQuery(query);

   ui->comboBox_2->setModel(modal1);



   QAbstractItemModel * m = ui->comboBox_2->model();
   QString whereClause = m->data(m->index(ui->comboBox_2->currentIndex(),1)).toString();

   QSqlQuery * modquery1 = new QSqlQuery();

   modquery1->prepare("select * from chambre where type = '"+whereClause+"';");
   modquery1->exec();
}

*/

void MainWindow::on_comboBox_3_currentIndexChanged(const QString &arg1)
{
    QString tii=ui->comboBox_3->currentText();


    ui->lineEdit_type->setText(tii);
}




void MainWindow::on_pushButton_17_clicked()
{

    dash *x = new dash;

    x->show();
    this->hide();

}

void MainWindow::on_pushButton_malek_clicked()
{
    statistiques *x = new statistiques;

    x->show();
    //this->hide();
}



void MainWindow::on_comboBox_4_currentTextChanged(const QString &arg1)
{

    QString tii=ui->comboBox_4->currentText();


    ui->lineEdit_type2->setText(tii);
}

void MainWindow::on_lineEdit_4_textChanged(const QString &arg1)
{
    chambre c;
    c.clearTable(ui->tabchambre);
    int mat=ui->lineEdit_4->text().toInt();
    c.searchRegexp(ui->tabchambre,mat);
}


void MainWindow::on_pushButton_3_released()
{
    QSqlQueryModel * model = new QSqlQueryModel();

    model->setQuery("SELECT * FROM SERVICECH ORDER BY prix ASC");
    model->setHeaderData(0, Qt::Vertical, QObject::tr("id"));
    model->setHeaderData(1, Qt::Vertical, QObject::tr("dispo"));
    model->setHeaderData(2, Qt::Vertical, QObject::tr("prix"));
    model->setHeaderData(3, Qt::Vertical, QObject::tr("type"));

    ui->tabservicech->setModel(model);
    ui->tabservicech->show();
}

void MainWindow::on_radioButton_3_clicked()
{
    on_pushButton_10_released();
}

void MainWindow::on_radioButton_4_clicked()
{
    on_pushButton_3_released();
}

void MainWindow::on_pushButton_17_released()
{
    dash *x = new dash;

    x->show();
    this->hide();
}

void MainWindow::on_pushButton_18_clicked()
{

    webcam *x = new webcam;

    x->show();
    //this->hide();
}

void MainWindow::on_pushButton_19_clicked()
{


    ui->lineEdit_num->setStyleSheet(" border-radius:9px; border: 2px solid #b50000;background: qradialgradient(cx: 0.3, cy: -0.4,fx: 0.0, fy: -0.0,radius: 1.89, stop: 0 #ffffff, stop: 1 #999);");
    ui->lineEdit_prix->setStyleSheet(" border-radius:9px; border: 2px solid #b50000;background: qradialgradient(cx: 0.3, cy: -0.4,fx: 0.0, fy: -0.0,radius: 1.89, stop: 0 #ffffff, stop: 1 #999);");


ui->label_22->clear();
ui->label_21->clear();
ui->label_20->clear();








}

void MainWindow::on_pushButton_20_clicked()
{
    settings *x = new settings;
    x->show();
   // this->hide();

}

void MainWindow::on_mode_jour_clicked()
{

    QPixmap pix("C:/Users/hp/Desktop/to work on/New backup 4 +interface/MALEK/malek/az.png");


    ui->label_mask->setPixmap(pix.scaled(215,215,Qt::KeepAspectRatio));
}



void MainWindow::on_mode_nuit_clicked()
{
    QPixmap pix("C:/Users/hp/Desktop/to work on/New backup 4 +interface/MALEK/malek/mask.png");


    ui->label_mask->setPixmap(pix.scaled(1800,1800,Qt::KeepAspectRatio));
}




void MainWindow::on_lineEdit_5_textChanged(const QString &arg1)
{
    Schambre c;
    c.clearTable(ui->tabservicech);
    int mat=ui->lineEdit_5->text().toInt();
    c.searchRegexp(ui->tabservicech,mat);
}



void MainWindow::on_pushButton_convert_clicked()
{

    mainwindoweuro *x = new mainwindoweuro;
    x->show();
}
