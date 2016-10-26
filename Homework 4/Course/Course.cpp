#include "Course.h"

/// The following code (unless stated otherwsie) comes from page 441 of our textbook.  
/// I'm assuming it's okay to copy it verbatum because the exercise references it directly and the bulk of the assignment deals with altering key portions of it (which I will comment on).

Course::Course(const string & courseName, int capacity)
{
	numberOfStudents = 0;
	this->courseName = courseName;
	this->capacity = capacity;
	students = new string[capacity];
}

Course::~Course()
{
	delete[]students;
}

string Course::getCourseName() const
{
	return courseName;
}

void Course::addStudent(const string & name)
{
	/// CODE ADDED BY ME STARTS HERE

	// Check to see if adding another student would exceed the array's capacity, and expand the array if it would.
	if (numberOfStudents = capacity) {

		// Allocate memory to the heap for a new array with 10 extra slots and increase the capacity variable by 10.
		string* newStudents = new string[capacity + 10];
		capacity += 10;

		// Fill the new array with all of the old values.

		for (int i = 0; i < (capacity - 10); i++) {
			newStudents[i] = students[i];
		}

		// Reclaim the memory from the old array and point the students pointer to the new array.

		delete[] students;
		students = newStudents;

	}

	/// CODE ADDED BY ME STOPS HERE

	students[numberOfStudents] = name;
	numberOfStudents++;
}

void Course::dropStudent(const string & name)
{

}

string * Course::getStudents() const
{
	return students;
}

int Course::getNumberOfStudents() const
{
	return numberOfStudents;
}
