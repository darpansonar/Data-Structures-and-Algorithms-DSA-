#include<iostream>
using namespace std;
#define MAX 5

int rear,front;
int data[MAX];
int x;

//Insert_rear 
//Insert_front
//Delete_rear
//Delete_front
//Display

void init()
{
	rear=-1;
	front=-1;
}

void insert_rear()
{
	cout<<"Enter data : ";
	cin>>x;
	
	if(rear==-1)
	{
		rear=front=0;
		data[rear]=x;
		cout<<"Inserted "<<x;
	}
	
	else
	{
		rear=rear+1;
		data[rear]=x;
		cout<<"Inserted "<<x;
	}
}

void del_front()
{
	int x;
	x=data[front];
	
	if(rear==front)
	{
		rear=-1;
		front=-1;
		cout<<"Queue is empty";
	}
	
	else
	{
		front=front+1;
		cout<<"Deleted "<<x;
	}
}

void insert_front()
{
	int x;
	cout<<"Enter data : ";
	cin>>x;
	
	if(rear==-1)
	{
		rear=front=0;
		data[front]=x;
		cout<<"Inserted "<<x;
	}
	
	else
	{
		front=front-1;
		data[front]=x;
		cout<<"Inserted "<<x;
	}
}

void del_rear()
{
	int x;
	x=data[rear];
	
	if(rear==front)
	{
		rear=-1;
		front=-1;
	}
	
	else
	{
		rear=rear-1;
		cout<<"Deleted "<<x;
	}
	
}

void display()
{
	int i;
	
	if(rear==-1)
	{
		cout<<endl<<"Queue is empty";
	}
	
	else
	{
		cout<<endl;
		cout<<"Queue : ";
		for(i=front;i<=rear;i++)
		{
			cout<<data[i]<<"\t";
		}
	}
}

int main()
{
	int c=0,x;
	
	init();
	
	while(c!=6)
	{
		cout<<"\n\nEnter : 1.Insert_rear  2.Insert_front  3.Delete_rear  4.Delete_front  5.Display  6.exit : ";
		cin>>c;
		
		switch(c)
		{
			case 1:
				if(rear!=MAX-1)
					insert_rear();
				else
					cout<<"Queue is full";
					break;
			
			case 2:
				if(rear!=MAX-1)
					insert_front();
				else
					cout<<"Queue is full";
					break;
			
			case 3:
				if(rear!=-1)
					del_rear();
				else
					cout<<"Queue is empty";
					break;
					
			case 4:
				if(rear!=-1)
					del_front();
				else
					cout<<"Queue is empty";
					break;
					
			case 5:
				cout<<"Displaying queue : ";
				display();
				break;
				
			case 6:
				break;
				break;
				
			default:
				cout<<"Wrong choice";
		}
	}
	return 0;
}

