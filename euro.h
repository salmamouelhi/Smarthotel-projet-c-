#ifndef EURO_H
#define EURO_H

#include <QDialog>

namespace Ui {
class euro;
}

class euro : public QDialog
{
    Q_OBJECT

public:
    explicit euro(QWidget *parent = nullptr);
    ~euro();
    private slots:
    void on_pushButton_2222_clicked();

    void on_pushButton100_clicked();

private:
    Ui::euro *ui;
};

#endif // EURO_H
