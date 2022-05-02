#include "HashTable.h"
#include<iostream>
using namespace std;

HashTable::HashTable() {
    tablesize = 10;
    table = new HashNode[10];
}

HashTable::HashTable(int size) {
    tablesize = size;
    table = new HashNode[size];
}

HashTable::~HashTable() {
    delete [] table;
}

/*
Function to return index for a given key "k"
*/
int HashTable::hashFunction(string k){
  int temp = k.length();

  while(temp > tablesize){
    temp=temp-tablesize;
  }

  return temp;
}

/*
Function to insert key and value into the hashtable
*/
bool HashTable::insert(string k, string v){
  HashNode temp(k, v);
  int hVal = hashFunction(k);

  //Finds next available empty position
  while(table[hVal].getKey() != k && table[hVal].getKey() != ""){
    hVal++;   //Increments hVal until empty position is found
    hVal %= tablesize;

    //Avoids looping infinitely
    if(hVal>tablesize){
      return false;
    }
  }

  //If empty position found then place key and string in.
  if(table[hVal].getKey() == ""){
    table[hVal] = temp;
    return true;
  }else{
    return false;
  }
}

/*
Function returns index for key "k"
*/
int HashTable::search(string k){
  int hVal = hashFunction(k);

  //Finds which position
  while(table[hVal].getKey() != "" && table[hVal].getValue() != "" && table[hVal].getKey() != k){
    hVal++;

    //Avoids looping infinitely
    if(hVal>tablesize){
      return -1;
    }
  }

  if(table[hVal].getKey() == "" && table[hVal].getValue() == ""){
    return-1;
  }else{
    return hVal;
  }
}

/*
Uses search to get index for given key "k" and updates the value "v" in the hashtable
*/
bool HashTable::update(string k, string v){
  //If search returns -1 then a bad input was given
  if(search(k) == -1){
    return false;
  }else{
    table[search(k)].setValue(v); //replace value in correct position/index
    return true;
  }
}

/*
Uses search to get index for given key "k" and returns the value "v" for corresponding key
*/
string HashTable::lookup(string k){
  //If search returns -1 then a bad input was given
  if(search(k) == -1){
    return "";
  }else{
    return table[search(k)].getValue(); //return correct value
  }
}

/*
Runs through the table and returns the output in the form
index:key:value
*/
ostream& operator<<(ostream &output, const HashTable &ht) {
  for(int i=0; i<ht.tablesize; i++){
    output << i << ":" << ht.table[i] << endl;
  }
  return output;
}
