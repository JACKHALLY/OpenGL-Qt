#include "common_point.h"

CGPointGLint::CGPointGLint(const GLint x, const GLint y)
             :x(x), y(y)
{}

void CGPointGLint::draw() const
{
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
    glFlush();
}

GLint CGPointGLint::getX() const
{
    return x;
}
GLint CGPointGLint::getY() const
{
    return y;
}
void CGPointGLint::setX(const GLint x)
{
    this->x = x;
}
void CGPointGLint::setY(const GLint y)
{
    this->y = y;
}
