#include "cgwidget.h"
#include "common_point.h"
#include <cstdlib>

CGWidget::CGWidget(QWidget *parent,
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

CGWidget::~CGWidget()
{}

void CGWidget::initializeGL()
{
    // without this method, will be cracked because of
    // runtime exception
    initializeOpenGLFunctions();

    glClearColor(1.0, 1.0, 1.0, 0.0);
    glColor3f(0.0f, 0.0f, 0.0f);
    glPointSize(4.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, winWidth, 0.0, winHeight);
}

void CGWidget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glViewport(0, 0, winWidth, winHeight);

    sierpinski();
    glFlush();
}

void CGWidget::resizeGL(int width, int height)
{
    if(height == 0)
    {
        height = 1;
    }

    glViewport(0, 0,
               static_cast<GLint>(width),
               static_cast<GLint>(height));
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, width, 0.0, height);
    winWidth = width;
    winHeight = height;
}

void CGWidget::keyPressEvent(QKeyEvent *event)
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

void CGWidget::sierpinski() const
{
    CGPointGLint T[3] = {
        CGPointGLint(10, 10),
        CGPointGLint(300, 30),
        CGPointGLint(200, 300)
    };

    int index = random(3);

    // initial point
    CGPointGLint point = T[index];
    point.draw();

    GLint x, y;
    for(int i = 0; i < 1000; ++i)
    {
        index = random(3);
        x = (point.getX() + T[index].getX()) / 2;
        y = (point.getY() + T[index].getY()) / 2;
        point.setX(x);
        point.setY(y);
        point.draw();
    }
}

