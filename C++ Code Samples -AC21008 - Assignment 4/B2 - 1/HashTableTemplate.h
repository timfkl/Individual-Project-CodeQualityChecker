#include "HashTable.h"
#include<iostream>
using namespace std;

//Sets default array size to 10
template <class T1, class T2>
HashTable<T1,T2>::HashTable() {
  tablesize = 10;
  table = new List<HashNode<T1, T2>>[10];
}

//sets the array size used equal to the given parameter.
template <class T1, class T2>
HashTable<T1,T2>::HashTable(int size) {
  tablesize = size;
  table = new List<HashNode<T1, T2>>[size];
}

//Destructor for the HashTable class.
template <class T1, class T2>
HashTable<T1,T2>::~HashTable() {
  delete[] table;
}

//Computes a hashed value based on the provided key, k
template <class T1, class T2>
int HashTable<T1,T2>::hashFunction(T1 k) {
  int temp = k.length();

  while(temp > tablesize) {
    temp = temp-tablesize;
  }
  return temp;
}

//Function to insert new node
template <class T1, class T2>
bool HashTable<T1,T2>::insert(T1 k, T2 v){
  HashNode<T1, T2> node(k, v);  //craete instance of HashNode
  int hVal = hashFunction(k); //location for new node

  if(table[hVal].search(node)) {
    return false; //If the node is already there then return false
  } else if (!table[hVal].search(node)) {
    table[hVal].insert(node); //else insert it
    return true;  //return true if everything went well.
  }
}


//Update function will remove a node that is already there and then insert
//a node to replace it
template <class T1, class T2>
bool HashTable<T1,T2>::update(T1 k, T2 v){
  int hVal = hashFunction(k);
  HashNode<T1, T2> node(k, v);  //craete instance of HashNode

  //If the node doesnt exist then return false
  if(!table[hVal].search(node)) {
    return false;
  } else {
    HashNode<T1, T2> newNode(k, v);
    table[hVal].remove(node); //Remove the node that is already there
    table[hVal].insert(newNode); //Insert new one
    return true;  //return true if everything went well.
  }
}


//Finds an item in the table with the key k and return true if found
template <class T1, class T2>
bool HashTable<T1,T2>::lookup(T1 k, T2 &v){
  HashNode<T1, T2> node(k, v); //craete instance of HashNode
  int hVal = hashFunction(k);

  //If the node doesnt exist then return false
  if(!table[hVal].search(node)) {
    return false;
  } else {
    v = node.getValue();  //Set value of v to the value held in the node
    return true;
  }
}

template <class T1, class T2>
std::ostream& operator<<(std::ostream &output, const HashTable<T1,T2> &ht) {
  for(int i = 0 ; i < ht.tablesize; i++) {
    output << i << " [ " << ht.table[i] << "]" << endl;
  }
  return output;
}
