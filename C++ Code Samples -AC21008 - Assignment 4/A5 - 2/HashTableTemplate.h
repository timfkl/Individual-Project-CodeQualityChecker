#include "HashTable.h"
#include<iostream>
#include<sstream>
using namespace std;

template <class T1, class T2>
HashTable<T1,T2>::HashTable() {
	tablesize = 10;
	table = new List<HashNode<T1,T2>>[tablesize]();
}

template <class T1, class T2>
HashTable<T1,T2>::HashTable(int size) {
	tablesize = size;
	table = new List<HashNode<T1, T2>>[tablesize]();
}

template <class T1, class T2>
HashTable<T1,T2>::~HashTable() {
	delete [] table;
}

template <class T1, class T2>
int HashTable<T1,T2>::hashFunction(T1 k) {
	std::stringstream string;
	string << k;
	std::string temp = string.str();
	int result = (int(k[0])+(3*int(k[1]))+(5*int(k[2])))%tablesize;
	return result;
}

template <class T1, class T2>
bool HashTable<T1,T2>::insert(T1 k, T2 v){
	int key = hashFunction(k);
	HashNode<T1, T2> tempNode = HashNode<T1, T2>(k, v);
	if (!table[key].search(tempNode))
	{
		table[key].insert(tempNode);
		return true;
	}
	return false;
}

template <class T1, class T2>
bool HashTable<T1,T2>::update(T1 k, T2 v){
	int key = hashFunction(k);
	table[key].remove(HashNode<T1, T2>(k, v));
	table[key].insert(HashNode<T1, T2>(k, v));
	return true;
}

template <class T1, class T2>
bool HashTable<T1,T2>::lookup(T1 k, T2 &v){
	int key = hashFunction(k);
	HashNode<T1, T2> tempNode = HashNode<T1, T2>(k, v);
	table[key].search(tempNode);
	v = tempNode.getValue();
	return true;
}

template <class T1, class T2>
std::ostream& operator<<(std::ostream &output, const HashTable<T1,T2> &ht) {
	for (int i = 0; i < ht.tablesize; ++i)
	{
		output << i << "[ " << ht.table[i] << "]" << endl;
	}
	return output;
}
