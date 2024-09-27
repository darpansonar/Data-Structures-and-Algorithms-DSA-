#include<iostream>
#include<cstring>
using namespace std;
#define max 10
#define DT char

class Stack
{
	private:
		DT data[max];
		int top;
		
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
		
		void push(DT v)
		{
			if(!isFull())
			{
				top++;
				data[top]=v;	
			}
		}
		
		char pop()
		{
			if(!isEmpty())
			{
				int x=data[top];
				top--;
				return x;
			}
		}
		
		char peek()
		{
			if(!isEmpty())
				return data[top];
			else
				return -1;
		}
};

int precedence(char op)
{
	if (op == '+' || op == '-') 
        return 1;
        
    else if (op == '*' || op == '/') 
        return 2;
        
    else 
        return 0;
}

int main()
{
	int i;
	char exp[max],opening_bracket;
	Stack s;
	
	cout<<"Enter an infix exp : ";
	cin>>exp;
	
	for(i=0;i<strlen(exp);i++)
	{
		if(exp[i]>='a' && exp[i]<='z')
		{
			cout<<exp[i];
		}
		
		else if(exp[i]=='(' || exp[i]=='{' || exp[i]=='[' )
		{
			s.push(exp[i]);
		}
		
		else if(exp[i]==')' || exp[i]=='}' || exp[i]==']' )
		{
			if(exp[i]==')') opening_bracket='(';
			else if(exp[i]=='}') opening_bracket='{';
			else if(exp[i]==']') opening_bracket='[';
			
			while(!s.isEmpty() && s.peek()!=opening_bracket )
			{
				cout<<s.pop();
			}
			
			s.pop();  // Remove the opening bracket
		}
		
		else if(exp[i]=='+' || exp[i]=='-' || exp[i]=='*' || exp[i]=='/')
		{
			while (!s.isEmpty() && precedence(s.peek()) >= precedence(exp[i])) 
			{
                cout<<s.pop();
            }
            
            s.push(exp[i]);
		}
	}
	
	while(!s.isEmpty())
	{
		cout<<s.pop();
	}
}

