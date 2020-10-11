/*  Name : Annie Bhalla
     Roll No : 19HCS4009
     Course : Bsc (H) Computer Science
     Semester : 3
     Subject : Data Structures 
     Title : Implementation of Circular Linked List
*/

#include<iostream>
using namespace std;

typedef int Elem;
class Cnode
{
  public:
	Cnode* next;
	Elem elem;
	
	friend class CircularLinkedList;
};

class CLinkedList
{
        Cnode* cursor;
	public:
	    CLinkedList();                        			// 1
	    ~CLinkedList();						  			// 2
	    bool empty();						  			// 3
	    const Elem& front() const ;				     	// 4
	    const Elem& back() const ;				  		// 5
	    void advance(); 					  			// 6
	    void addFront(const Elem& x);         			// 7
	    void addBack(const Elem& x);          			// 8
	    void addAfter(const Elem& x, const Elem& y);    // 9
	    void remove();									// 10
	    void removeFront();					      	    // 11
	    void removeBack();								// 12
	    void removeElement(const Elem& x);				// 13
	    void display();                       			// 14
	    Cnode* search(const Elem& x); 					// 15
	    void concatenate(CLinkedList& C);               // 16
	    int count();                                    // 17
	       	    	    
};

// (1) Constructor

CLinkedList::CLinkedList() : cursor(NULL) { }

// (2) Destructor

CLinkedList::~CLinkedList()
{
	while( !empty() )
	remove();
}

// (3) To check whether the list is empty or not

bool CLinkedList::empty()
{
	return ( cursor == NULL);
}

// (4) fucntion to return the element following cursor

const Elem& CLinkedList::front() const
{
	return ( cursor->next->elem);
}

// (5) to return the elemnt at cursor

const Elem& CLinkedList::back() const
{
	return (cursor->elem);
}

// (6) to advance the cursor in the circular list

void CLinkedList::advance()
{
	cursor=cursor->next;
}

// (7) to add element x in front of the list

void CLinkedList::addFront(const Elem& x)
{
	Cnode* p= new Cnode;
	p->elem= x;
	
	if(empty())
	{
		p->next = p;
		cursor=p;
	}
	else
	{
		p->next = cursor->next;
		cursor->next= p;
	}
	
}

// (8) to add element at the back of the list

void CLinkedList::addBack(const Elem& x)
{
	Cnode* newnode = new Cnode;
	newnode->elem= x;
	if( empty())
	{
		newnode->next= newnode;
		cursor= newnode;
	}
	else
	{
		newnode->next= cursor->next;
		cursor->next = newnode;
		cursor= newnode;
	}
	
}


// (9) add an element y after an element x in the list

void CLinkedList::addAfter(const Elem& x, const Elem& y)
{
	if ( empty()) throw " Function addAfter() : Empty List ";
	 
	 bool flag=0;
	Cnode* ptr = cursor->next;
	do
	{
		if ( ptr->elem == x)
		{
			flag=1;
			Cnode* newnode = new Cnode;
			newnode->elem= y;
			newnode->next= ptr->next;
			ptr->next= newnode;
		}
	}while(ptr!=cursor->next);
	if(!flag) throw " Function addAfter() : Element you are trying to find does not exist in the list ";
	
}


// (10) to remove the element following cursor

void CLinkedList::remove()
{
	Cnode* old= cursor->next;
	if( old== cursor)
	 	cursor= NULL;
	else
	  cursor->next= old->next;
	delete old;
			 
}


// (11) to remove an element from front

void CLinkedList::removeFront()
{
	if(empty())  throw " Function removeFront() : Empty List " ;
	Cnode* old = cursor->next  ;
	if( old == cursor)
	cursor= NULL;
	else
	 cursor->next = old->next;
	 delete old;
}

// (12) to remove a node from back

void CLinkedList::removeBack()
{
	if( empty()) throw " Function removeBack() : Empty List ";
	
	Cnode* old = cursor->next;
	if(old==cursor)
	 cursor= NULL;
	else
	{
		while(old->next!=cursor)  
				old=old->next;
		cursor= old;
		old= old->next;
		cursor->next = old->next;
		delete old;	
	}
}

// (13) to remove element x from list

void CLinkedList::removeElement(const Elem& x)
{
	if( empty()) throw " Function removeElement() : Empty List ";
	bool flag=0;
	
	Cnode* ptr = cursor->next;
	Cnode* q= cursor;
	do
	{
		if(ptr->elem == x)
		{
			flag=1;
			q->next = ptr->next;
			if(ptr==cursor) cursor=q;
			delete ptr;			
		}
		ptr=ptr->next;
		q=q->next;
	}while( ptr!= cursor->next);
	if(!flag)
	    throw " Function removeElement(): element not found ";
	
}

// (14) to display the list

void CLinkedList::display()
{
	if(empty()) throw " Function display(): Empty List ";
	
	cout<<endl;
	Cnode* ptr= cursor->next;
	do
	{
		cout<<ptr->elem<<" -> ";
		ptr=ptr->next;
	} while ( ptr != cursor->next);
	
}

// (15) to search an element in CLL

Cnode* CLinkedList::search(const Elem& x)
{
	if(empty()) throw " Function search() : Empty List ";
	
	
	Cnode* ptr= cursor->next;
	do
	{
		if( ptr->elem == x)
			return ptr;
			
	}while( ptr != cursor->next);
	
	return NULL;

}

// (16) to concatenate two CLL

void CLinkedList::concatenate(CLinkedList& C)
{
	if( empty() && C.empty())
	  throw " Function concatenate() : Both lists are empty ";
	  
	if( empty())
	{
		C.display();
	 	return;
	}
	
	if( C.empty())
	{
		display();
		return;
	}
	
	Cnode* first= cursor;
	Cnode* second = C.cursor->next;
	C.cursor->next = cursor->next;
	cursor= C.cursor;
	first->next=second;
	C.cursor= NULL;
	display();

	
}


// (17) to count the number of nodes in CLL

int CLinkedList::count()
{
	int count=0;
	if ( empty())
	 return 0;
	else
	  {
	  	Cnode* ptr= cursor->next;
	  	do
	  	{
	  		count++;
	  		ptr=ptr->next;
		} while( ptr!=cursor->next);
	  }
	return count;
}


// driver code

int main()
{
	try
   {
   	CLinkedList C1, C2,C3,C4;
   	
	C1.addFront(5);
	C1.addFront(4);
	C1.addFront(2);
	C1.addBack(6);
	C1.addAfter(2,3);
	C1.display();
	
	cout<<endl;
	C2.addBack(11);
	C2.addFront(10);
	C2.addFront(9);
	C2.addFront(7);
	C2.addAfter(7,8);
	
	C2.display();
	
	cout<<"\n ************** CONCATENATED LIST ****************";
	C1.concatenate(C2);
	
	int x= C1.count();
	cout<<"\n Number of nodes in Concatenated List : "<<x;
	cout<<endl;
	
	cout<<"\n Removing elements from concatenated string "<<endl;
	C1.removeFront();
	C1.display();
	cout<<endl;
	
	C1.removeBack();
	C1.display();
	cout<<endl;
	
	C1.removeElement(6);
	C1.display();
	cout<<endl;
	
	C3.concatenate(C4);
	
	
   }
	catch(const char* str)
	{
		cout<<"\n Exception Occured : "<<str;
	}
	
	
	
	return 0;
}
