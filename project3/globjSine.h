#ifndef GLobjS_H
#define GLobSj_H

#include <QtOpenGL/QGLWidget>

class GLobjS : public QGLWidget  {
    Q_OBJECT

public:
    GLobjS(QWidget *parent = 0);
    ~GLobjS();

protected:
    void initializeGL();
    void resizeGL(int w, int h);
    void paintGL();
    void ngon(int n);
   
};
#endif // GLOBJS_H
