#include<iostream>
using namespace std;
class Heap
{
	public:
		int arr[100];
		void getarray(int n);
		void printarray(int n);
		void maxheapify(int arr[],int n,int i);
		void maxheapsort(int arr[],int n);
		void minheapify(int arr[],int n, int i);
		void minheapsort(int arr[],int n);
};

//Insert value
void Heap:: getarray(int n)
{
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
}

//display value
void Heap::printarray(int n)
{
	for(int i=0;i<n;i++)
	{
		cout<<" "<<arr[i];
	}
}

//max heapify
void Heap::maxheapify(int arr[],int n,int i)
{
	int max = i;
	int left = 2*i+1;
	int right = 2*i+2;
	if (left < n && arr[left] > arr[max])
	{
		max = left;
	}
	if (right < n && arr[right] > arr[max])
	{
		max = right;
	}
	if (max != i)
	{
		swap(arr[i], arr[max]);
		maxheapify(arr, n, max);
	}
}

//max heap sort
void Heap::maxheapsort(int arr[],int n)
{
	for (int i=n/2-1;i>=0;i--)
	{
		maxheapify(arr,n,i);
	}
	for(int i=n-1;i>=0;i--)
	{
		swap(arr[0],arr[i]);
		maxheapify(arr,i,0);
	}
}

void Heap::minheapify(int arr[],int n,int i)
{
	int max = i;
	int left = 2*i+1;
	int right = 2*i+2;
	if (left < n && arr[left] < arr[max])
	{
		max = left;
	}
	if (right < n && arr[right] < arr[max])
	{
		max = right;
	}
	if (max != i)
	{
		swap(arr[i], arr[max]);
		maxheapify(arr, n, max);
	}
}

//min heapsort
void Heap::minheapsort(int arr[],int n)
{
	for (int i=n/2-1;i>=0;i--)
	{
		minheapify(arr,n,i);
	}
	for(int i=n-1;i>=0;i--)
	{
		swap(arr[0],arr[i]);
		minheapify(arr,i,0);
	}
}

int main()
{
	Heap h1;
	int n,a=1;
	cout<<"\n Heap Sort Program";
	while(a==1)
	{
		cout<<"\n ----------------------------------------"<<endl;
		cout<<"\n Enter The Number of Elements: ";
		cin>>n;
		cout<<"\n Enter The Array Elements: "<<endl;
		h1.getarray(n);
		cout<<"\n ----------------------------------------"<<endl;
		cout<<"\n Array Before Sorting:-"<<endl; h1.printarray(n);
		cout<<"\n ----------------------------------------"<<endl;
		h1.maxheapsort(h1.arr,n);
		cout<<"\n Array After Sorting(Max Heapify):- "<<endl;
		h1.printarray(n);
		cout<<"\n ----------------------------------------"<<endl;
		h1.minheapsort(h1.arr,n);
		cout<<"\n Array After Sorting(Min Heapify):- "<<endl;
		h1.printarray(n);
		cout<<"\n ----------------------------------------"<<endl;
		cout<<"\n Do You Want to Continue?Press 1 Else 0: ";
		cin>>a;
	}
}
