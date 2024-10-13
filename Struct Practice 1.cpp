#include<iostream>
using namespace std;


enum Gender 
{Male, Female};

struct Person{
	string name;
	int age; 
	Gender gen;
};

int main()
{
	Person a; 
	
	cout << "Welcome, enter your name, age and gender!\n";
	cout << "Name ::";
		cin>> a.name;
		cout << endl; 
	cout << "Age ::";
		cin>> a.age;
		cout << endl; 
	cout << "Gender (Male = 0 / Female = 1 ) ::";
		int x;
		cin >> x;
		a.gen = Gender(x);
		cout << endl; 
	

	cout<< "Data has been stored :";
	cout << "Name ::";
		cout<< a.name;
		cout << endl; 
	cout << "Age ::";
		cout<< a.age;
		cout << endl; 
	cout << "Gender (Male/Female) ::";
		if(x == 0)
			{ cout<< "Male";}
			else
			{ cout << "Female";}
		cout << endl; 
		
	
return 0;
}
