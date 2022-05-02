#include "HashTable.h"
#include<iostream>
using namespace std;

template <class T1, class T2>
HashTable<T1,T2>::HashTable() {
    tablesize = 9;
    table = new List<HashNode<T1, T2>>[tablesize];
}

template <class T1, class T2>
HashTable<T1,T2>::HashTable(int size) {
    tablesize = size;
    table = new List<HashNode<T1, T2>>[tablesize];
}

template <class T1, class T2>
HashTable<T1,T2>::~HashTable() {
    delete[] table;
}

template <class T1, class T2>
int HashTable<T1, T2>::hashFunction(T1 k)
{
    return k%tablesize;
}

/**template <>
int HashTable<string,string>::hashFunction(string k) {
    int sumOfKey = 0;
    int keyValue;
    ???
    return keyValue;
}**/

/**template <class T1, class T2>
bool HashTable<T1,T2>::insert(T1 k, T2 v){
    return true;
}**/

/**template <class T, class T2>
bool HashTable<T1,T2>::update(T1 k, T2 v){
    return true;
}**/
    

template <class T1, class T2>
std::ostream& operator<<(std::ostream &output, const HashTable<T1,T2> &ht) {
    for(int i = 0; i < ht.tablesize;i++){
        output<<i<<"["<<ht.table[i]<<"]"<<endl;
    }
    return output;
}
