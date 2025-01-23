#include <iostream>
using namespace std;

// Function declaration
int addNumbers(int a, int b); // Takes two integers as input and returns their sum

int main()
{
    int num1, num2, sum;

    // Taking input from the user
    cout << "Enter the first number: ";
    cin >> num1;
    cout << "Enter the second number: ";
    cin >> num2;

    // Calling the function to calculate the sum
    sum = addNumbers(num1, num2);
    int num = 5;
    int num4 = 23;
    int sum2 = addNumbers(num, num4);
    cout << sum2 << endl;

    // Displaying the result
    cout << "The sum of " << num1 << " and " << num2 << " is: " << sum << endl;

    return 0;
}

// Function definition
int addNumbers(int a, int b)
{
    int sum;
    sum = a + b;
    return sum; // Returns the sum of two numbers
}
