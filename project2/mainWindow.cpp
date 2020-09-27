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
#include <QToolBar>
#include <QMenu>
#include <QtGui>
#include "globj.h"
#include <QGridLayout>
#include <QDockWidget>

mainMenu::mainMenu(QWidget *parent)
: QMainWindow(parent) {

    //For DockWidget
    QDockWidget *dock = new QDockWidget(this);
    dock->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);


    // For widgets decleration
    QLabel *volume = new QLabel("       VOLUME",dock);
    QDial *dial = new QDial(dock);
    QLCDNumber *lcd = new QLCDNumber(dock);
    QLabel *modulation = new QLabel("MODULATION", dock);
    QRadioButton *am = new QRadioButton("AM",dock);
    QRadioButton *fm = new QRadioButton("FM", dock);
    QLabel *station = new QLabel("STATION", dock);
    QSpinBox *spinBox = new QSpinBox(dock);
    QSlider *slider = new QSlider(Qt::Horizontal, dock);
    QLabel *bass = new QLabel("BASS", dock);
    QSpinBox *bassSpin = new QSpinBox(dock);
    QSlider *bassSlide = new QSlider(Qt::Vertical, dock);
    QLabel *treble = new QLabel("          TREBLE", dock);
    QSpinBox *trebleSpin = new QSpinBox(dock);
    QSlider *trebleSlide = new QSlider(Qt::Vertical, dock);
    QPushButton *exit = new QPushButton("EXIT", dock);

    //For menubar
    createActions();
    createMenus();


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

    // For adding shapes
    globj = new GLobj(this);
    dock->setWidget(globj);
    addDockWidget(Qt::RightDockWidgetArea, dock);


}

void mainMenu::open()
{
    infoLabel->setText(tr(" <b>File|Open</b>"));
}

void mainMenu::save()
{
    infoLabel->setText(tr(" <b>File|Save</b>"));
}

void mainMenu::quit()
{
    infoLabel->setText(tr(" <b>Quit|Quit application</b>"));

}

void mainMenu::about()
{
    infoLabel->setText(tr(" <b>Help|About</b>"));
    QMessageBox::about(this, tr("About Menu"),
                       tr("The <b>Menu</b> example "
                          "menu-bar"));
}

void mainMenu::aboutQt()
{
    infoLabel->setText(tr(" <b>Help|About Qt</b>"));
}




void mainMenu::createActions()
{
    openAct = new QAction(tr("&Open"), this);
    openAct->setShortcuts(QKeySequence::Open);
    openAct->setStatusTip(tr("Open an file"));
    connect(openAct, SIGNAL(triggered()), this, SLOT(open()));

    saveAct = new QAction(tr("&Save"), this);
    saveAct->setShortcuts(QKeySequence::Save);
    saveAct->setStatusTip(tr("Save the document"));
    connect(saveAct, SIGNAL(triggered()), this, SLOT(save()));


    aboutAct = new QAction(tr("&About"), this);
    aboutAct->setStatusTip(tr("About box"));
    connect(aboutAct, SIGNAL(triggered()), this, SLOT(about()));

    aboutQtAct = new QAction(tr("About &Qt"), this);
    aboutQtAct->setStatusTip(tr("Show the Qt library's"));
    connect(aboutQtAct, SIGNAL(triggered()), qApp, SLOT(aboutQt()));
    connect(aboutQtAct, SIGNAL(triggered()), this, SLOT(aboutQt()));


    quitAct = new QAction(tr("&Quit application"), this);
    quitAct->setShortcuts(QKeySequence::Quit);
    quitAct->setStatusTip(tr("Exit the application"));
    connect(quitAct, SIGNAL(triggered()), this, SLOT(close()));

}



void mainMenu::createMenus()
{
    fileMenu = menuBar()->addMenu(tr("&File"));
    fileMenu->addAction(openAct);
    fileMenu->addAction(saveAct);

    helpMenu = menuBar()->addMenu(tr("&Help"));
    helpMenu->addAction(aboutAct);
    helpMenu->addAction(aboutQtAct);

    QuitMenu = menuBar()->addMenu(tr("&Quit"));
    QuitMenu->addAction(quitAct);

}
