#include <iostream>
#include <string>

using namespace std;

// Structure to represent Student details
struct Student {
    int rollNumber;
    string name;
    int age;
    string address;
};

// Function that input student details
void Input(Student* students, int& index, int size) {
    if (index == size) {
        system("cls");
        cout << ":: All Student Details Have Been Stored :: " << endl;
        return;
    }
students[index].name = "";
students[index].rollNumber = 0;
students[index].age = 0;
students[index].address = "";
system("cls");
cout << "Enter name :: ";
cin >> students[index].name;
cout << "Enter roll number :: ";
cin >> students[index].rollNumber;
cout << "Enter age :: ";
cin >> students[index].age;
cout << "Enter address :: ";
cin >> students[index].address;

    index++; //increments index
}

// Function to display details with roll number
void display(Student* students, int index, int rollNumber) {
    bool found = false;
    for (int i = 0; i < index; i++) {
        if (students[i].rollNumber == rollNumber) {
    cout << "Name :: " << students[i].name << endl;
cout << "Roll Number :: " << students[i].rollNumber << endl;
    cout << "Age :: " << students[i].age << endl;
    cout << "Address :: " << students[i].address << endl;

            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Roll number does not exist in system: " << rollNumber << "." << endl;
    }
}

// Function to print names of students 14
void AgeSpecific(Student* students, int index) {
    cout << "Names of students with age 14:\n";
    for (int i = 0; i < index; ++i) {
        if (students[i].age == 14) {
    cout << students[i].name << endl;
        }
    }
}

// Function to print names of studemts even
void EvenRollNo(Student* students, int index) {
    cout << "Names of students with even roll numbers:\n";
    for (int i = 0; i < index; ++i) {
        if (students[i].rollNumber % 2 == 0) {
            cout << students[i].name << endl;
        }
    }
}

int main() {
    int size;
    cout << "Enter the number of students :: \n";
    cin >> size;
    Student* students = new Student[size]; // initialization of ptr using memory allocation
    int index = 0;

    while (index < size) {
        Input(students, index, size);
    }
cout<< "14 year olds:: \n";
AgeSpecific(students, index);
cout << endl;

cout<< "Even Roll No. \n";
EvenRollNo(students, index);
cout << endl;

int rollNumber;
cout<< endl;
cout << "Give the student roll number to display details of :: ";
cin >> rollNumber;
display(students, index, rollNumber);
cout << endl << endl << endl;

delete[] students; // deletes memory allocated to ptr
    return 0;
}

