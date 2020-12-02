// Implementing Upper Traingle using 1 safe array

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class UpperTriangle
{
	int *element;
	int size;
public:
	//parameterised constructor
	UpperTriangle(int n=0)
	{
		if(n<0) throw "Bad Initialiser";
		element= new int[(n*(n+1))/2];
		size=n;	
		for(int i=0;i<n;i++)
		element[i]=0;	
	}
	
	// copy constructor
	
	UpperTriangle(const UpperTriangle& m)
	{
		size= m.size;
		int x= (size*(size+1))/2;
		element= new int[x];
		for(int i=0;i<x;i++)
		{
			element[i]= m.element[i];
		}
	}
	
	//destructor
	
	~UpperTriangle(){
		delete [] element;
	}
	
	
	UpperTriangle& store(const int val,int i,int j);
	int Retrieve(int i,int j) const;
	friend ostream& operator<<(ostream& out,const UpperTriangle& m);
		
};

// function to store variables 
UpperTriangle& UpperTriangle::store(const int val,int i, int j)
{
	if(i<1 || i>size || j<1 || j>size) throw "Out of bound exception";
	if(i>j) throw " Value must be zero" ;
	
	if(i<=j)
	{
		int k= ((j-1)*j)/2 + (i-1);
		element[k]= val;
	}
	return (*this);
}

//function to retrieve the value from the matrix

int UpperTriangle::Retrieve(int i,int j) const
{
    	if(i<1 || i>size || j<1 || j>size) throw "Out of bound exception";
    	if(i<=j)
    	{
    		int k= ((j-1)*j)/2 + (i-1);
    		return element[k];
		}
}


//overloading output operator

ostream& operator<<(ostream& out,const UpperTriangle& ob)
{
	for(int i=1;i<=ob.size;i++)
	{
		for(int j=1;j<=ob.size;j++)
		 {
		 	if(i<=j)
		  	 	out<<ob.Retrieve(i,j);
		 	else
		  	 	out<<"0";
		}
		out<<endl;
	}
	return out;
}

//driver function

int main()
{
	try
	{
		UpperTriangle obj(10);
		obj.store(1,1,1);
		obj.store(2,1,2);
		obj.store(1,2,2);
		obj.store(8,1,3);
		obj.store(9,2,2);
		obj.store(2,3,3);
		cout<<obj;
	}
	catch(const char * str)
	{
		cout<<"\n Exception Occured "<<str;
	}
}

