#include<iostream>
using namespace std;
#define max 3
#define DT int

class DeQueue
{
	private:
		DT s[max];
		int front;
		int rear;
		int countVal;
		
	public:
		DeQueue()
		{
			front=-1;
			rear=-1;
			countVal=0;
		}
		
		int count()
		{
			return countVal;
		}
		
		bool isEmpty()
		{
			return(countVal==0);
		}
		
		bool isFull()
		{
			return(countVal==max);
		}
		
		bool enQueueRear(DT v)
		{
			if(isFull()) return false;
			
			else
			{
				if(countVal==0)
				{
					front=0;
					rear=0;
				}
				
				else
				{
					rear=(rear+1)%max;
				}
				
				s[rear]=v;
				countVal++;
				return true;
			}
		}
		
		bool enQueueFront(DT v)
		{
			if(isFull()) return false;
			
			else
			{
				if(front==-1)
				{
					front=0;
					rear=0;
				}
				
				else
				{
					front--;
					if(front<0)
					{
						front=max-1;
					}
				}
				
				countVal++;
				s[front]=v;
				return true;
				
			}
		}
		
		DT deQueueFront()
		{
			DT temp=s[front];
			if(countVal==1)
			{
				front=-1;
				rear=-1;
			}
			
			else
			{
				front=(front+1)%max;
			}
			
			countVal--;
			return temp;
		}
		
		DT deQueueRear()
		{
			DT temp=s[rear];
			if(countVal==1)
			{
				front=-1;
				rear=-1;
			}
			
			else
			{
				rear--;
				if(rear<0)
				{
					rear=max-1;
				}
			}
			
			countVal--;
			return temp;
		}
		
		int display()
		{
			if(isEmpty())
			{
				cout<<"Queue is Empty";
				return false;
			}
			
			int i=front;
			while(true)
			{
				cout<<s[i]<<"\t";
				
				if(i==rear) break;
				i=(i+1)%max;
			}
			cout<<endl;
			return true;
		}
};

int main()
{
	DeQueue q;
	int c,v;
	
	while(c<7)
	{
		cout<<"\n\nEnter : 1.enQueueRear  2.enQueueFront  3.deQueueRear  4.deQueueFront  5.Count  6.Display  7.Exit : ";
		cin>>c;
		
		switch (c)
		{
			case 1:
				cout<<"Enter value to enQueue : ";
				cin>>v;
				
				q.enQueueRear(v);
				break;   
				
			case 2:
				cout<<"Enter value to enQueue : ";
				cin>>v;
				
				q.enQueueFront(v);
				break;                                                   
				
			case 3:
				cout<<"Removed "<<q.deQueueRear();
				break;
				
			case 4:
				cout<<"Removed "<<q.deQueueFront();
				break;
				
			case 5:
				cout<<"No. of elements : "<<q.count();
				break;
				
			case 6:
				cout<<"Elements of Queue are : ";
				q.display();
				break; 
				
			case 7:
				exit(0);
				
		}
	}
	
	return 0;
}
