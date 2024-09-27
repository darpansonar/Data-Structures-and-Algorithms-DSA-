#include<iostream>
using namespace std;

void counting_sort(int a[],int n)
{
	int output[10],i;
	int count[10]={0,0,0,0,0,0,0,0,0,0};
	int max=9;
	
	//count of each element
	for(i=0;i<n;i++)
	count[a[i]]++;
	
	//cummulative count of each array
	for(i=1;i<=max;i++)
	count[i]=count[i]+count[i-1];
	
	//Index of each element in count array - place the elements in output array
	for(i=n-1;i>=0;i--)
	{
		output[count[a[i]]-1] = a[i];
		count[a[i]]--;
	}
	
	//copy sorted elements into original array
	for(i=0;i<n;i++)
	a[i]=output[i];
	
	cout<<"\n\nCounting Sort Array\n";
	for(i=0;i<n;++i)
	cout<<a[i]<<" ";
}

int main()
{
	int a[8]={1,3,2,4,1,6,3,5};
	int n=8,i;
	
	cout<<"\nUnsorted Array\n";
	for(i=0;i<n;++i)
	cout<<a[i]<<" ";
	counting_sort(a,n);
}
