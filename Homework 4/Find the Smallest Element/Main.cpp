////////////////
// Ben Morledge-Hampton
// Homework 4
// CS 172-1
// 10/25/2016
////////////////


// Pre-Processor directives
#include <iostream>
using namespace std;


// Given a pointer to an array, and that array's size, return the smallest element in the array.
int smallestElement(int* list, int listSize) {

	int smallestElement = list[0]; // The smallest element that has been found so far.

								   // Use a for loop to determine the smallest element.
	for (int i = 1; i < listSize; i++) {

		if (list[i] < smallestElement) {
			smallestElement = list[i];
		}

	}

	// Return the smallest element.
	return smallestElement;

}


// Main function.
int main() {

	int bookArray[] = { 1,2,4,5,10,100,2,-22 }; // The array of integers provided by the book.

	int* myArray = new int[8]; // Array on the heap.
	int myArraySize = 8; // The size of the Array on the heap.

						 // Put the values from the book's array into myArray.  (Is this necesarry?)
	for (int i = 0; i < myArraySize; i++) {
		myArray[i] = bookArray[i];
	}


	// Display the smallest element to the screen.
	cout << "The smallest element in your array is " << smallestElement(myArray, myArraySize) << endl;


	// Free up memory allocated to the heap.
	delete[] myArray;

	// End function.  Everything is okay!
	return 0;

}
