#include <iostream>
#include <iomanip>

using namespace std;

int countOccurances(int arr[], int size, int n);
void sortArray(int arr[], int size);

int main() {
	int size = 0;
	    
	int arr[50];

	// Read in the values into an array
	cout << "Enter values ended with -1: ";
	while (size < 50) {  // Ensure value size less than 50 integers
        int value;
        cin >> value;
        if (value == -1) break; // End input on -1
        arr[size] = value;
        size++;
    }

	sortArray(arr,size);

	cout << left << setw(10) << "N" << setw(10) << "Count" << endl;
	for (int i = 0; i < size; i++) {
        if (i == 0 || arr[i] != arr[i - 1]) { // Unique value check
            int count = countOccurances(arr, size, arr[i]);
            cout << left << setw(10) << arr[i] << setw(10) << count << endl;
        }
    }

	return 0;
}

int countOccurances(int *arr, int size, int n) {
	int count = 0;
	for (int i = 0; i < size; i++) {  // If the current element matches n, increment the count
        	if (arr[i] == n) {
            count++;
        }
    }
    return count;
}

// I used bubble sort since that is covered in the text for this chapter
void sortArray(int *arr, int size) {
	int temp = 0;
	for (int i = 0; i < size - 1; i++) {
        	for (int j = 0; j < size - i - 1; j++) { // If the current element is less than the next element,
            						// swap them to sort in descending order
            		if (arr[j] < arr[j + 1]) { // Sort in descending order
                	int temp = arr[j];
                	arr[j] = arr[j + 1];
                	arr[j + 1] = temp;
            }
        }
    }

}

