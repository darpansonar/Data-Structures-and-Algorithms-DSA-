#include<iostream>
using namespace std;
int main()
{
	int n,i,a[i],num;
	
	cout<<"Enter no. of elements : ";
	cin>>n;
	
	cout<<"Enter elements : ";
	for(i=0 ; i<n ; i++)
	{
		cin>>a[i];
	}
	
	cout<<"Enter no. that is to be searched : ";
	cin>>num;
	
	// l=lower bound , u=upper bound
	
	int l=0 , u=n-1 , mid;
	mid=(l+u)/2;
	
	while(l<=u)
	{
		if(num==a[mid])
		{
			cout<<num<<" found at location "<<mid+1;
			break;
		}
		
		else if(num>a[mid])
		{
			l=mid+1;
		}
		
		else
		{
			u=mid-1;
		}
		mid=(l+u)/2;
	}
	
	if(l>u)
	{
		cout<<"Error";
	}
	
}
