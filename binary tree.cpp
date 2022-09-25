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
		Node *q=getNode(x);
		if(q!=NULL)
		{
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
		return false;
	}	
	
	
//delfullParent
	void delFullParent(Node *root)
	{
		Node *q=root;
		q=q->right;
		while(q->left!=NULL)
		{
			q=q->left;
		}	
		root->data=q->data;
		root->data>q->data?root->right=q->right:root->left=q->right;
		if(isLeaf(q))
		{
			getParent(q->data)->right==q?getParent(q->data)->right=NULL:getParent(q->data)->left=NULL;
		}
		delete root;
	}	
//delleaf
	void delLeaf(Node *root)
	{
		int x=root->data;
		root==getParent(x)->right?getParent(x)->right=NULL:getParent(x)->left=NULL;
		delete root;
	}
//delSingleParent
	void delSingleParent(Node *root)
	{
		Node *x=getParent(root->data);
		if(x->right==root) 
		{
			x->right=getChild(root);
		}
		else 
		{
			x->left=getChild(root);	
		}
		delete root;		
	}		
//getChild
	Node* getChild(Node *root)
	{
		if(isLeaf(root))
		{
			if(root->left==NULL)
			{
				return root->right;
			}
			return root->left;
		}
		
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
