

#include<bits/stdc++.h>
#include<iostream>
#include<process.h>
using namespace std;

class DiagonalMatrix
{
	int n;
	int* diag;
public:
// default parameterised constructor 

	DiagonalMatrix(int size=0)
	{
		if(size<=0) throw " bad initialiser ";
		n=size;
		diag= new int[n];
	}
	
	// destructor
	
	~DiagonalMatrix()
	{
		delete[] diag;
	}
	
	DiagonalMatrix(const DiagonalMatrix& obj);
	DiagonalMatrix& Store(const int x,int i,int j);
	int Retrieve(int i,int j) const;
	friend ostream& operator<<(ostream& out,const DiagonalMatrix& m);

};

// copy constructor

DiagonalMatrix::DiagonalMatrix(const DiagonalMatrix& obj)
{
	n= obj.n;
	diag= new int[n];
	for(int i=0;i<n;i++)
	{
		obj.diag[i]= diag[i];
	}
}

// Function to store the values in the diagonal matrix and return the matrix

DiagonalMatrix& DiagonalMatrix::Store(const int x, int i , int j)
{
	if(i<1 || i>n || j<1 || j>n) throw "Out of bound exception";
	if(i!=j && x!=0) throw " Value must be zero" ;    // only digaonal elements are non zero 
	
	if(i==j)   // condition in a diagonal matrix values are stored
	  diag[i-1]=x;
	
	return(*this);
}

// function to retrieve the element from the matrix

int DiagonalMatrix::Retrieve(int i,int j) const
{
		if(i<1 || i>n || j<1 || j>n) throw "Out of bound exception";
	if(i==j) return diag[i-1];
	return 0;
}


//overloading output operator

ostream& operator<<(ostream& out,const DiagonalMatrix& ob)
{
	for(int i=1;i<=ob.n;i++)
	{
		for(int j=1;j<=ob.n;j++)
		 {
		 	if(i!=j)
		  	 	out<<"0";
		 	else
		  	 	out<<ob.Retrieve(i,j);
		}
		out<<endl;
	}
	return out;
}

// driver function

int main()
{
	try
	{
		DiagonalMatrix object1(7);
		
		for(int i=1;i<8;i++)
		   object1.Store(i,i,i);
		cout<<"Matrix is "<<endl<<object1;
		
	}
	catch(const char *str)
	{
		cout<<str;
	}
}
