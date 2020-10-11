/*  Name : Annie Bhalla
     Roll No : 19HCS4009
     Course : Bsc (H) Computer Science
     Semester : 3
     Title : Implementation of Addition of large numbers using Doubly Linked List
*/

#include<iostream>
#include<string>
using namespace std;

class node
{
	private:
	node *next;
	node *prev;
	int elem;
  public:
   friend class DLinkedList;
};

class DLinkedList
{
	private:
		node* header;
		node* trailer;

	public:
		DLinkedList();                         //1
		~DLinkedList();                        //2
		bool empty();                          //3
		void addFront(const int& e);          //4
		void addBack(const int& e);           //5
		void display();                        //6
		void add(DLinkedList& obj);            //7
		void insert(string S);                 //8
		void delFront();                       //9
		
};

// (1) Constructor

DLinkedList::DLinkedList()
{
	header= new node;
	trailer= new node;
	header->next=trailer;
	trailer->next= header;
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

// (4) to add an element in the front 

void DLinkedList::addFront(const int& e)
{
	node *p= new node;
	p->elem=e;
	p->prev= header;
	p->next= header->next;
	header->next->prev= p;
	header->next=p;
}

// (5) to add an element at the back

void DLinkedList::addBack(const int& e)
{
	node *p = new node;
	p->elem= e;
	p->next = trailer;
	p->prev= trailer->prev;
	trailer->prev->next =p;
	trailer->prev=p;
}

// (6) display function
void DLinkedList::display()
{

  if(empty())
	throw " empty list ";

	{         
        node *n=header->next;
        int a;
        while(n!=trailer){
            a=n->elem;
            cout<<a<<" -> ";
            n=n->next;
        }cout<<endl;
    }
}

// (7) adding two large numbers 

void DLinkedList::add(DLinkedList& obj)
{
	DLinkedList D;
	int carry=0,sum=0;
	if(empty() && obj.empty())
	 {
	 	cout<<"\n OOPS ! Missing Operands ";
	 	return;
	 }
	if(empty())
	  obj.display();
	 
	else
		if(obj.empty())
	 		display();
	
	else
	{
		node* a= (*this).trailer->prev;
		node* b= obj.trailer->prev;
		while( a!= header && b!= obj.header)
		{
			sum = (a->elem) + (b->elem) + carry;
			carry= sum/10000;
			D.addFront(sum%10000);
			a=a->prev;
			b=b->prev;
			sum=0;
		}
		
		if(carry!=0)
		 {
		  while( a!= header)
		   { 
		      int sum1 = a->elem +carry;
		      carry=sum1/10000;
			  D.addFront(sum1%10000);
			  a=a->prev;
		   }
		  while( b!=header)
		  {
			int sum1 = b->elem +carry;
		      carry=sum1/10000;
			  D.addFront(sum1%10000);
			  b=b->prev;
		  }
		  
		  D.addFront(carry);
    	}
       D.display();
	}
	 	
}


// (8) to convert the string into a DLL

void DLinkedList::insert(string S)
{
    int k=S.length()-1;
    
    while(k>=0)
    {
    	int j=1,t=0, val=0;
    	while(k>=0 && t<4)
    	{
    		val= val + (S[k]- 48) * j;
    		j= j*10;
    		t++;
    		k--;
   		}
   		
   		addFront(val);
	}
	
	display();

}

// (9 ) delete the elements from the fron
void DLinkedList::delFront()
{
	if( empty() )  throw " Empty list ";
	
	node *p= header->next;
	header->next = p->next;
	p->next->prev = p->prev;
	delete p;
}

// driver  code

int main()
{
	string s1;
	string s2;
	DLinkedList D1,D2,D3,D4;
	cout<<"\n Enter the first number : "<<endl;
	cin>>s1;
	D1.insert(s1);
	cout<<"\n Enter the second number : "<<endl;
	cin>>s2;
	D2.insert(s2);
	
	cout<<endl<<" ************ SUM ************* "<<endl;
	D1.add(D2);
	D3.add(D4);            
	return 0;
	
}







