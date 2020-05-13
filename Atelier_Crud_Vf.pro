#-------------------------------------------------
#
# Project created by QtCreator 2018-10-31T08:31:47
#
#-------------------------------------------------

QT       += core gui sql  multimedia multimediawidgets texttospeech
QT += printsupport
QT       += widgets multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Atelier_Crud_Vf
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
    activite.cpp \
    categorie.cpp \
    client.cpp \
    etagere.cpp \
    euro.cpp \
    evenement.cpp \
    fournisseur.cpp \
    image.cpp \
    livre.cpp \
        main.cpp \
        mainwindow.cpp \
    connexion.cpp \
    login.cpp \
    chambre.cpp \
    Schambre.cpp \
    dash.cpp \
    mainwindowa.cpp \
    mainwindoweuro.cpp \
    mainwindowf.cpp \
    mainwindowr.cpp \
    mainwindowsa.cpp \
    produit.cpp \
    promo.cpp \
    qcustomplot.cpp \
    settings.cpp \
    smtp.cpp \
    statistiques.cpp \
    statistiquessalma.cpp \
    webcam.cpp

HEADERS += \
    activite.h \
    categorie.h \
    client.h \
    etagere.h \
    euro.h \
    evenement.h \
    fournisseur.h \
    image.h \
    livre.h \
        mainwindow.h \
    connexion.h \
    login.h \
    chambre.h \
    Schambre.h \
    dash.h \
    mainwindowa.h \
    mainwindoweuro.h \
    mainwindowf.h \
    mainwindowr.h \
    mainwindowsa.h \
    produit.h \
    promo.h \
    qcustomplot.h \
    settings.h \
    smtp.h \
    statistiques.h \
    statistiquessalma.h \
    webcam.h

FORMS += \
    euro.ui \
    image.ui \
        mainwindow.ui \
    login.ui \
    dash.ui \
    mainwindowa.ui \
    mainwindoweuro.ui \
    mainwindowf.ui \
    mainwindowr.ui \
    mainwindowsa.ui \
    settings.ui \
    statistiques.ui \
    statistiquessalma.ui \
    webcam.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
