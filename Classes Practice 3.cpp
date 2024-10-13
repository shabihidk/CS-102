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
    
    int getRows() const
    {
        return rows;
    }
    
    int getColumns() const
    {
        return columns;
    }
    
    void display() const
    { 
        cout<< "Your Matrix is " << rows << "x" << columns <<endl; 
        for (int i = 0; i < rows; i++)
        { 
            for (int j = 0; j < columns; j++)
            {  
                cout << "x "; 
            } 
            cout << endl;
        }  
    }
    
    friend void Transpose(const Matrix& Lol);
};

void Transpose(const Matrix& Lol)
{
    cout<< endl << "Your transpose is:: \n";
    cout<< "Your Matrix is " << Lol.columns << "x" << Lol.rows <<endl; 
    for (int i = 0; i < Lol.columns; i++)
    { 
        for (int j = 0; j < Lol.rows; j++)
        { 
            cout << "x "; 
        } 
        cout << endl;
    }  
}

int main()
{
    int r,c;
    cout<< "Enter rows: ";
    cin>> r;
    cout<< "Enter columns: ";
    cin>> c;
    
    Matrix Lol(r,c);
    
    Lol.display();
    Transpose(Lol);
    
    return 0;
}

