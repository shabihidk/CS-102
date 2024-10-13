#include<iostream>
using namespace std;

class Rectangle
{
private: 
	int length;
	int width;

public:

Rectangle(int l, int w)
{	length = l;
  	width = w;
}

int getLength()
{ return length;

};

int getWidth()
{return width;	
}	
};

int main()
{
	int l,w;
	cout<< "Enter length :: ";
	cin>> l;
	
	cout<< "Enter width :: "; 
	cin >> w;
	
Rectangle rec(l,w);

cout<< "Rectangle length stored is :: " << rec.getLength() << endl;
cout<< "Rectangle width stored is ::" << rec.getWidth() << endl;

return 0;
	
	
};
