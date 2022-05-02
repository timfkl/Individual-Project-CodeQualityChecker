

#include "HashTable.h"
#include <iostream>
#include <stdexcept> // For throwing exceptions
#include <sstream> // Use string stream to convert to string type -  https://www.javatpoint.com/cpp-int-to-string - 11/12/2021

using namespace std;

template <class T1, class T2>
HashTable<T1,T2>::HashTable() {
    this->tablesize = 10;
    this->table = new List<HashNode<T1, T2>>[10];
}

template <class T1, class T2>
HashTable<T1,T2>::HashTable(int size) {
    this->tablesize = size;
    this->table = new List<HashNode<T1, T2>>[size];
}

template <class T1, class T2>
HashTable<T1,T2>::~HashTable() {
    table = NULL;
    delete[] table;
}

template <class T1, class T2>
int HashTable<T1,T2>::hashFunction(T1 k) {
    stringstream ss; // Use string stream to convert to string type - https://www.javatpoint.com/cpp-int-to-string - 11/12/2021
    string key;
    ss << k; // Insert the k variable of any data type as a stringstream
    ss >> key; // Extraction stream into string variable

    // Checks if string is empty
    if(key.empty())
        return 0;

    int hash = 0;

    // Index through every character of the string and get it's ASCII code and add to the hash multiplied by 47
    for(size_t i=0; i<key.length(); i++)
    {
        hash = hash*47 + int(key[i]);
    }
    hash = hash % tablesize; // Get the modulo of hash divided by the tablesize.

    // Make negative to positive
    if(hash < 0)
        hash = hash*-1;
    
    // If hash is greater than the tablesize then reduce it still it is smaller than the tablesize
    if(hash > (tablesize-1))
    {
        while(hash > (tablesize-1))
        {
            hash = hash - tablesize;
        }
    }
    
    return hash;
}

template <class T1, class T2>
bool HashTable<T1,T2>::insert(T1 k, T2 v){
    HashNode<T1,T2> node(k,v);
    
    if (table[hashFunction(k)].search(node))
        return false;
    else
        table[hashFunction(k)].insert(node);
    return true;
}

template <class T1, class T2>
bool HashTable<T1,T2>::update(T1 k, T2 v){

    HashNode<T1,T2> node(k,v);

    if( table[hashFunction(k)].search(node))
    {  
        table[hashFunction(k)].remove(node);
        table[hashFunction(k)].insert(HashNode(k,v));
        return true;
    }

    return false;
}

template <class T1, class T2>
bool HashTable<T1,T2>::lookup(T1 k, T2 &v){
    
    HashNode<T1,T2> node(k,v);
    
    if( table[hashFunction(k)].search(node) )
    {
        v = node.getValue();
        return true;
    }
    return false;
}

template <class T1, class T2>
std::ostream& operator<<(std::ostream &output, const HashTable<T1,T2> &ht) {

    for (int i=0; i<ht.tablesize; i++)
    {
        output << i << " [ " << ht.table[i] << "]" << endl;
    }
    return output;
}