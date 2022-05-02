#include "HashTable.h"
#include<iostream>
using namespace std;

/**
 * Default constructor for the HashTable class.  
 * This sets a default array size of 10.
 */
HashTable::HashTable() 
{
    tablesize = 10;
    table = new HashNode[10];
}

/**
 * Paramererised constructor for the HashTable class.  
 * This sets the array size used equal to the given parameter.
 * @param size The size of the parameter
 */
HashTable::HashTable(int size) 
{
    tablesize = size;
    table = new HashNode[size];
}

/**
 * Destructor for the HashTable class.
 */
HashTable::~HashTable() 
{
    delete [] table;
}

/**
 * This will compute a hashed value based on the provided key
 * @param k Key provided 
 * @return int The hashed value
 */
int HashTable::hashFunction(string k)
{
    int hashedValue = 0; //Hashed value to get to divide by table size
    int index; //The index value to be returned

    //For loop to get the hashed value
    for(int i = 0; i < k.length(); i++) 
    {
        hashedValue = hashedValue + (int)k[i];
    }
    index = hashedValue % tablesize; //Divided by table size so that the key is within range to be an index of the table
}
    return index; 

/**
 * Function  to  insert  a  key/value  pair  into  the  hash  table. 
 * This will use the hash function to determine a frst choice slot. 
 * It will then need to implement probe to fnd another slot if that slot is full
 * 
 * @param k The key
 * @param v The value
 * @return true If it's successfully inserted
 * @return false If it is not inserted successfully
 */
bool HashTable::insert(string k, string v)
{
    HashNode hn(k, v); //New reference to hash node
    int index = hashFunction(k); //Determines first choice slot
    //For loop to probe to find a slot
    for (int i = index; i < tablesize; i++) 
    {
        if (table[i].getKey() == "") //If the table is empty
        {
            table[i]= hn; // Add in the key, value pair
            return true;
        }
    }
    return false;    
}

/**
 * This  function  will  search  for  an  item  in  the  hash  table  with  the  given key value, k.  
 * If the item is found, the array index where it was found should be returned, if not, “-1” should be returned. 
 * @param k The key
 * @return index if the key is found
 * @return -1 if it is not found
 */
int HashTable::search(string k)
{
  int index = hashFunction(k); //Calling hash function
  
  //While loop to determine what you are searching for
  while(table[index].getKey() != "" && table[index].getValue() != "" && table[index].getKey() != k)
  {
    index++; //Increment until it's found
  }
  //If it is not empty
  if(table[index].getKey() != "")
  {
    return index; //Return what has been found
  }
  else 
  {
    return -1; //If it didn't work
  }
}
/**
 * This function is used to update an existing item in the hash table. 
 * It will first find an item with the key k and then set its value to v. 
 * @param k The key
 * @param v The value
 * @return true If it is updated successfully
 * @return false If there is an error 
 */
bool HashTable::update(string k, string v)
{
  int index = hashFunction(k); //Calling hash function
  
  //While loop to determine what you are trying to update
  while(table[index].getKey() != "" && table[index].getValue() != "" && table[index].getKey() != k)
  {
    index++; //Increment until it's found
  }

  //If it is not empty
  if(table[index].getKey() != "")
  {
    table[index].setValue(v); //Set the new value to the key
    return true;
  }
  //Not successful
  else 
  {
    return false;
  }
}

/**
 * This function will find an item in the table with the key k and return its value. 
 * It will return an empty string if the key is not found. 
 * @param k The key
 * @return the value of the key it finds
 * @return an empty string if it isn't found
 */
string HashTable::lookup(string k)
{
  int index = hashFunction(k); //Calling hash function

  //While loop to determine what you are trying to look up
  while(table[index].getKey() != "" && table[index].getValue() != "" && table[index].getKey() != k)
  {
    index++; //Increment until it's found
  }
  //If it is not empty
  if(table[index].getKey() != "")
  {
    return table[index].getValue(); //Return the value of the key
  }
  //If it's not successful in updating
  else 
  {
    return "";
  }
}

/**
 * Overloading of the output operator for a HashTable. 
 * This will print the array index and HashNode followed by a newline for each slot in the table
 * @param output Getting the values for the array index and hash node
 * @param ht The hashtable
 * @return ostream& The array index and hashnode 
 */
ostream& operator<<(ostream &output, const HashTable &ht) {
  for(int i=0 ; i < ht.tablesize; i++)
  {
    output << i;
    output << ":"; //Seperates the number it is in the table
    output << ht.table[i];
    output << endl;
  }
  return output; //Array index and hashode
}
