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

int HashTable::hashFunction(string k){
    int asciiValue;
    int hashValue;
    int tempAscii;
    for (int i = 0; i < k.length(); i++)
    {
                char tempChar = k.at(i);
                tempAscii = int(tempChar);
                asciiValue = asciiValue + tempAscii;
    }
    hashValue = asciiValue % tablesize;
    if(hashValue < 0 && hashValue > tablesize){
        return hashValue;
    }
    else{
        return INT_ERROR;
    }

}

bool HashTable::insert(string k, string v){

    int hashNumber;
    hashNumber = hashFunction(k);


    

}

int HashTable::search(string k){
    return 0;
}

bool HashTable::update(string k, string v){
    bool success;
    return success;
}

string HashTable::lookup(string k){
    return "";
}

ostream& operator<<(ostream &output, const HashTable &ht) {
    return output;
}
