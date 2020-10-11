// Array Insertion and Deletion

#include<iostream>
using namespace std;

class insertDel
{
	int *array;
	int size;
	int index=0;
public:
	insertDel(int n=0)
	{
		if(n<0) throw " Bad Initialiser";
		size= n;
		array = new int[size];
	}
	
	insertDel(const insertDel& m)
	{
		size= m.size;
		array= new int[size];
	}
	
	~insertDel()
	{
		delete [] array;
	}
	
	void insert(int value);
	void del();
	void display();	
};


void insertDel::insert(int value)
{
	if(index==size) throw " Reached Capacity cannot add more elements ";
	array[index]= value;
	index++;
}

void insertDel::del()
{
	if(index<=0) throw "Empty array Operation not possible ";
	cout<<"\n Deleting element at position : "<<index-1<<" with value "<<array[index-1];
	index--;
}

void insertDel::display()
{
	cout<<"\n Displaying the array "<<endl;
	for(int i=0;i<index;i++)
	cout<<array[i]<<" ";
	cout<<endl;
	cout<<"\n Reached Index :"<<index<<endl;
}



// driver function

int main()
{
	try
	{
		insertDel obj(5);
		obj.insert(10);
		obj.insert(20);
		obj.display();
	obj.del();
	obj.del();
	obj.display();
	obj.del();
	}
	catch(const char *str)
	{
		cout<<str;
	}
}
