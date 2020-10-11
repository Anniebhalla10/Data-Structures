// Linked List Implementation

class StringNode
{
	private:
		string elem;
		StringNode *next;
  public:
  	friend class LinkedList;
};

class LinkedList
{
	StringNode *head,*tail;
	public:
		LinkedList(): head(NULL) : tail(NULL){};
		~LinkedList();   
		bool empty() const;  // done
 		const string& front() const; 	  // done								
		void insert_front(const string& str);  // done
		
		void remove_front();    // done
		void insert_end(const string& str); // done
		void remove_end();     // done
		void insert_middle(int position, const string& str);     // done
		void display();  // done
		void remove_middle(int position);  // done
		void search(const string& str);      // dpne
		int count();                          // done
		void concatenation(const LinkedList& obj); // done
				
};

// function to determine whether the list in empty or not
bool LinkedList::empty()
{
	if(head->next==NULL)
	return 0;
	else
	return 1;
}

//function that returns the element at the head of list
string& LinkedList::front()
{
	if(head==NULL) throw" Empty List";
	return head->elem;
}

// function to insert an element in the beginning of the list
void LinkedList::insert_front(const string& str)
{
	StringNode *p= new StringNode;
	  p->elem=str;      
	  p->next=head; 			// head points to p 
	  if(empty())  
	    tail=p; 
	     head=p;				// p follows head 
	  											 
}

// function to remove the head element or beginning element in the list
void LinkedList::remove_front()
{
	StringNode *old=head;
	head=old->next;
	delete old;
}

// function to insert an elemet at the end of the list
void LinkedList::insert_end(const string& str)
{
	StringNode *ptr,*arrow;
	ptr= new StringNode;
	ptr->elem=str;
	arrow=head;
	while(arrow!=NULL)
	{
		arrow=arrow->next;
	}
	arrow=p;
	tail=p;
}

// function to remove an elemenet from the end of list 
void LinkedList::remove_end()
{
	if(empty())
	{
		cout<<"\n Empty list";
		return;
	}
	
	if(count()==1)
	{
		StringNode *i=head;
		head= NULL;
		tail= NULL;
		delete i;
		return;
	}
	StringNode *ptr,*arrow;
	ptr=head;
	arrow=head->next;
	while(arrow->next!=NULL)
	{
		ptr=ptr->next;
		arrow=arrow->next;
	}
	
	ptr->next=NULL:
		tail=ptr;
	delete arrow;
}

// function to display all the elements in the linked list
void LinkedList::display()
{
	if(head==NULL) cout<<"\n Empty List";
	else
	{
		StringNode *pt= head;
		while(pt!=NULL)
		{
			cout<<pt->elem<<" ";
			pt=pt->next;
		}
	}
	
}

// functiont to insert an element at a given position in the list 
void LinkedList::insert_middle(int position,const String& str)
{
	if(position>count())
	{
		StringNode *x;
		x->elem=str;
		x->next=NULL;
		tail->next=x;
		x=tail;	
		return;
	}
	
	if(position<1)
	{
		cout<<"\n Invalid position";
		return;
	}
	
	if(position==1)
	{
		insert_front(str);
		return;
	}
	
	int count=1;
	StringNode *ptr,*arrow;
	arrow=head;
	while(arrow!=NULL)
	{
		if(count==position-1)
		{
			ptr=new StringNode;
			ptr->elem=str;
			ptr->next=arrow->next;
			arrow->next=ptr;
		}
		else
		{
				arrow=arrow->next;
				count++;
		}	
	}
	
}

// function to remove an element from given position in the list
void LinkedList::remove_middle(int position)
{
	
	if(position>count())
	{
		cout<<"\n Position "<<position<<" does not exist for the linked list ";
		return;
	}
	if(position==1)
	{
		StringNode *ptr=head;
		head=ptr->next;
	    delete ptr;
	    return;
	}
	
	int count=1;
	StringNode *ptr,*arrow;
	arrow=head;
	  while(arrow->next!=NULL)
	  {
	  	if(count==(position-1))
	  	{
	  		ptr=arrow->next;
	  		arrow->next=ptr->next;
	  		delete ptr;
		  }
		  else
		  {
		  	arrow=arrow->next;
		  	count++;
		  	
		  }
	  }
	  
}


// function that returns the number of nodes in a list
int count()
{
	int ctr=1;
	StringNode *ptr=head;
	while(ptr->!=NULL)
	{
		ptr=ptr->next;
		ctr++;
	}

	return ctr;
}


// fuction to search the element in the list
	StringNode* search(const string& x)
	{
		StringNode *ptr=head;
		while(ptr!=NULL)
		{
			if(ptr->elem==x)
			 return ptr;	
		}
		return ptr;
	}


// function to concatenate two singly linked lists
void concatenation(const LinkedList& obj)
{
	StringNode *ptr,*ptr2;
	ptr= tail;
	ptr2=obj.head;
	ptr->next= ptr2;    
}

// Driver Code
int main()
{
	
}
