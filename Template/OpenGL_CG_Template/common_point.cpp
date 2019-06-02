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
