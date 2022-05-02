

#include "HashTable.h"
#include<iostream>
using namespace std;

template <class T1, class T2>
HashTable<T1,T2>::HashTable() {
	tablesize = 10;
    table = new List<HashNode<T1, T2>>[10];
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
	int num;
	int length = int(k.length());
	for (int i = 0; i < length; ++i)
    {
        num = num +(int(k[i]));
    }

    int hash = num%tablesize;

    return hash;
}

template <class T1, class T2>
bool HashTable<T1,T2>::insert(T1 k, T2 v){
	int hash = hashFunction(k);

    HashNode<T1,T2> temp(k, v);

    table[hash].insert(temp);
    
    return true;
}

template <class T1, class T2>
bool HashTable<T1,T2>::update(T1 k, T2 v){
	int hash = hashFunction(k);

    //string val="";
    
    //temp = table[hash].Head->Next;*/

    HashNode<T1,T2> temp(k , v);
    bool result = table[hash].remove(temp);

    table[hash].insert(temp);

    /*while(temp.getKey()!=k){
        temp = temp->Next;
    }*/

    //temp()

    return result;
}

template <class T1, class T2>
bool HashTable<T1,T2>::lookup(T1 k, T2 &v){
	int hash = hashFunction(k);
    

    //cout << table[hash].search() << endl;
    T2 val;
    HashNode<T1,T2> temp(k, v);
    

    bool result = table[hash].search(temp);
    v = temp.getValue();

    return result;
}

template <class T1, class T2>
std::ostream& operator<<(std::ostream &output, const HashTable<T1,T2> &ht) {
	for (int i = 0; i < ht.tablesize; ++i)
	{
		 output << i << "[ " << ht.table[i] << " ]" << endl;
	}
    return output;
}
