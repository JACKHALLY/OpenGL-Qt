#ifndef NEHEWIDGET_H
#define NEHEWIDGET_H

#include <QtOpenGL>
#include <QOpenGLFunctions>
#include <QKeyEvent>
#include <GL/glu.h>
#include <GL/gl.h>

class NeheWidget : public QGLWidget, protected QOpenGLFunctions
{
    Q_OBJECT
public:
    NeheWidget(QWidget *parent = nullptr,
               const QString &title = "Nehe",
               bool isFullScreen = false);
    ~NeheWidget();

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
