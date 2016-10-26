#include "Course.h"
#include <iostream>
using namespace std;

/// The following code (unless stated otherwsie) comes from page 441 and pages 446-447 of our textbook.  
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

Course::Course(const Course &course)
{
	courseName = course.courseName;
	numberOfStudents = course.numberOfStudents;
	capacity = course.capacity;
	students = new string[capacity];

	/// CODE ADDED BY ME STARTS HERE

	// Put all student names from the parent object into the newly created object
	for (int i = 0; i < numberOfStudents; i++) {
		students[i] = course.students[i];
	}

	/// CODE ADDED BY ME STOPS HERE


}

string Course::getCourseName() const
{
	return courseName;
}

void Course::addStudent(const string & name)
{
	/// CODE ADDED BY ME STARTS HERE

	// Check to see if adding another student would exceed the array's capacity, and expand the array if it would.
	if (numberOfStudents == capacity) {

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

	/// CODE ADDED BY ME STARTS HERE

	bool finished = false; // A variable to keep track of whether or not the entire array of students has been checked.
	int droppedID = 0; // A variable to determine the index of the last dropped student.

	// Run the loop until all students have been checked.
	while (!finished){

		// Search the array students for any students with the name to drop.
		for (int i = droppedID; i < numberOfStudents; i++) {

			// Check to see if the for loop is on its last instance and the while loop should be terminated.
			if (numberOfStudents - 1 == i) {
				finished = true;
				droppedID = numberOfStudents;
			}

			// Check to see if a given student has the name to be dropped.  If they do, record the array index, decrement NumberOfStudents, and exit the for loop to readjust the array.
			if (students[i] == name) {
				droppedID = i;
				numberOfStudents--;
				break;
			}

		}


		// Move all students above the dropped student down 1 position in the array, effectively removing the student.
		for (int i = droppedID; i < numberOfStudents; i++) {
			students[i] = students[i + 1];
		}

	}

}

void Course::clear()
{

	// Reset numberOfStudents to 0 to effectively drop all students.  The array does not need to be altered because it will just be overwritten as new students are added.
	numberOfStudents = 0;

}

/// CODE ADDED BY ME STOPS HERE

string * Course::getStudents() const
{
	return students;
}

int Course::getNumberOfStudents() const
{
	return numberOfStudents;
}

/// THE FOLLOWING CODE WAS ADDED BY ME
void Course::printRoster() const
{
	// Use a for loop to print out the names of all the students in the course.
	for (int i = 0; i < numberOfStudents; i++) {
		cout << students[i] << endl;
	}

}
