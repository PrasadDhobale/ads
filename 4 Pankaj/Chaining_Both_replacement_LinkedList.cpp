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
            hashTable[i] = nullptr;
        }
    }

    // Hash function to map key to index
    int hashFunction(int key) {
        return key % tableSize;
    }

    // Insert a key into the hash table (without replacement)
    void insertKeyWithoutReplacement(int key) {
        int index = hashFunction(key);
        Node* newNode = new Node;
        newNode->data = key;
        newNode->next = nullptr;

        if (hashTable[index] == nullptr) {
            hashTable[index] = newNode;
        } else {
            Node* temp = hashTable[index];
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    // Insert a key into the hash table (with replacement)
    void insertKeyWithReplacement(int key) {
        int index = hashFunction(key);
        Node* newNode = new Node;
        newNode->data = key;
        newNode->next = nullptr;

        if (hashTable[index] == nullptr) {
            hashTable[index] = newNode;
        } else {
            Node* temp = hashTable[index];
            Node* prev = nullptr;
            while (temp != nullptr) {
                if (temp->data == key) {
                    // Key already exists, replace it
                    newNode->next = temp->next;
                    if (prev != nullptr) {
                        prev->next = newNode;
                    } else {
                        hashTable[index] = newNode;
                    }
                    delete temp;
                    return;
                }
                prev = temp;
                temp = temp->next;
            }
            prev->next = newNode;
        }
    }

    // Search for a key in the hash table
    bool searchKey(int key) {
        int index = hashFunction(key);
        Node* temp = hashTable[index];
        while (temp != nullptr) {
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
            while (temp != nullptr) {
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
        cout << "1. Insert a key (without replacement)" << endl;
        cout << "2. Insert a key (with replacement)" << endl;
        cout << "3. Search for a key" << endl;
        cout << "4. Print the hash table" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the key to insert (without replacement): ";
                cin >> key;
                hashTable.insertKeyWithoutReplacement(key);
                break;
            case 2:
                cout << "Enter the key to insert (with replacement): ";
                cin >> key;
                hashTable.insertKeyWithReplacement(key);
                break;
            case 3:
                cout << "Enter the key to search: ";
                cin >> key;
                if (hashTable.searchKey(key)) {
                    cout << "Key found!" << endl;
                } else {
                    cout << "Key not found!" << endl;
                }
                break;
            case 4:
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

