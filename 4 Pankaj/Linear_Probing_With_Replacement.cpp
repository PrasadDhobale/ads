#include <iostream>

using namespace std;

int main()
{
    int i, hash[100],choice,n,flag,item,key,flag1,temp;
    cout<<"\n\t Enter size of Array (Hash Table) :- ";
    cin>>n;
    //Empty Hash Table
    for(i=0;i<n;i++)
        hash[i]=-1;
    
    while(1)
    {
        cout<<"\n\t Following operations can be performed on Hash Table :- "<<endl;
        cout<<"\n\t\t 1. Insert";
        cout<<"\n\t\t 2. Search";
        cout<<"\n\t\t 3. Delete";
        cout<<"\n\t\t 4. Display";
        cout<<"\n\t\t 5. Exit"<<endl;
        cout<<"\n\t Enter your Choice :- ";
        cin>>choice;
        switch(choice)
        {
            case 1: flag=0;
                    flag1=0;
                    cout<<"\n\t Accept the item to insert in heap :- ";
                    cin>>item;
                    key= item % n;
                    
                    if(hash[key] == -1)
                    {
                        hash[key] = item;
                        flag=1;
                    }
                    else
                    {
                        temp=hash[key];
                        hash[key] = item;
                        flag=1;
                        
                        for(i=key+1;i<n;i++)
                        {
                            if(hash[i]==-1)
                            {
                                hash[i]=temp;
                                flag1=1;
                                break;
                            }
                        }
                    }
                    if(flag==1 && flag==1)
                        cout<<"\n\t\t ===== Item Inserted Succesfully ====="<<endl;
                    else
                        cout<<"\n\t\t ===== Old Item Not Inserted bco of Hash Overlow ====="<<endl;
                    break;
            case 2: flag=0;
                    cout<<"\n\t Accept the item to search in Heap :- ";
                    cin>>item;
                    key= item % n;
                    
                    for(i=key;i<n;i++)
                        if(hash[i]==item)
                        {
                            flag=1;
                            break;
                        }
                    if(flag==1)
                        cout<<"\n\t Item "<<item<<" present at "<<i<<"th index in the heap"<<endl;
                    else
                        cout<<"\n\t Item "<<item<<" does not exist in the heap"<<endl;                
                    break;
            case 3: cout<<"\n\t Accept the item to be deleted :- ";
                    cin>>item;
                    key= item % n;
                    hash[key] = item;
                    for(i=key;i<n;i++)
                        if(hash[i]==item)
                        {
                            flag=1;
                            break;
                        }
                    if(flag==1)
                    {
                        cout<<"\n\t Item "<<item<<" present at "<<i<<"th index in the hash table is delted"<<endl;
                        hash[i]=-1;
                    }
                    else
                        cout<<"\n\t Item "<<item<<" does not exist in the hash table"<<endl;                
                    
                    break;
            case 4: cout<<"\n\t Hash Table is :- ";
                    for(i=0;i<n;i++)
                        cout<<hash[i]<<" ";
                    cout<<endl;
                    break;
            case 5: exit(0);break;
            default : cout<<"\n\t\t ===== Invaild Choice ====="<<endl;break;
        }
    }
    return 0;
}
