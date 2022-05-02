
#include "HashTable.h"
#include<iostream>
using namespace std;

template <class T1, class T2>
HashTable<T1,T2>::HashTable() {
    tablesize=10;
    table = new List<HashNode<T1, T2>>[tablesize];
}

template <class T1, class T2>
HashTable<T1,T2>::HashTable(int size) {
    tablesize=size;
    table=new List<HashNode<T1, T2>>[tablesize];
}

template <class T1, class T2>
HashTable<T1,T2>::~HashTable() {
    delete[] table;
}

//Template Specialisation
//Hash function for key types of string only
template <>
int HashTable<string,string>::hashFunction(string k) {
    //Local variables
    int keyValue=0;
    int keyTotal;
    //loop through amount of characters in the string (size)
    for (int i=0; i<(int)k.size(); i++)
    {
        //converts each character into an ASCII value (integer)
        //add up the values of the characters
        keyTotal = keyTotal + (int)k[i];
    }
    //sets the key value as the remainder
    //of the value divided by the range of tablesize
    keyValue = keyTotal % this->tablesize;
    //returns the key value
    return keyValue;
}

//Hash function for non-string key/ types
template <class T1, class T2>
int HashTable<T1,T2>::hashFunction(T1 k) {
    return k%tablesize;
}

template <class T1, class T2>
bool HashTable<T1,T2>::insert(T1 k, T2 v){
    int key = hashFunction(k);
    HashNode<T1, T2> newNode = HashNode(k, v);

    if(table[key].search(newNode)==true)
    {
        return false;
    }
    table[key].insert(newNode);
    return true;
}

template <class T1, class T2>
bool HashTable<T1,T2>::update(T1 k, T2 v){
    int key=hashFunction(k);
    HashNode<T1, T2> updateNode = HashNode(k, v);

    if(!table[key].search(updateNode) || table[key].empty())
    {
        return false;
    } else {
        table[key].remove(updateNode);
        updateNode = HashNode(k,v);
        table[key].insert(updateNode);
        return true;
    }
}

template <class T1, class T2>
bool HashTable<T1,T2>::lookup(T1 k, T2 &v){
    int key=hashFunction(k);
    HashNode<T1, T2> keyToFind = HashNode(k, v);

    if(!table[key].search(keyToFind) || table[key].empty())
    {
        return false;
    } else {
        v=keyToFind.getValue();
        return true;
    }
}

template <class T1, class T2>
std::ostream& operator<<(std::ostream &output, const HashTable<T1,T2> &ht) {
    for(int i=0; i<ht.tablesize; i++)
    {
        output << i << "[" << ht.table[i] << "]" << endl;
    }
    return output;
}

