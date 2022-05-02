#include "HashTable.h"
#include<iostream>
using namespace std;

// Default constructor
template <class T1, class T2>
HashTable<T1,T2>::HashTable(){

    // set table size to 10
	tablesize = 10;

    // set table's new list to 10
    table = new List<HashNode<T1, T2>>[10];
}

// Parameterised constructor
template <class T1, class T2>
HashTable<T1,T2>::HashTable(int size){

    // set table size to size
    tablesize = size;

    // set table's new list to size
    table = new List<HashNode<T1, T2>>[size];
}

// Destructor for the HashTable class
template <class T1, class T2>
HashTable<T1,T2>::~HashTable(){
	    delete[] table;
}

// Hash Function for the Hash table
template <class T1, class T2>
int HashTable<T1,T2>::hashFunction(T1 k){
	
	int hash = 0;

    // set the hash value to the sum of the ASCII values of the first 3 characters
    hash = (int(k[0])+1*int(k[1])+3*int(k[2])) % tablesize;
    
    if (hash > 0 && hash <= tablesize)
    {
    	// return hash value if between 0 and size of hash table
        return hash; 
    }
    else
    {
    	// return -1 if hash value is out of range
        return -1;
    }
}

// Function to insert a key/value pair into the hash table.
template <class T1, class T2>
bool HashTable<T1,T2>::insert(T1 k, T2 v){
	
	// set index to hashfunctions' output 
	int index = hashFunction(k); 

	// create new node
    HashNode<T1, T2> newNode(k, v);

    // check if node exist in table 
    int exists = table[index].search(newNode); 

    if (exists == false)
    {
    	// add new node to table if node does not exist
        table[index].insert(newNode);

        // return true 
        return true; 
    }
    else 
    {
    	// return false if node exists 
        return false; 
    } 

}

// Function to update the value of the existing item in the hash table
template <class T1, class T2>
bool HashTable<T1,T2>::update(T1 k, T2 v){
	
	// set position to hashfunctions' output    
	int position = hashFunction(k); 

	// create new node
    HashNode<T1, T2> updateNode(k, v);

    // create node to represent old node 
    HashNode<T1, T2> oldNode(k, ""); 

	// search table to check if key exist in table
    int exists = table[position].search(oldNode); 

    if (exists == false)
    {
    	// return false if key does not exist in table
        return false; 
    }
    else
    {
        // delete old node at position if key exist in table
        table[position].remove(oldNode);

        // insert new data 
        table[position].insert(updateNode); 
        
        // return true
        return true; 
    }
}

// This function should find an item in the table with the key k and return true if the item is found, or false otherwise.
template <class T1, class T2>
bool HashTable<T1,T2>::lookup(T1 k, T2 &v){

	// create new node
	HashNode<T1, T2> searchNode(k, v); 

	// set position to hashfunctions' output
    int position = hashFunction(k); 
    
    // check if node to lookup exist
    int exists = table[position].search(searchNode); 

    if (exists == false)
    {
    	// return false if node to lookup does not exist
        return false; 
    }
    else
    {
    	// set v to value of node found in table if node exist
        v = searchNode.getValue();

        // return true 
        return true; 
    }
}

// Overloading of the output operator for a HashTable
template <class T1, class T2>
std::ostream& operator<<(std::ostream &output, const HashTable<T1,T2> &ht) {

	for (int i = 0; i < ht.tablesize; i++)
    {
    	// print array index and linked list surrounded by []
        cout << i << "[" << ht.table[i] << "]" << endl;
    }

    // return output
    return output;
}
