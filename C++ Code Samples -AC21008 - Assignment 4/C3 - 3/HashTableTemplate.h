#include "HashTable.h"
#include<iostream>
using namespace std;
#include<cmath>


template <class T1, class T2>
HashTable<T1,T2>::HashTable() {

	 tablesize = 10;
    table = new List<HashNode<T1, T2>>[10];
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
	
	int  primeNumber = 31;
   

    int key = 0; 

    for (int i = 0; i < k.length(); ++i)
    {
        key += (k[i] * (int)pow(primeNumber, i)) % tablesize; 
    }

   

    return key % tablesize;
	
}

template <class T1, class T2>
bool HashTable<T1,T2>::insert(T1 k, T2 v){


	     
    int hash = hashFunction(k);
for(int i = hash; i<tablesize; ++i){


if (table[hash].empty()){
    HashNode<string, string> h(k,v);
    table[hash].insert(h);
   
	return true;
}else{
hash++;

}
}
return false;
}


template <class T1, class T2>
bool HashTable<T1,T2>::update(T1 k, T2 v){
	
    int hash = hashFunction(k);
    HashNode<string, string> h(k,v);
    //table[hash].remove(h); 
    table[hash].insert(h);   

    return true;

}

template <class T1, class T2>
bool HashTable<T1,T2>::lookup(T1 k, T2 &v){
 int hash = hashFunction(k);
 HashNode<string, string> h(k,v);
if(table[hash].search(h)){

		
		v = h.getValue();
	}else{
			
 		cout << k << h << " NOT FOUND" << endl;
}


return true;
}

template <class T1, class T2>
std::ostream& operator<<(std::ostream &output, const HashTable<T1,T2> &ht) {
	 for (int i = 0; i < ht.tablesize; ++i)
    {
        output << i << ":" << ht.table[i] << endl;
    }

    return output;

}
