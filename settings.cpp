



#include "settings.h"
#include "ui_settings.h"
#include <QLoggingCategory>
#include <QMediaPlayer>
#include<qthread.h>


settings::settings(QWidget *parent):
QDialog(parent),
ui(new Ui::settings)
{
ui->setupUi(this);
    QLoggingCategory::setFilterRules(QStringLiteral("qt.speech.tts=true \n qt.speech.tts.*=true"));

    // Populate engine selection list
   // ui->engine->addItem("Default", QString("default"));
    foreach (QString engine, QTextToSpeech::availableEngines())
   // ui->engine->addItem(engine, engine);
    //ui->engine->setCurrentIndex(0);
    //engineSelected(0);

    connect(ui->speakButton, &QPushButton::clicked, this, &settings::speak);
    connect(ui->pitch, &QSlider::valueChanged, this, &settings::setPitch);
    connect(ui->rate, &QSlider::valueChanged, this, &settings::setRate);
    connect(ui->volume, &QSlider::valueChanged, this, &settings::setVolume);
    //connect(ui->engine, static_cast<void (QComboBox::*)(int)>(&QComboBox::currentIndexChanged), this, &settings::engineSelected);
}

void settings::speak()
{
    m_speech->say(ui->plainTextEdit->toPlainText());


}
void settings::stop()
{
    m_speech->stop();
}

void settings::setRate(int rate)
{
    m_speech->setRate(rate / 10.0);
}

void settings::setPitch(int pitch)
{
    m_speech->setPitch(pitch / 10.0);
}

void settings::setVolume(int volume)
{
    m_speech->setVolume(volume / 100.0);
}

void settings::stateChanged(QTextToSpeech::State state)
{

    ui->pauseButton->setEnabled(state == QTextToSpeech::Speaking);
    ui->resumeButton->setEnabled(state == QTextToSpeech::Paused);
    ui->stopButton->setEnabled(state == QTextToSpeech::Speaking || state == QTextToSpeech::Paused);
}


/*
void settings::engineSelected(int index)
{
    //QString engineName = ui->engine->itemData(index).toString();
    delete m_speech;
    //if (engineName == "default")
        m_speech = new QTextToSpeech(this);


    else
        m_speech = new QTextToSpeech(engineName, this);
    disconnect(ui->language, static_cast<void (QComboBox::*)(int)>(&QComboBox::currentIndexChanged), this, &settings::languageSelected);
    ui->language->clear();
    // Populate the languages combobox before connecting its signal.
    QVector<QLocale> locales = m_speech->availableLocales();
    QLocale current = m_speech->locale();
    foreach (const QLocale &locale, locales) {
        QString name(QString("%1 (%2)")
                     .arg(QLocale::languageToString(locale.language()))
                     .arg(QLocale::countryToString(locale.country())));
        QVariant localeVariant(locale);
        ui->language->addItem(name, localeVariant);
        if (locale.name() == current.name())
            current = locale;

    }

    setRate(ui->rate->value());
    setPitch(ui->pitch->value());
    setVolume(ui->volume->value());
    connect(ui->stopButton, &QPushButton::clicked, m_speech, &QTextToSpeech::stop);
    connect(ui->pauseButton, &QPushButton::clicked, m_speech, &QTextToSpeech::pause);
    connect(ui->resumeButton, &QPushButton::clicked, m_speech, &QTextToSpeech::resume);

    connect(m_speech, &QTextToSpeech::stateChanged, this, &settings::stateChanged);
    connect(m_speech, &QTextToSpeech::localeChanged, this, &settings::localeChanged);



}
*/

/*
void settings::voiceSelected(int index)
{
    m_speech->setVoice(m_voices.at(index));
}
*/

/*
void settings::localeChanged(const QLocale &locale)
{
    QVariant localeVariant(locale);
    //ui->language->setCurrentIndex(ui->language->findData(localeVariant));

    //disconnect(ui->voice, static_cast<void (QComboBox::*)(int)>(&QComboBox::currentIndexChanged), this, &settings::voiceSelected);
    //ui->voice->clear();

    m_voices = m_speech->availableVoices();
    QVoice currentVoice = m_speech->voice();
    //foreach (const QVoice &voice, m_voices) {
      //  ui->voice->addItem(QString("%1 - %2 - %3").arg(voice.name())
                          //.arg(QVoice::genderName(voice.gender()))
                          //.arg(QVoice::ageName(voice.age())));
        //if (voice.name() == currentVoice.name())
         //   ui->voice->setCurrentIndex(ui->voice->count() - 1);
   // }
   // connect(ui->voice, static_cast<void (QComboBox::*)(int)>(&QComboBox::currentIndexChanged), this, &settings::voiceSelected);
}
*/
