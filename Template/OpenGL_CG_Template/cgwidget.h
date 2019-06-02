#ifndef NEHEWIDGET_H
#define NEHEWIDGET_H

#include <QtOpenGL>
#include <QOpenGLFunctions>
#include <QKeyEvent>
#include <GL/glu.h>
#include <GL/gl.h>

class CGWidget : public QGLWidget, protected QOpenGLFunctions
{
    Q_OBJECT
public:
    CGWidget(QWidget *parent = nullptr,
               const QString &title = "Nehe",
               bool isFullScreen = false);
    ~CGWidget();

protected:
    void initializeGL();
    void paintGL();
    void resizeGL(int width, int height);
    void keyPressEvent(QKeyEvent *event);

protected:
    bool isFullScreen;
    int winStartX;
    int winStartY;
    int winWidth;
    int winHeight;
};

#endif // NEHEWIDGET_H
