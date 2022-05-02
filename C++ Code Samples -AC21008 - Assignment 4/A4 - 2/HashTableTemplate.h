#include "HashTable.h"
#include <cmath>
#include <iostream>
using namespace std;

/**
 * @brief Default constructor a new Hash Table< T 1,  T 2> of size 10:: Hash Table object
 *
 * @tparam T1
 * @tparam T2
 */
template <class T1, class T2>
HashTable<T1, T2>::HashTable()
{
    // create an array of custom size
    this->table = new List<HashNode<T1, T2>>[10];

    // updating table size
    this->tablesize = 10;
}

/**
 * @brief Constructor a new Hash Table< T 1,  T 2> of size 'size':: Hash Table object
 *
 * @tparam T1
 * @tparam T2
 * @param size
 */
template <class T1, class T2>
HashTable<T1, T2>::HashTable(int size)
{
    // create an array of custom size
    this->table = new List<HashNode<T1, T2>>[size];

    // updating table size
    this->tablesize = size;
}

/**
 * @brief Destroy the Hash Table< T 1,  T 2>:: Hash Table object
 *
 * @tparam T1
 * @tparam T2
 */
template <class T1, class T2>
HashTable<T1, T2>::~HashTable()
{
    delete[] this->table;
}

/**
 * @brief Specialised has functions for strings
 *
 * @tparam
 * @param k
 * @return int
 */
template <>
int HashTable<string, string>::hashFunction(string k)
{
    int stringLength = k.length();

    // validating input
    if (stringLength > 0)
    {
        double hashValue = 0;
        int p = 31;

        // looping through each character in the string
        for (int i = 0; i < stringLength; i++)
        {
            // getting the sum of all the ascii values in the key
            hashValue += (int(k[i]) * (pow(p, i)));
        }

        // getting the index of the the key
        hashValue = fmod(hashValue, this->tablesize);
        int newHashValue = (int)hashValue;

        // returning the index for the new node
        return newHashValue;
    }
    else
    {
        return -1;
    }
}

/**
 * @brief General hash function for key types
 *
 * @tparam T1
 * @tparam T2
 * @param k
 * @return int
 */
template <class T1, class T2>
int HashTable<T1, T2>::hashFunction(T1 k)
{
    string str = to_string(k);

    int stringLength = str.length();

    // validating input
    if (stringLength > 0)
    {
        double hashValue = 0;
        int p = 31;

        // looping through each character in the string
        for (int i = 0; i < stringLength; i++)
        {
            // getting the sum of all the ascii values in the key
            hashValue += (int(str[i]) * (pow(p, i)));
        }

        // getting the index of the the key
        hashValue = fmod(hashValue, this->tablesize);
        int newHashValue = (int)hashValue;

        // returning the index for the new node
        return newHashValue;
    }
    else
    {
        return -1;
    }
}

/**
 * @brief insert a key/value pair into the hash table
 *
 * @tparam T1
 * @tparam T2
 * @param k
 * @param v
 * @return true
 * @return false
 */
template <class T1, class T2>
bool HashTable<T1, T2>::insert(T1 k, T2 v)
{

    int hashVal = hashFunction(k);

    // checking hash value is valid
    if (hashVal < 0 || hashVal > this->tablesize)
    {
        return false;
    }

    // creating new hash node with the key and value parameters
    HashNode<T1, T2> newNode(k, v);

    // adding to the head of the list
    this->table[hashVal].insert(newNode);

    // checking if element was added correctly
    if (this->table[hashVal].search(newNode))
    {
        return true;
    }
    else
    {
        return false;
    }
}

/**
 * @brief updates the value for an existing item in the hash table
 *
 * @tparam T1
 * @tparam T2
 * @param k
 * @param v
 * @return true
 * @return false
 */
template <class T1, class T2>
bool HashTable<T1, T2>::update(T1 k, T2 v)
{
    // finding the array position from the key
    int hashVal = hashFunction(k);

    // temp hashnode
    HashNode<T1, T2> tempNode(k, v);

    // deleting the node from the table
    this->table[hashVal].remove(tempNode);

    insert(k, v);

    // checking if element was added correctly
    if (this->table[hashVal].search(tempNode))
    {
        return true;
    }
    else
    {
        return false;
    }
}

/**
 * @brief Finds an item in the table from key and returns true if the item is found, or false otherwise. Set the value for the parameter
 * v (passed by reference) to the value found in the table for the key k.
 *
 * @tparam T1
 * @tparam T2
 * @param k
 * @param v
 * @return true
 * @return false
 */
template <class T1, class T2>
bool HashTable<T1, T2>::lookup(T1 k, T2 &v)
{
    // getting the hash value for the array position
    int hashval = hashFunction(k);

    // temp hashnode
    HashNode<T1, T2> tempNode(k, v);

    // searching for specific node
    if (this->table[hashval].search(tempNode))
    {
        v = tempNode.getValue();
        return true;
    }
    else
    {
        return false;
    }
}

/**
 * @brief Overloads the '<<' for a hashtable
 *
 * @tparam T1
 * @tparam T2
 * @param output
 * @param ht
 * @return std::ostream&
 */
template <class T1, class T2>
std::ostream &operator<<(std::ostream &output, const HashTable<T1, T2> &ht)
{

    for (int i = 0; i < ht.tablesize; i++)
    {
        output << '[' << ht.table[i] << ']' << endl;
    }

    return output;
}
