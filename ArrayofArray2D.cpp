#include<iostream>
using namespace std;

class Array2D
{
	int rows,cols;
	int** element;
public:
	Array2D(int r=0,int c=0);
	Array2D(const Array2D& m);
	~Array2D();
	int& operator()(int i,int j) const;
	friend istream& operator>>(istream& in, Array2D&);
	friend ostream& operator<<(ostream& out,Array2D&);
	int Rows()const
	{
		return rows;
	}
	int Cols()const
	{
		return cols;
	}
	

	
};

// Parameterised constructor to allocate memory to array of array of int
Array2D::Array2D(int r,int c)
{
	if(r<=0 || c<=0) throw "bad initialisers";
		rows=r;
		cols=c;
		element = new int*[r];
		for(int i=0;i<r;i++)
		{
			element[i]= new int[c];
		}
}

// copy constructor

Array2D::Array2D(const Array2D& m)
{
	rows= m.Rows();
	cols=m.Cols();
	element= new int*[rows];
	for(int i=0;i<cols;i++)
	{
		element[i]= new int[cols];
	}
	//to copy each element
	for(int i=0;i<rows;i++)
	{
		for(int j=0;j<cols;j++)
		{
			element[i][j]= m.element[i][j];
		}
	}
}

//destructor

Array2D::~Array2D()
{
	for(int i=0;i<rows;i++)
	delete[] element[i]; // deleting the elemenets stored in each 1d array(row)
	delete[] element;    // deleting the array of the pointers to the 1-D array
}

// overloading () operator to access the values in the 2D array
int& Array2D::operator()(int i,int j)const
{
	if(i<0 || i>=rows || j<0 || j>=cols) throw "Out Of Bound Exception";
	return element[i][j];
}


// overloading input operator
istream& operator>>(istream& in,Array2D& m)
{
	for(int i=0;i<m.Rows();i++)
	  for(int j=0;j<m.Cols();j++)
	     in>>m(i,j);
	
	return in;
		
}


//overloading output operator

ostream& operator<<(ostream& out,Array2D& m)
{
	for(int i=0;i<m.Rows();i++)
	  for(int j=0;j<m.Cols();j++)
	   out<<m(i,j);
	
	return out;
}

// driver function
int main()
{
	try
	{
		Array2D obj(2,3);
		cin>>obj;
		cout<<obj;
		Array2D obj2(3,2);
		cin>>obj2;
		cout<<obj2;	
	}
	catch(const char* str)
	{
		cout<<str;
	}
}
