#include "parameter_house.h"
#include "common_polyline.h"

std::vector<CGPoint<GLint>> ParameterHouse::generateChimney()
{
    std::vector<CGPoint<GLint>> points;

    GLdouble k = (3.0 * static_cast<GLdouble>(height) / 8.0) /
            (static_cast<GLdouble>(width) / 2.0);

    GLint x = peak.getX() - 3 * width / 8;
    GLint y = static_cast<GLint>(k * (x - peak.getX()) + peak.getY());
    points.push_back(CGPoint<GLint>(CGType::GL_INT_T,
                     x, y));
    points.push_back(CGPoint<GLint>(CGType::GL_INT_T,
                     x, peak.getY()));

    x = peak.getX() - width / 8;
    points.push_back(CGPoint<GLint>(CGType::GL_INT_T,
                     x, peak.getY()));


    y = static_cast<GLint>(k * (x - peak.getX()) + peak.getY());
    points.push_back(CGPoint<GLint>(CGType::GL_INT_T,
                     x, y));

    return points;
}

std::vector<CGPoint<GLint>> ParameterHouse::generateShell()
{
    std::vector<CGPoint<GLint>> points;

    points.push_back(CGPoint<GLint>(CGType::GL_INT_T,
                     peak.getX(), peak.getY()));
    points.push_back(CGPoint<GLint>(CGType::GL_INT_T,
                     peak.getX() + width / 2,
                     peak.getY() - 3 * height / 8));
    points.push_back(CGPoint<GLint>(CGType::GL_INT_T,
                     peak.getX() + width / 2,
                     peak.getY() - height));
    points.push_back(CGPoint<GLint>(CGType::GL_INT_T,
                     peak.getX() - width / 2,
                     peak.getY() - height));
    points.push_back(CGPoint<GLint>(CGType::GL_INT_T,
                     peak.getX() - width / 2,
                     peak.getY() - 3 * height / 8));

    return points;
}

std::vector<CGPoint<GLint>> ParameterHouse::generateDoor()
{
    std::vector<CGPoint<GLint>> points;

    points.push_back(CGPoint<GLint>(CGType::GL_INT_T,
                     peak.getX() - 3 * width / 8,
                     peak.getY() - height));
    points.push_back(CGPoint<GLint>(CGType::GL_INT_T,
                     peak.getX() - 3 * width / 8,
                     peak.getY() - height / 2));
    points.push_back(CGPoint<GLint>(CGType::GL_INT_T,
                     peak.getX() - width / 8,
                     peak.getY() - height / 2));
    points.push_back(CGPoint<GLint>(CGType::GL_INT_T,
                     peak.getX() - width / 8,
                     peak.getY() - height));

    return points;
}

std::vector<CGPoint<GLint>> ParameterHouse::generateWindow()
{
    std::vector<CGPoint<GLint>> points;

    points.push_back(CGPoint<GLint>(CGType::GL_INT_T,
                     peak.getX() + width / 8,
                     peak.getY() - 5 * height / 8));
    points.push_back(CGPoint<GLint>(CGType::GL_INT_T,
                     peak.getX() + width / 8,
                     peak.getY() - height / 2));
    points.push_back(CGPoint<GLint>(CGType::GL_INT_T,
                     peak.getX() + width / 4,
                     peak.getY() - height / 2));
    points.push_back(CGPoint<GLint>(CGType::GL_INT_T,
                     peak.getX() + width / 4,
                     peak.getY() - 5 * height / 8));

    return points;
}
void ParameterHouse::draw()
{
    // draw the door
    CGPolyLine<GLint> polyLineShell(CGType::GL_INT_T, generateShell(),
                               true);
    polyLineShell.draw();

    // draw the chimney
    CGPolyLine<GLint> polyLineChimney(CGType::GL_INT_T, generateChimney(),
                               false);
    polyLineChimney.draw();


    // draw the door
    CGPolyLine<GLint> polyLineDoor(CGType::GL_INT_T, generateDoor(),
                               false);
    polyLineDoor.draw();

    // draw the window
    CGPolyLine<GLint> polyLineWindow(CGType::GL_INT_T, generateWindow(),
                               true);
    polyLineWindow.draw();
}
