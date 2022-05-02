#include "HashTable.h"
#include<iostream>
using namespace std;

template <class T1, class T2>
HashTable<T1,T2>::HashTable() 
{
	tablesize = 10;
	table = new HashNode[10];
}

template <class T1, class T2>
HashTable<T1,T2>::HashTable(int size) 
{
	//unfinished
	table = new List<HashNode<T1, T2>>
	[tablesize]();
}

template <class T1, class T2>
HashTable<T1,T2>::~HashTable() 
{
	delete[] table;
}

template <class T1, class T2>
int HashTable<T1,T2>::hashFunction(T1 k) 
{
	return k % tablesize;
}

template <class T1, class T2>
bool HashTable<T1,T2>::insert(T1 k, T2 v)
{
	//unfinished
	return true;
}

template <class T1, class T2>
bool HashTable<T1,T2>::update(T1 k, T2 v)
{
	//unfinished
	if (table[hash].search(key) == key)
	{
		table[hash].remove(key);
		table[hash].insert(HashNode<T1,T2>(k,v));
		return true;
	}
	return false;
}

template <class T1, class T2>
bool HashTable<T1,T2>::lookup(T1 k, T2 &v)
{
	//unfinished
	return true
}

template <class T1, class T2>
std::ostream& operator<<(std::ostream &output, const HashTable<T1,T2> &ht) 
{
	output << ht.key << ":" << ht.value;
    return output;
}
