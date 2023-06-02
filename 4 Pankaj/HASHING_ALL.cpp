#include <iostream>
using namespace std;
const int MAX = 5;
class HashTable
{
private:
int key[MAX], value[MAX], status[MAX];
public:
int hash(int key);
void insertLinearChainingWithReplacement(int key, int value);
void insertLinearChainingWithoutReplacement(int key, int value);
void insertLinearProbingWithReplacement(int key, int value);
void insertLinearProbingWithoutReplacement(int key, int value);
int search(int key);
void remove(int key);
void printTable();
HashTable()
{
for (int i = 0; i < MAX; i++)
{
status[i] = 0;
}
}
};
int HashTable::hash(int key)
{
return key % MAX;
}
void HashTable::insertLinearChainingWithReplacement(int k, int v)
{
int index = hash(k);
if (status[index] == 0)
{
key[index] = k;
value[index] = v;
status[index] = 1;
}
else
{
while (status[index] == 1)
{
index = (index + 1) % MAX;
}
key[index] = k;
value[index] = v;
status[index] = 1;
}
}
void HashTable::insertLinearChainingWithoutReplacement(int k, int v)
{
int index = hash(k);
if (status[index] == 0)
{
key[index] = k;
value[index] = v;
status[index] = 1;
}
else
{
while (status[index] == 1 && key[index] != k)
{
index = (index + 1) % MAX;
}
if (status[index] != 1)
{
key[index] = k;
value[index] = v;
status[index] = 1;
}
else
{
cout << "Key already exists, insertion failed" << endl;
}
}
}
void HashTable::insertLinearProbingWithReplacement(int k, int v)
{
int index = hash(k);
if (status[index] == 0)
{
key[index] = k;
value[index] = v;
status[index] = 1;
}
else
{
int newIndex = (index + 1) % MAX;
while (newIndex != index && status[newIndex] == 1)
{
newIndex = (newIndex + 1) % MAX;
}
if (newIndex == index)
{
cout << "Hash table is full, insertion failed" << endl;
}
else
{
key[newIndex] = k;
value[newIndex] = v;
status[newIndex] = 1;
}
}
}
void HashTable::insertLinearProbingWithoutReplacement(int k, int v)
{
int index = hash(k);
if (status[index] == 0)
{
key[index] = k;
value[index] = v;
status[index] = 1;
}
else
{
int newIndex = (index + 1) % MAX;
while (newIndex != index && (status[newIndex] == 1 && key[newIndex] != k))
{
newIndex = (newIndex + 1) % MAX;
}
if (newIndex == index)
{
cout << "Hash table is full, insertion failed" << endl;
}
else if (status[newIndex] == 1 && key[newIndex] == k)
{
cout << "Key already exists, insertion failed" << endl;
}
else
{
key[newIndex] = k;
value[newIndex] = v;
status[newIndex] = 1;
}
}
}
int HashTable::search(int k)
{
int index = hash(k);
while (status[index] != 0 && key[index] != k)
{
index = (index + 1) % MAX;
}
if (status[index] == 0)
{
cout << "Key not found" << endl;
return -1;
}
else
{
return value[index];
}
}
void HashTable::remove(int k)
{
int index = hash(k);
while (status[index] != 0 && key[index] != k)
{
index = (index + 1) % MAX;
}
if (status[index] == 0)
{
cout << "Key not found" << endl;
}
else
{
status[index] = -1;
cout << "Key-value pair removed" << endl;
}
}
void HashTable::printTable()
{
cout << "Hash Table:" << endl;
cout << "Index\tKey\tValue" << endl;
for (int i = 0; i < MAX; i++)
{
cout << i << "\t";
if (status[i] == 1)
{
cout << key[i] << "\t" << value[i];
}
else
{
cout << "-" << "\t" << "-";
}
cout << endl;
}
}
int main()
{
HashTable hashTable;
int choice, key, value;
do
{ cout << "*********************Hashing***********************"<<endl;
cout << "\n1. Insert (linear chaining with replacement)" << endl;
cout << "2. Insert (linear chaining without replacement)" << endl;
cout << "3. Insert (linear probing with replacement)" << endl;
cout << "4. Insert (linear probing without replacement)" << endl;
cout << "5. Search" << endl;
cout << "6. Delete" << endl;
cout << "7. Display" << endl;
cout << "8. Exit" << endl;
cout << "Enter your choice: ";
cin >> choice;
switch (choice)
{
case 1:
cout << "Enter key and value: ";
cin >> key >> value;
hashTable.insertLinearChainingWithReplacement(key, value);
break;
case 2:
cout << "Enter key and value: ";
cin >> key >> value;
hashTable.insertLinearChainingWithoutReplacement(key, value);
break;
case 3:
cout << "Enter key and value: ";
cin >> key >> value;
hashTable.insertLinearProbingWithReplacement(key, value);
break;
case 4:
cout << "Enter key and value: ";
cin >> key >> value;
hashTable.insertLinearProbingWithoutReplacement(key, value);
break;
case 5:
cout << "Enter key to search: ";
cin >> key;
value = hashTable.search(key);
if (value != -1)
{
cout << "Value of key " << key << " is " << value << endl;
}
break;
case 6:
cout << "Enter key to remove: ";
cin >> key;
hashTable.remove(key);
break;
case 7:
hashTable.printTable();
break;
case 8:
cout << "Exiting..." << endl;
break;
default:
cout << "Invalid choice" << endl;
break;
}
} while (choice != 8);
return 0;
}
