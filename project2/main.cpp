#include <QApplication>
#include <QDesktopWidget>
#include "mainWindow.h"
#include "mainWindow.cpp"


int main(int argc, char *argv[]) {

    QApplication app(argc, argv);

    mainMenu window;

    window.resize(700,550);
    
    window.setWindowTitle("Software Radio Interface");
    window.show();

    return app.exec();
}
