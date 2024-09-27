#include<iostream>
using namespace std;

void insertionSort(int a[],int n)
{
	int i,j,temp;
	
	for(i=1;i<n;i++)
	{
		temp=a[i];
		for(j=i-1 ; j>=0 && a[j]>temp ; j--)
		{
			a[j+1]=a[j];
		}
		a[j+1]=temp;
	}
}

int main()
{
	int n,i;
	int a[n];
	
	cout<<"Enter no. of elements : ";
	cin>>n;	

	cout<<"Enter elements : ";
	for(i=0;i<n;i++)
	{
		cin>>a[i];
	}
	
	cout<<"Unsorted array : ";
	for(i=0;i<n;i++)
	{
		cout<<a[i]<<"	";
	}
	
	cout<<endl;
	insertionSort(a,n);
	
	cout<<"Sorted array   : ";
	for(i=0;i<n;i++)
	{
		cout<<a[i]<<"	";
	}
	
	return 0;
}
