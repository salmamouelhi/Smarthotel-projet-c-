#ifndef MAINWINDOWA_H
#define MAINWINDOWA_H
#include "livre.h"
#include "etagere.h"
#include <QMainWindow>
#include <QDialog>

namespace Ui {
class mainwindowA;
}

class mainwindowA : public QDialog
{
    Q_OBJECT

public:
    explicit mainwindowA(QWidget *parent = nullptr);
    ~mainwindowA();



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

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pb_modifier_2_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_6_clicked();

    void on_lblBkImge_linkActivated(const QString &link);

    void on_lblBkImge_linkHovered(const QString &link);

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

private:
    Ui::mainwindowA *ui;
    Post tmppost;
    personnel tmpperso;

};

#endif // MAINWINDOWA_H
