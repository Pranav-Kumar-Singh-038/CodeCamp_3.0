#include <iostream>
#include <string.h>
using namespace std;

int main() {
    int size;

    // Taking the size of the array as input
    cout << "Enter the size of the array: ";
    cin >> size;

    int arr[size]; // Declaring an array of user-defined size

    // Taking array elements as input
    cout << "Enter " << size << " elements of the array:" << endl;
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    // Finding the largest element in the array
    int largest = arr[0]; // Assume the first element is the largest
    for (int i = 1; i < size; i++) {
        if (arr[i] > largest) {
            largest = arr[i]; // Update largest if a bigger element is found
        }
    }

    // Displaying the largest element
    cout << "The largest element in the array is: " << largest << endl;

    return 0;
}
