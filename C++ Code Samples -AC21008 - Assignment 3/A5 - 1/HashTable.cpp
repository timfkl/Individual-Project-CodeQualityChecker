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
    int num = 0;
    /*int length = int(k.length());
    int odd = 0;*/


    /*for (int i = length; i > 0; --i)
    {
        num = (k[i])*31^odd;
        odd = odd + 1;
    }
*/

    /*for (int i = 0; i< length; i++){
        num = ((k[i])+(i^2))+1;
    }*/

    /*for (int i = 0; i < length; ++i)
    {
        num = num +(int(k[i]));
    }*/

    //num = int(k[0]) + 3*(int(k[1])) + 5*(int(k[2])) + 7*(int(k[3]));
    num = 31*int(k[0])/*+13*int(k[1])+2*int(k[2])*/;
    //cout << "This is num : " << num << " This is table size : "<< tablesize<< endl;
    int hash = num%tablesize;
    return hash;
}

bool HashTable::insert(string k, string v){
    
    int hash = hashFunction(k);

    table[hash]=HashNode(k,v);
    
    return true;
}

int HashTable::search(string k){
    int hash = hashFunction(k);

    if ((table[hash].getKey()).compare(k) != 0)
    {
        hash = -1;
    }

    return hash;
}

bool HashTable::update(string k, string v){
    int hash = search(k);
    table[hash].setValue(v);

    if ((table[hash].getValue()).compare(v)!=0)
    {
        return false;
    }

    return true;
}

string HashTable::lookup(string k){
    int hash = search(k);
    string value = table[hash].getValue();

    if ((table[hash].getKey()).compare(k) != 0)
    {
        value = "";
    }


    return value;
}

ostream& operator<<(ostream &output, const HashTable &ht) {
    
    for (int i = 0; i < ht.tablesize; ++i)
    {
        output << i << ":" << ht.table[i] << endl;
    }

    //output << ht.table << endl;

    return output;
}
