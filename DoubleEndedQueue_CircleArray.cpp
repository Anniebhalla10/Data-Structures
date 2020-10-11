/* Name : Annie Bhalla
   Roll No. : 19HCS4009
   Course : BSC (H) Computer Science
   Semester : 3
   Subject : Data Structures
   Title : Implementation of Double Ended Queues ( Circular Array )
*/

#include<iostream>
using namespace std;

typedef int Elem;

class DQueue
{
   Elem *arr;
   int actual_len;
   int front;
   int rear;
   int ctr;
public:
	DQueue(int );						// 1
	bool empty()const;						// 2
	int size()const;  						// 3					
	void addFront(const Elem& e);			// 4
	void addBack(const Elem& e);			// 5
	void eraseFront();						// 6
	void eraseBack();						// 7
	void display();
	
};


// (1) Constructor

DQueue::DQueue(int n=0)
{
	actual_len=n;
	arr= new Elem[n];
	front=-1;
	rear=-1;
	ctr=0;	
}

// (2) to check whether the DQ is empty

bool DQueue::empty()const
{
	return (ctr==0);
}

// (3) to return the size of the queue

int DQueue::size()const
{
	return ctr;
}

// (4) to add an element in the front

void DQueue::addFront(const Elem& e)
{
		if(size()==actual_len) throw " Function enqueue() : Queue Full ";
	if(front==-1)
	 front =0;
	rear= (rear+1)%actual_len;
		arr[rear] = e;
	ctr++;
}

// (5) to add element at the back

void DQueue::addBack(const Elem& e)
{
	if(size()==actual_len)  throw " Function enqueue() : Queue Full ";
	if(front==-1)
	front=0;
	rear= (rear+1)%actual_len;
		arr[rear] = e;
		ctr++;
}

// (6) to remove element from front

void DQueue::eraseFront()
{
	if(empty()) 
	{
	   front=-1;
	   rear=-1;
	   throw " Function dequeue() : Empty List , Cannot delete more elements";	
	}
	front = (front+1)%actual_len;
	ctr= ctr-1;
}

// (7) to remove element from back

void DQueue::eraseBack()
{
		if(empty()) 
	{
	   front=-1;
	   rear=-1;
	   throw " Function dequeue() : Empty List , Cannot delete more elements";	
	}
		if(rear==0)
			rear = actual_len-1;
		rear--;
	ctr=ctr-1;
}

// (8) display queue

void DQueue::display()
{
	if(empty()) throw " Function Display() : Empty List ";
	
	int i=front;
	while( i!= rear)
	{
		cout<<arr[i]<<" -> ";
		i = (i+1)% actual_len;
	
	}
	cout<<arr[rear];
	cout<<endl;
}

// driver code

int main()
{
	int N;
	cout<<"\n Enter the size of the queue :";
	cin>>N;
	try
	{
		DQueue D(N);
		D.addFront(5);
		D.addBack(10);
		D.addBack(15);
		D.addBack(20);
		D.display();
		D.eraseFront();
		D.display();
		D.eraseBack();
		D.display();
		cout<<"\n Number of elements : "<<D.size();
	}
	catch(const char* str)
	{
		cout<<"\n Exception Found at : "<<str;
	}
	return 0;
}
