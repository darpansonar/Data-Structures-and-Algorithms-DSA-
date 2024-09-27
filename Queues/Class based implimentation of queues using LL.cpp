#include<iostream>
#include<malloc.h>
using namespace std;

struct node
{
	int data;
	struct node *next;
}*head;

void insertBeginning(int d)
{
	struct node *ptr;
	ptr=(struct node *)malloc(sizeof(struct node));
	ptr->data=d;
	
	if(head==NULL)
	{
		head=ptr;
		head->next=NULL;
	}
	
	else
	{
		ptr->next=head;
		head=ptr;
	}
}

void insertEnd(int d)
{
	struct node *ptr,*ln;
	ptr=(struct node *)malloc(sizeof(struct node));
	ptr->data=d;
	ln=head;
	
	if(head==NULL)
	{
		head=ptr;
		head->next=NULL;
	}
	
	else
	{
		while(ln->next!=NULL)
		{
			ln=ln->next;
		}
		
		ptr->next=NULL;
		ln->next=ptr;
	}
}

void deleteBeginning()
{
	struct node *ptr;
	ptr=head;
	head=ptr->next;
	delete(ptr);
}

void deleteEnd()
{
	struct node *ptr,*sln;  //sln=second last node
	ptr=head;
	sln=head;
	
	while(ptr->next!=NULL)
	{
		ptr=ptr->next;
	}
	
	while(sln->next!=ptr)
	{
		sln=sln->next;
	}
	
	free(ptr);
	sln->next=NULL;
}

void display_LL()
{
	struct node *ptr;
	ptr=head;
	
	if(ptr==NULL)
	{
		cout<<"Queue is empty";
	}
	
	else
	{
		cout<<"Elements of Queue are : ";
		while(ptr!=NULL)
		{
			cout<<ptr->data<<"\t";
			ptr=ptr->next;
		}
	}
}

class Queue
{
	private:
		int front;
		int rear;
		int countVal;
		int maxElements;
		
	public:
		Queue()
		{
			front=-1;
			rear=-1;
			countVal=0;
			maxElements=5;
		}
		
		bool enQueueFront(int v)
		{
			if(countVal==maxElements)
			{
				cout<<"Queue is full ! enQueue unsuccessfull";
				return false;
			}
			
			else
			{
				if(rear==-1)
				{
					front=0;
					rear=0;
				}				
				
				else
				{
					front--;
				}
				
				insertBeginning(v);
				countVal++;
				return true;
			}
		}
		
		bool enQueueRear(int v)
		{
			if(countVal==maxElements)
			{
				cout<<"Queue is full ! enQueue unsuccessfull";
				return false;
			}
			
			else
			{
				if(rear==-1)
				{
					front=0;
					rear=0;
				}
				
				else
				{
					rear++;
				}
				
				insertEnd(v);
				countVal++;
				return true;
			}
		}
		
		bool deQueueFront()
		{
			if(rear==-1)
			{
				return false;
			}
				
			else
			{
				if(rear==front)
				{
					rear=-1;
					front=-1;
				}
					
				else
				{
					front++;
				}
					
				deleteBeginning();
				countVal--;
				return true;
			}
		}
		
		bool deQueueRear()
		{
			if(rear==-1)
			{
				return false;
			}
			
			else
			{
				if(rear==front)
				{
					rear=-1;
					front=-1;
				}
				
				else
				{
					rear--;
				}
				deleteEnd();
				countVal--;
				return true;
			}
		}
		
		int count()
		{
			return countVal;
		}
		
		void display()
		{
			display_LL();
		}
};

int main()
{
	int c=0,v;
	Queue q;
	while(c<7)
	{
		cout<<"\n\nEnter => 1.enQueueFront  2.enQueueRear"<<endl;
		cout<<"         3.deQueueFront  4.deQueueRear"<<endl;
		cout<<"         5.Display       6.Count      "<<endl;
		cout<<"         7.Exit                       : ";
		cin>>c;
		
		switch(c)
		{
			case 1:
				cout<<"Enter element to enQueue : ";
				cin>>v;
				q.enQueueFront(v);
				break;
				
			case 2:
				cout<<"Enter element to enQueue : ";
				cin>>v;
				q.enQueueRear(v);
				break;
				
			case 3:
				q.deQueueFront();
				cout<<"Deleted 1st element";
				break;
				
			case 4:
				q.deQueueRear();
				cout<<"Deleted last element";
				break;
				
			case 5:
				q.display();
				break;
				
			case 6:
				cout<<"Number of elements in Queue are : ";
				cout<<q.count();
				break;
				
			case 7:
				exit(0);
				
		}
	}
	
	return 0;
	
}
