/* Name : Annie Bhalla
   Roll No. : 19HCS4009
   Course : BSC (H) Computer Science
   Semester : 3
   Subject : Data Structures
   Title : Implementation of Queues ( circular Linked List )
*/

#include<iostream>
#include "CLL.h"
using namespace std;

typedef int Elem;

class LinkedQueue
{
		CLinkedList C;
		int n;
	public:
		LinkedQueue();    // 1
		int size() const; // 2
		bool empty()const; // 3
		const Elem& front()const;  // 4
		void enqueue(const Elem& e); // 5
		void dequeue(); // 6
		void display();  // 7
};

// (1) Constructor
LinkedQueue::LinkedQueue(): C(),n(0){ };  

// (2) to get the number of elements in queue
int LinkedQueue::size()const { return n;}

// (3) to know if our queue is empty or not
bool LinkedQueue::empty()const 
{
	return (n==0);
}

// (4) to return the first element
const Elem& LinkedQueue::front()const
{
	if(empty()) throw " Exception : front of empty queue ";
	return C.front();
 } 
 
 // (5) to enqueue elements at rear
 void LinkedQueue::enqueue(const Elem& e)
{
	C.addBack(e);
	n++;
}

// (6) to dequeue elememts from front
void LinkedQueue::dequeue()
{
	if(empty()) throw " Exception : Dequeue of empty queue ";
	C.removeFront();
	n--;
}

// (7) to display the list
void LinkedQueue::display()
{
	C.display();
}

// driver code
int main()
{
	try
	{
		LinkedQueue L;
		L.enqueue(7);
		L.enqueue(5);
		L.enqueue(9);
		L.dequeue();
		L.front();
		L.display();
	}
	catch ( const char *str)
	{
		cout<<endl<<str;
	}
	return 0;
}

