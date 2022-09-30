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
    public:
    Node *root;
//isEmpty
    bool isEmpty()
    {
   		return root==NULL;
	}
//preOrder		
    void preOrder(Node *root)
	{
		if(root==NULL)
		{return;
	
		}
		visitRoot(root);
		preOrder(root->left);
		preOrder(root->right);
	}
//postOrder	
	void postOrder(Node *root)
	{
		if(root==NULL)
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
//getParent
	Node* getParent(int x)
	{
		Node *q,*parent=NULL;
		q=root;
		while(q!=NULL)
		{
			parent=q;
			if(q->data<x)
			{
			q=q->right;
			}
			else
			{
			q=q->left;
			}
			
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
//    Node getLeftMost(Node *r)
//	{
//		
//		if(r->left==NULL)
//		{
//			return r;
//		}
//		getLeftMost(r->left);
//	}
		
//getRightMost
//	Node getRightMost(Node *root)
//	{
//		Node *temp=root;
//		if(temp->right==NULL)
//		{
//			return temp;
//		}
//		getRightMost(root->right);
//	
//	}

//successor
//	Node getSuccessor(Node *r)
//	{
//		if(r->right!=NULL)
//		{
//			getLeftMost(r->right);
//			
//		}
//		else
//		{
//			if(r->data>getParent(r->data)) return NULL;
//			else return getParent(r->data);
//			
//		}
//		
//		
//	}
////predecessor
//	int getPredecessor(int x)
//	{
//		if(getNode(x)->left!=NULL)
//		{
//			return getRightMost(getNode(x)->left);
//		}
//	}
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
		if(q==NULL) return false;
		
		
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
			q->data>GetParent(q->data)->data?GetParent(q->data)->right=q->right:GetParent(q->data)->left=q->right;
		}
	}
//GetParent	
	Node* GetParent(int x)
	{
		Node *q=root;
		
		while(!(q->left->data==x||q->right->data==x))
		{
			q->data>=x?q=q->left:q=q->right;
			if(q==NULL)return NULL;
		}
		return q;
				
	}	
//delleaf
	void delLeaf(Node *r)
	{
		int x=r->data;
		r==GetParent(x)->right?GetParent(x)->right=NULL:GetParent(x)->left=NULL;
		delete r;
	}
//delSingleParent
	void delSingleParent(Node *r)
	{
		Node *x=GetParent(r->data);
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
	Node* getChild(Node *r)
	{
		if(isSingleParent(r))
		{
			if(r->right!=NULL)
			{
				return r->right;
			}
			return r->left;
		}
		return NULL;
		
	}	

};
int main()
{
	BSTree t1;
	t1.insert(14);
	t1.insert(10);
	t1.insert(16);
	t1.insert(7);
	t1.insert(6);
	t1.insert(9);	
	t1.insert(15);	
	t1.insert(18);
	t1.insert(20);
	t1.insert(17);
	
	t1.Print();
//	t1.del(15);
	
	cout<<endl<<t1.GetParent(6)->data<<endl;
	t1.Print();
}
