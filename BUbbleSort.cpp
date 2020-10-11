// Implementing Bubble Sort

#include<iostream>
using namespace std;

int main()
{
    int *arr;
	int size;
	cout<<"\ Enter the size ";
	cin>>size;
	arr= new int[size];
	cout<<"\n Enter the elements ";
	for(int i=0;i<size;i++)
	cin>>arr[i];
	
	// bubble sort code
	bool sorted=false;
	for(int i=0; !sorted && i<size ;i++)
	{
		sorted=true;
		for(int j=0;j<size-i-1;j++)
		{
			if(arr[j]>arr[j+1])
			{
				sorted= false;
				int temp= arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
	}
	
	cout<<"\n Displaying sorted array ";
	for(int i=0;i<size;i++)
		cout<<arr[i]<<" ";	
	
	
}                
