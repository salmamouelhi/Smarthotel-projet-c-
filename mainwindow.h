#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "activite.h"
#include "evenement.h"
#include <QMainWindow>
#include <QVector>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pb_ajouter_clicked();

    void on_pb_supprimer_clicked();

    void on_pb_ajouter_2_clicked();

    void on_pb_supprimer_2_clicked();

    void on_pb_modifier_clicked();

    void on_pb_modifier_2_clicked();

    void on_pb_rechercher_clicked();

    void on_pb_rechercher_2_clicked();

   // void on_pb_supprimer_5_clicked();

   // void on_pb_modifier_5_clicked();

    void on_tablivre_activated(const QModelIndex &index);

    void on_tabetagere_activated(const QModelIndex &index);

   // void on_pushButton_6_clicked();

   // void on_trier_3_clicked();

    void on_comboBox_currentIndexChanged(int index);

   // QVector<double> Statistique_client();

    void on_pushButton_1229_clicked(); // stat
    void makePlot_client (); //stat
    QVector<double> Statistique_client(); //stat


    void on_tablivre_doubleClicked(const QModelIndex &index);

    void  sendMail();


   // void on_pushButton_1229_clicked();

private:
    Ui::MainWindow *ui;
    activite tmplivre;
    evenement tmpetagere;
};

#endif // MAINWINDOW_H
