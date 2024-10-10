#include <iostream>
#include <string>
using namespace std;

int main() {
	string first, second;

	int added[20];
    	int carry = 0;
	
	// Get the values
	cout << "Enter the first number:";
	cin  >> first;
	cout << "Enter the second number:";
	cin  >> second;	

	// Reverse the strings for addition
    	int length1 = first.length();
    	int length2 = second.length();
    	int maxLength = max(length1, length2);

	// Convert digits to ints
	int x[first.length()], y[second.length()];

	// Add the arrays
for (int i = 0; i < maxLength; i++) {
        int digit1 = (i < length1) ? (first[length1 - 1 - i] - '0') : 0; // Get digit from first number
        int digit2 = (i < length2) ? (second[length2 - 1 - i] - '0') : 0; // Get digit from second number
        
        int sum = digit1 + digit2 + carry; // Add digits and carry
        added[i] = sum % 10; // Store the last digit of the sum
        carry = sum / 10; // Calculate carry for next iteration
}
	// Output the result
    cout << "The sum is: ";
    bool leadingZero = true; // To skip leading zeros
    for (int i = maxLength; i >= 0; i--) {
        if (added[i] != 0) {
            leadingZero = false; // Found a non-zero digit
        }
        if (!leadingZero) {
            cout << added[i]; // Print the result
        }
    }
    if (leadingZero) {
        cout << 0; // If all were zero
    }
    cout << endl;
	
	
	return 0;
}

