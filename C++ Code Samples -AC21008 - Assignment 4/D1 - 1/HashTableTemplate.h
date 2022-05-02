#include "HashTable.h"
#include<iostream>
using namespace std;

template <class T1, class T2>
HashTable<T1,T2>::HashTable() {
  this(10);
}

template <class T1, class T2>
HashTable<T1,T2>::HashTable(int size) {
  tablesize = size;
  table = new List<HashNode<T1,T2>>[tablesize]();
}

template <class T1, class T2>
HashTable<T1,T2>::~HashTable() {
  // delete array
  delete [] table;
}

template <class T1, class T2>
int HashTable<T1,T2>::hashFunction(T1 k) {
  // cout << (typeid(T1) == typeid(string)) << endl;

  // WE ASSUME -T1- IS A STRING

  // 13 & 31 are primes
  // unsigned so when getting remainder from tablesize it will be a positive value
  unsigned int hash = 13; // set initial value to prime number

  for (size_t n=0; n<k.length(); n++) { // for each character in key
    hash = (hash * k[n] * 31); // feed character to hash
  }

  int keyHash = hash % tablesize; // convert hash to value between 0-tablesize

  return keyHash;
}



template <class T1, class T2>
bool HashTable<T1,T2>::insert(T1 k, T2 v){
  int hash = hashFunction(k);

  // check if k in table[hash]
  HashNode<T1,T2> newNode(k,v);
  if (table[hash].search(newNode))
    return false;

  // push to list
  table[hash].insert(newNode);
  return true;
}

template <class T1, class T2>
bool HashTable<T1,T2>::update(T1 k, T2 v){
  int hash = hashFunction(k);
  // delete then add again

  HashNode<T1,T2> updateNode(k,v);

  // delete
  bool removed = table[hash].remove(updateNode);
  if (!removed) // not removed => never existed => cant update
    return false;

  // add again
  table[hash].insert(updateNode);

  return true;
}

template <class T1, class T2>
bool HashTable<T1,T2>::lookup(T1 k, T2 &v){
  int hash = hashFunction(k);

  HashNode<T1,T2> searchNode(k,"");
  bool ret = table[hash].search(searchNode);
  if (ret) {
    v = searchNode.getValue();
    return true;
  }
  return false;
}

template <class T1, class T2>
std::ostream& operator<<(std::ostream &output, const HashTable<T1,T2> &ht) {
  for (int i=0; i<ht.tablesize; i++) {
    output << "[ ";
    output << ht.table[i];
    output << "]";
    output << endl;
  }
  return output;
}
