#ifndef WEBCAM_H
#define WEBCAM_H

#include <QDialog>

namespace Ui {
class webcam;
}


class QCamera;
class QCameraViewfinder;
class QCameraImageCapture;
class QVBoxLayout;
class QMenu;
class QAction;


class webcam : public QDialog
{
    Q_OBJECT

public:
    explicit webcam(QWidget *parent = nullptr);
    ~webcam();

private:
    Ui::webcam *ui;
    QCamera *mCamera;
    QCameraViewfinder *mCameraViewfinder;
    QCameraImageCapture *mCameraImageCapture;
    QVBoxLayout *mLayout;
    QMenu *mOpcionesMenu;
    QAction *mEncenderAction;
    QAction *mApagarAction;
    QAction *mCapturarAction;
};

#endif // WEBCAM_H
