#include<iostream>
#include<string.h>
using namespace std;
#define MAX_SIZE 10

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
	char exp[MAX_SIZE];
	stack s;
	int opnd1,opnd2,n;
	
	cout<<"Enter length of exp : ";
	cin>>n;
	
	cout<<"Enter expression : ";
	for(int i=0;i<n;i++)
	{
		cin>>exp[i];
	}
	
	cout<<"Result of given postfix exp. : ";
	
	for(int i=0;i<n;i++)
	{
		if(exp[i]=='+' || exp[i]=='-' || exp[i]=='*' || exp[i]=='/' )
		{
			opnd1=s.pop();
			opnd2=s.pop();
			
			if(exp[i]=='+') s.push(opnd2+opnd1);
			else if(exp[i]=='-') s.push(opnd2-opnd1);
			else if(exp[i]=='*') s.push(opnd2*opnd1);
			else if(exp[i]=='/') s.push(opnd2/opnd1);
		}
		
		else if((exp[i] - '0')>=0 && (exp[i] - '0')<=9)
		{
			s.push(exp[i]-'0');  
		}
		
	}
	
	cout<<s.pop();
}
