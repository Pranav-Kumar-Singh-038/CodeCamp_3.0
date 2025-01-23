#include <iostream>
using namespace std;

// Class definition
class Calculator
{
public:
    // Member functions to perform arithmetic operations
    int add(int a, int b)
    {
        return a + b; // Returns the sum of two numbers
    }

    int subtract(int a, int b)
    {
        return a - b; // Returns the difference between two numbers
    }

    int multiply(int a, int b)
    {
        return a * b; // Returns the product of two numbers
    }

    double divide(int a, int b)
    {
        if (b == 0)
        {
            cout << "Error: Division by zero!" << endl;
            return 0; // Returns 0 if denominator is 0
        }
        return (double)a / b; // Returns the quotient as a double
    }
};

class Car
{
public:
    // Member functions to perform arithmetic operations
    bool drive()
    {
        cout << "Car is driving" << endl;
        return true;
    }
};

int main()
{
    Car skoda;
    Car ferrari;
    bool val3 = ferrari.drive();
    bool val = skoda.drive();
    Calculator calc;
    Calculator pranav; // Creating an object of the Calculator class
    int num1, num2;

    // Taking input from the user
    cout << "Enter two numbers: ";
    cin >> num1 >> num2;

    // Performing operations using the Calculator object
    cout << "Sum: " << pranav.add(num1, num2) << endl;
    cout << "Difference: " << pranav.subtract(num1, num2) << endl;
    cout << "Product: " << pranav.multiply(num1, num2) << endl;
    cout << "Quotient: " << pranav.divide(num1, num2) << endl;

    return 0;
}
