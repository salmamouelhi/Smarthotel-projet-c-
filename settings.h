#ifndef SETTINGS_H
#define SETTINGS_H

#include <QDialog>
#include <QtWidgets/qmainwindow.h>
#include "ui_mainwindow.h"
#include <QTextToSpeech>


namespace Ui {
class settings;
}


class settings : public QDialog
{
    Q_OBJECT
public:
    explicit settings(QWidget *parent = nullptr);
   // ~settings();

public slots:
    void speak();
    void stop();

    void setRate(int);
    void setPitch(int);
    void setVolume(int volume);

    void stateChanged(QTextToSpeech::State state);
    void engineSelected(int index);
    void languageSelected(int language);
    void voiceSelected(int index);

    void localeChanged(const QLocale &locale);

private slots:
    void on_speakButton_clicked();

private:
  Ui::settings *ui;
    QTextToSpeech *m_speech;
    QVector<QVoice> m_voices;
};

#endif
