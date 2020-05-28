#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Livre.h"
#include <QMessageBox>
#include <QFileDialog>
#include <QPixmap>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
ui->setupUi(this);
ui->tabpost->setModel(tmppost.afficher());

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pb_ajouter_clicked()
{
    int id = ui->lineEdit_id->text().toInt();
    QString grade= ui->lineEdit_grade->text();
    QString salaire= ui->lineEdit_salaire->text();
    QString competences= ui->lineEdit_competences->text();
    QString mission= ui->lineEdit_mission->text();

  Post l(id,grade,salaire,competences,mission);
  bool test=l.ajouter();
  if(test)
{ui->tabpost->setModel(tmppost.afficher());//refresh
QMessageBox::information(nullptr, QObject::tr("Ajouter un post"),
                  QObject::tr("post ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter un post"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);


}

void MainWindow::on_pb_supprimer_clicked()
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

void MainWindow::on_pb_ajouter_2_clicked()
{
    int id = ui->lineEdit_id_3->text().toInt();
    int quantite = ui->lineEdit_quantite->text().toInt();
    QString etat= ui->lineEdit_etat->text();
  Etagere e(id,quantite,etat);
  bool test=e.ajouter_2();
  if(test)
{ui->tabetagere->setModel(tmpetagere.afficher());//refresh
QMessageBox::information(nullptr, QObject::tr("Ajouter une étagère"),
                  QObject::tr("Etagère ajoutée.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter une étagère"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}

/*******************************/
void MainWindow::on_pb_supprimer_2_clicked()
{
    int id = ui->lineEdit_id->text().toInt();
    bool test=tmpetagere.supprimer_2(id);
    if(test)
    {ui->tabetagere->setModel(tmpetagere.afficher());//refresh
        QMessageBox::information(nullptr, QObject::tr("Supprimer une étagère"),
                    QObject::tr("Etagère supprimée.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer une étagère"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}
/************************************/

void MainWindow::on_pb_modifier_clicked()
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


void MainWindow::on_pb_modifier_4_clicked()
{
    int id = ui->lineEdit_idmod_2->text().toInt();
    int quantite= ui->lineEdit_quantitemod->text().toInt();
    QString etat= ui->lineEdit_etatmod->text();

  Etagere e(id,quantite,etat);
  bool test=e.modifier_4(id);
  if(test)
{ui->tabetagere->setModel(tmpetagere.afficher());//refresh
QMessageBox::information(nullptr, QObject::tr("Modifier une étagère"),
                  QObject::tr("Etagère modifiée.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Modifier étagère"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);


}

void MainWindow::on_pb_rechercher_clicked()
{

    QString str=ui->lineEdit_id->text();
    ui->tabpost->setModel(tmppost.recherche(str));
}




void MainWindow::on_pb_modifier_5_clicked()
{
    QString str=ui->lineEdit_idmod_3->text();
    ui->tabrecherche2->setModel(tmpetagere.modifier_5(str));
}

void MainWindow::on_tablivre_activated(const QModelIndex &index)
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


void MainWindow::on_pushButton_clicked()
{
    ui->lineEdit_id->setText("");

    ui->lineEdit_grade->setText("");
    ui->lineEdit_salaire->setText("");
    ui->lineEdit_competences->setText("");
    ui->lineEdit_mission->setText("");
}

void MainWindow::on_pushButton_2_clicked()
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

void MainWindow::on_pushButton_3_clicked()
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
