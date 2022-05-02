#include "HashTable.h"
#include <iostream>
#include <typeinfo>
#include <sstream>
#include <cmath>
using namespace std;

/**
 * @brief Construct a new HashTable with a default table size of 10
 * 
 * @tparam T1 The key parameter type
 * @tparam T2 The value parameter type 
 */
template <class T1, class T2>
HashTable<T1,T2>::HashTable() {
    tablesize = 10;
    table = new List<HashNode<T1, T2>>[tablesize];
}

/**
 * @brief Constructs a new HashTable with the specified table size
 * 
 * @tparam T1 The key parameter type
 * @tparam T2 The value parameter type 
 * @param size The amount of slots in the HashTable
 */
template <class T1, class T2>
HashTable<T1,T2>::HashTable(int size) {
    tablesize = size;
    table = new List<HashNode<T1, T2>>[tablesize];
}

/**
 * @brief Destroys a HashTable
 * 
 * @tparam T1 The key parameter type
 * @tparam T2 The value parameter type 
 */
template <class T1, class T2>
HashTable<T1,T2>::~HashTable() {
    // Free up memory taken up by HashTable array
    delete[] table;
}

/**
 * @brief Hashes the key value k to return a value in the domain of the table indices
 * 
 * @tparam T1 The key parameter type
 * @tparam T2 The value parameter type 
 * @param k The key to hash
 * @return int The hash value
 */
template <class T1, class T2>
int HashTable<T1,T2>::hashFunction(T1 k) {
    /***************************************************************
    *   DUE TO THE CONSTRAINTS OF THIS PROJECT, EVERY TYPE WILL
    *   BE HASHED BASED ON THEIR STRING OUTPUT AS DEFINED IN THE
    *   OUTPUT OPERATOR OVERLOAD 
    * 
    *   STRING HASHING
    * 
    *   In the case of an string key, the hash function calculates
    *   the hash using a modular polynomial rolling hash function  
    *   of the following formula:
    * 
    *       h(k) = Σ[i=0][n-1] (k[i] * p^n-i) mod tablesize,
    * 
    *   where k is the string, n is the length of the string, and
    *   p is a chosen prime number.
    * 
    *   Using Horner's method, we can rewrite this as 
    *       
    *       h(k[i]) = (h(k[i-1]) * p + k[i]) mod tablesize,
    * 
    *   which allows us to take the modulo at every step while
    *   still producing the correct value. This is to avoid 
    *   integer overflow, as the sum would get rather large.
    * 
    *   This works best for table sizes that are prime numbers, to
    *   avoid collision clusters at factors of the table size.
    * 
    *   A next-lowest prime could be calculated and used as the
    *   modulo instead, but that causes items to only be stored in
    *   indices [0,p-1], whereas [p,tablesize] remains empty.
    ***************************************************************/
   
   // Send key into stringstream
   stringstream sstream;
   sstream << k;

    // Extract key from stringstream
    string key;
    sstream >> key;

    // Set length and prime parameters
    int length = key.length();
    int prime = 31;

    // Calculate hash value according to formula above
    int hash = 0;
    for(int i = 0; i < length; i++){
        hash = int(hash * prime + key.at(i)) % tablesize;
    }

    // Return hash value
    return hash;
}

/**
 * @brief Inserts a new item into the HashTable
 * 
 * @tparam T1 The key parameter type
 * @tparam T2 The value parameter type 
 * @param k The key of the item to insert
 * @param v The value of the item to insert
 * @return true If the item was inserted successfully
 * @return false If the item could not be inserted (e.g. it already exists in the table)
 */
template <class T1, class T2>
bool HashTable<T1,T2>::insert(T1 k, T2 v){
    // Create a new node object and get the key hash
    HashNode<T1,T2> node(k,v);
    int index = hashFunction(k);

    // Check if the node already exists
    if(table[index].search(node)){
        return false;
    }
    // Attempt to insert the node otherwise
    else{
        return (table[index].insert(node));
    }
}

/**
 * @brief Updates the value for an existing item with the specified key
 * 
 * @tparam T1 The key parameter type
 * @tparam T2 The value parameter type 
 * @param k The key of the item to update
 * @param v The value to update the item to
 * @return true If the item was updated successfully
 * @return false If the item could not be updated (e.g. it does not exist)
 */
template <class T1, class T2>
bool HashTable<T1,T2>::update(T1 k, T2 v){
    // Create new node object and get key hash
    HashNode<T1,T2> node(k,v);
    int index = hashFunction(k);

    // Check if item exists in table
    if(!table[index].search(node)){
        return false;
    }
    // Attempt to update item
    else{
        // Remove node first
        if(!table[index].remove(node)){
            return false;
        }

        // Create new node object, as old one was overwritten by remove
        HashNode<T1,T2> newNode(k,v);

        // Insert newNode and return success
        return table[index].insert(newNode);
    }
}

/**
 * @brief Finds an item with key k and sets the reference v to the value
 * 
 * @tparam T1 The key parameter type
 * @tparam T2 The value parameter type 
 * @param k The key to look up
 * @param v A reference to a value object, to store the value upon lookup
 * @return true If the item was found
 * @return false If the item could not be found
 */
template <class T1, class T2>
bool HashTable<T1,T2>::lookup(T1 k, T2 &v){
    // Create new node object and get key hash
    HashNode<T1,T2> node(k,v);
    int index = hashFunction(k);

    // Check if item exists
    if(!table[index].search(node)){
        return false;
    }
    // Set v to value and return true
    else{
        v = node.getValue();
        return true;
    }
}

/**
 * @brief Overloaded output operator
 * 
 * @tparam T1 The key parameter type
 * @tparam T2 The value parameter type 
 * @param output The output stream to stream the HashTable to
 * @param ht The HashTable to output
 * @return std::ostream& The populated output stream
 */
template <class T1, class T2>
std::ostream& operator<<(std::ostream &output, const HashTable<T1,T2> &ht) {    
    // Iterate over all indices of the table and output its' list
    for(int i = 0; i < ht.tablesize; i++){
        output << i << "[ " << ht.table[i] << "]" << endl;
    }

    // Return the output stream
    return output;
}
