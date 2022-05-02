#include "HashTable.h"
#include <iostream>
using namespace std;

HashTable::HashTable() {
    tablesize = 10;
    table = new HashNode[10];
}

// Parameterised constructor for the Hash Table class. Sets the array size used equal to the given parameter.
HashTable::HashTable(int size) {
    
    tablesize = size;
    table = new HashNode[size];
}

// destructor for the hash table class
HashTable::~HashTable() {
    delete [] table;
}

// Hash function for the hash table. Computes the hashed value based on the provided key, k
int HashTable::hashFunction(string k){

    // initialise hash value
    int hashValue = 0;

    // set hash value to the sum of the ASCII values of the first 3 characters 
    hashValue = (int(k[0])+1*int(k[1])+1*int(k[2])) % tablesize;


    // if hash value is between 0 and table size
    if (hashValue > 0 && hashValue <= tablesize) 
    {
        // return hash value
        return hashValue; 
    }
    else
    {
        // return -1 
        return -1; 
    }
}

// Function to insert a key/value pair into the hash table
bool HashTable::insert(string k, string v) {
 
    // initialise hashed value
    bool hashedValue = false; 

    // generate a hash value
    int index = hashFunction(k); 

    // set exist 
    int exist = search(k); 
    
    // initialise full 
    bool full = false; 
    
    // initialise count
    int count = 0; 

    for (int i = 0; i < tablesize; i++)
    {
        // if current table node is not empty
        if (table[i].getKey() != "")
        {
            // increment count by 1
            count++; 
        }
    }

    // if count is equal to table size 
    if (tablesize == count)
    {
        // set full
        full = true; 
    }

    // if key provided does not exist in table and table is not full
    if (exist == -1 && full != true)
    {
        // if table index node is empty
        if (table[index].getKey() == "")
        {
            // insert key and value in hashnode
            table[index] = HashNode(k, v); 

            // set hashed value 
            hashedValue = true; 
        }
        else
        {
            // loop through hash table 
            for (int i = 0; hashedValue == false && i < tablesize; i++)
            {
                // if new hash index node generated is empty
                if (table[(index + i) % tablesize].getKey() == "")

                {
                    // insert key and value in table
                    table[(index + i) % tablesize] = HashNode(k, v);

                    // set hashed value 
                    hashedValue = true; 
                }
            }
        } 
    }
    else 
    {
        // return false 
        return false; 
    }

    // if hashed value is true
    if (hashedValue == true)
    {
        // return true 
        return true; 
    }
    else
    {
        // return false 
        return false; 
    }
}

// Function should search for an item in the hash table with the given key value
int HashTable::search(string k){

    // generate hash value 
    int index = hashFunction(k); 
    
    // initialise position 
    int position = 0; 

    // initialise found
    bool found = false; 

    // if item at hash value index is same as key value
    if (table[index].getKey() == k)
    {
        // set position to original hash value
        position = index; 

        // set found to true
        found = true; 
    }
    else
    {
        for (int i = 0; found == false && i < tablesize; i++)
        {
            // if item at new hash value index is same as key value
            if (table[(index + i) % tablesize].getKey() == k)
    
            {
                // set position to new hash value
                position = (index + i) % tablesize;

                // set found
                found = true; 
            }
        }

    }  

    // if item was found
    if (found == true)
    {
        // return pos 
        return position;  
    }
    else 
    {
        // return -1 
        return -1; 
    }
}

// Function used to update an existing item in the hash table
bool HashTable::update(string k, string v) {

    int updateItem;

    // set updateItem to search functions' output   
    updateItem = search(k);

    if (updateItem == -1)
    {
        // return false if the key is not found
        return false; 
    }
    else 
    {
        // set node to new value
        table[updateItem] = HashNode(k, v); 
        
        // return true
        return true;
    } 
}

// Function used to find an item in the table with the key k and return its value
string HashTable::lookup(string k) {

    int lookupItem;    

    // set lookupItem as output of the search function
    lookupItem = search(k);

    // if item is not found in hash table
    if (lookupItem == -1)        
    {
        // return empty string
        return ""; 
    }
    else
    {
        // initialise lookupValue
        string lookupValue = ""; 

        // set lookupValue to stored value
        lookupValue = table[lookupItem].getValue();

        // return lookupValue
        return lookupValue;
    }
}

// Overloading of the output operator for a Hash Table 
ostream& operator<<(ostream &output, const HashTable &ht) {

    // Print the array index and HashNode 
    for(int i=0; i < ht.tablesize; i++) {
        output << i << ":" << ht.table[i].getKey() << ":" << ht.table[i].getValue() << endl;

    }

    // return output
    return output;
}
