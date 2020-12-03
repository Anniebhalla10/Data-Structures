/* Bracket Matching using Stacks */

#include<iostream>
using namespace std;

typedef string Elem;
class node
{
	Elem ele;
	node *next;
	public:
		friend class Stack;
};

class Stack
{
	node* head;
	node* top;
public:
	Stack()
	{
		head=NULL;
		top=NULL;
	}
	~Stack()
	{
		while(!empty()) pop();
		delete head;
		delete top;
	}
	
	bool empty()
	{
		return (head==NULL);
	}
	
	void push(const Elem& e)
	{
		node* n= new node;
		n->ele= e;
		n->next=NULL;
		if(empty())
		  {
		  	head=n;
		  	top=n;
		  }
		else
		{
			top->next=n;
			top=n;
		}
    }
    
    void pop()
    {
    	if(empty())
    	throw " Function pop() : Stack Underflow ";
    	if(count()==1)
    	{
    		node* n=head;
    		head=NULL;
    		top=NULL;
    		delete n;
		}
		else
		{
			node *n= head;
			node* ptr= head->next;
			while(ptr->next!=NULL)
			{
				n=n->next;
				ptr=ptr->next;
			}
			n->next=NULL;
			top=n;
			delete ptr;
		}	
	}
	
	const Elem& atTop()
	{
		return top->ele;
	}
	
	void display()
	{
		node *ptr= head;
		while(ptr!=NULL)
		{
			cout<<ptr->ele<<" ";
			ptr=ptr->next;
		}
		cout<<endl;
	}
	
	int count()
	{
		int ctr=0;
		node *ptr=head;
		while(ptr!=NULL)
		{
			ptr=ptr->next;
			ctr++;
		}
		return ctr;
	}	
};

bool type_match(Elem a,char b)
{
   bool flag=false;
   switch(b)
   {
   	case ']' : if(a=="[") return true;
   				else flag=0;
   				break;
   	case '}' : if( a=="{" ) return true;
		       else flag=false;
            break;
    case ')':
            if(a=="(") return true;
            else flag=false;
            break;
        default:
            break;
    }
    return flag;
	 	
}

bool match_bracket(Elem& exp, Stack& S)
{
	int i=0;
    while(exp[i]!='\0'){
        if(exp[i]=='(' || exp[i]=='[' || exp[i]=='{'){
            switch (exp[i]) {
                case '(':
                    S.push("(");
                    break;
                case '[':
                    S.push("[");
                    break;
                case '{':
                    S.push("{");
                    break;
                default:
                    break;
            }
        }
        else
        if (exp[i]==')' || exp[i]==']' || exp[i]=='}'){
            if (S.empty()) {
                return false;
            }
            if (!type_match(S.atTop(), exp[i])) {
                return false;
            }
            if(type_match(S.atTop(), exp[i])){
                S.pop();
            }
        }
        i++;
        S.display();
    }
    if (S.empty()) 
        return true;
    else
        return false;
    
}


int main()
{
	try
	{
		Stack S;
		Elem exp;
    cout<<"Enter the brackets or expression: "<<endl;
    exp="(()[]{}{[]})()";
     if(match_bracket(exp, S)){
        cout<<"Brackets matched!! :D"<<endl;
    }
    else{
        cout<<"Brackets not in proper order or missing!! :("<<endl;
    }
	}
	catch(const char* str)
	{
		cout<<str;
	}
	return 0;
}
