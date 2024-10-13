#include<iostream>
using namespace std;


class Matrix 
{ 
private:
	int rows;
	int columns;
	
public:
	Matrix(int r, int c)
	{
		rows = r;
		columns = c;
	
	}
	
	int getRows()
	{return rows;
	};
	
	int getColumns()
	{return columns;
	}
	
	void display()
	{ 
		cout<< "Your Matrix is " << rows << "x" << columns <<endl; 
		for (int i; i < rows; i++)
		{ for (int j; j < columns; j++)
				{  cout<<"x"; } }  
	};
	
	friend void Transpose(Matrix Lol);
};

void Transpose(Matrix Lol)
{
	
	Lol.display();
	
	cout<< endl << "Your transpose is:: \n";
		cout<< "Your Matrix is " << Lol.getColumns() << "x" << Lol.getRows() <<endl; 
		for (int i; i < Lol.getColumns(); i++)
			{ for (int j; j < Lol.getRows(); j++)
				{ cout<<"x"; }}  
};

int main()
{
	int r,c;
	cout<< "Enter rows";
	cin>> r;
	cout<< "Enter columns";
	cin>> c;
	
	Matrix Lol(r,c);
	
	Transpose(Lol);
	
	return 0;
	
}
