// Insertion sort

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
	
	// insertion sort code
	int key=0;
	for(int j=1;j<size;j++)
	{
		 key= arr[j];
		 int i=j-1;
		 while(i>=0 && arr[i]>key)
		 {
		 	arr[i+1]=arr[i];
		 	i--;
		 }
		 arr[i+1]=key;
	}
	
	
	cout<<"\n Displaying sorted array ";
	for(int i=0;i<size;i++)
		cout<<arr[i]<<" ";	
	
}
