/* Name : Annie Bhalla
   Roll No. : 19HCS4009
   Course : BSC (H) Computer Science
   Semester : 3
   Subject : Data Structures
   Title : Implementation of Tri Diagonal Matrix
*/


#include<iostream>
#include<math.h>
using namespace std;

class TridiagonalMatrix
{
	int n;
	int *value;
public:
	//parameterised constructor
	
	TridiagonalMatrix(int size=0)
	{
		if(size<=0) throw "Bad Initialiser";
			n=size;
			value= new int[3*n-2];
			for(int i=0;i<3*n-2;i++)
			   value[i]=0;	
	}	
	
	
	//destructor
	~TridiagonalMatrix()
	{
		delete [] value;
	}
	
	TridiagonalMatrix(const TridiagonalMatrix& obj);
	TridiagonalMatrix& Store(const int x,int i,int j);
	int Retrieve(int i,int j) const;
	friend ostream& operator<<(ostream& out,const TridiagonalMatrix& m);

};

//copy constructor
TridiagonalMatrix::TridiagonalMatrix(const TridiagonalMatrix& obj)
{
    n=obj.n;
    value= new int[3*n-2];
    for(int i=0;i<3*n-2;i++)
    {
    	(*this).value[i]=value[i];
	}
}

// store function to store the values in 1d array row wise , column wise and diagonal wise
TridiagonalMatrix&  TridiagonalMatrix::Store(const int x   , int i, int j)
{
	if(i<1 || i>n || j<1 || j>n) throw "Out of bound exception";
	if( abs(i-j)>1 && x!=0) throw " Value must be zero" ;

	if( abs(i-j)==1 ||  abs(i-j)==0)
	{
		int k= 2+ 3*(i-2)+j-i+1;
	
      // row wise
	 	 value[k]=x;
	 }
	 
	 // value[2+3(j-2)+i-j+1]=x   column wise
	 
	 /* Diagonal Wise
	    if(i>j && i-j=1) value[j-1]=x;
	    if(j>i && j-i=1 ) value[2n-1+i-1]=x;
	    if(i==j) value[n-1+i-1]=x;
	 */     
	 
	 return(*this);
}

// function to retrieve the value at undex i,j
int TridiagonalMatrix::Retrieve(int i,int j ) const
{
	if(i<1 || i>n || j<1 || j>n) throw "Out of bound exception";
	if(abs(i-j)==1 ||  abs(i-j)==0)
	{
		int k;
		k=2+3*(i-2)+j-i+1;
		return value[k];
	}
	return 0;
}


// overloadingoutput operator
ostream& operator<<(ostream& out, const TridiagonalMatrix& m)
{
	for(int i=1;i<=m.n;i++)
	{
		for(int j=1;j<=m.n;j++)
		 {
		 	if(abs(i-j)==1 ||  abs(i-j)==0)
		  	 	out<<m.Retrieve(i,j);
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
		TridiagonalMatrix t(9);
		t.Store(1,1,1);
		t.Store(2,2,2);
		cout<<t;
	}
	catch(const char* str)
	{
		cout<<str;
	}
}
