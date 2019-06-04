#ifndef COMMON_POINT_H
#define COMMON_POINT_H

#include <GL/gl.h>
#include "common_type.h"

template<class T>
class CGPoint {
public:
    CGPoint(CGType::DataType type = CGType::GL_INT_T,
            const T x = 0, const T y = 0);
    void draw() const;
    T getX() const;
    T getY() const;
    void setX(const T x);
    void setY(const T y);
private:
    void drawInt() const;
    void drawDouble() const;
private:
    T x;
    T y;
    CGType::DataType type;
};

template<class T>
CGPoint<T>::CGPoint(CGType::DataType type, const T x, const T y)
             :x(x), y(y), type(type)
{}

template<class T>
void CGPoint<T>::draw() const
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
void CGPoint<T>::drawInt() const
{
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
}

template<class T>
void CGPoint<T>::drawDouble() const
{
    glBegin(GL_POINTS);
    glVertex2d(x, y);
    glEnd();
}

template<class T>
T CGPoint<T>::getX() const
{
    return x;
}

template<class T>
T CGPoint<T>::getY() const
{
    return y;
}

template<class T>
void CGPoint<T>::setX(const T x)
{
    this->x = x;
}

template<class T>
void CGPoint<T>::setY(const T y)
{
    this->y = y;
}

#endif // COMMON_POINT_H
