#include "cgwidget.h"
#include "common_point.h"
#include <cmath>

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
    xRange = 4.0;
    yRange = 2.0;

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


    CGPoint<GLdouble> point(CGPoint<GLdouble>::GL_DOUBLE_T);
    for(GLdouble x = 0.0; x < xRange; x += 0.005)
    {
        point.setX(scaleX(x));
        point.setY(scaleY(f(x)));
        point.draw();
    }
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

GLdouble CGWidget::scaleX(GLdouble x) const
{
    const GLdouble scale = winWidth / xRange;
    const GLdouble shift = 0.0;

    return scale * x + shift;
}

GLdouble CGWidget::scaleY(GLdouble y) const
{
    const GLdouble scale = winHeight / yRange;
    const GLdouble shift = scale;

    return scale * y + shift;
}

GLdouble CGWidget::f(GLdouble x) const
{
    const double PI = 3.1415926;
    return -exp(-x) * cos(2 * PI * x);
}

