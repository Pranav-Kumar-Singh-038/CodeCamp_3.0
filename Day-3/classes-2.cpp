#include <iostream>
#include <string>
using namespace std;

// Class definition
class Student
{
private:
    // Private data members
    string name;
    int rollNumber;
    float marks;

public:
    // Public member functions
    void setDetails(string studentName, int studentRollNumber, float studentMarks)
    {
        // Setting the values of private members
        name = studentName;
        rollNumber = studentRollNumber;
        marks = studentMarks;
    }

    void displayDetails()
    {
        // Displaying the student's details
        cout << "Student Name: " << name << endl;
        cout << "Roll Number: " << rollNumber << endl;
        cout << "Marks: " << marks << endl;
    }
};

int main()
{
    Student student1; // Creating an object of the Student class
    Student student2; // Creating an object of the Student class

    // Setting the details of the student
    student1.setDetails("John Doe", 101, 95.5);
    string name;
    int roll;
    float marks;
    cin >> name;
    cout << endl;
    cin >> roll;
    cin >> marks;

    student2.setDetails(name, roll, marks);

    // Displaying the details of the student
    cout << "Student Details:" << endl;
    student1.displayDetails();

    cout << "Student 2 Details:" << endl;
    student1.displayDetails();

    return 0;
}
