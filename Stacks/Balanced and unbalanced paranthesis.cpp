#include<iostream>
#include<string.h>
using namespace std;
#define Max 10

int top=-1;
char data[Max];

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

void push(char x)
{
	if(!isFull())
	{
		top++;
		data[top]=x;
	}
}

char pop()
{
	if(isEmpty())
    {
        return '\0';
    }
        	
    else
    {
        int x=data[top];
        top--;
        return x;
    }
}

bool isMatchingPair(char open,char close)
{
	if((open == '(' && close == ')') || (open == '{' && close == '}') || (open == '[' && close == ']'))
	{
		return true;
	}
	
	else
	{
		return false;
	}
}

int main()
{
	char exp[Max];
	int i,x;
	cout<<"\nEnter character expression : ";
	cin>>exp;
	
	bool Balanced=true;
	
	for(i=0;i<strlen(exp);i++)
	{
		if(exp[i]=='[' || exp[i]=='{' || exp[i]=='(')
		{
			push(exp[i]);
		}
		
		else if(exp[i]==']' || exp[i]=='}' || exp[i]==')')
		{
			if(isEmpty())
			{
				Balanced=false;
				break;
			}
			
			else
			{
				char x=pop();
				
				if(!isMatchingPair(x,exp[i]))
				{
					Balanced=false;
					break;
				}
			}
		}
	}
	
	if(Balanced && isEmpty())
	{
		cout<<"Balanced Paranthesis";
	}
	
	else
	{
		cout<<"Unbalanced Paranthesis";
	}
	
	return 0;
}
