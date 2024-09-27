#include<iostream>
#include<cstring>
using namespace std;
#define max 10
#define DT int

class Stack
{
	private:
		DT data[max];
		int top=-1;
		
	public:
		Stack()
		{
			top=-1;
		}
		
		bool isEmpty()
		{
			if(top==-1) 
				return true;
			else 
				return false;
		}
		
		bool isFull()
		{
			if(top==max-1) 
				return true;
			else 
				return false;
		}
		
		void push(int v)
		{
			if(!isFull())
			{
				top++;
				data[top]=v;	
			}
		}
		
		int pop()
		{
			if(!isEmpty())
			{
				int x=data[top];
				top--;
				return x;
			}
		}
	
};

int main()
{
	int i,v,opnd1,opnd2;
	char exp[max];
	Stack s;
	
	cout<<"Enter prefix expression : ";
	cin>>exp;
	
	int len=strlen(exp);
	
	for(i=len-1;i>=0;i--)
	{
		if(exp[i]>='0' && exp[i]<='9')
		{
			s.push(exp[i]-'0');
		}
		
		else if(exp[i]=='+' || exp[i]=='-' || exp[i]=='*' || exp[i]=='/')
		{
			opnd1=s.pop();
			opnd2=s.pop();
			
			if(exp[i]=='+') 
				s.push(opnd1+opnd2);
				
			else if(exp[i]=='-')
				s.push(opnd1-opnd2);
				
			else if(exp[i]=='*')
				s.push(opnd1*opnd2);
				
			else if(exp[i]=='/')
				s.push(opnd1/opnd2);
		}
	}
	
	cout<<"Result of given prefix exp : "<<s.pop();
	
	return 0;
}

