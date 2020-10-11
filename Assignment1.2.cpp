// binary search for sorted array
// Annie Bhalla 
// 19HCS4009


#include<iostream>
using namespace std;


int binarySearch(int size, int array[], int value)
{		
		int start=0;
		int end=size-1;
		int middle;
		
		while(start<=end )
		{
			middle = (start+end)/2;
			if(array[middle]==value)
			{
				return middle+1;
			}
			
			else if(value<array[middle])
				end=middle-1;
			
			else if(value>array[middle])
			 start = middle +1;
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
	
	int index=binarySearch(N,array,value);
	if(index==-1)
	cout<<"\n Element not found ";
	else
	cout<<"\n Element "<<value<<" found at position "<<index;
	return 0;
}
