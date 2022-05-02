#include "HashTable.h"
#include<iostream>
#include <variant>
using namespace std;
using T1 = std::variant<int, string>;

template <class T1, class T2>
HashTable<T1,T2>::HashTable() {
	tablesize = 10;
	table = new List<HashNode<T1, T2>>[tablesize];
}

template <class T1, class T2>
HashTable<T1,T2>::HashTable(int size) {
	tablesize = size;
	table = new List<HashNode<T1, T2>>[tablesize];
}

template <class T1, class T2>
HashTable<T1,T2>::~HashTable() {
	delete [] table;
}

template <class T1, class T2>
int HashTable<T1,T2>::hashFunction(T1 k) {
	/*if (std::is_same_v<k, int>)
	{
		int sum = 0;
		if (k < 0)
			k *= -1;
		while (k > 0)
		{
			sum += k % tablesize;
			k /= tablesize;
		}
		sum %= tablesize;
		return sum;
	}
	else if (std::is_same_v<k, string>)
	{
		int sum = 0;
		for (size_t i = 0; i < k.size(); i++)
		{
			sum += (int(k[i]) - 'A');
			sum %= tablesize;
		}
		return sum;
	}
	else
		return -1;*/
	return 1;
}


template <class T1, class T2>
bool HashTable<T1,T2>::insert(T1 k, T2 v){
	int index = hashFunction(k);
	HashNode<T1, T2>* tmp = new HashNode<T1, T2>(k, v);
	bool isFound = table[index].search(*tmp);
	if (isFound)
		return false;
	table[index].insert(*tmp);
	return true;
}

template <class T1, class T2>
bool HashTable<T1,T2>::update(T1 k, T2 v){
	int index = hashFunction(k);
	HashNode<T1, T2>* tmp = new HashNode<T1, T2>(k, v);
	bool isFound = table[index].search(*tmp);
	if (!isFound)
		return false;
	table[index].remove(*tmp);
	table[index].insert(*tmp);
	return true;
}

template <class T1, class T2>
bool HashTable<T1,T2>::lookup(T1 k, T2 &v){
	int index = hashFunction(k);
	HashNode<T1, T2>* tmp = new HashNode<T1, T2>(k, v);
	bool isFound = table[index].search(*tmp);
	if (!isFound)
		return false;
	table[index].remove(*tmp);
	table[index].insert(*tmp);
	return true;
}

template <class T1, class T2>
std::ostream& operator<<(std::ostream &output, const HashTable<T1,T2> &ht) {
	for (size_t i = 0; i < ht.tablesize; i++)
	{
		output << ht.table[i] << "\n";
	}
	return output;
}
