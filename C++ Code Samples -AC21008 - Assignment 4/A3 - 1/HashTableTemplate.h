#include "HashTable.h"
#include<iostream>
using namespace std;

template <class T1, class T2>
HashTable<T1,T2>::HashTable() {
    tablesize = 10;
    table = new  List<HashNode<T1, T2>>[10];
}

template <class T1, class T2>
HashTable<T1,T2>::HashTable(int size) {
    tablesize = size;
    table = new  List<HashNode<T1, T2>>[size];
}

template <class T1, class T2>
HashTable<T1,T2>::~HashTable() {
    delete [] table;
}

template <class T1, class T2>
int HashTable<T1,T2>::hashFunction(T1 k) {
    long unsigned int hash = 0;

    //parsing throught string adding up ASCII values of chars
     for (long unsigned int i = 0; i < k.length(); i++) {
        hash = hash + k[i];
    }

    //taking the remainder of hash  divided by the tablesize
    
    hash %= tablesize;
   
    return hash;
}

template <class T1, class T2>
bool HashTable<T1,T2>::insert(T1 k, T2 v){

     if(k == ""){
        return false;
    }

     if(v == ""){
        return false;
    }

    //creating hashnode object
    HashNode<T1,T2> newNode(k,v);

    int slot = hashFunction(k);
    
    

    //if the key already exists
    if(table[slot].search(newNode)){
        return false;
        
    }

    //if key does not exist
    if(!table[slot].search(newNode)){
        table[slot].insert(newNode);
        return true;
    }else{
            // table[slot].insert(newNode);
        }
    
        
    
    return true;
}

template <class T1, class T2>
bool HashTable<T1,T2>::update(T1 k, T2 v){

    //if key is null
    if(k == ""){
        return false;
    }

    //if value is null
    if(v == ""){
        return false;
    }
    
    int location = hashFunction(k);

    //checking if table is empty i.e. item doesn't exist
    if(table[location].empty()){
        return false;
    }else{

        HashNode<T1, T2> temp(k,v);
        table[location].search(temp); //copying the value onto a temp node
        table[location].remove(temp); //removing the old node
        temp.setValue(v); //setting the new value
        table[location].insert(temp); // adding new value

    }

    return true;
}

template <class T1, class T2>
bool HashTable<T1,T2>::lookup(T1 k, T2 &v){

     if(k == ""){
        return false;
     }

    int val = hashFunction(k);
    
    
     if(table[val].empty()){
        return false;

    }else{
        HashNode<T1, T2> temp(k,v);
        table[val].search(temp);
        v = temp.getValue();
        return true;
    }
   
     return true;
}

template <class T1, class T2>
std::ostream& operator<<(std::ostream &output, const HashTable<T1,T2> &ht) {
     for(int i = 0; i < ht.tablesize; i++){
       output << i <<"[ " << ht.table[i] << "]" << endl;
    }
    return output;
}