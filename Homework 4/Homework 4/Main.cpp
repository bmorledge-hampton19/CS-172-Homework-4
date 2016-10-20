////////////////
// Ben Morledge-Hampton
// Homework 4
// CS 172-1
// 10/25/2016
////////////////

// Pre-Processor directives
#include <iostream> 
using namespace std;


// For an array of a given size, have the user input a value for each index.
void readIntoArray(int* anArray, int size) {

	// Use a for loop to run through the array and assign a value for every index.
	for (int i = 0; i < size; i++) {

		cout << "Enter number " << i << ": ";
		cin >> anArray[i];
		cout << endl;

	}

}


// For an array of a given size, compute and display the average of all of its values and how many values are greater than that average.
void greaterThanAverage(int* anArray, int size) {

	int arraySum = 0; // The sum of all of the array's values.
	double average; // The average of the array's values.
	int greaterThanAverage = 0; // The number of values in the array greater than the average.

	// Use a foor loop to find the sum of all values in the array.
	for (int i = 0; i < size; i++) {
		arraySum += anArray[i];
	}

	// Compute and display the average.
	average = arraySum / size;
	cout << "The average of your array is : " << average << endl;

	// Determine how many values are greater than the average (with a for loop) and return that number.

	for (int i = 0; i < size; i++) {
		if (anArray[i] > average) greaterThanAverage++;
	}

	cout << "You have " << greaterThanAverage << " numbers in your array that are greater than " << average << "." << endl << endl;


}

// Main function
int main() {

	int arraySize; // The size of the array, to be provided by the user.
	int* myArray; // The pointer for the array to be created.

	// Prompt the user for the size of the array, and then allocate that size to the array.
	cout << "How big do you want your array to be? ";
	cin >> arraySize;
	myArray = new int[arraySize];


	// Have the user put values into the array.
	readIntoArray(myArray, arraySize);
	
	// For the array, compute and display the average and how many numbers are greater than it.
	greaterThanAverage(myArray, arraySize);
	

	// Delete memory allocated to the heap.
	delete myArray;
	

	return 0;  // End function.  Everything is ok!
}