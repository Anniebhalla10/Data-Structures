// Selection Sort

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
	
	// selection sort code
	int temp , min;
	for(int i=0;i<size;i++)
	{
		min=i;
		for(int j=min+1;j<size;j++)
		{
			if(arr[j]<arr[min])
			 min=j;
		}
		if(min!=i)
		{
			temp=arr[i];
			arr[i]=arr[min];
			arr[min]=temp;
		}
	}
	
	
	
	
	cout<<"\n Displaying sorted array ";
	for(int i=0;i<size;i++)
		cout<<arr[i]<<" ";	
	
}
