#include<iostream>
using namespace std;

void bubble_sort(int a[],int n)
{
	int i,j,temp;
	
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-(i+1);j++)   // or u can also take limits of j from j=0 to j<n-1
		// We are writing n-(i+1) so that steps are not repeated
		{
			if(a[j]>a[j+1])
			{
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
	}
	
	cout<<"\nBubble Sorted\n";
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
	
	bubble_sort(a,n);
	
	return 1;
}












