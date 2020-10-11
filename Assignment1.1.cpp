// Linear search for unsorted array 
// Annie Bhalla 
// 19HCS4009


#include<iostream>
using namespace std;

int linearSearch(int length, int array[], int element)
{

	for(int i=0;i<length;i++)
	{
		if(element==array[i])            
		{
			return i+1;
	   }
	}
	return -1;
}

int main()
{
	int *array;
	int N;
	int value;
	cout<<"\n Enter the size of the array : ";
	cin>>N;
	array = new int[N];
	cout<<"\n Enter the elements in the array "<<endl;
	for(int i=0;i<N;i++)
	{
		cin>>array[i];
	}
	cout<<"\n Enter the value you wish to search in the array :";
	cin>>value;
	
	int index=linearSearch(N,array,value);
	if(index==-1)
	cout<<"\n Element not found ";
	else
	cout<<"\n Element "<<value<<" found at position "<<index;
	return 0;
}



