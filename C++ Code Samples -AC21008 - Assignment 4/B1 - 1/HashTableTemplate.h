#include "HashTable.h"
#include<iostream>
using namespace std;

//contructor
//set parameters to 10
template <class T1, class T2>
HashTable<T1,T2>::HashTable() {
	tablesize = 10;
    table = new List<HashNode<T1, T2>>[10];
}

//parameterised constructor
//set parameters to given values
template <class T1, class T2>
HashTable<T1,T2>::HashTable(int size) {
	tablesize = size;
    table = new List<HashNode<T1, T2>>[size];
}

//deconstructor
template <class T1, class T2>
HashTable<T1,T2>::~HashTable() {
	delete [] table;
}

//Hash function to calculate the position a node should be inserted in
template <class T1, class T2>
int HashTable<T1,T2>::hashFunction(T1 k) {
	//temporary variables needed
	int total =0;
	int i=0;
	int length=k.length();

	//Go through each item in the given k value
	while(i<length)
	{
		//Get the ASCII value for each item in the k value and add all of them together
		total=total+(int)k.at(i);
		i++;
	}
	//Get the reminder of the ASCII sum divided by the table size
	//In this way the return value MUST be betweeen 0 and the table size-1
	int index = total % tablesize;

	//return the previously calculated value
	return index;
	
}

//Function to insert a node inside the hash table
//The position where the node needs to be inserted is given by the hash function
template <class T1, class T2>
bool HashTable<T1,T2>::insert(T1 k, T2 v){

	//calculate the position for the node insertion
	int index = hashFunction(k);

	//create the node to be inserted
	HashNode<T1,T2>* newHashNode = new HashNode(k,v);

	//call the insert function from the list template file
	//creating a list inside the hash table at the position calculated before
	//then adding the node to that list
	table[index].insert(*newHashNode);
	
	//once finished the insertion return true
	return true;
}
	
//Function to update a node in the table
template <class T1, class T2>
bool HashTable<T1,T2>::update(T1 k, T2 v){

	//calculate the node's position
	int index = hashFunction(k);

	//create the new updated node
	HashNode<T1,T2>* newHashNode = new HashNode(k,v);

	//remove the old node in the calculated position
	table[index].remove(*newHashNode);

	//insert the newly created node with the updated values
	table[index].insert(*newHashNode); 

	//once completed the function return true
	return true;
	

}

//function to find a node in the table
template <class T1, class T2>
bool HashTable<T1,T2>::lookup(T1 k, T2 &v){

	//calculate the node's position
	int index = hashFunction(k);

	//create a temporary variable with the node to find
	HashNode<T1,T2>* tempHashNode = new HashNode(k,v);

	//use the search funcion to search inside the list in the position calculated before
	//if the node is found return true
	if(table[index].search(*tempHashNode))
	{	
		//get the value of the node and store it to the v value passed by reference 
		v=tempHashNode->getValue();
		return true;
	}
	//if the node is not found return false
	else
	{
		return false;
	}


}

//Output overload function
template <class T1, class T2>
std::ostream& operator<<(std::ostream &output, const HashTable<T1,T2> &ht) {

	//run through each item in the hash table
	for (int i=0;i< ht.tablesize;i++)
	{
		//overload the output for each iteam in the table
		output << i << "[" << ht.table[i] << "]"<<endl;
		
	}
	//return the overloaded output
	return output;
}
