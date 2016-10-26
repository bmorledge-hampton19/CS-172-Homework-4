#pragma once

#include <string>
using namespace std;

/// The following code (unless stated otherwsie) comes from page 440 and 445 of our textbook.  
/// I'm assuming it's okay to copy it verbatum because the exercise references it the bulk of the assignment deals with altering key portions (which I will comment on).

class Course {

public:
	Course(const string& courseName, int capacity);
	~Course(); // What does that squiggle mean?  I'm not entirely sure...  Oh.  I guess it's a destructor.  That seems nifty!  Why haven't we learned about this?  Or did I just miss it...
	Course(const Course &); /// Implementation altered by me to also copy any existing students in the roster to the new object.
	string getCourseName() const;
	void addStudent(const string& name); /// Altered from original function to expand the students array if the capacity would be exceeded.
	void dropStudent(const string& name); /// Implemented by me to drop all students with a given name.
	void clear(); /// Implemented by me.  Drops all students from the course.
	string* getStudents() const; 
	int getNumberOfStudents() const;
	void printRoster() const; /// Defined and implemented by me because it helps prevent tinadvertently displaying student names in the array that aren't actually part of the course.
	

private:
	string courseName;
	string* students;
	int numberOfStudents;
	int capacity;

};