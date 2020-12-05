/*  Name : Annie Bhalla
     Roll No : 19HCS4009
     Course : Bsc (H) Computer Science
     Semester : 3
     Title : Sorted Linked List
*/

#include<iostream>
using namespace std;

class node
{
	private :
		int data;
		node *next;
	public:
		node()
		{
		   data=0;
		   next=NULL;
		}
		node(const int x, node *n=NULL)
		{
			data=x;
			next=n;
			
		}
	friend class LinkedList;
};

class LinkedList
{
		node *head,*tail;
	protected:
		void display(node *p);
	public:
		LinkedList(): head(NULL), tail(NULL){ }     // (a) constructor
		~LinkedList();								// (b) destructor
		void insert(const int x);  	// (c) 
		void insert_front(const int x); // (c.1)
		void insert_end(const int x); // (c.2)
		void insert_middle(const int x, node *first, node* second); // (c.3)
		void remove(const int x);   // (d) 
		void remove_front(const int x); // (d.1)
		void remove_end(const int x); // (d.2)
		void remove_middle(node *f); // (d.3)
		void display()				// (e) to diplay contents
		{
			if(head==NULL)
			  throw " Function display() : Empty List ";
			display(head);
		}	
};

// (b) Destructor
LinkedList::~LinkedList()
{
		node *p=head;
			while(head!=NULL)
				{
				p=head;
				head=head->next;
				delete p;
			}
			tail=NULL;
}

// (c) to insert x in Linked List in sorted order
void LinkedList::insert(const int x)
{
	if(head==NULL)
	  {
	  	insert_front(x);
	  	return;
	  }
	
 	if( x < head->data)
	  {
	  	insert_front(x);
	  	return;
	  }
	
	node *ptr= head;
	node *ctr= head->next;
	while(ctr!=NULL)
	{
		if(x >ptr->data && x< ctr->data)
		  {
		  	insert_middle(x,ptr,ctr);
		  	return;
		  }
		ptr=ctr;
		ctr=ctr->next;	
	}
	if(ctr==NULL && x > ptr->data)
	{
		 insert_end(x);
		 return;
	}
	else
	
   throw " Function insert() : Insertion of Duplicate elements ";	 
}
// (c.1) to insert at front
void LinkedList::insert_front(const int x)                           
{
    node *n=new node(x);
        n->next=head;
        head=n;
        if(tail==NULL)
          tail=n; 
}
 

// (c.2)to insert at end 
void LinkedList::insert_end(const int x)
{
	node *ptr,*arrow;
	ptr= new node;
	ptr->data=x;
	arrow=head;
	while(arrow->next!=NULL)
	{
		arrow=arrow->next;
	}
	arrow->next=ptr;
	tail=ptr;	
}

// (c.3) to insert in between two nodes
void LinkedList::insert_middle(const int x , node *first, node *second)
{
	node *newnode= new node(x);
	newnode->next= second;
	first->next=newnode;
}

// (d) to remove x from linked List
void LinkedList::remove(const int x)
{
	node *ptr=head;
	if(ptr==NULL)
	  throw " Function Delete() : Deletion from an Empty Linked List ";
	if( x == head->data)
	{
		remove_front(x);
		return;
	}
	while(ptr!=NULL && ptr->data !=x)
	{
		ptr=ptr->next;
	}
	
	if(ptr==NULL)
	 throw " Function Delete() : Deletion of Non Existing Element ";
	 
	if(ptr->next==NULL)
	  {
	  	remove_end(x);
	  	return;
	  }
    else
		{
			remove_middle(ptr);
			return;
		}	
}

// (d.1) to remove element from front
void LinkedList::remove_front(const int x)
{
	    node *old=head;
        head=old->next;
        delete old;
        if(head==NULL)
        tail==NULL;
}

//  (d.2) to remove element from end
void LinkedList::remove_end(const int x)
{
	node *ptr,*arrow;
	ptr=head;
	arrow=head->next;
	while(arrow->next!=NULL)
	{
		ptr=ptr->next;
		arrow=arrow->next;
	}
	
	ptr->next=NULL;
		tail=ptr;
	delete arrow;
}

// (d.3) to remove element from middle
void LinkedList::remove_middle(node *f)
{
	node *ptr= head;
	while(ptr->next!=f)
         ptr=ptr->next;
    ptr->next=f->next;
    delete f;
}

// (e) to display the linked list recursively
void LinkedList::display(node* ptr)
{
	if(ptr==NULL)
	  return;
	cout<<ptr->data<<" ";
	display(ptr->next);
}

// driver fucntion
int main()
{
	try
	{
		LinkedList L;
	    int n;
		int element;
		cout<<"\n How many numbers do you wish to store in Linked List ";
		cin>>n;
		cout<<"\n Enter the elements : "<<endl;
		for(int i=0;i<n;i++)
		{
			cin>>element;
			L.insert(element);
		}
		cout<<endl;
		cout<<"\n <---------- Contents of Linked List -------------> "<<endl;
		L.display();
		cout<<endl;
		char ch;
		do
		{
			cout<<"\n Enter the element you want to delete : ";
			cin>>element;
			L.remove(element);
			cout<<"\n Element Removed Successfully : "<<endl;
			L.display();
			cout<<endl;
			cout<<"\n Do you wish to continue ? (y/n) : ";
			cin>>ch;
		}while(ch=='Y' || ch=='y');   
	}
	catch(const char *str)
	{
		cout<<"\n Exception from : "<<str;
	}
 return 0;
}
