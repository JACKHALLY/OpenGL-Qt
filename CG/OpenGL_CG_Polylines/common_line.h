#ifndef COMMON_LINE_H
#define COMMON_LINE_H

#include <GL/gl.h>
#include "common_type.h"

template<class T>
class CGLine
{
public:
    CGLine(CGType::DataType type = CGType::GL_INT_T,
                T startX = 0, T startY = 0,
                T endX = 0, T endY = 0);
    T getStartX() const;
    T getStartY() const;
    void setStartX(T x);
    void setStartY(T y);
    T getEndX() const;
    T getEndY() const;
    void setEndX(T x);
    void setEndY(T y);
    void draw() const;
private:
    void drawInt() const;
    void drawDouble() const;
private:
    T startX;
    T startY;
    T endX;
    T endY;
    CGType::DataType type;
};

#include <iostream>
//#include "common_line.template"
template<class T>
CGLine<T>::CGLine(CGType::DataType type, T startX, T startY,
                         T endX, T endY)
            :startX(startX), startY(startY),
             endX(endX), endY(endY),
             type(type)
{}

template<class T>
void CGLine<T>::draw() const
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
void CGLine<T>::drawInt() const
{
    glBegin(GL_LINES);
    glVertex2i(startX, startY);
    glVertex2i(endX, endY);
    glEnd();
}

template<class T>
void CGLine<T>::drawDouble() const
{
    glBegin(GL_LINES);
    glVertex2d(startX, startY);
    glVertex2d(endX, endY);
    glEnd();
}

template<class T>
T CGLine<T>::getStartX() const
{
    return startX;
}

template<class T>
T CGLine<T>::getStartY() const
{
    return startY;
}

template<class T>
void CGLine<T>::setStartX(T x)
{
    startX = x;
}

template<class T>
void CGLine<T>::setStartY(T y)
{
    startY = y;
}

template<class T>
T CGLine<T>::getEndX() const
{
    return endX;
}
template<class T>
T CGLine<T>::getEndY() const
{
    return endY;
}

template<class T>
void CGLine<T>::setEndX(T x)
{
    endX = x;
}

template<class T>
void CGLine<T>::setEndY(T y)
{
    endY = y;
}

#endif // COMMON_LINE_H
