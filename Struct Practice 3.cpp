#include <iostream>
#include <string>

using namespace std;

// union kept causing error in compiler
//union EmployeeDetails
//{
//char Department2[6];
//float Salary2;
//};

// Structure to represent Employee details
struct Employee {
    string name;
    int ID;
    string department;
    float salary;


};


// Function that input employee details
void Input(Employee* empptr, int& index, int size) {
    if (index == size) {
    	system("cls");
        cout << ":: All Employee Details Have Been Stored :: " << endl;
  
        return;
    }
empptr[index].name = "";
empptr[index].ID = 0;
empptr[index].department = "";
empptr[index].salary = 0; // Initialize employee details to 0 to avoid error
system("cls");

cout << "Enter name :: ";
cin >> empptr[index].name;
cout << "Enter ID :: ";
cin >> empptr[index].ID;
cout << "Enter department :: ";
cin >> empptr[index].department;    // Input employee details from user
    
    cout << "Enter salary :: ";
    cin >> empptr[index].salary;
  
    index++; //increments index
}


// Function to display details w ID 
void display(Employee* empptr, int index, int ID) {
bool found = false;
for (int i = 0; i < index; i++) {
        if (empptr[i].ID == ID) {
cout << "Name :: " << empptr[i].name << endl;
cout << "ID :: " << empptr[i].ID << endl;
cout << "Department :: " << empptr[i].department << endl;
cout << "Salary :: " << empptr[i].salary << endl;
            
found = true;
break;
        }
    }
if (!found) {
cout << "ID does not exist in system" << ID << "." << endl;
    }
}

// Function for totals
int Total(Employee* empptr, int index, int ID)
{
int TotalSalary = 0;
for (int i = 0; i < index; i++) 
{
TotalSalary+= empptr[i].salary;
}

return TotalSalary;
}
int main() {
int size;
cout << "Enter the number of employees :: \n";
cin >> size;
  Employee* empptr = new Employee[size]; //intialization of ptr using memory allocation
int index = 0;

  while (index < size) {
        Input(empptr, index, size);
    }
int ID;
 system("cls");
 cout << "Give the employee ID to display details of :: ";
cin >> ID;
display(empptr, index, ID);
cout<<endl << endl << endl;
char jawab;
cout<< "Do you want to calculate total salary? \n";
cin>>jawab;
if (jawab == 'Y' || jawab == 'y')
{ 

cout<< "The combined total of all  Employee salaries is :: " << Total(empptr, index, size);
}
    delete[] empptr; // deletes memory allocated to ptr
    return 0;
}
