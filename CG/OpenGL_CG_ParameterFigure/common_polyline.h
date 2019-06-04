#ifndef COMMON_POLYLINE_H
#define COMMON_POLYLINE_H

#include <vector>
#include <fstream>
#include <GL/gl.h>
#include "common_type.h"
#include "common_point.h"

template<class T>
class CGPolyLine
{
public:
    CGPolyLine(CGType::DataType type,
                std::vector<CGPoint<T>> points,
                bool isClosed);
    std::vector<CGPoint<T>> getPoints() const;
    void draw() const;
    void drawFromFileStream(std::fstream &pointsStream);
private:
    void drawInt() const;
    void drawDouble() const;
private:
    std::vector<CGPoint<T>> points;
    CGType::DataType type;
    bool isClosed;
};

template<class T>
CGPolyLine<T>::CGPolyLine(CGType::DataType type,
               std::vector<CGPoint<T>> points,
               bool isClosed)
            : points(points), type(type),
              isClosed(isClosed)
{}

template<class T>
void CGPolyLine<T>::draw() const
{
    switch(type)
    {
    case CGType::GL_INT_T:
        drawInt();
        break;
    case CGType::GL_DOUBLE_T:
        drawDouble();
        break;
    }
}

template<class T>
void CGPolyLine<T>::drawInt() const
{
    typename std::vector<CGPoint<T>>::const_iterator citer;

    if(isClosed)
    {
        glBegin(GL_LINE_LOOP);
    }
    else
    {
        glBegin(GL_LINE_STRIP);
    }
    for(citer = points.begin(); citer != points.end(); ++citer)
    {
        glVertex2i(citer->getX(), citer->getY());
    }
    glEnd();
}

template<class T>
void CGPolyLine<T>::drawDouble() const
{
    typename std::vector<CGPoint<T>>::const_iterator citer;

    if(isClosed)
    {
        glBegin(GL_LINE_LOOP);
    }
    else
    {
        glBegin(GL_LINE_STRIP);
    }
    for(citer = points.begin(); citer != points.end(); ++citer)
    {
        glVertex2d(citer->getX(), citer->getY());
    }
    glEnd();
}

template<class T>
std::vector<CGPoint<T>> CGPolyLine<T>::getPoints() const
{
    return points;
}

template<class T>
void CGPolyLine<T>::drawFromFileStream(std::fstream &pointsStream)
{
    GLint pointsNum;
    T x, y;

    pointsStream >> pointsNum;
    if(isClosed)
    {
        glBegin(GL_LINE_LOOP);
    }
    else
    {
        glBegin(GL_LINE_STRIP);
    }
    for(GLint i = 0; i < pointsNum; ++i)
    {
        pointsStream >> x >> y;
        switch(type)
        {
        case CGType::GL_INT_T:
            glVertex2i(x, y);
            break;
        case CGType::GL_DOUBLE_T:
            glVertex2d(x, y);
            break;
        }
    }
    glEnd();
}


#endif // COMMON_POLYLINE_H
