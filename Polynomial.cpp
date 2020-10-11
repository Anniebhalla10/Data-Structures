/*   Name : Annie Bhalla
     Roll No : 19HCS4009
     Course : Bsc (H) Computer Science
     Semester : 3
     Title : Polynomials implementation usign singly linked list
*/

#include<iostream>
using namespace std;

class node
{
	      int coeff;
	      int expo;
	      node* next;
	public:
		friend class Polynomial;
};

class Polynomial
{
	node* head;
	node* tail;
public:
	Polynomial();                               // 1
	void addTail(int e, int c);					// 2
	void insert();								// 3
	Polynomial sum(const Polynomial& P) const;  // 4
	void display();								// 5
};


// (1) Constructor

Polynomial::Polynomial()
{
	head= NULL;
	tail=NULL;
}

// (2) to append the term to tail of polynomial

void Polynomial::addTail(int e,int c)
{
	if(c!=0)
	{
	
	if(head==NULL && tail==NULL )
	{
		node *p =new node;
		p->coeff=c;
		p->expo=e;
		p->next=NULL;
		head=p;
		tail=p;
		return;
	}
	node *ptr,*arrow;
	ptr= new node;
	ptr->expo=e;
	ptr->coeff=c;
	ptr->next=NULL;
	arrow=head;
	while(arrow->next!=NULL)
	{
		arrow=arrow->next;
	}
	arrow->next=ptr;
	tail=ptr;
  }
  return;
}

// (3) To insert the polynomial

void Polynomial::insert()
{
	int num;
	int exp,coef;
	cout<<"\n Enter the number of terms ";
	cin>>num;
	for(int i=0;i<num;i++)
	{
		cout<<"\n Enter Exponent : ";
		cin>>exp;
		cout<<endl<<" Enter Coefficient : ";
		cin>>coef;
		addTail(exp,coef);
	}
	
}

// (4) to find the sum of two polynomials

Polynomial Polynomial::sum(const Polynomial& P) const
{
	if(head==NULL)
	{
	return P;
   }
	
	else if (P.head==NULL)
	{
	
	return (*this);   }
	
	else
	{
		Polynomial P3;
		node *a= (*this).head;
		node *b= P.head;
		int c=0;
		
		while(a!=NULL && b!=NULL)
		{
			if( a->expo == b->expo)
			{
				c = a->coeff + b->coeff ;
				if(c!=0)
			    P3.addTail(a->expo , c);
			    a=a->next;
			    b=b->next;
			}
			else  if( a->expo > b->expo )
				{
					 c =a->coeff;
					 P3.addTail(a->expo , c);
					 a= a->next;
				} 
			    else
			    	{
			    		c= b->coeff;
			    		P3.addTail(b->expo , c);
			    		b = b->next;
					}
					
        	}
        	
        	while( a!=0)
        	{
        		c =a->coeff;
					 P3.addTail(a->expo , c);
					 a= a->next;
			}
			  
			  while(b!=0)
			  {
			  	
			  	c= b->coeff;
			    		P3.addTail(b->expo , c);
			    		b = b->next;
		    	}   
				
				return P3;   
			
		}
			
}

// (5) To display the poynomial

void Polynomial::display()
{
	if(head==NULL)
	{
	cout<<"\n No Such Polynomial ";
	return;
   }
      	cout<<"\nThe polynomial is: ";
			node* temp= head;
			while(temp!=NULL)
			{
				cout<<temp->coeff<<" x^"<<(temp->expo);
				if(temp->next==NULL)
				{
					cout<<" ";
				}
				else
				cout<<" + ";
				
				temp=temp->next;
			}
		
	
}


// driver code
int main()
{
	cout<<"\n *** POLYNOMIAL 1 *** "<<endl;
	Polynomial P1;
	P1.insert();
	P1.display();
	
	cout<<"\n *** POLYNOMIAL 2 ***"<<endl;
	Polynomial P2;
	P2.insert();
	P2.display();
	
	Polynomial P4;
	P4 = P1.sum(P2);
	
	cout<<"\n Sum of polynomials is : ";
	P4.display();
	
	return 0;
}
