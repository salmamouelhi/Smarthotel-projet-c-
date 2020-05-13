#ifndef MAINWINDOWR_H
#define MAINWINDOWR_H

#include <QDialog>
#include "client.h"
#include "promo.h"
#include <QMainWindow>

namespace Ui {
class mainwindowR;
}

class mainwindowR : public QDialog
{
    Q_OBJECT

public:
    explicit mainwindowR(QWidget *parent = nullptr);
    ~mainwindowR();

private slots:
   /* void on_pb_ajouter_clicked();

    void on_pb_supprimer_clicked();

    void on_pb_ajouter_2_clicked();



    void on_pb_modifier_clicked();

    void on_pb_modifier_4_clicked();

    void on_pb_rechercher_clicked();

    void on_pb_supprimer_5_clicked();

    void on_pb_modifier_5_clicked();*/

    void on_tabclient_activated(const QModelIndex &index);

    void on_supprimerclient_clicked();

    void on_ajouterclient_clicked();

    void on_modifierclient_clicked();

    /***********/
    void on_tabpromo_activated(const QModelIndex &index);

    void on_supprimerpromo_clicked();

    void on_ajouterpromo_clicked();

    void on_modifierpromo_clicked();

    /***********/

    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_pdf_clicked();

    void on_recherchepromo_clicked();

    void on_photo_clicked();



    void on_pb_tri_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::mainwindowR *ui;
    promo tmppromo;
    client tmpclient;


};

#endif // MAINWINDOWR_H
