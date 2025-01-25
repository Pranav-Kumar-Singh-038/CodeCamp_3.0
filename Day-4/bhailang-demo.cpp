#include <iostream>
using namespace std;

// Custom names for cin and cout
#define sun_bhai cin
#define bol_bhai cout

int main() {
    int age;
    string name;

    // Taking input using sun bhai (instead of cin)
    bol_bhai << "Sun bhai, enter your name: ";
    sun_bhai >> name;

    bol_bhai << "Sun bhai, enter your age: ";
    sun_bhai >> age;

    // Output using bol bhai (instead of cout)
    bol_bhai << "\nBol bhai, your name is " << name << " and you are " << age << " years old." << endl;

    // Using another basic operation
    if (age >= 18) {
        bol_bhai << "Bol bhai, you are eligible to vote!" << endl;
    } else {
        bol_bhai << "Bol bhai, you are not eligible to vote yet!" << endl;
    }

    return 0;
}
