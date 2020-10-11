// binary search for ascending ordered array
// Annie Bhalla
// 19HCS4009

#include<iostream>
using namespace std;

class binarySearch
{
	int size;
	int *array;
	int start , end, mid;
public:
	binarySearch(int n=0)
	{
		if(n<0) throw " Bad initialiser";
		size=n;
		array = new int[size];
		cout<<"\n Enter the elements in the array "<<endl;
		for(int i=0;i<n;i++)
		cin>>array[i];
		start=0;
		end= size-1;
	}
	
	binarySearch(const binarySearch& m)
	{
		size= m.size;
		array= new int[size];
		for(int i=0;i<size;i++)
		array[i]= m.array[i];
	}
	
	~binarySearch()
	{
		delete [] array;
	}
	
	void search(int value);
	


};

void binarySearch::search( int value)
{		
		bool flag=0;
		while(start<=end && flag==0)
		{
			mid = (start+end)/2;
			if(array[mid]==value)
			{
				cout<<value<<" foudn at position : "<<mid+1;
				flag=1;
			}
			
			else if(value<array[mid])
				end=mid-1;
			
			else if(value>array[mid])
			 start = mid +1;
		}
		if(!flag)
		cout<<"\n Element does not exist in this array ";
}

//driver function

int main()
{
	try
	{
		binarySearch obj(5);
		int num;
		cout<<endl<<"Enter the value youre searching for ";
		cin>>num;
		obj.search(num);
	}
	catch(const char * str)
	{
		cout<<str;
	}
}



