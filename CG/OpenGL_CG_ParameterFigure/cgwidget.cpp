#include <cstdlib>
#include "cgwidget.h"

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

    // hardwiredHouse();
#if 0
    // draw parameter house
    CGPoint<GLint> peak;
    peak.setX(70);
    peak.setY(120);
    parameterizedHouse(peak, 60, 80);
#endif

    for(std::vector<ParameterHouse>::iterator iter = houses.begin();
        iter != houses.end(); ++iter)
    {
        iter->draw();
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

void CGWidget::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        CGPoint<GLint> peak;
        peak.setX(event->x());
        peak.setY(winHeight - event->y());

        GLint width = rand() % 100 + 40;
        GLint height = rand() % 100 + 60;

        // whether flipped or not
        if(rand() % 2 == 0)
        {
            // even to flip
            width = -width;
            height = -height;
        }

        ParameterHouse house(peak, width, height);
        addHouse(house);
    }
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

void CGWidget::hardwiredHouse(void)
{
    // draw the shell of house
    glBegin(GL_LINE_LOOP);
    glVertex2i(40, 40);
    glVertex2i(40, 90);
    glVertex2i(70, 120);
    glVertex2i(100, 90);
    glVertex2i(100, 40);
    glEnd();

    // draw the chimney
    glBegin(GL_LINE_STRIP);
    glVertex2i(50, 100);
    glVertex2i(50, 120);
    glVertex2i(60, 120);
    glVertex2i(60, 110);
    glEnd();

    // draw the door
    glBegin(GL_LINE_STRIP);
    glVertex2i(50, 40);
    glVertex2i(50, 60);
    glVertex2i(60, 60);
    glVertex2i(60, 40);
    glEnd();

    // draw the window
    glBegin(GL_LINE_LOOP);
    glVertex2i(70, 65);
    glVertex2i(70, 75);
    glVertex2i(80, 75);
    glVertex2i(80, 65);
    glEnd();
}

void CGWidget::parameterizedHouse(const CGPoint<GLint> &peak,
                        GLint width,
                        GLint height)
{
    // draw the door
    glBegin(GL_LINE_LOOP);
    glVertex2i(peak.getX(), peak.getY());
    glVertex2i(peak.getX() + width / 2, peak.getY() - 3 * height / 8);
    glVertex2i(peak.getX() + width / 2, peak.getY() - height);
    glVertex2i(peak.getX() - width / 2, peak.getY() - height);
    glVertex2i(peak.getX() - width / 2, peak.getY() - 3 * height / 8);
    glEnd();

    // draw the chimney
    GLdouble k = (3.0 * static_cast<GLdouble>(height) / 8.0) /
            (static_cast<GLdouble>(width) / 2.0);
    glBegin(GL_LINE_STRIP);
    GLint x = peak.getX() - 3 * width / 8;
    GLint y = static_cast<GLint>(k * (x - peak.getX()) + peak.getY());
    glVertex2i(x, y);
    glVertex2i(x, peak.getY());

    x = peak.getX() - width / 8;
    glVertex2i(x, peak.getY());
    y = static_cast<GLint>(k * (x - peak.getX()) + peak.getY());
    glVertex2i(x, y);
    glEnd();

    // draw the door
    glBegin(GL_LINE_STRIP);
    glVertex2i(peak.getX() - 3 * width / 8, peak.getY() - height);
    glVertex2i(peak.getX() - 3 * width / 8, peak.getY() - height / 2);
    glVertex2i(peak.getX() - width / 8, peak.getY() - height / 2);
    glVertex2i(peak.getX() - width / 8, peak.getY() - height);
    glEnd();

    // draw the window
    glBegin(GL_LINE_LOOP);
    glVertex2i(peak.getX() + width / 8, peak.getY() - 5 * height / 8);
    glVertex2i(peak.getX() + width / 8, peak.getY() - height / 2);
    glVertex2i(peak.getX() + width / 4, peak.getY() - height / 2);
    glVertex2i(peak.getX() + width / 4, peak.getY() - 5 * height / 8);
    glEnd();
}

