////////////////
// Ben Morledge-Hampton
// Homework 4
// CS 172-1
// 10/25/2016
////////////////

// Pre-Processor Directives 
#include "Rectangle2D.h"
#include <iostream>
using namespace std;


// Main function

int main() {

	// Create four Rectangle2D objects as per the book's instructions (and one of my own).

	Rectangle2D* r1 = new Rectangle2D(2, 2, 5.5, 4.9);
	Rectangle2D* r2 = new Rectangle2D(4, 5, 10.5, 3.2);
	Rectangle2D* r3 = new Rectangle2D(3, 5, 2.3, 5.4);
	Rectangle2D* r4 = new Rectangle2D(3, 3, 2, 2);


	// Perform a variety of tests on the rectanbgles as instructed by the book + some of my own to double check that functions are working as expected.

	// Check display of area and perimeter
	cout << "Area of r1: " << r1->getArea() << endl;
	cout << "Perimeter of r1: " << r1->getPerimeter() << endl;
	cout << endl;

	// Check contains function for a point with several points.
	cout << boolalpha << "r1 contains point (3,3): " << r1->contains(3, 3) << endl;
	cout << "r1 contains point (10, 10): " << r1->contains(10, 10) << endl;
	cout << "r1 contains point (-3, -3): " << r1->contains(-3, -3) << endl;
	cout << endl;

	// Check contains function for a rectangle with several different rectangles.
	cout << "r1 contains r2: " << r1->contains(*r2) << endl;
	cout << "r1 contains r3: " << r1->contains(*r3) << endl;
	cout << "r1 contains r4: " << r1->contains(*r4) << endl;
	cout << endl;

	// Check overlaps function for a rectangle with several different rectangles.
	cout << "r1 overlaps r2: " << r1->overlaps(*r2) << endl;
	cout << "r1 overlaps r3: " << r1->overlaps(*r3) << endl;
	cout << "r1 overlaps r4: " << r1->overlaps(*r4) << endl;
	cout << endl;


	// Delete memory allocated to the heap.

	delete r1;
	delete r2;
	delete r3;
	delete r4;

	// End function.  Everything is ok!
	return 0;

}