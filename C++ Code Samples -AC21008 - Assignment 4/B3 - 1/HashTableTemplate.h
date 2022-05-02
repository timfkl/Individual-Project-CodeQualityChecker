#include "HashTable.h"
#include<iostream>
using namespace std;

template <class T1, class T2>
HashTable<T1,T2>::HashTable() {
}

template <class T1, class T2>
HashTable<T1,T2>::HashTable(int size) {
    tablesize=size;
}

template <class T1, class T2>
HashTable<T1,T2>::~HashTable() {
}

template <class T1, class T2>
int HashTable<T1,T2>::hashFunction(T1 k) {
    int i=0;
     for (int j=0; k[j]; j++) {
        i+=k[j];
    }
    int sum=k[1]+k[2];
    return sum % tablesize;
}

template <class T1, class T2>
bool HashTable<T1,T2>::insert(T1 k, T2 v){
    //int index=hashFunction(k);
    for (int i = 2; i < tablesize; i++)
    {
 //table[index].insert(HashNode<T1,T2>(k,v));
 table=new List<HashNode<T1,T2>>[tablesize]();
 
    }
return false;
}

template <class T1, class T2>
bool HashTable<T1,T2>::update(T1 k, T2 v){
    return false;
}

template <class T1, class T2>
bool HashTable<T1,T2>::lookup(T1 k, T2 &v){
    return false;
    
}

template <class T1, class T2>
std::ostream& operator<<(std::ostream &output, const HashTable<T1,T2> &ht) {
    for (int num = 0; num <= 12; num++)
    {
    output<<num<<":"<<ht.table<<"\n";
    }
    return output;
}
