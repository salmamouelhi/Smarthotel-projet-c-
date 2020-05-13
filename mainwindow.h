
#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "chambre.h"
#include "Schambre.h"
#include <QMainWindow>

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

    void on_pb_modifier_4_clicked();

    void on_pb_rechercher_clicked();

    void on_pb_supprimer_5_clicked();

    void on_pb_modifier_5_clicked();

    void on_tablivre_activated(const QModelIndex &index);

    void on_lineEdit_prix_cursorPositionChanged(int arg1, int arg2);

    void on_lineEdit_num_cursorPositionChanged(int arg1, int arg2);

    void on_tabchambre_activated(const QModelIndex &index);

    void on_radioFemelle_clicked();

    void on_radioMale_clicked();

    void on_tabservicech_activated(const QModelIndex &index);

    void on_radioMale_2_clicked();

    void on_radioFemelle_2_clicked();

    void on_pushButton_clicked();


    void on_pushButton_2_clicked();

    void on_pushButton_2_released();

    void on_comboBox_activated(const QString &arg1);

    void on_fontComboBox_activated(const QString &arg1);

    void showTime();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_released();

    void on_pushButton_7_clicked();

    void on_Digital_clock_linkActivated(const QString &link);

    void on_Digital_clock_linkHovered(const QString &link);

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_10_released();

    void on_lineEdit_idservice_cursorPositionChanged(int arg1, int arg2);

    void on_tabservicech_clicked(const QModelIndex &index);

    void on_pushButton_11_clicked();

    void on_pushButton_12_clicked();

    void on_malek_activated(const QString &arg1);

    void on_comboBox_currentIndexChanged(const QString &arg1);

    void on_pushButton_13_clicked();

    void on_pushButton_14_clicked();

    void on_pushButton_15_clicked();

    void on_radioButton_clicked();

    void on_pushButton_16_clicked();

    void on_pushButton_16_released();

    void on_radioButton_2_clicked();

    void on_pushButton_12_released();

    void on_pushButton_17_clicked();

    void on_comboBox_2_activated(const QString &arg1);

    void on_comboBox_2_currentIndexChanged(const QString &arg1);

    void on_comboBox_3_currentIndexChanged(const QString &arg1);

    void on_pushButton_malek_clicked();

    void on_comboBox_4_currentTextChanged(const QString &arg1);

    void on_lineEdit_4_textChanged(const QString &arg1);

    void on_pushButton_10_clicked();

    void on_pushButton_3_released();

    void on_radioButton_3_clicked();

    void on_radioButton_4_clicked();

    void on_pushButton_17_released();

    void on_pushButton_18_clicked();

    void on_pushButton_19_clicked();

    void on_pushButton_20_clicked();

    void on_pushButton_convert_clicked();

    void on_mode_jour_clicked();

    void on_mode_nuit_clicked();

    void on_lineEdit_5_textChanged(const QString &arg1);



private:

    Ui::MainWindow *ui;
    chambre tmpchambre;
    Schambre tmpservicech;
};

#endif // MAINWINDOW_H
