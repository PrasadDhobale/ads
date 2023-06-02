#include <iostream>
using namespace std;

class CuckooFilter
{
 public:
    string hashtable[50][10];
    int table_size;
    int buckets;

    CuckooFilter(int s, int b)
    {
        table_size = s;
        buckets = b;

        for(int i=0;i<table_size;i++)
        {
            for(int j=0;j<buckets;j++)
            {
                hashtable[i][j] = "";
            }
        }
    }

    void store_data_in_filter(string s);
    int hash_function1(string s);
    int hash_function2(string s);
};

int CuckooFilter::hash_function1(string s)
{
    int hashvalue = 0;

    for(unsigned int i=0;i<s.length();i++)
    {
        hashvalue = hashvalue + (int)s[i];
    }
    hashvalue = hashvalue % table_size;
    return hashvalue;
}

int CuckooFilter::hash_function2(string s)
{
    int hashvalue = 0;

    for(unsigned int i=0;i<s.length();i++)
    {
        hashvalue = hashvalue + ((int)s[i]*7);
    }
    hashvalue = hashvalue % table_size;
    return hashvalue;
}

void CuckooFilter::store_data_in_filter(string s)
{
    int hv1 = hash_function1(s);
    int hv2 = hash_function2(s);
    int loop_ctr = 0;
    int i, j;
    if(hashtable[hv1][0] == s)
    {
        cout<<"\n The data is already present in the hash table at location "<<hv1;
    }
    else if(hashtable[hv2][1] == s)
    {
        cout<<"\n The data is already present in the hash table at location "<<hv2;
    }
    else
    {
        cout<<"\n Inserting the key : "<<s<<" in hash table";
        cout<<"\n Hash value 1 : "<<hv1;
        cin.get();
        
        if(hashtable[hv1][0] == "")
        {
            hashtable[hv1][0] = s;
            loop_ctr++;
            cout<<"\n\nIndex       Table1      Table2";
            for(i=0;i<table_size;i++)
            {
                cout<<"\n  "<<i;
                for(j=0;j<buckets;j++)
                {
                    cout<<"          "<<hashtable[i][j];
                }
            }
        }
        else  
		{
            int bucket_flag = 1;
            while(1)
            {
                if(loop_ctr == table_size*buckets)
                {
                    cout<<"\n The loop is detected.  Data can not be placed.  Try using other hash function";
                    break;
                }
                
                if(bucket_flag == 1)
                {
                    hv1 = hash_function1(s);
                    cout<<"\n Inserting the key : "<<s<<" in hash table 1";
                    cout<<"\n Hash value 1 : "<<hv1;
                    cin.get();
                    
                    if(hashtable[hv1][0] != "")
                    {
                        string temp = hashtable[hv1][0];
                        hashtable[hv1][0] = s;
                        bucket_flag = 2;
                        s = temp;
                        loop_ctr++;

                        cout<<"\n\nIndex       Table1      Table2";
                        for(i=0;i<table_size;i++)
                        {
                            cout<<"\n  "<<i;
                            for(j=0;j<buckets;j++)
                            {
                                cout<<"          "<<hashtable[i][j];
                            }
                        }
                    }
                    else 
                    {
                        hashtable[hv1][0] = s;
                        loop_ctr++;

                        cout<<"\n\nIndex       Table1      Table2";
                        for(i=0;i<table_size;i++)
                        {
                            cout<<"\n  "<<i;
                            for(j=0;j<buckets;j++)
                            {
                                cout<<"          "<<hashtable[i][j];
                            }
                        }
                        break;
                    }
                }
                else if(bucket_flag == 2)
                {
                    hv2 = hash_function2(s);
                    cout<<"\n Inserting the key : "<<s<<" in hash table 2";
                    cout<<"\n Hash value 2 : "<<hv2;
                    cin.get();
                    if(hashtable[hv2][1] != "")
                    {
                        string temp = hashtable[hv2][1];
                        hashtable[hv2][1] = s;
                        bucket_flag = 1;
                        s = temp;
                        loop_ctr++;

                        cout<<"\n\nIndex       Table1      Table2";
                        for(i=0;i<table_size;i++)
                        {
                            cout<<"\n  "<<i;
                            for(j=0;j<buckets;j++)
                            {
                                cout<<"          "<<hashtable[i][j];
                            }
                        }
                    }
                    else
                    {
                        hashtable[hv2][1] = s;
                        loop_ctr++;

                        cout<<"\n\nIndex       Table1      Table2";
                        for(i=0;i<table_size;i++)
                        {
                            cout<<"\n  "<<i;
                            for(j=0;j<buckets;j++)
                            {
                                cout<<"          "<<hashtable[i][j];
                            }
                        }
                        break;
                    }
                }
            }
        }
    }
}

int main()
{
    CuckooFilter cf(10,2);
    int ch;
    string s;
    while(1)
    {
        cout<<"\n Enter the data to be stored : ";
        cin>>s;
        cf.store_data_in_filter(s);
        cout<<"\nDo you want to enter other data (0/1) : ";
        cin>>ch;
        if(ch!=1)
            break;
    }
    return 0;
}
