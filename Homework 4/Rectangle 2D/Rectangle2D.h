#pragma once

class Rectangle2D {

private:

	double x; // The x position of the rectangle.
	double y; // The y position of the rectangle.
	double width; // The width of the rectangle.
	double height; // The height of the rectangle.

public:

	Rectangle2D(); // Default constructor.  Sets x and y as 0 and width and height as 1.
	Rectangle2D(double x, double y, double width, double height);  // Values for width and height must be positive or they default to 1.
	
	double getArea() const; // Returns the rectangle's area.
	double getPerimeter() const; // Returns the rectangle's perimeter.

	bool contains(double x, double y) const; // Returns true if a point with the given x and y coordinates is within the rectangle.
	bool contains(const Rectangle2D &r) const; // Returns true if the given rectangle lies completely within the class's rectangle.
	bool overlaps(const Rectangle2D &r) const; // Returns true if the given rectangle overlaps the class's rectangle.

	// Basic getters and setters follow:

	double getX() const;
	void setX(double x);

	double getY() const;
	void setY(double y);

	double getWidth() const;
	bool setWidth(double width); // Will only set positive values.  Will only return true if a value was set properly.

	double getHeight() const;
	bool setHeight(double height); // Will only set positive values.  Will only return true if a value was set properly.
};