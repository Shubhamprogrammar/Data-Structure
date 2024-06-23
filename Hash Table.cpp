#include <iostream>
#include <list>
#include <vector>
using namespace std;

// Hash Table class
class HashTable {
    int BUCKET; // Number of buckets
    vector<list<int>> table; // Array of lists to store keys

public:
    HashTable(int V); // Constructor

    // Inserts a key into the hash table
    void insertItem(int key);

    // Deletes a key from the hash table
    void deleteItem(int key);

    // Hash function to map values to key
    int hashFunction(int x) {
        return (x % BUCKET);
    }

    // Display the hash table
    void displayHash();
};

HashTable::HashTable(int b) {
    BUCKET = b;
    table.resize(BUCKET);
}

void HashTable::insertItem(int key) {
    int index = hashFunction(key);
    table[index].push_back(key);
}

void HashTable::deleteItem(int key) {
    int index = hashFunction(key);
    // Find the key in (index)th list
    list<int>::iterator i;
    for (i = table[index].begin(); i != table[index].end(); i++) {
        if (*i == key)
            break;
    }

    // If key is found in hash table, remove it
    if (i != table[index].end())
        table[index].erase(i);
}

void HashTable::displayHash() {
    for (int i = 0; i < BUCKET; i++) {
        cout << i;
        for (auto x : table[i])
            cout << " --> " << x;
        cout << endl;
    }
}

// Driver program
int main() {
    // Array that contains keys to be mapped
    int arr[] = {15, 11, 27, 8, 12};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Create a hash table with 7 buckets
    HashTable ht(7);

    // Insert the keys into the hash table
    for (int i = 0; i < n; i++)
        ht.insertItem(arr[i]);
        
    // Display the hash table
    ht.displayHash();
    // Delete a key
    ht.deleteItem(12);

    // Display the hash table
    ht.displayHash();

    return 0;
}

