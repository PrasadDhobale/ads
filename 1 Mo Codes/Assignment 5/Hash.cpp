#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define max 100
class hash
{
	public:
		int arr1[max];
		int arr2[max];
		int flag[max];
		void withoutreplacement(int n);
		void display(int n);
		void withreplacement(int n);
		void chaining(int n);
};

class Node{
	public:
	    int data;
	    Node* next;
};

void hash::withoutreplacement(int n)
{
	for(int i=0;i<n;i++)
	{
		flag[i]=0;
		arr2[i]=-1;
	}
	cout<<"Enter Elements: "<<endl;
	for(int i=0;i<n;i++)
	{
		cin>>arr1[i];
	}
	for(int i=0;i<n;i++)
	{
		int h=arr1[i]%n;
		if(arr2[h]==-1)
		{
			arr2[h]=arr1[i];
			flag[h]=1;
		}
		else
		{
			int c=h+1;
			int flag1=0;
			while(c!=h && flag1==0)
			{
				if(flag[c]==0 && c<n)
				{
					arr2[c]=arr1[i];
					flag[c]=1;
					flag1=1;
					break;
				}
				else
				{
					if(c==n)
					{
						c=-1;
					}
					c++;
				}
			}
		}
	}
}

void hash::display(int n)
{
		cout<<"Hashing table is: "<<endl;
	for(int i=0;i<n;i++)
	{
		cout<<arr2[i]<<" ";
	}
	cout<<" "<<endl;
}

void hash::withreplacement(int n)
{
    cout << "Enter the elements: \n";

    for(int i=0; i<n; i++)
    {
        arr2[i] = 0;
    }

    for(int i=0; i<n; i++)
    {
        cin >> arr1[i];
        int k, m, j=0;
        k = m = arr1[i]%n;
        while(arr2[k] != 0)
        {
            k++;
        }
        arr2[k] = arr2[m];
        arr2[m] = arr1[i];    
    }
}

void hash::chaining(int n)
{
	Node* chain[n];
	int ele;
    for (int i = 0; i < n; i++) {
        chain[i] = NULL;
    }
    cout << "Enter element: "<<endl;
    for (int i = 1; i <= n; i++) {
        cin >> ele;
        int index = ele % n;

        Node* newNode = new Node();
        newNode->data = ele;
        newNode->next = NULL;

        if (chain[index] == NULL) {
            chain[index] = newNode;
        } else {
            Node* curr = chain[index];
            while (curr->next != NULL) {
                curr = curr->next;
            }
            curr->next = newNode;
        }
    }

    cout << "\nHash table with chaining: " << endl;
    for (int i = 0; i < n; i++) {
        cout << i << ": ";
        Node* curr = chain[i];
        while (curr != NULL) {
            cout << curr->data << " ";
            curr = curr->next;
        }
        cout << endl;
    }
}

int main()
{
	int n,ch;
	hash h;
	
	do
	{
		cout<<"\n1.Linear Probing without replacement\n2.Linear Probing with replacement\n3.Chaining\n4.Exit\nEnter your choice: ";
		cin>>ch;
		switch(ch)
		{
			case 1:
				{
					cout<<"Enter length of hashing table: ";
					cin>>n;
					h.withoutreplacement(n);
					h.display(n);
					break;
				}
			case 2:
				{
					cout<<"Enter length of hashing table: ";
					cin>>n;
					h.withreplacement(n);
					h.display(n);
					break;
				}
			case 3:
				{
					cout<<"Enter length of hashing table: ";
					cin>>n;
					h.chaining(n);
				}
			default:
				{
					break;
				}
		}
	}while(ch!=4);
}
