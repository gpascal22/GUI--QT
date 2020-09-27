// Software Radio Interface
// Author: Pascal Gautam
// Submitted to: Dr Dan Tamir


#include "mainWindow.h"
#include <QWidget>
#include <QApplication>
#include <QSlider>
#include <QSpinBox>
#include <QDial>
#include <QLCDNumber>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QRadioButton>
#include <QLabel>
#include <QPushButton>


mainMenu::mainMenu(QWidget *parent)
: QMainWindow(parent) {


    // For widgets decleration
    QLabel *volume = new QLabel("               VOLUME");
    QDial *dial = new QDial;
    QLCDNumber *lcd = new QLCDNumber;
    QLabel *modulation = new QLabel("      MODULATION");
    QRadioButton *am = new QRadioButton("AM");
    QRadioButton *fm = new QRadioButton("FM");
    QLabel *station = new QLabel("       STATION");
    QSpinBox *spinBox = new QSpinBox;
    QSlider *slider = new QSlider(Qt::Horizontal);
    QLabel *bass = new QLabel("            BASS");
    QSpinBox *bassSpin = new QSpinBox;
    QSlider *bassSlide = new QSlider(Qt::Vertical);
    QLabel *treble = new QLabel("          TREBLE");
    QSpinBox *trebleSpin = new QSpinBox;
    QSlider *trebleSlide = new QSlider(Qt::Vertical);
    QPushButton *exit = new QPushButton("EXIT");


    //For connecting volume and LCD
    dial->setRange(0, 100);
    dial->setNotchesVisible(true);
    QObject::connect(dial, SIGNAL(valueChanged(int)), lcd , SLOT(display(int)));

    // For station
    spinBox->setRange(50, 120);
    slider->setRange(50, 120);
    spinBox->setValue(98);
    QObject::connect(spinBox, SIGNAL(valueChanged(int)), slider, SLOT(setValue(int)));
    QObject::connect(slider, SIGNAL(valueChanged(int)), spinBox, SLOT(setValue(int)));



    // For bass spin and slider
    bassSpin->setRange(-5, 20);
    bassSlide->setRange(-5, 20);
    bassSpin->setValue(0);
    QObject::connect(bassSpin, SIGNAL(valueChanged(int)), bassSlide, SLOT(setValue(int)));
    QObject::connect(bassSlide, SIGNAL(valueChanged(int)), bassSpin, SLOT(setValue(int)));

    // For treble spin and slider
    trebleSpin->setRange(-5, 20);
    trebleSlide->setRange(-5, 20);
    trebleSpin->setValue(0);
    QObject::connect(trebleSpin, SIGNAL(valueChanged(int)), trebleSpin, SLOT(setValue(int)));
    QObject::connect(trebleSlide, SIGNAL(valueChanged(int)), trebleSpin, SLOT(setValue(int)));



    // For layouts
    QHBoxLayout *topLayout = new QHBoxLayout;
    topLayout->addWidget(volume);
    topLayout->addWidget(dial);
    topLayout->addWidget(lcd);

    QVBoxLayout *midLayout = new QVBoxLayout;
    midLayout ->addWidget(modulation);
    midLayout->addWidget(am);
    midLayout->addWidget(fm);
    midLayout->addWidget(station);
    midLayout->addWidget(spinBox);
    midLayout->addWidget(slider);

    QHBoxLayout *bottomLayout = new QHBoxLayout;
    bottomLayout->addWidget(bass);
    bottomLayout->addWidget(bassSpin);
    bottomLayout->addWidget(bassSlide);
    bottomLayout->addWidget(treble);
    bottomLayout->addWidget(trebleSpin);
    bottomLayout->addWidget(trebleSlide);


    QVBoxLayout *QuitButton = new QVBoxLayout;
    QuitButton->addWidget(exit);
    exit->show();

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addLayout(topLayout);
    layout->addLayout(midLayout);
    layout->addLayout(bottomLayout);
    layout->addLayout(QuitButton);

    QWidget *centralWidget = new QWidget();
    setCentralWidget(centralWidget);
    centralWidget->setLayout(layout);

    // For exit button
    QObject::connect(exit, SIGNAL(clicked()), QApplication::instance(), SLOT(quit()));

}
