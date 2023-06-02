#include<iostream>
using namespace std;

int *LP_withoutReplacement(int arr[],int len,int size)
{
	int ele;
	for(int i = 0 ; i < len ; i++)
	{
		cin>>ele;
		if(arr[ele % size] == -1)
		{
			arr[ele % size] = ele;
		}
		else
		{
			for(int j = 1 ; j < size ; j++)
			{
				if(arr[(ele + j) % size] == -1)
				{
					arr[(ele + j) % size] = ele;
					break;
				}
			}
		}
	}
	return arr;
}


int *LP_with_Replacement(int arr[],int len,int size)
{
	int ele;
	for(int i = 0 ; i < len ; i++)
	{
		cin>>ele;
		if(arr[ele % size] == -1)
		{
			arr[ele % size] = ele;
		}
		else
		{
			int temp = arr[ele % size]; //changes
			arr[ele % size] = ele; //CHANGES
			
			for(int j = 1 ; j < size ; j++)
			{
				if(arr[(ele + j) % size] == -1)
				{
					arr[(ele + j) % size] = temp;//change
					break;
				}
			}
		}
	}
	return arr;
}

void display(int n,int *ptr)
{
	for(int i = 0 ; i < n ; i++)
	{
		cout<<endl<<i<<" "<<ptr[i];
	}
}

int main()
{
	
	int *ptr,size,len,choice;
	
	cout<<"Enter Bucket Size"<<endl;
	cin>>size;
	cout<<"Enter Length"<<endl;
	cin>>len;
	int arr[size];
	
	
	do{
	cout<<"\n1.Linear Probing  without replacement"<<endl;
	cout<<"2.Linear Probing with replacement"<<endl;
	cout<<"Enter your choice: ";
	cin>>choice;
	switch(choice)
	{
		case 1:
			{
				for(int i=0;i<size;i++)
					arr[i]=-1;
				cout<<"Enter the data elements one by one: ";
		        ptr = LP_withoutReplacement(arr,len,size);
		        display(size,ptr);
	    	}
	            break;
	        
	    case 2:
	    	{
		    	for(int i=0;i<size;i++)
					arr[i]=-1;
				cout<<"Enter the data elements one by one: ";
		    	ptr=LP_with_Replacement(arr,len,size);
		    	display(size,ptr);
		    	 break;
	    	}
		}
	}while(choice != 3);
		       
}
