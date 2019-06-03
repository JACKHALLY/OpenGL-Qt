#include "cgwidget.h"
#include "common_point.h"

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

    static CGPointGLint STARS[] = {CGPointGLint(289, 190),
                                   CGPointGLint(320, 128),
                                   CGPointGLint(239, 67),
                                   CGPointGLint(194, 101),
                                   CGPointGLint(129, 83),
                                   CGPointGLint(75, 73),
                                   CGPointGLint(74, 74),
                                   CGPointGLint(20, 10)};
    for(int i = 0; i < StarsNum; ++i)
    {
        STARS[i].draw();
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

