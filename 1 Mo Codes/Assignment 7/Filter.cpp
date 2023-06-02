#include<iostream>
#include<bits/stdc++.h>
#include<string>
using namespace std;

#define MAX 100
class bloom{
 public:
 	int m;
	string arrin[MAX];
	int arr[MAX];
	bloom()
	{
	   for (int i = 0; i < MAX; i++)
	   {
	       arr[i] = 0;
	   }
	}
 	void input();
 	void bloomwork();
};

class cuckoo
{
	public:
		int c1[10],c2[10],num;
		cuckoo()
		{
			for(int i=0;i<10;i++)
			{
				c1[i]=c2[i]=0;
			}
		}
		void insert(int num,int size);
		void display(int size);
};

void bloom::input()
{
	cout<<"Enter the no of string"<<endl;
    cin>>m;
    cout<<"Enter the string char"<<endl;
    for (int i = 0; i < m; i++)
    {
        cin>>arrin[i];
    }
}
void bloom::bloomwork()
{

    for (int i = 0; i < m; i++)
    {
        int hash1= 0;
        string s = arrin[i];
        for (int j = 0; j < s.size(); j++)
        {
            hash1 = hash1+int(s[j]);
        }
        
        int h1 = (2*hash1)%m;
        int h2 = ((hash1/2)+3)%m;

        arr[h1] = 1;
        arr[h2] = 1;
    }
    for (int i = 0; i < m; i++)
    {
        cout<<arr[i]<<endl;
    }
    

}

void cuckoo::insert(int num,int size)
{
	int a=num%size;
	if(c1[a]==0)
	{
		c1[a]=num;
	}
	else
	{
		int temp;
		temp=c1[a];
		c1[a]=num;
		int b=((temp/size)%size);
		if(c2[b]==0)
		{
			c2[b]=temp;
		}
		else
		{
			insert(temp,size);
		}
	}
	display(size);
}

void cuckoo::display(int size)
{
	cout<<endl<<"Hashtable 1 : ";
	for(int i=0;i<size;i++)
	{
		cout<<c1[i]<<" ";
	}
	cout<<endl<<"Hashtable 2 : ";
	for(int i=0;i<size;i++)
	{
		cout<<c2[i]<<" ";
	}
	cout<<endl;
}

int main()
{
	bloom obj;
	cuckoo c;
	int ch;
	do
	{
		cout<<"\n1.Bloom Filter\n2.Cuckoo Filter\n3.Exit\nEnter your choice: ";
		cin>>ch;
		switch(ch)
		{
			case 1:
				{
					obj.input();
					cout<<"\n";
						cout<<"Final Hash Table"<<endl;
						obj.bloomwork();
						break;
				}
			case 2:
				{
					int a=1;
					while(a==1)
					{
						int num;
						cout<<"\nEnter number to be inserted: ";
						cin>>num;
						c.insert(num,10);
						cout<<"\nTo insert more enter 1 else 0: ";
						cin>>a;
					}
					break;
				}
			default:
				{
					break;
				}
		}
	}while(ch!=3);
}
