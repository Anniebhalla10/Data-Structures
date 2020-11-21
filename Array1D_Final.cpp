/* Aray 1d 
*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

template <class T>
class Array1D
{
		T* arr;
		int size;
	public:
		Array1D(int x=0)			// (1) Constructor
		{
			size=x;
			arr= new T[size];
		}
		
		// (2) input function
		
		void input()
		{
			cout<<"\n Enter the elements : ";
			for(int i=0;i<size;i++)
			cin>>arr[i];
		}
		
		// (3) access operator
		
		T& operator[](int i)
		{
			if(i<0 || i>size ) throw " Operator[] : Invalid Index ";
			return arr[i];
		}
		
		// (4) Addition operator
		
		Array1D& operator+(Array1D& obj)
		{
			if(size!=obj.size)
			 throw " Operator + : Invalid Operation ";
			 
			 Array1D temp(size);
			 for(int i=0;i<size;i++ )
			 {
			 	temp.arr[i]= arr[i]+obj.arr[i];
			 }
			return temp;
		}
		
		// (5) Subtraction operator
		
		Array1D& operator-(Array1D& obj)
		{
			if(size!=obj.size)
			 throw " Operator - : Invalid Operation ";
			 
			 Array1D temp(size);
			 for(int i=0;i<size;i++ )
			 {
			 	temp.arr[i]= arr[i]-obj.arr[i];
			 }
			return temp;
		}
		
		// (5) Multiplication operator
		
		Array1D& operator*(Array1D& obj)
		{
			if(size!=obj.size)
			 throw " Operator * : Invalid Operation ";
			 
			 Array1D temp(size);
			 for(int i=0;i<size;i++ )
			 {
			 	temp.arr[i]= arr[i]*obj.arr[i];
			 }
			return temp;
		}
		
		// (6) Unary - operator
		
		 Array1D& operator-()
		{
				for(int i=0;i<size;i++)
				{
					arr[i]= -(arr[i]);
				}
				return (*this);
		}
		
		// (7) equal to operator
		
		Array1D& operator=(Array1D& obj)
		{
			size= obj.size;
			arr= new T[size];
			for(int i=0;i<size;i++)
			{
				arr[i]=obj.arr[i];
			}
			return (*this);
		}
		
		template <class U>
		friend ostream& operator<<(ostream& out,const Array1D<U>& a);
		
		template <class U>
		friend istream& operator>>(istream& in , const Array1D<U>& a);

};

template <class U>
ostream& operator<<(ostream& out, const Array1D<U>& a)
{
	out<<"\n Array is : ";
        for(int i=0;i<a.size;i++)
          out<<a.arr[i]<<" ";
          return out;
}

template <class U>
istream& operator>>(istream& in, const Array1D<U>& a)
{
	for(int i=0;i<a.size;i++)
        {
            in>>a.arr[i];
        }
        return in;
}

int main()
{
	try
   {
   	Array1D<int> obj1(6), obj2(6);
   	obj1.input();
   	obj2.input();
   //	Array1D obj3=obj1;
   //	cout<<"\n Assignment operator used "<<endl<<obj3;
  	Array1D<int> obj4;
	  obj4= obj1+obj2;
 	cout<<obj4;
 	cout<<endl;
 	cout<<obj1[5];
 	cout<<endl;
	 cout<<-obj2;
	 
       
   }

   catch(const char* str)
   {
       cout<<"\n Exception Caught : "<<str;
   }
    return 0;
}
