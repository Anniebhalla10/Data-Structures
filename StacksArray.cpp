/* Name : Annie Bhalla
   Roll No. : 19HCS4009
   Course : BSC (H) Computer Science
   Semester : 3
   Subject : Data Structures
   Title : Implementation of Stacks ( Array )
*/

#include<iostream>
#include<exception>
using namespace std;


//class StackEmpty : public RuntimeException
//{
//	
//	public:
//		StackEmpty(const string& err) 
//		{
//			RuntimeException(err);
//		}
//};



		
template <typename E>
class Stack
{

	private:
		E* arr;
		int capacity;
		int t;
			enum DEFCAPACITY {cap = 10};
	
	public:
		Stack();					 				// 1
		Stack(int cap);								// 2
		int size() const;							// 3
		bool empty() const; 						// 4
		const E& top()const ;//throw(EmptyStack);	// 5
		void push(const E& elem);					// 6
		void pop() ;// throw (StackEmpty);			// 7
		void display();								// 8
			
};

// (1) Default Constructor

template <typename E>
Stack<E>::Stack() 
{
	capacity= cap;
	arr = new E[cap];
	t=-1;
}

// (2) para constructor
template <typename E>
Stack<E>::Stack(int cap) : capacity(cap),arr(new E[cap]), t(-1){}


// (3) Return size

template <typename E>
int Stack<E>::size() const
{
	return (t+1);
}

// (4) To check if stack is empty or not

template <typename E>
bool Stack<E>::empty() const
{
	return (t<0);
}

// (5) To return element at top

template <typename E>
const E& Stack<E>::top() const 
{
	if(empty()) " Function top() : STACK UNDERFLOW ";
	return (arr[t]);
}

// (6) To push an element to top of stack

template <typename E>
void Stack<E>::push(const E& elem) 
{
	if(t==capacity) throw " Function push() : STACK OVERFLOW ";
	arr[++t]=elem;
}

// (7) To pop an element out of stack

template <typename E>
void Stack<E>::pop() 
{
	if(empty()) throw " Function pop() : STACK UNDERFLOW " ;
	cout<<"\n Pop Element : "<<arr[t]<<endl;
	t--;
}


// (8) To display elements in stack

template <typename E>
void Stack<E>::display()
{
	if(empty()) throw " Function display() : STACK UNDERFLOW ";
	for(int i=t;i>=0;i--)
	{
		cout<<arr[i]<<" -> "; 
	}
	cout<<endl;
}



// Driver Code

int main()
{
	try
	{
		Stack<int> S1(4);
	S1.push(2);
	S1.push(4);
	S1.push(6);
	S1.display();
	cout<<S1.top()<<endl;
	S1.pop();
	cout<<S1.top()<<endl;
	S1.display();
	}
	catch(const char* str)
	{
		cout<<"\n Exception Found From : "<<str;
	}
	
	return 0;
}


