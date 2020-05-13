#include "mainwindowf.h"
#include "ui_mainwindowf.h"
#include "activite.h"
#include "evenement.h"
#include <QMessageBox>
#include <QSqlQuery>
#include <QtPrintSupport/QPrinter>
#include <QtPrintSupport/QPrintDialog>
#include <iostream>
#include "C:\Users\hp\Desktop\Others's work\FaroukChtioui\projet2020\src\SmtpMime"
#include "smtp.h"
#include "dash.h"

mainwindowf::mainwindowf(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::mainwindowf)
{
    ui->setupUi(this);
    ui->tablivre->setModel(tmplivre.afficher());
    ui->tabetagere->setModel(tmpetagere.afficher());
    connect(ui->sendBtn, SIGNAL(clicked()),this, SLOT(sendMail()));
    connect(ui->exitBtn, SIGNAL(clicked()),this, SLOT(close()));
}

mainwindowf::~mainwindowf()
{
    delete ui;
}



void mainwindowf::on_pb_ajouter_clicked()
{

 /*   if(ui->lineEdit_id_activite->text().isEmpty() || ui->lineEdit_type->text().isEmpty() || ui->lineEdit_duree->text().isEmpty()|| ui->lineEdit_lieux->text().isEmpty() || ui->lineEdit_responsable->text().isEmpty()){
        QMessageBox ok;
        ok.setWindowTitle("Erreur");
        ok.setText("Ajout échoué! Veuillez remplir tous les champs.");
        ok.setStandardButtons(QMessageBox::Ok);
        ok.exec();

        return;
    }*/

    if(ui->lineEdit_id_activite->text().isEmpty() || ui->lineEdit_type->text().isEmpty() || ui->lineEdit_duree->text().isEmpty() || ui->lineEdit_lieux->text().isEmpty() || ui->lineEdit_responsable->text().isEmpty()){


        if(ui->lineEdit_id_activite->text().isEmpty()){
            ui->lineEdit_id_activite->setPlaceholderText("erreur");
            ui->lineEdit_id_activite->setStyleSheet("background: red");
        }
        if(ui->lineEdit_type->text().isEmpty()){ui->lineEdit_type->setPlaceholderText("erreur");
           ui->lineEdit_type->setStyleSheet("background: red");
        }
        if(ui->lineEdit_duree->text().isEmpty()){ui->lineEdit_duree->setPlaceholderText("erreur");
           ui->lineEdit_duree->setStyleSheet("background: red");
        }
        if(ui->lineEdit_responsable->text().isEmpty()){ui->lineEdit_responsable->setPlaceholderText("erreur");
           ui->lineEdit_responsable->setStyleSheet("background: red");
        }
        if(ui->lineEdit_lieux->text().isEmpty()){ui->lineEdit_lieux->setPlaceholderText("erreur");
           ui->lineEdit_lieux->setStyleSheet("background: red");
        }


        QMessageBox ok;
            ok.setWindowTitle("Erreur");
            ok.setText("Ajout échoué! Veuillez remplir tous les champs.");
            ok.setStandardButtons(QMessageBox::Ok);
            ok.exec();

            return;
        }




/*ui->lineEdit_duree->setPlaceholderText(" ");
ui->lineEdit_id_activite->setPlaceholderText(" ") ;
ui->lineEdit_type->setPlaceholderText(" ") ;
*/




    int id_activite = ui->lineEdit_id_activite->text().toInt();
    QString type= ui->lineEdit_type->text();
    QString duree= ui->lineEdit_duree->text();
    QString lieux= ui->lineEdit_lieux->text();
    QString responsable= ui->lineEdit_responsable->text();

  activite l(id_activite,type,duree,lieux,responsable);
  bool test=l.ajouter();
  if(test)
{ui->tablivre->setModel(tmplivre.afficher());//refresh
QMessageBox::information(nullptr, QObject::tr("Ajouter une activite"),
                  QObject::tr("Activite ajoutée.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

   foreach(QLineEdit* le, findChildren<QLineEdit*>()) {
   le->clear();
   ui->lineEdit_id_activite->setPlaceholderText("");
   ui->lineEdit_id_activite->setStyleSheet("background: white");
   ui->lineEdit_type->setPlaceholderText("");
   ui->lineEdit_id_activite->setStyleSheet("background: white");
   ui->lineEdit_duree->setPlaceholderText("");
   ui->lineEdit_id_activite->setStyleSheet("background: white");
   ui->lineEdit_lieux->setPlaceholderText("");
   ui->lineEdit_id_activite->setStyleSheet("background: white");
   ui->lineEdit_responsable->setPlaceholderText("");
   ui->lineEdit_id_activite->setStyleSheet("background: white");


                                                      }

}
  else

      QMessageBox::critical(nullptr, QObject::tr("Ajouter une activite"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);


}

void mainwindowf::on_pb_supprimer_clicked()
{
int id_activite = ui->lineEdit_id_activite->text().toInt();
bool test=tmplivre.supprimer(id_activite);
if(test)
{ui->tablivre->setModel(tmplivre.afficher());//refresh
    QMessageBox::information(nullptr, QObject::tr("Supprimer une activite"),
                QObject::tr("Activite supprimée.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);


    ui->lineEdit_id_activite->show();
    foreach(QLineEdit* le, findChildren<QLineEdit*>()) {
    le->clear();
    }


}
else
    QMessageBox::critical(nullptr, QObject::tr("Supprimer une activite"),
                QObject::tr("Erreur !.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);


}

void mainwindowf::on_pb_ajouter_2_clicked()
{
    if(ui->lineEdit_id_evenement->text().isEmpty() || ui->lineEdit_type_2->text().isEmpty() || ui->lineEdit_date->text().isEmpty()|| ui->lineEdit_salle->text().isEmpty() || ui->lineEdit_disponibilite->text().isEmpty() || ui->lineEdit_prix->text().isEmpty() || ui->lineEdit_nombre_personnes->text().isEmpty()){
        QMessageBox ok;
        ok.setWindowTitle("Erreur");
        ok.setText("Ajout échoué! Veuillez remplir tous les champs.");
        ok.setStandardButtons(QMessageBox::Ok);
        ok.exec();
        return;
    }
    int id_evenement = ui->lineEdit_id_evenement->text().toInt();
    QString type= ui->lineEdit_type_2->text();
    QString date_= ui->lineEdit_date->text();
    int salle = ui->lineEdit_salle->text().toInt();
    int nombre_personnes = ui->lineEdit_nombre_personnes->text().toInt();
    QString prix= ui->lineEdit_prix->text();
    QString disponibilite= ui->lineEdit_disponibilite->text();

  evenement e(id_evenement,type,date_,salle,nombre_personnes,prix,disponibilite);
  bool test=e.ajouter_2();
  if(test)
{ui->tabetagere->setModel(tmpetagere.afficher());//refresh
QMessageBox::information(nullptr, QObject::tr("Ajouter un evenement"),
                  QObject::tr("evenement ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

foreach(QLineEdit* le, findChildren<QLineEdit*>()) {
le->clear();
}

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter un evenement"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}

void mainwindowf::on_pb_supprimer_2_clicked()
{
    int id_evenement = ui->lineEdit_id_evenement->text().toInt();
    bool test=tmpetagere.supprimer_2(id_evenement);
    if(test)
    {ui->tabetagere->setModel(tmpetagere.afficher());//refresh
        QMessageBox::information(nullptr, QObject::tr("Supprimer un evenement"),
                    QObject::tr("evenement supprimée.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
        foreach(QLineEdit* le, findChildren<QLineEdit*>()) {
        le->clear();
        }

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer un evenement"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}

void mainwindowf::on_pb_modifier_clicked()
{
    int id_activite = ui->lineEdit_id_activite->text().toInt();
    QString type= ui->lineEdit_type->text();
    QString duree= ui->lineEdit_duree->text();
    QString lieux= ui->lineEdit_lieux->text();
    QString responsable= ui->lineEdit_responsable->text();

  activite l(id_activite,type,duree,lieux,responsable);
  bool test=l.modifier(id_activite);
  if(test)
{ui->tablivre->setModel(tmplivre.afficher());//refresh
QMessageBox::information(nullptr, QObject::tr("Modifier une activite"),
                  QObject::tr("activite modifiée.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

ui->lineEdit_id_activite->show();
foreach(QLineEdit* le, findChildren<QLineEdit*>()) {
le->clear();
}

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Modifier activite"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);


}


void mainwindowf::on_pb_modifier_2_clicked()
{
    int id_evenement = ui->lineEdit_id_evenement->text().toInt();
    QString type= ui->lineEdit_type_2->text();
    QString date_= ui->lineEdit_date->text();
    int salle= ui->lineEdit_salle->text().toInt();
    int nombre_personnes= ui->lineEdit_nombre_personnes->text().toInt();
    QString prix= ui->lineEdit_prix->text();
    QString disponibilite= ui->lineEdit_disponibilite->text();


  evenement e(id_evenement,type,date_,salle,nombre_personnes,prix,disponibilite);
  bool test=e.modifier_2(id_evenement);
  if(test)
{ui->tabetagere->setModel(tmpetagere.afficher());//refresh
QMessageBox::information(nullptr, QObject::tr("Modifier un evenement"),
                  QObject::tr("evenement modifiée.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

foreach(QLineEdit* le, findChildren<QLineEdit*>()) {
le->clear();
}

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Modifier evenement"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);


}


void mainwindowf::on_pb_rechercher_clicked()
{

    QString str=ui->lineEdit_id_activite->text();
    ui->tablivre->setModel(tmplivre.recherche(str));
}




void mainwindowf::on_pb_rechercher_2_clicked()
{
    QString str=ui->lineEdit_id_evenement->text();
    ui->tabetagere->setModel(tmpetagere.rechercher_2(str));
}

void mainwindowf::on_tablivre_activated(const QModelIndex &index)
{
    QString val=ui->tablivre->model()->data(index).toString();
    QSqlQuery qry;
    qry.prepare("select * from activite where ID_ACTIVITE='"+val+"' or TYPE='"+val+"' or DUREE='"+val+"' or LIEUX='"+val+"' or RESPONSABLE='"+val+"'");

     if (qry.exec())
        {

        while (qry.next())
        {

                  ui->lineEdit_id_activite->setText(qry.value(0).toString());
                  ui->lineEdit_type->setText(qry.value(1).toString());
                  ui->lineEdit_duree->setText(qry.value(2).toString());
                  ui->lineEdit_lieux->setText(qry.value(3).toString());
                  ui->lineEdit_responsable->setText(qry.value(4).toString());

        }
    }
    else
    {
       // QMessageBox::critical(this,tr("error"),qry.lastError().text());
    }
      }


void mainwindowf::on_tabetagere_activated(const QModelIndex &index)
{
    QString val=ui->tabetagere->model()->data(index).toString();
    QSqlQuery qry;
    qry.prepare("select * from evenement where ID_EVENEMENT='"+val+"' or TYPE='"+val+"' or DATE_='"+val+"' or SALLE='"+val+"' or NOMBRE_PERSONNES='"+val+"' or PRIX='"+val+"' or DISPONIBILITE='"+val+"'");

     if (qry.exec())
        {

        while (qry.next())
        {

                  ui->lineEdit_id_evenement->setText(qry.value(0).toString());
                  ui->lineEdit_type_2->setText(qry.value(1).toString());
                  ui->lineEdit_date->setText(qry.value(2).toString());
                  ui->lineEdit_salle->setText(qry.value(3).toString());
                  ui->lineEdit_nombre_personnes->setText(qry.value(4).toString());
                  ui->lineEdit_prix->setText(qry.value(5).toString());
                  ui->lineEdit_disponibilite->setText(qry.value(6).toString());


        }
    }
    else
    {
       // QMessageBox::critical(this,tr("error"),qry.lastError().text());
    }
      }

void mainwindowf::sendMail()
{
    QString mail = ui->rcpt->text();
    Smtp* smtp = new Smtp(ui->uname->text(), ui->paswd->text(), ui->server->text(), ui->port->text().toInt());
    connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));


    smtp->sendMail(ui->uname->text(), ui->rcpt->text() , ui->subject->text(),ui->msg->toPlainText());

    if(    connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)))
)
    {
        QMessageBox::critical(this, "envoyer un mail", "Message non Envoyé (probleme de connexion)");
    }
    else
    {
        QMessageBox::information(this, "envoyer un mail", "Message envoyé avec succès.");
    }
}

/*void MainWindow::on_pushButton_6_clicked()
{
    SmtpClient smtp("smtp.gmail.com", 465, SmtpClient::SslConnection);
    smtp.setUser("faroukchtioui7@gmail.com");
    smtp.setPassword("farouk love");
    MimeMessage message;
    message.setSender(new EmailAddress("faroukchtioui7@gmail.com", "farouk chtioui"));
    QString email =ui->choisi_un_email->text();
    message.addRecipient(new EmailAddress(email, "Farouk CHTIOUI"));
    MimeText text;
    QString email2=ui->sujet->text();
    message.setSubject(email2);
    QString email3 = ui->pour_envoyer_email_2->toPlainText();
    text.setText(email3);
    message.addPart(&text);
    smtp.connectToHost();
    smtp.login();
    if(smtp.sendMail(message))
    {
        QMessageBox::information(this, "envoyer un mail", "Envoyé");
    }
    else
    {
        QMessageBox::critical(this, "envoyer un mail", "Message non Envoyé (probleme de connexion)");
    }
    smtp.quit();
}*/

/*void MainWindow::on_trier_3_clicked()
{QString col ;
    std::cout << "triii" << std::endl;
   QModelIndexList a = ui->tabetagere->selectionModel()->selectedColumns() ;
for (int i =0 ;i<a.count();i++){
 col =  ui->tabetagere->selectionModel()->model()->headerData(a.at(i).column(),Qt::Horizontal).toString();
qDebug() << col;
}
     evenement *e= new evenement();
     ui->tabetagere->setModel(e->trierevenement(col));
}*/
void mainwindowf::on_comboBox_currentIndexChanged(int index) // tri event
{
    if (index==0)
{
        ui->tabetagere->setModel(tmpetagere.afficher());
        ui->tabetagere->setModel(tmpetagere.tri_pub_2(index));

    }
    else{

        if (index==1)
        {
            ui->tabetagere->setModel(tmpetagere.afficher());

        ui->tabetagere->setModel(tmpetagere.tri_pub_3(index));
    }
        else

            if (index==2)
            {
                ui->tabetagere->setModel(tmpetagere.afficher());

        ui->tabetagere->setModel(tmpetagere.tri_pub_4(index));
     }
        else

                if (index==3)
                {
                    ui->tabetagere->setModel(tmpetagere.afficher());

            ui->tabetagere->setModel(tmpetagere.tri_pub_5(index));
         }  else
if (index==4) {

                        ui->tabetagere->setModel(tmpetagere.afficher());

                ui->tabetagere->setModel(tmpetagere.tri_pub_6(index));}
else

        if (index==5)
        {
            ui->tabetagere->setModel(tmpetagere.afficher());

    ui->tabetagere->setModel(tmpetagere.tri_pub_7(index));
 }

             }
}

QVector<double> mainwindowf::Statistique_client()
{
    QSqlQuery q;
    QVector<double> stat(5);
    stat[0]=0;
    stat[1]=0;
    stat[2]=0;
    stat[3]=0;
    stat[4]=0;

    q.prepare("SELECT type FROM EVENEMENT WHERE type='gala'");
    q.exec();
    while (q.next())
    {
        stat[0]++;
    }
    q.prepare("SELECT type FROM EVENEMENT WHERE type='marriage'");
    q.exec();
    while (q.next())
    {
        stat[1]++;
    }
    q.prepare("SELECT type FROM EVENEMENT WHERE type='conference'");
    q.exec();
    while (q.next())
    {
        stat[2]++;
    }
    q.prepare("SELECT type FROM EVENEMENT WHERE type='concert'");
    q.exec();
    while (q.next())
    {
        stat[3]++;
    }
    q.prepare("SELECT type FROM EVENEMENT WHERE type='autre'");
    q.exec();
    while (q.next())
    {
        stat[4]++;
    }

    return stat;
}
void mainwindowf::on_pushButton_1229_clicked()
{
    mainwindowf::makePlot_client();

}


void mainwindowf::makePlot_client()
{
    // prepare data:
    QVector<double> x3(5), y3(20);
    for (int i=0; i<x3.size(); ++i)
    {
      x3[i] = i+1;

    }
    for (int i=0; i<y3.size(); ++i)
    {
      y3[i] = i+1;

    }

    QCPBars *bars1 = new QCPBars(ui->CustomPlot99->xAxis, ui->CustomPlot99->yAxis);
    bars1->setWidth(2/(double)x3.size());
    bars1->setData(x3, mainwindowf::Statistique_client());
    bars1->setName("type d'evenement selon client");
    bars1->setPen(QPen(QColor(200, 40, 60).lighter(170)));

    bars1->setBrush(QColor(200, 40, 60, 170));
    ui->CustomPlot99->replot();


    // move bars above graphs and grid below bars:
    ui->CustomPlot99->addLayer("abovemain", ui->CustomPlot99->layer("main"), QCustomPlot::limAbove);
    ui->CustomPlot99->addLayer("belowmain", ui->CustomPlot99->layer("main"), QCustomPlot::limBelow);
    ui->CustomPlot99->xAxis->grid()->setLayer("belowmain");
    ui->CustomPlot99->yAxis->grid()->setLayer("belowmain");

    // set some pens, brushes and backgrounds:
    QVector<double> Ticks;
    Ticks<<1<<2<<3<<4<<5<<6;
    QVector<QString> labels;
    labels<<"gala"<<"marriage"<<"conference"<<"concert"<<"autre";
    QSharedPointer<QCPAxisTickerText> textTicker(new QCPAxisTickerText);
    textTicker->addTicks(Ticks,labels);
    ui->CustomPlot99->xAxis->setTicker(textTicker);
    ui->CustomPlot99->xAxis->setSubTicks(false);
    ui->CustomPlot99->xAxis->setTickLength(0,4);
    ui->CustomPlot99->xAxis->setBasePen(QPen(Qt::white, 1));
    ui->CustomPlot99->yAxis->setBasePen(QPen(Qt::white, 1));
    ui->CustomPlot99->xAxis->setTickPen(QPen(Qt::transparent, 1));
    ui->CustomPlot99->yAxis->setTickPen(QPen(Qt::white, 1));
    ui->CustomPlot99->xAxis->setSubTickPen(QPen(Qt::transparent, 1));
    ui->CustomPlot99->yAxis->setSubTickPen(QPen(Qt::transparent, 1));
    ui->CustomPlot99->xAxis->setTickLabelColor(Qt::white);
    ui->CustomPlot99->yAxis->setTickLabelColor(Qt::white);
    ui->CustomPlot99->xAxis->grid()->setPen(QPen(QColor(140, 140, 140), 1, Qt::DotLine));
    ui->CustomPlot99->yAxis->grid()->setPen(QPen(QColor(140, 140, 140), 1, Qt::DotLine));
    ui->CustomPlot99->xAxis->grid()->setSubGridPen(QPen(QColor(80, 80, 80), 1, Qt::DotLine));
    ui->CustomPlot99->yAxis->grid()->setSubGridPen(QPen(QColor(80, 80, 80), 1, Qt::DotLine));
    ui->CustomPlot99->xAxis->grid()->setSubGridVisible(true);
    ui->CustomPlot99->yAxis->grid()->setSubGridVisible(true);
    ui->CustomPlot99->xAxis->grid()->setZeroLinePen(Qt::NoPen);
    ui->CustomPlot99->yAxis->grid()->setZeroLinePen(Qt::NoPen);
    ui->CustomPlot99->xAxis->setUpperEnding(QCPLineEnding::esSpikeArrow);
    ui->CustomPlot99->yAxis->setUpperEnding(QCPLineEnding::esSpikeArrow);
    QLinearGradient plotGradient;
    plotGradient.setStart(0, 0);
    plotGradient.setFinalStop(0, 350);
    plotGradient.setColorAt(0, QColor(10, 50, 80));
    plotGradient.setColorAt(1, QColor(10, 20, 50));
    ui->CustomPlot99->setBackground(plotGradient);
    QLinearGradient axisRectGradient;
    axisRectGradient.setStart(0, 0);
    axisRectGradient.setFinalStop(0, 350);
    axisRectGradient.setColorAt(0, QColor(10, 50, 80));
    axisRectGradient.setColorAt(1, QColor(0, 0, 30));
    ui->CustomPlot99->axisRect()->setBackground(axisRectGradient);

    ui->CustomPlot99->rescaleAxes();
    //ui->CustomPlot99->xAxis->setRange(0, 7);
    //ui->CustomPlot99->yAxis->setRange(0, 10);



}



void mainwindowf::on_tablivre_doubleClicked(const QModelIndex &index)
{
    ui->lineEdit_id_activite->hide();

}


void mainwindowf::on_pushButton_clicked()
{
    dash *x = new dash;

    x->show();
    this->hide();

}
