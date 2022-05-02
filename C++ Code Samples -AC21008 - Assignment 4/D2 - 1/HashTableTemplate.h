#include "HashTable.h"
#include<iostream>
using namespace std;

template <class T1, class T2>
HashTable<T1,T2>::HashTable() {
    tablesize = 10;
    table = new List[10];
}

template <class T1, class T2>
HashTable<T1,T2>::HashTable(int size) {
    tablesize = size;
    table = new List<HashNode<T1, T2>>[size];
}

template <class T1, class T2>
HashTable<T1,T2>::~HashTable() {
    delete [] table;
}

template <class T1, class T2>
int HashTable<T1,T2>::hashFunction(T1 k) {
    int hashValue = 0;

    // gets the length of the word of the key
    int arraySize = k.length();

    // iterates through the word and adds the total of the ASCII chracter values 
    for (int i = 0; i < arraySize; i++) {
        hashValue += k[i];
    }

    // gets the final integer by doing the modulus of the total charcters with the table size
    hashValue = hashValue % tablesize;

    return hashValue;
}

template <class T1, class T2>
bool HashTable<T1,T2>::insert(T1 k, T2 v){

    int placeToInsert = hashFunction(k);
    HashNode newNode = HashNode(k,v);

    if(table[placeToInsert].search(newNode) != false)
    {
        return false;
    }

    table[placeToInsert].insert(newNode);

    return true;
}

template <class T1, class T2>
bool HashTable<T1,T2>::update(T1 k, T2 v){

    int placeToInsert = hashFunction(k);
    HashNode newNode = HashNode(k,v);

    if(table[placeToInsert].search(newNode) != true)
    {
        return false;
    }

    table[placeToInsert].remove(newNode);

    insert(k,v);

    return true;

}

template <class T1, class T2>
bool HashTable<T1,T2>::lookup(T1 k, T2 &v){
    int placeToInsert = hashFunction(k);
    HashNode newNode = HashNode(k,v);

    if(table[placeToInsert].search(newNode) != true)
    {
        return false;
    }
    else{
        
        v = newNode.getValue();
        return true;
    }

}

template <class T1, class T2>
std::ostream& operator<<(std::ostream &output, const HashTable<T1,T2> &ht) {
    for (int i = 0; i < ht.tablesize; i++)
    {
        output << i << "[ " << ht.table[i] << " ]\n";
    }
    
    
    
    return output;


}
