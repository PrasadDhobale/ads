#include <iostream>
using namespace std;


 
  void printarr(int arr[], int s)
{

	for(int i=0;i<s;i++)
	{
    cout << arr[i] << " ";
    cout << " ";	
	}
}
void MaxHeapify(int arr[], int s, int i)
{
	int Max = i;
    int LC = 2 * i + 1;
    int RC = 2 * i + 2;
    
    if (LC < s && arr[LC] > arr[Max])
    {
	
      Max = LC;
    }
    
    if (RC < s && arr[RC] > arr[Max])
    {
	
      Max = RC;
    }
      
    if (Max != i) 
	{
      swap(arr[i], arr[Max]);
      MaxHeapify(arr, s, Max);
      
    }
}

void heapSort(int arr[], int s) {
  

    for (int i = s/ 2 - 1; i >= 0; i--)
    {
	
      MaxHeapify(arr, s, i);
    }
    
    cout <<"\n Heap is :- ";
    
    printarr(arr, s);
  

    for (int i = s - 1; i >= 0; i--) 
    {
      swap(arr[0], arr[i]);
      
      MaxHeapify(arr, i, 0);
    
    }
  }
 

int main()
{
	int s;
	cout<<"Enter Size of Array:";
	cin>>s;

	int arr[s];
	
	for(int i=0;i<s;i++)
	{
	  	cout<<"Enter Array Element "<<i<<":";
	  	cin>>arr[i];
	}
	
	
	cout << "\n Array Before Sorting :- ";
    printarr(arr, s);
    
    heapSort(arr, s);
  
    cout << "\n Array After Sorting is :- ";
    printarr(arr, s);
	
	
}
