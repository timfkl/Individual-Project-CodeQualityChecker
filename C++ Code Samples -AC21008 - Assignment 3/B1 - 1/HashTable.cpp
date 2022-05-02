#include "HashTable.h"
#include <iostream>
#include <cmath>
using namespace std;

/**
 * @brief Construct a new Hash Table:: Hash Table object
 * 
 */
HashTable::HashTable()
{
    tablesize = 10;
    table = new HashNode[10];
}

/**
 * @brief Construct a new Hash Table:: Hash Table object
 * 
 * @param size 
 */
HashTable::HashTable(int size)
{
    //valid input parameter
    if (size > 0)
    {
        tablesize = size;
        table = new HashNode[size];
    }
}

/**
 * @brief Destroy the Hash Table:: Hash Table object
 * 
 */
HashTable::~HashTable()
{
    delete[] table;
}

/**
 * @brief works out the index position for a hash node in the hash table
 * 
 * @param k 
 * @return int 
 */
int HashTable::hashFunction(string k)
{

    int stringLength = k.length();

    //validating input
    if (stringLength > 0)
    {
        double hashValue = 0;
        int p = 31;

        //looping through each character in the string
        for (int i = 0; i < stringLength; i++)
        {
            //getting the sum of all the ascii values in the key
            hashValue += (int(k[i]) * (pow(p, i)));
        }

        //getting the index of the the key
        hashValue = fmod(hashValue, this->tablesize);
        int newHashValue = (int)hashValue;

        //returning the index for the new node
        return newHashValue;
    }
    else
    {
        return -1;
    }
}

/**
 * @brief inserts a hash node into the hash table at the correct index
 * 
 * @param k 
 * @param v 
 * @return true 
 * @return false 
 */
bool HashTable::insert(string k, string v)
{
    //returning fail as the key is already in the table
    if (this->search(k) != -1)
    {
        return false;
    }

    //init new hashnode
    HashNode newNode(k, v);

    //finding the index of the hash node from the key
    int index = hashFunction(k);

    // validting the hash value
    if (index == -1)
    {
        return false;
    }

    //inserting the new hash node into the hashtable
    if (this->table[index].getValue() == "" && this->table[index].getKey() == "")
    {
        this->table[index] = newNode;
    }
    else
    {
        bool finished = false;
        int i = 1;

        //quadratic probing
        while (finished != true)
        {
            //finding the new index based on quadratic probing
            int newIndex = fmod((index + pow(i, 2)), this->tablesize);

            //checking the new index has not gone outwith the table boundaries
            if (newIndex > this->tablesize || i > newIndex)
            {
                return false;
            }
            else if (this->table[newIndex].getValue() == "" && this->table[newIndex].getKey() == "")
            {
                this->table[newIndex] = newNode;
                finished = true;
            }
            else
            {
                i++;
            }
        }
    }

    return true;
}

/**
 * @brief searches through the entire hash table looking for a hash node based on the key
 * 
 * @param k 
 * @return int 
 */
int HashTable::search(string k)
{
    //looping through the whole table
    for (int i = 0; i < this->tablesize; i++)
    {
        //returning the index position if the key is found
        if (this->table[i].getKey() == k)
        {
            return i;
        }
    }

    //if the key is not found -1 is returned
    return -1;
}

/**
 * @brief updates the value of an item in the table based on a key
 * 
 * @param k 
 * @param v 
 * @return true 
 * @return false 
 */
bool HashTable::update(string k, string v)
{
    //finding the item to update's key
    int toUpdate = search(k);

    //updating said item's value
    this->table[toUpdate].setValue(v);

    if (this->table[toUpdate].getValue() == v)
    {
        return true;
    }
    else
    {
        return false;
    }
}

/**
 * @brief finds the value of a hashnode based on its key
 * 
 * @param k 
 * @return string 
 */
string HashTable::lookup(string k)
{
    string valueFound = "";

    //getting the value based on the key
    valueFound = this->table[search(k)].getValue();

    return valueFound;
}

/**
 * @brief overloads the << operator for HashTables
 * 
 * @param output 
 * @param ht 
 * @return ostream& 
 */
ostream &operator<<(ostream &output, const HashTable &ht)
{
    //looping through each line in the array
    for (int i = 0; i < ht.tablesize; i++)
    {
        output << i << ':' << ht.table[i].getKey() << ':' << ht.table[i].getValue() << endl;
    }

    return output;
}
