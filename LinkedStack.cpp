/* Name : Annie Bhalla
   Roll No. : 19HCS4009
   Course : BSC (H) Computer Science
   Semester : 3
   Subject : Data Structures
   Title : Stacks using SLL
*/


#include<iostream>
using namespace std;

typedef int E;
class node
{
    public:
        E ele;
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
	   	
        bool empty() const 							// 1
		{		if(head==NULL)
   				return 1;
    			else
    			return 0;
        }    
		
		                           
        void insert_front(const E& x)                    //2
        {
        	node *n=new node;
        	n->ele=x;
        	n->next=head;
       	 	head=n;
        	if(tail==NULL)
          	tail=n;
		}
		
		
        void remove_front()                                //3
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
		
		
        const E& front() const                          // 4
        {
        	if(head==NULL) throw" Empty List";
			return head->ele;
		}  
		
		void disp()									// 5
		{
			if(empty()) throw " Function display(): EMPTY STACK ";
			node* ptr=head;
			while(ptr!=NULL)
			{
				cout<<ptr->ele<<" -> ";
				ptr=ptr->next;
			}
		}
                                               
};


class LinkedStack
{
	LinkedList L;
	E num;
	
	public:
		LinkedStack() //1
			{
				LinkedList();
				num=0;
			}
			
			
		int size() const //2
		{
			return num;
		}
		
		bool empty() const  //3
		{
			return(num==0);
			
		}
		
		const E& top()  //4
		{   
			if(empty()) throw " Function top() : LIST EMPTY ";
				return L.front();
		}
		
		
		void push(const E& ele) //5 
		{
			++num;
			L.insert_front(ele);
		}
		
		
		void pop()  //6
		{
			if(empty()) throw " Function pop() : EMPTY LIST ";
			--num;
			L.remove_front();
		}
		
		void display()   // 7
		{
			L.disp();
		}
};

// driver code
int main()
{
	try
	{
		LinkedStack obj;
		obj.push(7);
		obj.push(10);
		obj.pop();
		obj.display();
		cout<<endl;
		cout<<obj.top();
		
	}
	catch(const char* str)
	{
		cout<<"\n Exception Found : "<<str;
	}	
	
	return 0;
}
