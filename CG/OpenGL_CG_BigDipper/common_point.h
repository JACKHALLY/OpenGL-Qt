#ifndef COMMON_POINT_H
#define COMMON_POINT_H

#include <GL/gl.h>

class CGPointGLint {
public:
    CGPointGLint(const GLint x, const GLint y);
    void draw() const;

    GLint getX() const
    {
        return x;
    }
    GLint getY() const
    {
        return y;
    }
private:
    GLint x;
    GLint y;
};

#endif // COMMON_POINT_H
