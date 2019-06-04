#ifndef PARAMETER_HOUSE_H
#define PARAMETER_HOUSE_H

#include <vector>
#include "common_point.h"

class ParameterHouse {
public:
    ParameterHouse(const CGPoint<GLint> &peak,
                   GLint width, GLint height)
        :peak(peak), width(width), height(height)
    {}
    void draw();
private:
    std::vector<CGPoint<GLint>> generateShell();
    std::vector<CGPoint<GLint>> generateChimney();
    std::vector<CGPoint<GLint>> generateDoor();
    std::vector<CGPoint<GLint>> generateWindow();
private:
    CGPoint<GLint> peak;
    GLint width;
    GLint height;
};

#endif // PARAMETER_HOUSE_H
