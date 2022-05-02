#include "HashTable.h"
#include <iostream>
#include <math.h>

using namespace std;

HashTable::HashTable()
{
    tablesize = 10;
    table = new HashNode[10];
}

HashTable::HashTable(int size)
{
    tablesize = size;
    table = new HashNode[size];
}

HashTable::~HashTable()
{
    delete[] table;
}

int HashTable::hashFunction(string k)
{
    // Check if a string value is passed in
    if (k.length() == 0)
    {
        throw invalid_argument("String is null");
    }

    // Initialise the prime numbers to be used for the hash function
    const int p = 31;
    const int T = tablesize;

    /* 
    Inititalise a variable to be used to store the total of the hash function
    
    total is an unsigned long int to prevent the number of integer overflow errors.
     */
    unsigned long int total = 0;

    // Store the length of the string passed into the function
    const int N = k.length();
    for (int i = 1; i <= N; i++)
    {
        /* 
        Add to the total with the function of:
        Character @ (Length - i) * p ^ (i - 1)
        */
        total += int(k[N - i]) * pow(p, i - 1);
    }
    if (total <= 0)
    {
        throw overflow_error("The total has overflown");
    }
    // When all of the characters have been added together divide it by T and the result of the hash function is that remainder
    return total % T;
}

bool HashTable::insert(string k, string v)
{
    if (v == "")
    {
        return false;
    }
    try
    {
        // Get the preferred location for this key
        int targetPos = hashFunction(k);
        // Loop up to the entire table size
        for (int i = 0; i < tablesize; i++)
        {
            // If there is already a node with this key return false
            if (table[(targetPos + i) % tablesize].getKey() == k)
            {
                return false;
            }
            // If there is a valid space (empty slot or deleted slot) insert a new node at that location
            if (table[(targetPos + i) % tablesize].getKey() == "D" || table[(targetPos + i) % tablesize].getKey() == "")
            {
                table[(targetPos + i) % tablesize] = HashNode(k, v);
                return true;
            }
        }
    }
    catch (const std::exception &e)
    {
        return false;
    }

    return false;
}

int HashTable::search(string k)
{
    // Make sure a valid key is passed in
    if (k == "")
    {
        return false;
    }

    try
    {
        // Get the preferred location for this key
        int targetPos = hashFunction(k);
        // Loop up to the entire table size
        for (int i = 0; i < tablesize; i++)
        {
            // If the current slot is the key return true
            if (table[(targetPos + i) % tablesize].getKey() == k)
            {
                return (targetPos + i) % tablesize;
            }

            // If you reach an empty slot the key is not in the table
            if (table[(targetPos + i) % tablesize].getKey() == "")
            {
                return -1;
            }
        }
    }
    catch (const std::exception &e)
    {
        return false;
    }

    return -1;
}

bool HashTable::update(string k, string v)
{

    // Make sure the key and value are valid
    if (k == "" || v == "")
    {
        return false;
    }

    const int result = search(k);
    if (result == -1)
    {
        return false;
    }
    table[result].setValue(v);
    return true;
}

string HashTable::lookup(string k)
{
    // Make sure that the key is valid
    if (k == "")
    {
        return "";
    }

    const int result = search(k);
    if (result == -1)
    {
        return "";
    }
    return table[result].getValue();
}

ostream &operator<<(ostream &output, const HashTable &ht)
{
    for (int i = 0; i < ht.tablesize; i++)
    {
        output << i << ":" << ht.table[i].getKey() << ":" << ht.table[i].getValue() << endl;
    }
    return output;
}
