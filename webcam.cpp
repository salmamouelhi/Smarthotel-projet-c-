#include "webcam.h"
#include "ui_webcam.h"
#include <QCamera>
#include <QCameraViewfinder>
#include <QCameraImageCapture>
#include <QImageEncoderSettings>
#include <QVBoxLayout>
#include <QFileDialog>
#include <QMenu>
#include <QAction>


webcam::webcam(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::webcam)
{
    ui->setupUi(this);
    mCamera= new QCamera(this);
    mCameraViewfinder= new QCameraViewfinder(this);
    mCameraImageCapture= new QCameraImageCapture(mCamera,this);
    mLayout= new QVBoxLayout;
    mOpcionesMenu= new QMenu("Options",this);
    mEncenderAction= new QAction("Allumer",this);
    mApagarAction= new QAction("Éteindre",this);
    mCapturarAction= new QAction("Capturer",this);

    mOpcionesMenu->addActions({ mEncenderAction, mApagarAction,mCapturarAction});
    ui->opcionesPushButton->setMenu(mOpcionesMenu);
    mCamera->setViewfinder(mCameraViewfinder);
    mLayout->addWidget(mCameraViewfinder);
    mLayout->setMargin(0);
    ui->scrollArea->setLayout(mLayout);

    connect(mEncenderAction,&QAction::triggered, [&](){
        mCamera->start();
            });

    connect(mApagarAction,&QAction::triggered, [&]{
          mCamera->stop();
           } );

    connect(mCapturarAction,&QAction::triggered, [&]{
       auto filename= QFileDialog::getSaveFileName(this,"capturar","/","Image File(*.jpg)");

      if (filename.isEmpty()){
          return ;
      }


mCameraImageCapture->setCaptureDestination(QCameraImageCapture::CaptureToFile);





QImageEncoderSettings imageEcoderSettings;
imageEcoderSettings.setCodec("image/jpg");
imageEcoderSettings.setResolution(1600,1200);
mCameraImageCapture->setEncodingSettings(imageEcoderSettings);
mCamera->setCaptureMode(QCamera::CaptureStillImage);
mCamera->start();
mCamera->searchAndLock();
mCameraImageCapture->capture(filename);
mCamera->unlock();



    } );

}

webcam::~webcam()
{
    delete ui;
}
