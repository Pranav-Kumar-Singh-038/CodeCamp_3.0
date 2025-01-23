#include <iostream>
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

    // Calculating the sum of the array elements
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i]; // Adding each element to the sum
    }

    // Displaying the sum
    cout << "The sum of the array elements is: " << sum << endl;

    return 0;
}
