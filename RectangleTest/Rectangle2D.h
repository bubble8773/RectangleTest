#pragma once
class Rectangle2D
{
public: 
	float x, y;
	float width, height;

	Rectangle2D(); 

	Rectangle2D(float x, float y, float width, float height); 

	bool TestIntersection(Rectangle2D *rect);
};

