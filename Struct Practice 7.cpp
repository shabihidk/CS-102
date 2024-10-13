// 4. Write a structure to store the names, salary and hours of work per day of 10 employees in a company. 
// Write a program to increase the salary depending on the number of hours of

// work per day as follows and then print the name of all the employees along with their final salaries.

//Hours of work per day 8 10 >=12

// Increase in salary $50 $100 $150
#include <iostream>
using namespace std;

struct Employee {
    string Name;
    int Hours;
    int Salary;
};

void display(Employee* empptr) {
    for (int i = 0; i < 10; i++) {
        cout << "Name :: " << empptr[i].Name << endl;
        cout << "Hours :: " << empptr[i].Hours << endl;
        cout << "Salary :: " << empptr[i].Salary << endl;
        cout << "====================================== \n";
    }
}

void SalaryIncrement(Employee* empptr, int& index) {
    if (empptr[index].Hours >= 8 && empptr[index].Hours < 10) {
        empptr[index].Salary += 50;
    }
    else if (empptr[index].Hours >= 10 && empptr[index].Hours < 12) {
        empptr[index].Salary += 100;
    }
    else if (empptr[index].Hours >= 12) {
        empptr[index].Salary += 150;
    }
}

void Input(Employee* empptr, int& index) {
    if (index == 10) {
        system("cls");
        cout << ":: All Employee Details Have Been Stored :: " << endl;
        return;
    }

    system("cls");

    cout << "Enter name :: ";
    cin >> empptr[index].Name;
    cout << "Enter hours worked :: ";
    cin >> empptr[index].Hours;

    cout << "Enter salary :: ";
    cin >> empptr[index].Salary;

    index++; // increments index
}

int main() {
    Employee* empptr = new Employee[10];
    int index = 0;

    while (index < 10) {
        Input(empptr, index);
    }

    index = 0; // Reset index for SalaryIncrement
    while (index < 10) {
        SalaryIncrement(empptr, index);
        index++;
    }

    system("cls");

    cout << "Your updated employee info is ::\n";
    display(empptr);

    delete[] empptr; // Don't forget to free the allocated memory

    return 0;
}

