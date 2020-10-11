/* Practical Assignment 3 : Singly Linked List
    Name : Annie Bhalla
    Roll No. : 19HCS4009
    Course : BSC (H) Computer Science
    Semester : 3
*/

#include<iostream>
using namespace std;

class node
{
    public:
        int ele;
        node *next;
  
      friend class LinkedList;
       
};

class LinkedList
{
    node *head,*tail;
    public:
    LinkedList(){                                    // constructor
        head=NULL;
        tail=NULL;
    }
    ~LinkedList(){                                   // destrcutor
	   	node* p= head;
			while(head!=NULL)
     		{
				p=head;
				head=head->next;
				delete p;	
			}
			tail=NULL;
	   	}
	   	
        bool empty() const;                                 //1
        void insert_front(int x);                           //2
        void remove_front();                                //3
        void insert_pos(int pos,int x);                     //4
        void remove_pos(int pos);                           //5
        node* search(int x);                                //6
         int count();                                       //7
        void concatenation(LinkedList& obj);                //8
        void insert_end(int x);							    //9
        void remove_end();							     	//10
        void reverse();					                	//11
         friend ostream& operator<<(ostream&,const LinkedList&);   //12
         const int& front() const;                          // 13
          
                                             
};


// (1) function to determine whether the list in empty or not
bool LinkedList::empty() const                              
{
    if(head==NULL)
    return 1;
    else
    return 0;
}

// (2) function to insert an element in the beginning of the list
void LinkedList::insert_front(int x)                           
{

    node *n=new node;
        n->ele=x;
        n->next=head;
        head=n;
        if(tail==NULL)
          tail=n;
        
}

// (3) function to remove the head element or beginning element in the list
void LinkedList::remove_front()                             
{
	if(empty()){
		cout<<"\n Empty List . Deletion Not possible "<<endl<<endl;
		return;
		}
	     node *old=head;
        head=old->next;
        delete old;
        if(head==NULL)
        tail==NULL;
}

// (4) functiont to insert an element at a given position in the list
void LinkedList::insert_pos(int pos,int e)       
{
    
    node *n= new node;
      n->ele=e;
      
      if(pos==1)
      {
      	n->next=head;
      	head=n;
      	tail=n;
      	return;
      	  }
      	  node *ptr= head;
      	  int count=1;
      	  while(ptr!=NULL && count<pos-1)
      	  {
      	  	ptr=ptr->next;
      	  	count++;
		}
		if(ptr==NULL)
		{
			cout<< "\n Invalid position ";
			return;
		}
			n->next=ptr->next;
			ptr->next=n;
    
}


// (5) function to remove an element from given position in the list
void LinkedList::remove_pos(int pos)                
{
    
      node *n=head;
        if(head==NULL) 
		{
		cout<<"Not possible ";
        return;
       }
        if(pos==1)
        {
        	node *old=head;
        	head=old->next;
        	delete old;
        	tail=NULL;
        	return;
		}
        
        int count=1;
        while(n!=NULL && count<pos-1){
            n=n->next;
            count++;
            }
           if(n==NULL)
		   cout<<"\n Invalid position ";
		   else
		   {
		   	node *old=n->next;
		   	n->next=old->next;
		   	delete old;
			} 
        
    }
    
    
    // (6) function to search for an element in the list
    node* LinkedList::search(int e){                
        node *n=head;
        while(n!=NULL){
            if(n->ele==e)
                return n;
            n=n->next;
        }
        return n;
      
}



// (7) function that returns the number of nodes in a list
int LinkedList::count()                                
{
      int ctr=1;
    node *ptr=head;
    while(ptr->next!=NULL)
    {
        ptr=ptr->next;
        ctr++;
    }

    return ctr;
}





// (8) function to concatenate two singly linked lists
void LinkedList:: concatenation( LinkedList& n1)  
{
        tail->next= n1.head; 
		tail=n1.tail;  
        n1.head=NULL;
        n1.tail=NULL;
}




// (9) function to add elements in the ned of the list
void LinkedList:: insert_end(int x)
{
	if(empty())
	{
		node *p =new node;
		p->ele=x;
		p->next=NULL;
		head=p;
		tail=p;
		return;
	}
	node *ptr,*arrow;
	ptr= new node;
	ptr->ele=x;
	ptr->next=NULL;
	arrow=head;
	while(arrow->next!=NULL)
	{
		arrow=arrow->next;
	}
	arrow->next=ptr;
	tail=ptr;	
}

// (10) function to remove elemenets from the end
void LinkedList::remove_end()
{
	if(empty())
	{
		cout<<"\n Empty list";
		return;
	}
	
	if(count()==1)
	{
		node *i=head;
		head= NULL;
		tail= NULL;
		delete i;
		return;
	}
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

//(11) function to reverse the singly linked list 
void LinkedList::reverse()
{
	if(empty())
	{
	  cout<<"\n Empty List ";
	 return;
	 }
	 node *p=head;
	 node *p1=head->next;
	 if(p1==NULL)
	 	return;
	 
	 while(p1!=NULL)
	 {
	   node *p2 =p1->next;
	 	p1->next=p;
	 	p=p1;
	 	p1=p2;
	 }
	 head->next=NULL;      // to break link between original first two elements
	 tail=head;
	 head=p;
	 
}

// (12) Overlaoding output operator <<
ostream& operator<<(ostream& out,const LinkedList& L)
{
	if(L.head==NULL)
	{
		out<<"\n Empty list ";
		return out;
	}
	
	else
	{         
        node *n=L.head;
        int a;
        while(n!=NULL){
            a=n->ele;
            out<<a<<" ";
            n=n->next;
        }
        return out;
    }
}

// (13) function that returns the element at the head of list
const int& LinkedList::front() const
{
	if(head==NULL) throw" Empty List";
	return head->ele;
}


// driver  code
int main()
{
	
    LinkedList l1;
    l1.remove_front();
    l1.insert_front(10);
    l1.insert_front(9);
    l1.insert_front(7);
    l1.insert_pos(2,8);
    cout<<l1;
    cout<<endl;
    
   LinkedList l2;
    l2.insert_front(1);
    l2.insert_pos(2,2);
    cout<<l2;
    
    cout<<endl<<"\n Number of nodes in L2 "<<l2.count();
    cout<<endl;
    
    cout<<"\n Result after concatenation "<<endl;
    l1.concatenation(l2);
    cout<<l1;
    cout<<endl;
    cout<<l2;
    cout<<endl;
    cout<<"\n Removing elements from l1 "<<endl;
    l1.remove_front();
   l1.remove_pos(3);
    cout<<l1;
    cout<<endl;
    
    cout<<"\n Searching element in L2 ";
    node *ptr=l2.search(2);
    if(ptr==NULL)
    cout<<"\n Not found ";
    else
   cout<<"\n "<<"2 Found at location "<<ptr;
   
   cout<<endl<<endl;
   
   
   l1.insert_end(0);
   cout<<l1;
   cout<<"\n Displaying after reversing "<<endl;
   l1.reverse();
   cout<<l1;
   
    
    return 0;
    
    
}
