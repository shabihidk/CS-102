#include<iostream>
#include<ctime>
#include<cstdlib>
#include<stdlib.h>

using namespace std;


int initialize(int *refptr, int limit)
{
for (int x = 0; x < limit; x++ )
{
cout<<"Enter Value for " << x + 1 << "\n "; 
cin>> *(refptr+x);
}
}	

int changevalue(int* w)
{
srand(time(NULL));

*w = rand() % 10; 
cout<< "New Limit is :: " << *w;
};


int main()
{
char question = 'y'; 
int limit;
cout<< "Enter Limit :: ";
cin>> limit;
do {
system("CLS");
int test[limit];
int * refptr;

refptr = test;

initialize(refptr, limit);
cout<<"Array is :: \n";

for (int x = 0; x < limit; x++ )
{
cout<< x + 1 << " ::  " << test[x];
cout<<endl; 
}	

cout<< "Changing Value of Limit \n ";
int *w;
w = &limit;
changevalue(w);


cout<< "\n Would you like to repeat process? \n";
cin>> question; 
} while (question == 'y'); 


return 0;	
	
}


