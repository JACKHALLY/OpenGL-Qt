#include "nehewidget.h"

NeheWidget::NeheWidget(QWidget *parent,
                       const QString &title,
                       bool isFullScreen)
           : QGLWidget(parent),
             isFullScreen(isFullScreen),
             winStartX(100),
             winStartY(100),
             winWidth(640),
             winHeight(480)
{
    setGeometry(winStartX, winStartY, winWidth, winHeight);
    setWindowTitle(title);
    if(isFullScreen)
    {
        showFullScreen();
    }
}

NeheWidget::~NeheWidget()
{}

void NeheWidget::initializeGL()
{
    // without this method, will be cracked because of
    // runtime exception
    initializeOpenGLFunctions();

    glShadeModel(GL_SMOOTH);
    glClearColor(0, 0, 0, 0);
    glClearDepth(1.0);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}

void NeheWidget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
}

void NeheWidget::resizeGL(int width, int height)
{
    if(height == 0)
    {
        height = 1;
    }

    glViewport(0, 0, static_cast<GLint>(width),
               static_cast<GLint>(height));
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0,
                static_cast<GLdouble>(width) / static_cast<GLdouble>(height),
                0.1, 100.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void NeheWidget::keyPressEvent(QKeyEvent *event)
{
    switch(event->key())
    {
    case Qt::Key_F2:
        isFullScreen = !isFullScreen;
        if(isFullScreen)
        {
            showFullScreen();
        }
        else
        {
            showNormal();
            setGeometry(winStartX, winStartY, winWidth, winHeight);
        }
        updateGL();
        break;
    case Qt::Key_Escape:
        close();
        break;
    }
}

