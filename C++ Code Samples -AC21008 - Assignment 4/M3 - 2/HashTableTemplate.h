#include "HashTable.h"
#include<iostream>
using namespace std;

template <class T1, class T2>
HashTable<T1,T2>::HashTable() {
 }

template <class T1, class T2>
HashTable<T1,T2>::HashTable(int size) {
}

template <class T1, class T2>
HashTable<T1,T2>::~HashTable() {
 }

template <class T1, class T2>
int HashTable<T1,T2>::hashFunction(T1 k) {
}

template <class T1, class T2>
bool HashTable<T1,T2>::insert(T1 k, T2 v){
}

template <class T1, class T2>
bool HashTable<T1,T2>::update(T1 k, T2 v){
}

template <class T1, class T2>
bool HashTable<T1,T2>::lookup(T1 k, T2 &v){
}

template <class T1, class T2>
std::ostream& operator<<(std::ostream &output, const HashTable<T1,T2> &ht) {
}
