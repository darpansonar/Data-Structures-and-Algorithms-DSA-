#include<iostream>
using namespace std;

void selection_sort(int a[],int n)
{
	int i,j,temp;
	
	for(i=0;i<n-1;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(a[i]>a[j])
			{
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
	
	cout<<"\nSelection Sorted\n";
	
	for(i=0;i<n;i++)
	{
		cout<<a[i]<<"\t";
	}
}

int main()
{
	int a[10],n,i;
	cout<<"\nEnter no. of elements : ";
	cin>>n;
	
	cout<<"\nEnter array elements : ";
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	
	cout<<"\nUnsorted array elements\n";
	for(i=0;i<n;i++)
	{
		cout<<a[i]<<"\t";
	}
	
	selection_sort(a,n);
	
	return 1;
}
