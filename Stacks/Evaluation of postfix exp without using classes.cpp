#include<iostream>
#include<string.h>
using namespace std;
#define Max 10

int top=-1;
int data[Max];

bool isEmpty()
{
	if(top==-1) 
		return true;
	else 
		return false;
}

bool isFull()
{
	if(top==Max-1) 
		return true;
	else 
		return false;
}

void push(int x)
{
	if(!isFull())
	{
		top++;
		data[top]=x;
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

int main()
{
	int i,opnd1,opnd2;
	char exp[Max];
	
	cout<<"\nEnter numeric expression : ";
	cin>>exp;
	
	for(i=0;i<strlen(exp);i++)
	{
		if(exp[i]>='0' && exp[i]<='9')
			push(exp[i] - '0'); //to convert char to int
			
		if(exp[i]=='+' || exp[i]=='-' || exp[i]=='*' || exp[i]=='/' )
		{
			opnd1=pop();
			opnd2=pop();
			
			if(exp[i]=='+')      push(opnd2 + opnd1); 
			else if(exp[i]=='-') push(opnd2 - opnd1); 
			else if(exp[i]=='*') push(opnd2 * opnd1);
			else if(exp[i]=='/') push(opnd2 / opnd1);
			
		}
	}
	
	cout<<data[top];	
	
	return 0;	
}












