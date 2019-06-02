#ifndef COMMON_POINT_H
#define COMMON_POINT_H

#include <GL/gl.h>

class CGPointGLint {
public:
    CGPointGLint(const GLint x, const GLint y);
    void draw() const;
    GLint getX() const;
    GLint getY() const;
    void setX(const GLint x);
    void setY(const GLint y);
private:
    GLint x;
    GLint y;
};

#endif // COMMON_POINT_H
