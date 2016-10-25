#include "Rectangle2D.h"

Rectangle2D::Rectangle2D()
{
	x = 0;
	y = 0;
	width = 1;
	height = 1;
}

Rectangle2D::Rectangle2D(double x, double y, double width, double height)
{
	this->x = x;
	this->y = y;

	if (width >= 0) this->width = width;
	else this->width = 1;

	if (height >= 0) this->height = height;
	else this->height = 1;

}

double Rectangle2D::getArea() const
{
	// Calculate and return the area.
	return (width*height);
}

double Rectangle2D::getPerimeter() const
{
	// Calculate and return the perimeter.
	return (width * 2 + height * 2);
}

bool Rectangle2D::contains(double x, double y) const
{
	
	// If the point's x and y values are bound by the rectangle considering its x, y, width and height values, return true.  Else return false.	
	if (x > this->x && x < this->x + width) {
		return (y > this->y && y < this->y + height);
	}
	else return false;

}

bool Rectangle2D::contains(const Rectangle2D & r) const
{
	bool containsVertex[4]; // An array to keep track of how many verticies or rectangle "r" are contained by the rectangle calling the function.
	
	// Check each of the vertices of rectangle "r" to see if they lie within the rectangle calling the function.  Utilizes the "contains" function for a point.

	containsVertex[0] = contains(r.getX(), r.getY());
	containsVertex[1] = contains(r.getX() + r.getWidth(), r.getY());
	containsVertex[2] = contains(r.getX(), r.getY() + r.getHeight());
	containsVertex[3] = contains(r.getX() + r.getWidth(), r.getY() + r.getHeight());

	// If each of the vertices is contained by the rectangle calling the function, return true.  Else return false.
	return (containsVertex[0] && containsVertex[1] && containsVertex[2] && containsVertex[3]);
}

bool Rectangle2D::overlaps(const Rectangle2D & r) const
{
	// First, check to see if rectangle "r" is contained by the rectangle calling the function.  If it is, they cannot overlap and the function returns false.
	if (contains(r)) return false;

	bool containsVertex[4]; // An array to keep track of how many verticies or rectangle "r" are contained by the rectangle calling the function.

	// Check each of the vertices of rectangle "r" to see if they lie within the rectangle calling the function.  Utilizes the "contains" function for a point.

	containsVertex[0] = contains(r.getX(), r.getY());
	containsVertex[1] = contains(r.getX() + r.getWidth(), r.getY());
	containsVertex[2] = contains(r.getX(), r.getY() + r.getHeight());
	containsVertex[3] = contains(r.getX() + r.getWidth(), r.getY() + r.getHeight());

	// If at least one of the vertices is contained by the rectangle calling the function, return true.  Else return false.
	return (containsVertex[0] || containsVertex[1] || containsVertex[2] || containsVertex[3]);

}

double Rectangle2D::getX() const
{
	return x;
}

void Rectangle2D::setX(double x)
{
	this->x = x;
}

double Rectangle2D::getY() const
{
	return y;
}

void Rectangle2D::setY(double y)
{
	this->y = y;
}

double Rectangle2D::getWidth() const
{
	return width;
}

bool Rectangle2D::setWidth(double width)
{
	if (width > 0) {
		this->width = width;
		return true;
	}
	else return false;
}

double Rectangle2D::getHeight() const
{
	return height;
}

bool Rectangle2D::setHeight(double height)
{
	if (height > 0) {
		this->height = height;
		return true;
	}
	else return false;
}
