﻿#include "cgwidget.h"
#include "common_line.h"
#include <cmath>
#include <limits>

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
    xRange = winWidth;
    yMax = std::numeric_limits<double>::min();
    yMin = std::numeric_limits<double>::max();
    calcYRange();

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

    CGLine<GLdouble> line(CGLine<GLdouble>::GL_DOUBLE_T);
    GLdouble x = 0.0;

    // the first point
    line.setStartX(scaleX(x));
    line.setStartY(scaleY(f(x)));
    // the second and other ponits in turn
    for(x += 0.005; x < xRange; x += 0.005)
    {
        line.setEndX(scaleX(x));
        line.setEndY(scaleY(f(x)));
        line.draw();

        line.setStartX(line.getEndX());
        line.setStartY(line.getEndY());
    }
    glEnd();
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
    xRange = width;
    calcYRange();
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
    const GLdouble shift = -scale * yMin;

    return scale * y + shift;
}

GLdouble CGWidget::f(GLdouble x) const
{
    const double PI = 3.1415926;
    return 300 - 100 * cos(2 * PI * x / 100.0) +
            30 * cos(4 * PI * x / 100.0) + 6 * cos(6 * PI * x / 100.0);
}

void CGWidget::calcYRange()
{
    GLdouble y;
    for(GLdouble x = 0.0; x < xRange; x += 0.005)
    {
        y = f(x);
        yMax = yMax > y ? yMax : y;
        yMin = yMin > y ? y : yMin;
    }
    yRange = yMax - yMin;
}
