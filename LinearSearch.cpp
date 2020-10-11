// linear search for unsorted array 
// Annie Bhalla 
// 19HCS4009

#include<iostream>
using namespace std;


class linearSearch
{
	int size;
 int *array;
public:
	linearSearch(int n=0)
	{
		if(n<0) throw " Bad initialiser";
		size=n;
		array = new int[size];
		cout<<"\n Enter the elements in the array "<<endl;
		for(int i=0;i<n;i++)
		cin>>array[i];
	}
	
	linearSearch(const linearSearch& m)
	{
		size= m.size;
		array= new int[size];
		for(int i=0;i<size;i++)
		array[i]= m.array[i];
	}
	
	~linearSearch()
	{
		delete [] array;
	}
	
	void search(int value);
	


};



void linearSearch::search( int value)
{
	bool flag=0;
	for(int i=0;i<size;i++)
	{
		if(value==array[i])            
		{
			flag=1;	
		cout<<value<<" found at position : "<<i+1;
		}
	}
	if(!flag)
	cout<<"\n The number you are searching for does not exits in the array ";
}

//driver code

int main()
{
	try
	{
		linearSearch obj(5);
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



