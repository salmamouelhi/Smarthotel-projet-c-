#ifndef IMAGE_H
#define IMAGE_H

#include <QDialog>

namespace Ui {
class image;
}

class image : public QDialog
{
    Q_OBJECT

public:
    explicit image(QWidget *parent = nullptr);
    ~image();

private:
    Ui::image *ui;
};

#endif // IMAGE_H
