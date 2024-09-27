#include<iostream>
using namespace std;
#define MAX_SIZE 3

int s[MAX_SIZE];
int top = -1;

bool isFull()
{
	if(top>=MAX_SIZE-1)
		return true;
	else
		return false;
}

bool isEmpty()
{
	//return top<=-1?true:false;
	if(top<=-1)
		return true;
	else
		return false;
}

bool push(int v)
{
	if(isFull())
		return false;
	
	else
	{
		top++;
		s[top]=v;
		return true;
	}
}

int pop()
{
	if (isEmpty())
		return INT_MIN;
		
	else
	{
		int val=s[top];
		top--;
		return val;
	}
}

void print()
{
	int i;
	cout<<"Contents of Stack are:";
	cout<<endl;
	
	for(i=top;i>=0;i--)
	{
		cout<<s[i]<<endl;
	}
}

int main()
{
	int c=0,v;
	while(c<6)
	{
		cout<<"\n\nEnter  1.Push  2.Pop  3.isEmpty  4.isFull  5.Print  6.Exit : ";
		cin>>c;
		
		switch(c)
		{
			case 1:
				cout<<"Enter the no. to be pushed : ";
				cin>>v;
				
				if(isFull())
					cout<<"Push unsucessfull";
				else
					push(v);
					cout<<"Pushed "<<v;
				break;
			
			case 2:
				if(isEmpty())
				cout<<"Pop unsuccessfull";
				
				else
				{
					cout<<"Popped "<<pop();
				}
				break;
				
			case 3:
				if(isEmpty())
					cout<<"Stack is empty";
					
				else
					cout<<"Stack is not empty";
				break;
					
			case 4:
				if(isFull()) 
					cout<<"Stack is full";
					
				else
					cout<<"Stack is not full";
			    break;
			    
			case 5:
				print();
				break;
				
		}
	}
}
