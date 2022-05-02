#include "HashTable.h"
#include<iostream>
#include<string.h>
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

	int total =0;
	int i=0;
	int length=k.length();
	while(i<length)
	{
		total=total+(int)k.at(i);
		i++;
	}
	int index = total % tablesize;
	return index;
	

}

bool HashTable::insert(string k, string v){
		

	int index = hashFunction(k);
	int checks=0;
	HashNode* newHashNode = new HashNode(k,v);
	
	 while(!table[index].getValue().empty())
	{
		
		index = hashFunction(k)+1;
		if (index == tablesize)
		{
			index= 0;
		}
		if(checks == tablesize)
		{
			return false;
		}
		checks++;
	}
	table[index] = *newHashNode;
	if (table[index].getValue().empty())
	{
		return false;
	}
	else
	{
		return true;
	}



 }

int HashTable::search(string k){
	int index = hashFunction(k);
	if (table[index].getValue().empty())
	{
		return -1;
	}
	else
	{
		return index;
	}
}

bool HashTable::update(string k, string v){
	int index = hashFunction(k); 

	table[index].setValue(v);
	if(table[index].getValue()==v)
	{
		return true;
	}
	else
	{
		return false;
	}

	
}

string HashTable::lookup(string k){
	std::string returnValue;
	int index = hashFunction(k);
	if (table[index].getValue().empty())
	{

		return returnValue;
	}
	else
	{
		returnValue = table[index].getValue();
		return returnValue;
	}
}

ostream& operator<<(ostream &output, const HashTable &ht) {
	for (int i=0;i< ht.tablesize;i++)
	{
		output << i << ":" << ht.table[i].getKey() << ":" << ht.table[i].getValue() << endl;
		
	}
	return output;

}
