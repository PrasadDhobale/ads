#include <iostream>
using namespace std;

// Node structure for linked list
struct Node {
    int data;
    Node* next;
};

// Hash Table class
class HashTable {
private:
    int tableSize;
    Node** hashTable;

public:
    HashTable(int size) {
        tableSize = size;
        hashTable = new Node*[tableSize];
        for (int i = 0; i < tableSize; i++) {
            hashTable[i] = NULL;
        }
    }

    // Hash function to map key to index
    int hashFunction(int key) {
        return key % tableSize;
    }

    // Insert a key into the hash table
    void insertKey(int key) {
        int index = hashFunction(key);
        Node* newNode = new Node;
        newNode->data = key;
        newNode->next = NULL;

        if (hashTable[index] == NULL) {
            hashTable[index] = newNode;
        } else {
            Node* temp = hashTable[index];
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    // Search for a key in the hash table
    bool searchKey(int key) {
        int index = hashFunction(key);
        Node* temp = hashTable[index];
        while (temp != NULL) {
            if (temp->data == key) {
                return true;
            }
            temp = temp->next;
        }
        return false;
    }

    // Print the hash table
    void printTable() {
        for (int i = 0; i < tableSize; i++) {
            cout << "Index " << i << ": ";
            Node* temp = hashTable[i];
            while (temp != NULL) {
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        }
    }
};

int main() {
    int size, choice, key;
    cout << "Enter the size of the hash table: ";
    cin >> size;

    HashTable hashTable(size);

    do {
        cout << "1. Insert a key" << endl;
        cout << "2. Search for a key" << endl;
        cout << "3. Print the hash table" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the key to insert: ";
                cin >> key;
                hashTable.insertKey(key);
                break;
            case 2:
                cout << "Enter the key to search: ";
                cin >> key;
                if (hashTable.searchKey(key)) {
                    cout << "Key found!" << endl;
                } else {
                    cout << "Key not found!" << endl;
                }
                break;
            case 3:
                hashTable.printTable();
                break;
            case 0:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }

        cout << endl;
    } while (choice != 0);

    return 0;
}
