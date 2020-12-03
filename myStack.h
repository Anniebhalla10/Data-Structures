#ifndef MYSTACK_H
#define MYSTACK_H
#include <iostream>
using namespace std;
template <typename T> class StackLL;

template <typename T> 
class Node
{
    T data; 
	Node<T>* next;
	
    public:
    Node(T data, Node<T>* next = NULL)
	{
        this->data = data;
        this->next = next;
    }
    template <typename U> friend class StackLL;
    template <typename U> friend ostream& operator <<(ostream&, const StackLL<U>&);
};


template <typename T> 
class StackLL
{
    Node<T>* top;
	int size;
	
    public:
    StackLL()					// 1
	{
		top = NULL;size = 0;
	}
	
    ~StackLL()    				// 2
	{
		while(top!=NULL) pop();
	}
	
    bool isEmpty()				// 3
	{
		return (top == NULL);
	}
	
    int getSize()				// 4
	{
		return size;
	}
	
    void push(T data)			// 5
    {
        Node<T> *p = new Node<T>(data,top);
        top = p;
        ++size;
    }
    
    T pop()      				// 6
    {
        if(top == NULL)
            throw string("Underflow");
        Node<T> *del = top;
        top = top->next;
        T data = del->data;
        delete del;
        --size;
        return data;
    }
    
    T Top()						// 7
    {
        if(top == NULL) throw string("Underflow");
        return top->data;
    }
    
    template <typename U> 
	friend ostream& operator <<(ostream& out, const StackLL<U>& stack);
};


template <typename U> 
ostream& operator <<(ostream& out, const StackLL<U>& stack)
{
    if(stack.top == NULL) out<<"Stack Empty";
    else
    {
        Node<U> *ptr = stack.top;
        while(ptr!=NULL)
        {
            out<<ptr->data<<"  ";
            ptr = ptr->next;
        }
    }
    return out;
}
#endif
