#include<Math.h>
#include <cstdlib>
#include "Rectangle2D.h"

using namespace std;
Rectangle2D::Rectangle2D()
{
    x = y = 0;
    width = height = 1;
}

Rectangle2D::Rectangle2D(float x, float y, float width, float height)
{
    this->x = x;
    this->y = y;
    this->width = width;
    this->height = height;
}

bool Rectangle2D::TestIntersection(Rectangle2D *rect)
{
    //Check for the distance between two rectangles 
    return (abs(rect->x - x) <= (rect->width + width) / 2 ||
        abs(rect->y - y) <= (rect->height + height) / 2);
    
}
