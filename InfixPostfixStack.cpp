/* Name : Annie Bhalla
   Roll No. : 19HCS4009
   Course : BSC (H) Computer Science
   Semester : 3
   Subject : Data Structures
   Title : Infix to Postfix Conversion and Evaluation (Stacks)
*/

#include "myStack.h"
#include <iostream>
#include <string>
#include <math.h>
using namespace std;

// function to check precedence of characters
int precedence(char c)
{
	if(c=='^')
	{
		return 3;
	}
	else if(c=='*' || c=='/')
	{
		return 2;
	}
	else if(c=='+' || c=='-')
	{
		return 1;
	}
	else
	{
		return -1;
	}
	
}


// function to check for valid operator

bool check_OP(char x)
{
	if( x=='+' || x=='-' || x=='*' || x=='/' || x=='^')
	  return true;
	  else
	   return false;
}


// function to convert from infix to postfix

string convert(StackLL<char> stack1 , string in_exp)
{
	string postfix;
	for(int i=0 ; i<in_exp.length() ; i++)
	{
		if(in_exp[i]>='0' && in_exp[i]<='9' )
		{
			char c=in_exp[i];
			int val = in_exp[i]- '0';
			postfix+=c;
		}
		
		else if( in_exp[i]=='(')
		{
			stack1.push(in_exp[i]);
		}
		
		else if(in_exp[i]==')')
		{
			while((stack1.Top()!='(') && (!stack1.isEmpty()))
			{
				char temp = stack1.Top();
				postfix+=temp;
				stack1.pop();
			}
			if(stack1.Top()=='(')
			  stack1.pop();
		}
		
		else if( check_OP(in_exp[i]))
		{
			if(stack1.isEmpty())
			 stack1.push(in_exp[i]);
			 
			 else
			 
			 {
			 	if((precedence(in_exp[i])) > (precedence(stack1.Top())))
			 	stack1.push(in_exp[i]);
			 	
			 	else if((precedence(in_exp[i])) == precedence(stack1.Top()) && in_exp[i]=='^')
				{
					stack1.push(in_exp[i]);
				}
				else
				{
					while((!stack1.isEmpty()) && precedence(in_exp[i])<=precedence(stack1.Top()))
					{
						char temp=stack1.Top();
						postfix+=temp;
						stack1.pop();
					}
					stack1.push(in_exp[i]);
				}
			 }
		}
	}
	
	while(!stack1.isEmpty())
	{
		postfix+=stack1.Top();
		stack1.pop();
	}
	return postfix;
}


// to evaluate the postfix expression

int evaluate(StackLL<double> stack2 , string post_exp)
{
	int total=0;			// final ans
	int op1 , op2 ;  // op = operand
	
	for(int i=0; i<post_exp.length() ; i++)
	{
		if(!(check_OP(post_exp[i])))
		{
			int x= post_exp[i]-48;
			stack2.push(x);
			cout<<"\n PUSH : "<<x;
		}
		else if(check_OP(post_exp[i]))
		{
			int val=0;
			char K = post_exp[i];
			cout<<"\n Operator : "<<K;
			op1 = stack2.Top();
			cout<<"\n POP : "<< op1;
			stack2.pop();
			
			op2 = stack2.Top();
			stack2.pop();
			cout<<"\n POP : "<<op2;
			
			switch(K)
			{
				 
				case '+' :
				{
					val= op1+op2;
					stack2.push(val);
					cout<<"\n PUSH : "<<val;
					break;
				}
				
				case '-' :
				{
					val= op2-op1;
					cout<<"\n PUSH : "<<val;
					stack2.push(val);
					break;
				}
				
				case '*' :
					{
						val= op1*op2;
						cout<<"\n PUSH : "<<val;
						stack2.push(val);
						break;
					}
					
				case '/' :
					{
						if(op1==0) throw "Exception : DIVIDE BY ZERO ";
						val= op2/op1;
						cout<<"\n PUSH : "<<val;
						stack2.push(val);
						
						break;
					}
				
				case '^' :
					{
						val=pow(op2,op1);
						stack2.push(val);
						cout<<"\n PUSH : "<<val;
						break;
					}
				
				
			}
		}
		
	}
	return stack2.Top();
}

// driver code
int main()
{

try
	{
	int value;			// evaluated answer
	string in_exp,post_exp;
	
	StackLL<char> stack1;		//stack 1 for infix to postfix conversion
	StackLL<double> stack2;			//stack 2 for evaluation of postfix expression
	
	cout<<"\n Enter the infix expression : ";
	cin>>in_exp;
	
	post_exp=convert(stack1,in_exp);
	
	cout<<"\n POSTFIX : "<<post_exp<<endl;
	value=evaluate(stack2,post_exp);
	
	cout<<"\n Evaluated expression : "<<value;

}
catch(const char *str)
{
	cout<<str;
}
	return 0;
	
}
