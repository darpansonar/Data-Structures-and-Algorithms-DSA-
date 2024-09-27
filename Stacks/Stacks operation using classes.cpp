#include<iostream>
using namespace std;
#define MAX_SIZE 5

class stack
{
	private:
		int s[MAX_SIZE];
		int top;
		
	public:
		stack()
		{
			top=-1;
		}
		
		bool isFull()
		{
			if(top>=MAX_SIZE-1)
				return true;
			else
				return false;
		}
	
		bool isEmpty()
		{
			return top<=-1?true:false;
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
};

int main()
{
	int option=0,v;
	stack s;
	
	while(option<6)
	{
		cout<<"\nEnter  1.Push  2.Pop  3.isEmpty  4.isFull  5.Print  6.Exit  : ";
		cin>>option;
		
		switch(option)
		{
			case 1: 
				cout<<"Enter the no. to be pushed : ";
				cin>>v;
				if(!s.push(v)) cout<<"Push unsuccessful";
				break;
				
			case 2:
				if(s.isEmpty()) cout<<"Pop unsuccessful";
				else cout<<"Poped : "<<s.pop();
				break;
				
			case 3:
				if(s.isEmpty()) cout<<"Empty stack";
				else cout<<"Stack is not empty";
				break;
				
			case 4:
				if(s.isFull()) cout<<"Full Stack";
				else cout<<"Stack is not full";
				break;
				
			case 5:
				s.print();
				break;
		}
	}
	return 0;
}
