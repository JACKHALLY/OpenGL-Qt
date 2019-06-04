﻿#include "cgwidget.h"
#include "common_polyline.h"
#include <fstream>
#include <vector>
#include <QDebug>

CGWidget::CGWidget(QWidget *parent,
                       const QString &title,
                       bool isFullScreen,
                       const QString &dataFile)
           : QGLWidget(parent),
             isFullScreen(isFullScreen),
             winStartX(100),
             winStartY(100),
             winWidth(640),
             winHeight(480),
             dataFile(dataFile)
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

    drawPolylineFile();
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

void CGWidget::drawPolylineFile()
{
    using std::fstream;
    using std::ios;

    fstream inStream;
    inStream.open(dataFile.toStdString().c_str(), ios::in);
    if(inStream.fail())
    {
        qDebug() << "fail to open the data file";
        return;
    }

    GLint numPloys;
    inStream >> numPloys;

    std::vector<CGPoint<GLdouble>> points;
    CGPolyLine<GLdouble> polyLines(CGType::GL_DOUBLE_T, points);
    for(int i = 0; i < numPloys; ++i)
    {
        polyLines.drawFromFileStream(inStream);
    }
    glFlush();
    inStream.close();
}

