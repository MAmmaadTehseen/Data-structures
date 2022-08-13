#include<iostream>
using namespace std;
class Node
{
    int data;
    Node *next;
public:
    Node(int data,Node *next=NULL) //parameterized constructor
    {
        this->data=data;
        this->next=next;
    } 
    void setNext(Node *next)// setter
    {
        this->next=next;
    }
    int getData()//getter
    {
        return this->data;
    }
    Node* getNext()//getter
    {
        return this->next;
    }
};
class linkedList
{
    Node *head;
    public:
        linkedList()
        {
            head=NULL;
        }
        linkedList(int data)
        {
            head=new Node(data);
        }
        bool isEmpty()
        {
            return head==NULL;
        }
        void insertAtBegin(int data)
        {
            if(isEmpty())
            {
                head=new Node(data);
            }
            else
            {
                Node *t=new Node(data,head);
                head=t;
            }
        }
        bool removeFromBegin()
        {
            if(!isEmpty())
            {
                 if(head->getNext()==NULL)
                 {
                     delete head;
                     return true;
                 }
                 else
                 {
                    Node *t=head->getNext();
                    delete head;
                    head=t;
                    return true;        
                 }
            }
            return false;
        }
        int getLength()
        {
            Node *t=head;
            int count=0;
            while(t!=NULL)
            {
                t=t->getNext();
                count++;
            }
            return count;
        }
        void insertAtLast(int val)
        {
            Node *t=head;
            if(!isEmpty())
            {
                while(t->getNext()!=NULL)
                {
                    t=t->getNext();

                }
                Node *n=new Node(val);
                t->setNext(n); 

            }
            else
			{
			head=new Node(val);
        	}
		}
        bool removeFromLast()
        {
            if(!isEmpty())
            {
            		Node *t=head;
            	if(head->getNext()!=NULL)
            	{
                	while(t->getNext()->getNext()!=NULL)
                	{
                    	t=t->getNext();
                	}
                	delete t->getNext();
                	t->setNext(NULL);
                	return true;
            		
				}
				else
				{
					delete t;
				}
            
            }
            return false;
        }
        int getFirstElement()
        {
            if(!isEmpty())
            {
                return head->getData();
            }
            return -1;
        }
        int getLastElement()
        {
            if(!isEmpty())
            {
                Node *t=head;
                while(t->getNext()!=NULL)
                {
                    t=t->getNext();
                }
                return t->getData();
            }
            return -1;
        }
        void Print()
        {
            if(!isEmpty())
            {
                Node *t=head;
                while(t!=NULL)
                {
                    cout<<t->getData()<<" ";
                    t=t->getNext();
                }
            }
            else
            {
            cout<<"empty";
        
                
            }
        }    


};
class Queue
{
	linkedList l1;
	public:
		Queue(int x)
		{
			l1.insertAtLast(x);
		}
		void enqueue(int x)
		{
			l1.insertAtLast(x);
			
		}
		int dequeue()
		{
			int x=l1.getFirstElement();
			l1.removeFromBegin();
			return x;
		}
		int front()
		{
			return l1.getFirstElement();
		}
		bool isEmpty()
		{
			return l1.isEmpty();
		}
		void print()
		{
			l1.Print();
		}
		
};
int main()
{
	Queue q1(12);
	q1.enqueue(34);
	q1.print();
	cout<<endl<<q1.front()<<endl;
	q1.dequeue();
	q1.print();

}
