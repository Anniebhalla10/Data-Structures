/*  Name : Annie Bhalla
     Roll No : 19HCS4009
     Course : Bsc (H) Computer Science
     Semester : 3
     Subject : Data Structures
     Title : Implementation of Doubly Linked List
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
		Dnode* search(const Elem& e);         //13
		void concatenate(DLinkedList& L);     //14
		
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


// (13) to search for an elemenet e and return its pointer

Dnode* DLinkedList::search(const Elem& e)
{
	Dnode* p= header->next;
	while(p!=trailer)
	{
		if(p->elem == e)
		return p;
		p=p->next;
	}
	return NULL;
}
// (14) To concatenate two doubly linked lists

void DLinkedList::concatenate(DLinkedList& L)
{
		if( empty() && L.empty())
		{
			cout<<"\n OOPS ! Both the lists are empty ";
			return;
		}
		
	if(empty())
	{
		L.display();
		return;
	}
	
	if( L.empty())
	{
		display();
		return;
	}
	
	Dnode* first= trailer->prev;
	Dnode* second= L.header->next;
	first->next= second;
	second->prev= first;
	trailer = L.trailer;
	L.header->next = trailer;
	display();
	L.display();
	
}

// driver code

int main()
{
	try
	{
		
	
	DLinkedList l1,l2,l3,l4;
      l4.addBack(111);
	 l4.addFront(98);
	 l4.addBack(99);
    l4.addBack(100); 
    l4.display();
    
    l1.addFront(7);
    l1.addFront(5);
    l1.addBack(9);
    l1.addBack(10);
    l1.addFront(3);
    l1.display();
   l1.delBack();
    l1.display();
    l1.delFront();
    l1.display();
   
    cout<<"\n Middle element at: "<<l1.middle();
    Dnode *q = l1.search(10);
    cout<<"\n Pointer of searched elemnet :";
    if(q==NULL)
    cout<<"\n Element does not exist ";
    else
     cout<<q;
     
     cout<<endl<<endl;
     l1.concatenate(l2);    
     l2.concatenate(l1);
     l2.concatenate(l3);  // both are empty
     cout<<endl;
     l1.concatenate(l4);
		}		
		catch(const char* str)
		{
			cout<<endl<<" Exception Occured : "<<str;
		}
    
    return 0;
    
	
}






 
