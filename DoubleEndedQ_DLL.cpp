/* Name : Annie Bhalla
   Roll No. : 19HCS4009
   Course : BSC (H) Computer Science
   Semester : 3
   Subject : Data Structures
   Title : Implementation of Double Ended Queues ( Doubly Linked List )
*/


#include<iostream>
using namespace std;

typedef int Elem;

class Dnode
{
	public:
	Dnode *next;
	Dnode *prev;
	Elem elem;

   friend class DLinkedList;
};

class DLinkedList
{
	private:
		Dnode* header;
		Dnode* trailer;
//	protected:
//	    void add(Dnode* v,const Elem& e);
//	    void remove(Dnode* v);
	public:
		DLinkedList();                         //1
		~DLinkedList();                        //2
		bool empty();                          //3
	    Elem& front() const;                   //4
		Elem& back() const;                    //5
		void addFront(const Elem& e);          //6
		void addBack(const Elem& e);           //7
		void delFront();                       //8
		void delBack();                        //9
		Dnode* middle() const ;                 //10
		friend ostream& operator<<(ostream& ,const DLinkedList& ); //11
		void display();                       //12
		
		
};

// (1) Constructor

DLinkedList::DLinkedList()
{
	header= new Dnode;
	trailer= new Dnode;
	header->next=trailer;
	trailer->prev= header;
 } 
 
// (2) Destructor

DLinkedList::~DLinkedList()
{
	while( !empty()) delFront();
	delete header;
	delete trailer;
}

// (3) To check whether linked list is empty

bool DLinkedList::empty()
{
	if(header->next==trailer)   
	return 1;
	else
	return 0;
}

// (4) to return the element at head

 Elem& DLinkedList::front() const
{
	if(header->next==trailer ) throw " EMPTY LIST ";
	
	return (header->next->elem);
}

// (5) to return the element at the last 

Elem& DLinkedList::back() const
{
	if( header->next==trailer) throw " EMPTY LIST ";

	return (trailer->prev->elem);
}

// (6) to add an element in the front 

void DLinkedList::addFront(const Elem& e)
{
	Dnode *p= new Dnode;
	p->elem=e;
	p->prev= header;
	p->next= header->next;
	header->next->prev= p;
	header->next=p;
}

// (7) to add an element at the back

void DLinkedList::addBack(const Elem& e)
{
	
	Dnode *p = new Dnode;
	p->elem= e;
	p->next = trailer;
	p->prev= trailer->prev;
	trailer->prev->next =p;
	trailer->prev=p;
}


// (8) to remove from front

void DLinkedList::delFront()
{
	if( empty() )  throw " Empty list ";
	
	Dnode *p= header->next;
	header->next = p->next;
	p->next->prev = p->prev;
	delete p;
}

// (9) to remove from back

void DLinkedList::delBack()
{
	if( empty() )
	
		throw " Empty list ";
	
	Dnode *p= trailer->prev;
	trailer->prev = p->prev;
	p->prev->next = p->next;
	delete p;
}

// (10) to return the middle element
 Dnode* DLinkedList:: middle()const 
{
	if(header->next==trailer) throw " Empty List ";
	
		Dnode *q= header->next; 
		Dnode *x= trailer->prev;
		while( q!=x && q->next!=x)
		{
			q=q->next;
			x=x->prev;
		}
		return q;
	
	
}


// (11) overloading output operator
ostream& operator<<(ostream& out, const DLinkedList& D)
{
	if(D.header->next==D.trailer)
	out<<" ";
	else
	{
		Dnode *p = D.header->next;
		while( p->next!=D.trailer)
		{
			out<<p->elem<<" ";
		}
	}
	return out;
}

// (12) display function
void DLinkedList::display()
{

  if(empty())
	throw " empty list ";

	{         
        Dnode *n=header->next;
        int a;
        while(n!=trailer){
            a=n->elem;
            cout<<a<<" ";
            n=n->next;
        }cout<<endl;
    }
}

class DQueue
{
   DLinkedList D;
   int ctr;
   int actual_len;
public:
	DQueue(int);						// 1
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
	D.addFront(e);
	ctr++;
}

// (5) to add element at the back

void DQueue::addBack(const Elem& e)
{
	if(size()==actual_len)  throw " Function enqueue() : Queue Full ";
	D.addBack(e);
		ctr++;
}

// (6) to remove element from front

void DQueue::eraseFront()
{
	if(empty()) 
	   throw " Function dequeue() : Empty List , Cannot delete more elements";	
	D.delFront();
	ctr= ctr-1;
}

// (7) to remove element from back

void DQueue::eraseBack()
{
		if(empty()) 
	   throw " Function dequeue() : Empty List , Cannot delete more elements";	
	D.delBack();
	ctr=ctr-1;
}

// (8) display queue

void DQueue::display()
{
	if(empty()) throw " Function Display() : Empty List ";
	D.display();
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
