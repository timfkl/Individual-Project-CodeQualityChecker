#include "HashTable.h"
#include<iostream>
using namespace std;

template <class T1, class T2>
HashTable<T1,T2>::HashTable() {
    tablesize = 10;
    table = new HashNode[10];
    
}

template <class T1, class T2>
HashTable<T1,T2>::HashTable(int size) {
    table = new HashNode[size];
    tablesize = size;
}

template <class T1, class T2>
HashTable<T1,T2>::~HashTable() {
    delete[] table;
}

template <class T1, class T2>
/**
 * @brief Method to get a hashed value
 * 
 * --Copied from previous assignment
 * 
 * @param k 
 * @return int 
 */
int HashTable<T1,T2>::hashFunction(T1 k) {
    
    // HashedValue is the variable to store the hash key
    int hashedValue = 0;

    // For i in range i < length of k
    for (unsigned long int i = 0; i < k.length(); i++)
    {

        // Adds ASCII values up
        hashedValue += int(k.at(i));
    }

    hashedValue = hashedValue % tablesize;

    // If it is out of bounds, displays error and calls the hashFunction again, passing hashedValue through
    if (hashedValue < 0 || hashedValue > tablesize)
    {
        // cout << "Error. Out of bounds. Rehashing..." << endl;
        string hashedValue;
        hashFunction(hashedValue);
    }

    // Else, returns hashed value
    else
    {

        return hashedValue;
    }

    // Returns hashedValue
    return hashedValue;
}

template <class T1, class T2>
bool HashTable<T1,T2>::insert(T1 k, T2 v){
    
    int hashValue = hashFunction(k);

    HashNode<T1, T2> *tempNode = new HashNode<T1, T2>(k, v);
    

    // cout << "Key is: " << tempNode->getKey() << endl;
    // cout << "Value is: " << tempNode->getValue() << endl;
    
    //For i while under tablesize
    for (int i = 0; i < tablesize; i++) {
    
    //If the list at table[i] does contain the key, returns false
    if (table[i].search(tempNode->getKey) == true)
        {

                return false;


            }
    }

    table[hashValue].insert(tempNode);

    

    return true;
    
}

template <class T1, class T2>
bool HashTable<T1,T2>::update(T1 k, T2 v){

    // The int hashed value- position to store in table
    int theHashedValue = hashFunction(k);

    //New node
    HashNode<T1, T2> *tempNode = new HashNode<T1, T2>(k, v);

    // If table[theHashedValue].getKey equals k
    if (table[theHashedValue].getKey() == k)
    {
        delete[table[theHashedValue]];
        table[theHashedValue] = tempNode;
        // Return the hashedValue at which it's found
        return true;
    }

    else
    {
        
        return false;
    }
}

template <class T1, class T2>
bool HashTable<T1,T2>::lookup(T1 k, T2 &v){
   
    //Gets hashed value
    int hashValue = hashFunction(k);

    // New instance of node
    HashNode<T1, T2> *tempNode = new HashNode<T1, T2>(k, v);

    // If table[hashValue].search's list contains the key
    if (table[hashValue].search(tempNode->getKey))
    {

        // Return table[search(k)].getValue();s
        v = tempNode->getValue();
        return true;
    }

    else
    {
        for (int i = 0; i /< tablesize; i++) {
            if (table[i].search(tempNode->getKey)) {
                // Return table[search(k)].getValue();s
                v = tempNode->getValue();
                return true;
            }

            else {
                return false;
            }
        }
    }
}

template <class T1, class T2>
std::ostream& operator<<(std::ostream &output, const HashTable<T1,T2> &ht) {
    for (int i = 0; i < ht.tablesize; i++) {
        output << i << "[" << ht.table[i] << "]" << endl;
    }

    return output;
    
}
