#include "HashTable.h"
#include<iostream>
using namespace std;


//I ATTEMPTED EVERY FUNCTION BUT COULD NOT GET MY CODE WORKING
//I HAVE SUBMITTED WHAT I HAD AND COMMENETED IT OUT SO MY PROGRAM CAN BE RUN WORKING 

template <class T1, class T2>
HashTable<T1,T2>::HashTable() {

	//tablesize = 10;
    //table = new HashNode[10];
}

template <class T1, class T2>
HashTable<T1,T2>::HashTable(int size) {

	//tablesize = size;
   // table = new HashNode[size];
}

template <class T1, class T2>
HashTable<T1,T2>::~HashTable() {

	 delete [] table;
}

template <class T1, class T2>
int HashTable<T1,T2>::hashFunction(T1 k) {

	//return (k % tablesize);
}

template <class T1, class T2>
bool HashTable<T1,T2>::insert(T1 k, T2 v){
	
//set position
//int hashValue = hashFunction(k);
	
	//loop round and insert key and value for each entry
	//for(int i = hashValue; i< tablesize; i++){

		//if(hashValue == 0){

			//table[i] =  new(HashNode<T1,T2>(k,v));

			//return true if success
			//return true;

		//} else{

			//return false if failed
			//return false;
		//}
	//}

	//return true;
	return false;
}

template <class T1, class T2>
bool HashTable<T1,T2>::update(T1 k, T2 v){

//if(table[hash].search(k) == k){

//table[hashNode].remove(HashNode<T1,T2>(k,v));
//table[hashNode].insert(HashNode<T1,T2>(k,v));
//return true;

//}
return false;
}

template <class T1, class T2>
bool HashTable<T1,T2>::lookup(T1 k, T2 &v){

//int search = hashFunction(k);
  

//if search value equals key
  //if (table[search].getKey() == k){

  	//return value
  	// return search;
  //}
  //else{
  	
  	//else return -1 not found
  	return -1;
  //}

  
	//int node = search;
	//if node is -1 return empty
	//if (node == -1){

	//	return " ";

	//} else{

		//else return the value of node to find
	//	return table[node].getValue();

//	}
	


}

template <class T1, class T2>
std::ostream& operator<<(std::ostream &output, const HashTable<T1,T2> &ht) {


	//for( int i = 0; i< 10; i++){
		
	//	HashNode node = ht[i];

	//	if(node.getKey().empty()){

	//		output << i << "[]";

	//	} else{

	//		output << i << "[" << node.getValue() << "]" << node.getKey();
	//	}
	//}
	
	return output;
}
