#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class heap
{
	public:
	int a[100];
	void input(int n);
	void display(int n);
	void maxheap(int a[],int n,int i);
	void minheap(int a[],int n,int i);
	void maxheapsort(int a[],int n);
	void minheapsort(int a[],int n);
};

void heap::input(int n)
{
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
}

void heap::display(int n)
{
	for(int i=0;i<n;i++)
	{
		cout<<a[i]<<" ";
	}
}
void heap::maxheap(int a[],int n,int i)
{
	int m=i;
	int left=2*i+1;
	int right=2*i+2;
	if(left<n && a[left]>a[m])
	{
		m=left;
	}
	if(right<n && a[right]>a[m])
	{
		m=right;
	}
	if(m!=i)
	{
		swap(a[i], a[m]);
		maxheap(a,n,m);
	}
}

void heap::minheap(int a[],int n,int i)
{
	int m=i;
	int left=2*i+1;
	int right=2*i+2;
	if(left<n && a[left]<a[m])
	{
		m=left;
	}
	if(right<n && a[right]<a[m])
	{
		m=right;
	}
	if(m!=i)
	{
		swap(a[i],a[m]);
		maxheap(a,n,m);
	}
}

void heap::maxheapsort(int a[],int n)
{
	for(int i=n/2-1;i>=0;i--)
	{
		maxheap(a,n,i);
	}
	for(int i=n-1;i>= 0;i--)
	{
		swap(a[0],a[i]);
		maxheap(a,i,0);
	}

}

void heap::minheapsort(int a[],int n)
{
	for(int i=n/2-1;i>=0;i--)
	{
		minheap(a,n,i);
	}
	for(int i=n-1;i>= 0;i--)
	{
		swap(a[0],a[i]);
		minheap(a,i,0);
	}
}

int main()
{
	heap h;
	int n,a=1;
	while(a==1)
	{
		cout<<"\nEnter number of elements you want to sort : ";
		cin>>n;
		cout<<"\n\nEnter the elements: "<<endl;
		h.input(n);
		cout<<"\nArray before sorting: "<<endl;
		h.display(n);
		cout<<"\n\nArray after Max Heapify: "<<endl;
		h.maxheapsort(h.a,n);
		h.display(n);
		cout<<"\n\nArray after Min Heapify: "<<endl;
		h.minheapsort(h.a,n);
		h.display(n);
		cout<<"\n\nTo continue enter 1 else 0: ";
		cin>>a;
	}
}
