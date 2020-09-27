// Software Radio Interface
// Author: Pascal Gautam

#include <QApplication>
#include "mainWindow.h"
#include "mainWindow.cpp"


int main(int argc, char *argv[]) {

    QApplication app(argc, argv);

    mainMenu radioWindow;

    radioWindow.resize(500, 500);
    radioWindow.setWindowTitle("Software Radio Interface");
    radioWindow.show();

    return app.exec();
}
