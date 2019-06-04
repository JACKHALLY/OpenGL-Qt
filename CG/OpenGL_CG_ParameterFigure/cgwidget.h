#ifndef NEHEWIDGET_H
#define NEHEWIDGET_H

#include <QtOpenGL>
#include <QOpenGLFunctions>
#include <QKeyEvent>
#include <QMouseEvent>
#include <GL/glu.h>
#include <GL/gl.h>
#include <vector>
#include "common_point.h"
#include "parameter_house.h"

class CGWidget : public QGLWidget, protected QOpenGLFunctions
{
    Q_OBJECT
public:
    CGWidget(QWidget *parent = nullptr,
               const QString &title = "Nehe",
               bool isFullScreen = false);
    ~CGWidget();
    void hardwiredHouse(void);
    void addHouse(const ParameterHouse &house)
    {
        houses.push_back(house);
        updateGL();
    }
    void parameterizedHouse(const CGPoint<GLint> &peak,
                            GLint width,
                            GLint height);

protected:
    void initializeGL();
    void paintGL();
    void resizeGL(int width, int height);
    void keyPressEvent(QKeyEvent *event);
    void mousePressEvent(QMouseEvent *event);

protected:
    bool isFullScreen;
    int winStartX;
    int winStartY;
    int winWidth;
    int winHeight;

    std::vector<ParameterHouse> houses;
};

#endif // NEHEWIDGET_H
