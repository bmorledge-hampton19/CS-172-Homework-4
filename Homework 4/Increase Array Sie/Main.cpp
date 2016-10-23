////////////////
// Ben Morledge-Hampton
// Homework 4
// CS 172-1
// 10/25/2016
////////////////

// Pre-Processor Directives
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;


// For an array of a given size, have the user input a value for each index.
void readIntoArray(int* anArray, int size) {

	// Use a for loop to run through the array and assign a value for every index.
	for (int i = 0; i < size; i++) {

		cout << "Enter number " << i + 1 << ": ";
		cin >> anArray[i];

	}

	cout << endl;

}


// Given an array and its size, return a new array that is twice that size, filling new spots with 0's and 1's randomly.  Takes size as pass by value in order to double it in the process.
int* doubleCapacity(const int* list, int& size) {
	
	int* doubledList = new int[size * 2]; // Allocate memory to the heap for the new doubled array.

	// Insert the values from the orignal array into the new array with a for loop.
	for (int i = 0; i < size; i++) {
		doubledList[i] = list[i];
	}

	// Randomly insert one's and zero's into the other empty spots of the array.
	for (int i = size; i < 2 * size; i++) {
		doubledList[i] = rand() % 2;
	}

	// Delete the old array, update size, and return the doubled array!
	delete[] list;
	size *= 2;
	return doubledList;

}


// Main function
int main() {

	srand(static_cast<unsigned int>(time(NULL)));

	int arraySize; // The size of the array, to be provided by the user.
	int* myArray; // The pointer for the array to be created.

	// Prompt the user for the size of the array, and then allocate that size to the array.
	cout << "How many numbers do you want in your Array? ";
	cin >> arraySize;
	myArray = new int[arraySize];


	// Have the user put values into the array.
	readIntoArray(myArray, arraySize);

	// Double the array's size.
	myArray = doubleCapacity(myArray, arraySize);


	// Print out the array's variables to make sure the doubling worked.
	cout << "Here are the new values for your array: " << endl;
	for (int i = 0; i < arraySize; i++) {
		cout << "  " << i + 1 << ": " << myArray[i] << endl;
	}
	cout << endl;

	// Don't forget to delete the array now that we're done!
	delete[] myArray;

	// End function.  Everything is ok.
	return 0;

}