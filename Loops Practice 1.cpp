#include<iostream>
using namespace std;

int main()
{
	int **array = new int*[3];
	
	
for (int x; x <3 ; x++)	
	{ for (int i; i< 3; i++)
		{ cin >> array[x][i]; 
		}
	}

cout << "Array is :: "<< endl; 

for (int x; x <3 ; x++)	
	{ for (int i; i< 3; i++)
		{ cout << array[x][i] << endl; 
		}
	}

for (int x = 0; x < 3; x++) {
        delete[] array[x];
    }
delete array;

return 0;
} 
