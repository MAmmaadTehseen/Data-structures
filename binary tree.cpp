#include<iostream>
using namespace std;
class Node
{
    public:
    int data;
    Node *left,*right;
    Node(int x)
    {
        data=x;
        left=NULL;
        right=NULL;

    }

};
class BSTree
{
    Node *root;
    public:
//isEmpty
    bool isEmpty()
    {
   		return root==NULL;
	}
//preOrder		
    void preOrder(Node *root)
	{
		if(isEmpty())
		{return;
	
		}
		visitRoot(root);
		preOrder(root->left);
		preOrder(root->right);
	}
//postOrder	
	void postOrder(Node *root)
	{
		if(isEmpty())
		{return;
	
		}
		postOrder(root->left);
		postOrder(root->right);
		visitRoot(root);
	}
//inOrder	
	void inOrder(Node *root)
	{
		if(root==NULL)
		{return;
		}
		inOrder(root->left);
		visitRoot(root);
		inOrder(root->right);
	}
//print
	void Print()
	{
		inOrder(root);
	}
//findParent
	Node* getParent(int x)
	{
		Node *q,*parent=NULL;
		q=root;
		while(q!=NULL)
		{
			parent=q;
			q->data<x?q=q->right:q=q->left;
		}
		return parent;
	}
//isFullParent
	bool isFullParent(Node *root)
	{
		return getNode(root->data)->left!=NULL&&getNode(root->data)->right!=NULL;
	}
//isSingleParent	
	bool isSingleParent(Node *root)
	{
		return !isFullParent(root)&&!isLeaf(root);
	}
//isLeaf	
	bool isLeaf(Node *root)
	{
		return getNode(root->data)->left==NULL&&getNode(root->data)->right==NULL;
	}
//insert	
    void insert(int x)
    {
    	
        if(!isEmpty())
        {
        	x>getParent(x)->data?getParent(x)->right=new Node(x):getParent(x)->left=new Node(x); 	
		}
        else
		{
			root=new Node(x);
   		}

    }
//doesExist
	bool doesExist(int x)
	{
		return (getNode(x)!=NULL);
	}
//getLeftChild
	Node* getLeftChild(Node *root)
	{
		return root->left;	
	}	
//getRightChild
	Node* getRightChild(Node *root)
	{
		return root->right;	
	}		
//getLeftMost    
    int getLeftMost(Node *root)
	{
		Node *temp=root;
		if(temp->left==NULL)
		{
			return temp->data;
		}
		getLeftMost(root->left);
		
	}
//getRightMost
	int getRightMost(Node *root)
	{
		Node *temp=root;
		if(temp->right==NULL)
		{
			return temp->data;
		}
		getRightMost(root->right);
	
	}

//successor
	int getSuccessor(int x)
	{
		if(getNode(x)->right!=NULL)
		{
			return getLeftMost(getNode(x)->right);
		}
	}
//predecessor
	int getPredecessor(int x)
	{
		if(getNode(x)->left!=NULL)
		{
			return getRightMost(getNode(x)->left);
		}
	}
//visitRoot    
	void visitRoot(Node *root)
	{
	cout<<root->data<<" ";
	}	
//getNode
	Node* getNode(int x)
	{
		Node *q=root;
		while(q->data!=x)
		{
			if(q==NULL)
			{
				return NULL;
			}
			q->data>=x?q=q->left:q=q->right;
		}
		return q;
	}
//delete
	bool del(int x)
	{
		if(getNode(x)==NULL) return false;
		Node *q=getNode(x);
		
		
			if(isLeaf(q))
			{
				delLeaf(q);
			}
			else if(isFullParent(q))
			{
				delFullParent(q);
			}
			else
			{
				delSingleParent(q);
			}
			return true;
		
		
	}	
	
	
//delfullParent
	void delFullParent(Node *r)
	{
		Node *q=r;
		q=q->right;
		while(q->left!=NULL)
		{
			q=q->left;
		}	
		r->data=q->data;
		if(isLeaf(q))
		{
			delLeaf(q);
		}
		else
		{
			delSingleParent(q);
		}
		delete q;
	}	
//delleaf
	void delLeaf(Node *r)
	{
		int x=r->data;
		r==getParent(x)->right?getParent(x)->right=NULL:getParent(x)->left=NULL;
		delete r;
	}
//delSingleParent
	void delSingleParent(Node *r)
	{
		Node *x=getParent(r->data);
		if(x->right==r) 
		{
			x->right=getChild(r);
		}
		else 
		{
			x->left=getChild(r);	
		}
		delete r;		
	}		
//getChild
	Node* getChild(Node *root)
	{
		if(!isLeaf(root))
		{
			if(root->right!=NULL)
			{
				return root->right;
			}
			return root->left;
		}
		return NULL;
		
	}	

};
int main()
{
	BSTree t1;
	t1.insert(8);	
	t1.insert(3);
	t1.insert(5);
	t1.insert(4);
	t1.insert(6);
	t1.insert(7);	
	t1.insert(1);
	t1.Print();
	t1.del(5);

	cout<<"\n";
	t1.Print();


}
