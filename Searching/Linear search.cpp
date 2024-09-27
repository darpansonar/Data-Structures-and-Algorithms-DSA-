#include<iostream>
using namespace std;
int main()
{
	int n,i,a[100],num;
	
	cout<<"Enter no. of elements : ";
	cin>>n;
	
	cout<<"Enter elements : ";
	
	for(i=0 ; i<n ; i++)
	{
		cin>>a[i];
	}
	
	cout<<"Enter no. that is to be searched : ";
	cin>>num;
	
	for(i=0 ; i<n ; i++)
	{
		if(num==a[i])
		{
			cout<<num<<" found at position "<<i+1;
			break;
		}
	}
	
	if(i==n)
	{
		cout<<num<<" not found";
	}
	

}
