/* Name : Annie Bhalla
   Roll No. : 19HCS4009
   Course : BSC (H) Computer Science
   Semester : 3
   Subject : Data Structures
   Title : Implementation of Queues ( circular arrays )
*/

#include<iostream>
using namespace std;

typedef int Elem;
class Queue
{
	int actual_len;
	int n;
	Elem *arr;
	int front;
	int rear;
public:
	Queue(int N=0)                                 // constructor
	{
		actual_len=N;
		arr = new Elem[N];
		front=-1;
		rear=-1;
		n=0;
	}
	int size() const;         						// 1
	bool empty() const;       						// 2
	const Elem& frontelement()const;			    // 3
	void enqueue(const Elem& e); 					// 4
	void dequeue();									// 5
	void display();									// 6
};


// (1) to return the size of the queue
int Queue::size()const
{
	return n;
}
	
// (2) to check whether queue is empty or not

bool Queue::empty()const
{
	return (n==0);
}

// (3) to return the first element in the queue

const Elem& Queue::frontelement() const
{
	if(empty()) throw " Function Front() : Empty Queue";
	return arr[front];
	
}

// (4) enqueue 

void Queue::enqueue(const Elem& e)
{
	if(size()==actual_len) throw " Function enqueue() : Queue Full ";
	if(front==-1)
	 front =0;
	rear= (rear+1)%actual_len;
		arr[rear] = e;
	n++;
}

// (5) dequeue

void Queue::dequeue()
{
	if(empty()) 
	{
	   front=-1;
	   rear=-1;
	   throw " Function dequeue() : Empty List , Cannot delete more elements";	
	}
	front = (front+1)%actual_len;
	n= n-1;
}

// (6) display queue

void Queue::display()
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
	int num;
	cout<<"\n Enter the size of the queue : ";
	cin>>num;
	try
	{
		Queue Q(num);
		cout<<"\n is empty? "<<Q.empty()<<endl;
		Q.enqueue(60);
		Q.display();
		Q.enqueue(70);
		Q.enqueue(90);
		Q.enqueue(100);
		Q.enqueue(110);
		Q.display();
		Q.enqueue(190);
		Q.display();
		Q.display();
		Q.dequeue();
		Q.display();
		Q.dequeue();
		Q.dequeue();
		Q.dequeue();
		Q.display();
		
		cout<<"\n NO. of elements "<<Q.size();
		
	
    }
catch(const char* str)
{
	cout<<"\n Exception Found at : "<<str;
}
	
	return 0;
	
}




