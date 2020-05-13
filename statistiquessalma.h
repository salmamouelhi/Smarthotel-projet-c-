#ifndef STATISTIQUESSALMA_H
#define STATISTIQUESSALMA_H

#include <QDialog>

namespace Ui {
class statistiquessalma;
}

class statistiquessalma : public QDialog
{
    Q_OBJECT

public:
    explicit statistiquessalma(QWidget *parent = nullptr);
    ~statistiquessalma();

private:
    Ui::statistiquessalma *ui;
};

#endif // STATISTIQUESSALMA_H
