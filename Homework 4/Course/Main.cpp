////////////////
// Ben Morledge-Hampton
// Homework 4
// CS 172-1
// 10/25/2016
////////////////

// Pre processor directives

#include "Course.h"
#include <iostream>
using namespace std;

// Main function
int main() {

	// Create a new course to test methods.

	Course* course1 = new Course("Cool Course", 1);

	// Add three distinct students with repeat.
	course1->addStudent("Bob");
	course1->addStudent("Billy");
	course1->addStudent("Billy");
	course1->addStudent("Brenda");
	course1->addStudent("Billy");

	// Display the roster
	cout << "Roster before drop: " << endl;
	course1->printRoster();
	cout << endl;

	// Remove the repeated student from all parts of the array.
	course1->dropStudent("Billy");

	// Display the roster
	cout << "Roster after drop: " << endl;
	course1->printRoster();
	cout << endl;

	// Deep copy course1, drop and add a student to the new course and display both.
	Course* course2 = new Course(*course1);

	course2->dropStudent("Bob");
	course2->addStudent("Ben");

	cout << "Course 1: " << endl;
	course1->printRoster();
	cout << endl;

	cout << "Course 2: " << endl;
	course2->printRoster();
	cout << endl;

	// Clear one roster and display both.

	course1->clear();

	cout << "Course 1 cleared" << endl << endl;

	cout << "Course 1: " << endl;
	course1->printRoster();
	cout << endl;

	cout << "Course 2: " << endl;
	course2->printRoster();
	cout << endl;


	// Delete the objects. Desturctors should deal with heap reclaiming within objects automatically... Right?

	delete course1;
	delete course2;


	// End function.  Everything is ok!
	return 0;

}