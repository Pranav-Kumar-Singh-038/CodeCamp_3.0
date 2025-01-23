#include <iostream>
using namespace std;

bool isEven(int number)
{
    return (number % 2 == 0); // Returns true if the remainder when divided by 2 is 0
}
int main()
{
    int num;

    // Taking input from the user
    cout << "Enter a number: ";
    cin >> num;

    // Checking if the number is even or odd using the function
    if (isEven(num))
    {
        cout << num << " is even." << endl;
    }
    else
    {
        cout << num << " is odd." << endl;
    }

    return 0;
}
