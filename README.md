bool Rectangle2D::TestIntersection(Rectangle2D *rect)
{
    //Check for the distance between two rectangles 
    //check either with c or y
   /* return (abs(rect->x - x) <= (rect->width + width) / 2 ||
        abs(rect->y - y) <= (rect->height + height) / 2);*/
        
    //Or check with both x or y 
    return (abs(rect->x - x) <= (rect->width + width) / 2 &&
        abs(rect->y - y) <= (rect->height + height) / 2);
    
}

The first condition: 

//check either with x or y
    return (abs(rect->x - x) <= (rect->width + width) / 2 ||
        abs(rect->y - y) <= (rect->height + height) / 2);

Results in 404 intersections

Whereas the second condition

 //Or check with both x or y 
    return (abs(rect->x - x) <= (rect->width + width) / 2 &&
        abs(rect->y - y) <= (rect->height + height) / 2);

Results in 5 interscetions.
