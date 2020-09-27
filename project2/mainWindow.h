#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QMainWindow>

class GLobj;
class QMenu;
class QLabel;


class mainMenu : public QMainWindow {

    Q_OBJECT

public:
   mainMenu(QWidget *parent = 0);
	
private:
   GLobj *globj;
private slots:
    void open();
    void save();
    void quit();
    void about();
    void aboutQt();
private:
    void createActions();
    void createMenus();


    QMenu *fileMenu;
    QMenu *helpMenu;
    QMenu *QuitMenu;
    QAction *openAct;
    QAction *saveAct;
    QAction *quitAct;
    QAction *aboutAct;
    QAction *aboutQtAct;
    QLabel *infoLabel;
};

#endif
