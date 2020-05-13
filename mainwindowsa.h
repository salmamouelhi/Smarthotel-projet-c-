#ifndef MAINWINDOWSA_H
#define MAINWINDOWSA_H
#include "categorie.h"
#include "fournisseur.h"
#include "produit.h"
#include <QMainWindow>
#include <QDialog>

namespace Ui {
class mainwindowsa;
}

class mainwindowsa : public QDialog
{
    Q_OBJECT

public:
    explicit mainwindowsa(QWidget *parent = nullptr);
    ~mainwindowsa();

private slots:
    void on_pb_ajouter_clicked();

    void on_pb_supprimer_clicked();

    void on_pb_ajouter_3_clicked();

    void on_pb_supprimer_3_clicked();

    void on_pb_modifier_clicked();

   void on_pb_modifier_3_clicked();

   void on_pb_rechercher_3_clicked();

    void on_pb_rechercher_clicked();


    void on_Trier_cat_clicked();

    void on_PDFcat_clicked();
    void on_PDFfour_clicked();
    void on_PDFprod_clicked();

    void on_pb_ajouter_2_clicked();


    void on_pb_supprimer_2_clicked();

    void on_pb_modifier_2_clicked();

    void on_pb_rechercher_2_clicked();


    void on_loadprod_clicked();
    void on_loadcat_clicked();
    void on_loadfour_clicked();
    void on_pushButton_4_clicked();

    void on_tabprod_activated(const QModelIndex &index);

    void on_tabcat_activated(const QModelIndex &index);

    void on_tabfour_activated(const QModelIndex &index);

    void on_btnChse_clicked();

    void on_comboBox_4_activated(const QString &arg1);



    void on_comboBox_4_currentIndexChanged(int index);

    void on_comboBox_5_currentIndexChanged(int index);

    void on_pushButton_clicked();

    void on_lineEdit_textChanged(const QString &arg1);

    void on_pushButton_2_clicked();

    void on_lineEdit_id_2_textChanged(const QString &arg1);

    void on_lineEdit_q_textChanged(const QString &arg1);

    void on_lineEdit_p_textChanged(const QString &arg1);

    void on_lineEdit_id_5_textChanged(const QString &arg1);

    void on_lineEdit_id_3_textChanged(const QString &arg1);

    void on_lineEdit_id_4_textChanged(const QString &arg1);

    void on_lineEdit_id_6_textChanged(const QString &arg1);

    void on_lineEdit_id_7_textChanged(const QString &arg1);

    void on_lineEdit_id_8_textChanged(const QString &arg1);

    void on_lineEdit_id_9_textChanged(const QString &arg1);

    void on_lineEdit_id_10_textChanged(const QString &arg1);

    void on_lineEdit_id_textChanged(const QString &arg1);

    void on_lineEdit_titre_textChanged(const QString &arg1);

    void on_pushButton_3_clicked();

private:
    Ui::mainwindowsa *ui;
    categorie tmpcat;
    fournisseur tmpfour;
    produit tmpprod;
};

#endif // MAINWINDOWSA_H
