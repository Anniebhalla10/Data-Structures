/*  Name : Annie Bhalla
     Roll No : 19HCS4009
     Course : Bsc (H) Computer Science
     Semester : 3
     Title : Implementation of Binary Search Trees
*/

#include<iostream>
#include<stack>
#include<queue>
using namespace std;

template <class T>
class BSTNode
{
	
	public:
		T data;
	BSTNode<T> *left, *right;
		BSTNode()
		{
			left=right=0;
		}
		BSTNode(const T &ele , BSTNode<T> *l=0 , BSTNode<T> *r=0)
		{
			data = ele;
			left = l;
			right= r;
			
	}
};

template <class T>
class BST
{
	BSTNode<T> *root;
	protected:
		void clear(BSTNode<T>*);
		BSTNode<T>* search (BSTNode<T>*, const T&)const;
		void preorder(BSTNode<T>*);
		void postorder(BSTNode<T>*);
		void inorder(BSTNode<T>*);
	    BSTNode<T>* insertnode(BSTNode<T>* ,const T&);
		int count(BSTNode<T>* p);
		int height(BSTNode<T>* p);
		T& findMax(BSTNode<T>*);
	     T& findMin(BSTNode<T>*);
	     int count_leaf_nodes(BSTNode<T> *p);
	      int count_nonleaf_nodes(BSTNode<T> *p);
		virtual void visit(BSTNode<T>* p)
		{
			cout<<p->data<<" ";
		}
	public:
		BST()							// 1
		{
			root=0;
		}
		
		~BST()							// 2
		{
			clear();
		}
		
		void clear()					// 3 
		{
			clear(root);
			root=0;
		}
		
		bool isempty() const			// 4
		{
			return (root==0);
		}
		
		void preorder()					// 5
		{
			preorder(root);  			
		}
		
		void inorder()					// 6
		{
			inorder(root);
		}
		
		void postorder()				// 7
		{
			postorder(root);			
		}
		
		BSTNode<T>* search(const T& ele) const	// 8
		{
		   /*	BSTNode*p=root;
				while(p!=NULL)
			{
				if(p->data==ele)
				break;
				else if(ele < p->data )
		   			p=p->left;
				else
				p=p->right;
			}
				return p;  */
			return search(root,ele);
		}
		
		void iterPreorder();			// 9
		void iterInorder();				// 10
		void iterPostorder();			// 11
    	void insert(const T& elem)   	// 12
		{
					/*
			 BSTNode *z= new BSTNode(elem);
			 BSTNode *y=NULL;
			 BSTNode *x=root;
			 while(x!=NULL)
			 {
			 y=x;
			 if(z->data < x->data) 
			    x=x->left;
			else
			  x=x->right;
		    }
		    if(y==NULL)
		      root=z;
		    else if(z->data < y->data)
			    y->left=z;
			else 
			   y->right=z;
			*/
			root=insertnode(root,elem);
		}
				
		T& findMin()								// 13
		{
			/* BSTNode*p=root;
			  if(p==NULL) throw " Function findMin() : empty tree";
			  while(p->left!=NULL)
			      p=p->left;
			      return p;
			*/
			findMin(root);
		}
		T& findMax()								// 14
		{
			/* BSTNode* p=root;
				if(p==NULL) 
				  throw "Function findMax() : empty tree";
				 while(p->right!=NULL)
				     p=p->right;
				return p;
			*/
			findMax(root);	
		}
		
		void breadthFirst();						// 15
		int count()									// 16
		{
			/*
				if(root==0)
				 return 0;
				else if((root->left==0) && (root->right==0))
				 return 1;
				else 
				return (1+count(root->left)+count(root->right));
			*/
			count(root);
		}
		
		int height()										// 17
		{
			height(root);
		}
				
		bool equals(BSTNode<T>* p, BSTNode<T>* q); 			// 18
		void delete_by_copy(const T& ele);				   // 19
		int count_leaf_nodes()							// 20
		{
			return (count_leaf_nodes(root));
		}
		
		int count_nonleaf_nodes()						// 21
		{
			return (count_nonleaf_nodes(root));
		}
};

// (3) to clear the tree

template <class T>
void BST<T>::clear(BSTNode<T>* node)
{
	if(node==NULL)
	return;
	
	clear(node->left);
	clear(node->right);
	
	cout<<"\n Deleting Node : "<<node->data;
	delete node;
	
}


// (5) Pre-order Traversal of BST - [ Root Left Right ]

template <class T>
void BST<T>::preorder(BSTNode<T>* node)
{
	if(node==NULL)
	  return;
	cout<<node->data<<" ";
	preorder(node->left);
	preorder(node->right);
}

// (6) In-order Traversal of BST - [ Left Root Right ]

template <class T>
void BST<T>::inorder(BSTNode<T>* node)
{
	if(node==NULL)
	 return;
	inorder(node->left);
	visit(node);
	inorder(node->right);
}

// (7) Post-order Traversal of BST - [  Left Right Root ]

template <class T>
void BST<T>::postorder(BSTNode<T>* node)
{
	if(node==NULL)
	 return;
	postorder(node->left);
	postorder(node->right);
	visit(node);
}


// (8) to search an element in the given BST

template <class T>
BSTNode<T>* BST<T>::search(BSTNode<T> *r, const T& ele)const
{
	BSTNode<T> *p= r;
	if(p==NULL) return p;
	if(p->data==ele) return p;
	else if( ele < p->data)
	 return (p->left,ele);
	else
	  return (p->right, ele);
}

// (9) pre-order traversal iterative method

template <class T>
void BST<T>::iterPreorder()
{
	stack<BSTNode<T>*> travStack;
	BSTNode<T> *p= root;
	if(p!=0)
	{
		travStack.push(p);
		while(!travStack.empty())
		{
			p=travStack.pop();
			visit(p);
			if(p->right !=0)
			  travStack.push(p->right);
			if(p->left !=0 )
			 travStack.push(p->left);
		}
	}
}

// (10) in-order iterative
template <class T>
void BST<T>::iterInorder()
{
	stack<BSTNode<T>*> travStack;
	BSTNode<T>* p= root;
	while(p!=0)
	{
		if(p->right !=0 )
		  travStack.push(p->right);
		p=p->left;
	}
	p=travStack.pop();
	while(!travStack.empty() && p->right==0)
	{
		visit(p);
		p=travStack.pop();
	}
	visit(p);
	if(!travStack.empty())
		p=travStack.pop();
	else
	  p=0;
}

// (11) post-order iter
template <class T>
void BST<T>::iterPostorder()
{
	stack<BSTNode<T>*> travStack;
	BSTNode<T>* p = root,*q=root;
	while(p !=0)
	{
		for( ; p->left!=0; p=p->left)
			travStack.push(p);
		while(p!=0 && (p->right==0))
		 {
		 	visit(p);
		 	q=p;
		 	if(travStack.empty())
		 		return;
		 	p= travStack.pop();
		 }
		 travStack.push(p);
		 p=p->right;
	}
}

// (12) to insert an element in BST
template <class T>
BSTNode<T>* BST<T>::insertnode(BSTNode<T>* node, const T& elem)
{
	if(node==NULL)
	  return new BSTNode<T>(elem);
	if(elem < node->data)
	   node->left = insertnode(node->left, elem);
	else if( elem > node->data)
	node->right =insertnode(node->right, elem);
	
	return node;

	   
}

// (13) to find the minimum element from BST

template <class T>
T& BST<T>::findMin(BSTNode<T>* p)
{
	if(p==NULL) 
	throw "Function findMin() : empty tree";
	if(p->left==NULL) 
	 	return p->data;
	else
		return(findMin(p->left));
}

// (14) to find the maximum element from BST

template <class T>
T& BST<T>::findMax(BSTNode<T>* p)
{
	if(p==NULL)
		throw " Function findMax() : empty tree";
	if(p->right==NULL)
	 return p->data;
	else
	 return(findMax(p->right));
}

// (15) level by level traversal    DOUBT

template <class T>
void BST<T>::breadthFirst()
{
	queue<BSTNode<T>*> Q;
	BSTNode<T> *p = root;
	if(p!= NULL)
	{
		Q.push(p);
		while(!Q.empty())
		{
			Q.pop();
			visit(p);
			if(p->left!=NULL)
			  Q.push(p->left);
			if(p->right!=NULL)
			  Q.push(p->right);	
		}
	}
}

// (16) to count number of nodes in BST

template <class T>
int BST<T>::count(BSTNode<T>* p)
{
	if(p==0)
		return 0;
	else if((p->left==0) && (p->right==0))
		return 1;
	else
	  return (1+count(p->left)+count(p->right));
}


// (17) to find the height of the tree

template <class T>
int BST<T>::height(BSTNode<T>* p)
{
	if(p==0)
	 	return -1;
	else
	 if((p->left==0) && (p->right==0))
	 	 return 0;
	else
	{
		int H_left= height(p->left);
		int H_right= height(p->right);
		int max= H_left>H_right? H_left : H_right;
		return (max+1);
	}
}


// (18) to check if two trees are qual or not

template <class T>
bool BST<T>::equals(BSTNode<T>* p, BSTNode<T> *q)
{
	if(p==NULL && q==NULL)
	  return true;
	if((p!=NULL && q==NULL) || (p==NULL && q!=NULL))
		return 0;
	if(p->data != q->data) return 0;
	return (equals(p->left,q->left) && equals(p->right,q->right));
}
	
	
// (19) to delete a particular element from the BSt by copying
template <class T>
void BST<T>::delete_by_copy(const T& ele)
{
	bool leftchild;
	if(root ==0)
		throw " Function delete_by_copy() : Empty Tree ";
	BSTNode<T>* p=root;
	BSTNode<T>* fp=0;
	while(p!=0 && p->data!= ele)
	{
		fp=p;
		if(ele < p->data)
		   p=p->left;
		else
			p=p->right;
	}
	if(p==0) throw "Element Not Present for deletion ";

   if(fp!=0)
       leftchild = ele< fp->data ? true : false ;
      
   // if deleted node is a leaf 
   if(p->left== NULL && p->right==NULL)
   {
	   	if(fp==NULL)
	   	{
	   		root=NULL;
	         delete p;
			   return;	
		}
		if(leftchild) fp->left=NULL;
		else
		  fp->right=NULL;
		  delete p;
   }
   
   // if deleted node has one child
   else if(p->left==NULL)
   {
	   	if(fp==NULL)
	   	{
	   		root = p->right;
	   		delete p;
	   		return ;
	   		
		   }
		if(leftchild) fp->left = p->right;
		else fp->right=p->right;
		delete p;
   }
   
   else if(p->right==0)
   {
	   	if(fp==0)
	   	{
	   		root= p->left;
	   		delete p;
	   		return ;
		}
		if(leftchild) fp->left= p->left;
		else fp->right = p->left;
		delete p;
   }
   
   // if deleted node has two children 
   else
   {
	   	BSTNode<T> *ptr= p->right;
	   	BSTNode<T> *fptr= p;
	   	while(ptr->left!=0)
	   	{
	   		fptr=ptr;
	   		ptr=ptr->left;
		}
		p->data = ptr->data;
		if(ptr->data< fptr->data) 
			fptr->left= ptr->right;
		else 
			fptr->right= ptr->right;
		delete ptr;
   }
}	
	
// (20) to count number of leaf nodes ( non terminal nodes)
template <class T>
int BST<T>::count_leaf_nodes(BSTNode<T> *p)
{
	if(p==NULL)
	 return 0;
	 else if(p->left==NULL && p->right==NULL ) 
		 return 1;
	return (count_leaf_nodes(p->left) + count_leaf_nodes(p->right));
}

// (21) to count number of non leaf nodes
template <class T>
int BST<T>::count_nonleaf_nodes(BSTNode<T> *p)
{
	if(p==NULL)
		return 0;
	if(p->left==NULL && p->right==NULL)
		 return 0;
	return (1+count_nonleaf_nodes(p->left)+count_nonleaf_nodes(p->right));
	
	
}
	
// driver function
	
	int main()
	{
		BST<int> tree1;
		try
		{
		tree1.insert(4);         
		tree1.insert(10);
		tree1.insert(1);
		tree1.insert(7);
		tree1.inorder();
		tree1.preorder();
		tree1.postorder();
		cout<<"\n Number of nodes : "<<tree1.count();	
		cout<<"\n Minimum Element is : "<<tree1.findMin();
		cout<<"\n Maximum Element is : "<<tree1.findMax();
		cout<<"\n Height of tree : "<<tree1.height();
	   // tree1.breadthFirst();     
	   // tree1.iterInorder();     
	   // tree1.iterPreorder();
	      //tree1.iterPostorder();
	    cout<<"\n check empty tree condition : "<<tree1.isempty();
		tree1.delete_by_copy(7);     
		tree1.inorder();
		
		cout<<"\n Number of leaf nodes : "<<tree1.count_leaf_nodes();
		cout<<"\n Number of NON - leaf nodes : "<<tree1.count_nonleaf_nodes();
		
		}
		catch(const char* str)
		{
			cout<<"\n Exception : "<<str<<endl;
		}
		
		return 0;
	}
	
	
