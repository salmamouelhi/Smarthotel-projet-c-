#ifndef MAINWINDOWEURO_H
#define MAINWINDOWEURO_H

#include <QDialog>

namespace Ui {
class mainwindoweuro;
}

class mainwindoweuro : public QDialog
{
    Q_OBJECT

public:
    explicit mainwindoweuro(QWidget *parent = nullptr);
    ~mainwindoweuro();

private slots:


    void on_pushButton208_clicked();
private:
    Ui::mainwindoweuro *ui;
};

#endif // MAINWINDOWEURO_H
