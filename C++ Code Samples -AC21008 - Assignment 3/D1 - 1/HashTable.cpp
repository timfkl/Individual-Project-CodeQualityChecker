#include "HashTable.h"
#include<iostream>
using namespace std;

//don't touch
HashTable::HashTable() {
    tablesize = 10;
    table = new HashNode[10];
}

//don't touch
HashTable::HashTable(int size) {
    tablesize = size;
    table = new HashNode[size];
}

//don't touch
HashTable::~HashTable() {
    delete [] table;
}

//this should compute a hahed value from k
//return is always between 0 and array length
int HashTable::hashFunction(string k){
    //name = the inputed name
    string name = k;
    //turn the first letter of the string into the ascii equivelent
    int key = name.at(0);
    //num equals the last digit
    int index = key % 10;
    //return the array index
    return index;
}

//inserts the key and value into the hash table
//refers to the hash function to get first choice placement
//then implement a probing strategy if first choice is full
//linear probing with step size of 1 is fine
//when searching for a slot don't go past the end of the array
//keys are unique and thus must all be different
//return true if item added successfully and false if not
//table was full or key already exists
bool HashTable::insert(string k, string v){
    //index stores the index provided from hash function
    int index = hashFunction(k);
    int start = index;
    HashNode node;
    //boolean found to specify a spot has been found
    bool found = false;
    //while found is false
    while(found = false)
    {
        //if the first location is empty then store there
        if (table[index].getKey() == "") 
        {
            //found is true
            found = true;
        }
        else 
        {
            //if at the end of the array
            if (index = tablesize)
            {
                //set to the start
                index = 0;
            }
            //increase the index
            index++;
            //found is still false
            found = false;
            //if the index is back at the original position
            if (index = start)
            {
                //break from while loop
                found = true;
                //return -1 as item doesnt exist
                return false;
            }
        }
        
    }

    // //insert the key
    table[index].getKey() = k;
    // //insert the value
    table[index].setValue(v);  
    //return true as its set succesfully  
    return true;
}

//search for an item in the table with the given key 
//if found return array index it was found at 
//if it was not found return -1
int HashTable::search(string k){
    //index is the index provided by hash function
    int index = hashFunction(k);
    int start = index;
    //boolean found to specify item has been found
    bool found = false;
    //while found is false
    while (found = false)
    {
        //if the key is the key serached for
        if (table[index].getKey() == k)
        {
            //found = true
            found = true;
            //return the index found at
            return index;
        }
        else 
        {
            //if index is at the end of the array
            if (index = tablesize)
            {
                //reset to the start
                index = 0;
            }
            //increase the index
            index++;
            //found is false
            found = false;
            //if back at the start
            if (index = start)
            {
                //break from while loop
                found = true;
                //return -1 as item doesnt exist
                return -1;
            }
        }
    }
}

//updates an existing item in the hash table
//it finds the item with the key provided 
//then sets the value to the value provided(v)
//return true or false depending on success
//item doesnt exist
bool HashTable::update(string k, string v){
    //int index as the index provided from function
    int index = search(k);
    //boolean found to specify if the item was found
    bool found = false;
    //while found is false
    while (found = false)
    {
        //if the location is equal to the key
        if (table[index].getKey() == k)
        {
            //update the value
            table[index].setValue(v);
            //found is true
            found = true;
            //return true
            return true;
        }
        else
        {
            //return false if not found
            return false;
        }
    }
}

//finds an item in the table with key k
//search function this part^
//then return its value 
//returns empty string if key not found
string HashTable::lookup(string k){
    //index is the index provided by function
    int index = search(k);
    //if the key was not found
    if (index = -1)
    {
        //return empty string
        return "";
    }
    else
    {
        //else return the value found
        return table[index].getValue();
    }
    
}

//overload output operator
//1:john:123
//2::
//3:steve:456
ostream& operator<<(ostream &output, const HashTable &ht) {

    HashTable table;
    for (int i = 0; i < table.tablesize; i++)
    {
        output << i << ":" << ht.table[i].getKey() << ":" << ht.table[i].getValue() << endl;
    }
    return output;
}
