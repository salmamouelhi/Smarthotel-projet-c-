#ifndef DASH_H
#define DASH_H

#include <QDialog>

namespace Ui {
class dash;
}

class dash : public QDialog
{
    Q_OBJECT

public:
    explicit dash(QWidget *parent = 0);
    ~dash();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_4_pressed();

    void on_Mode_jour_clicked();

    void on_Mode_nuit_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_11_clicked();

private:
    Ui::dash *ui;
};

#endif // DASH_H
