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
}

bool HashTable::insert(string k, string v){
}

int HashTable::search(string k){
}

bool HashTable::update(string k, string v){
}

string HashTable::lookup(string k){
}

ostream& operator<<(ostream &output, const HashTable &ht) {
}
