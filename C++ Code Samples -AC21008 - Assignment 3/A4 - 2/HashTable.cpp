#include "HashTable.h"
#include <iostream>
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
    // Gets the first char of the given string
    // Casts it to an int, getting its num value
    // Takes the modulo of the number to the tablesize.
    char firstChar = k.at(0);
    return ((int)firstChar) % tablesize;
}

bool HashTable::insert(string k, string v)
{
    if (search(k) != -1)
    {
        return false;
    }

    int indexToCheck = hashFunction(k);

    for (int i = 0; i < tablesize; i++)
    {
        if (table[indexToCheck].getValue() == "" || table[indexToCheck].getValue() == "Deleted")
        {
            //found it

            table[indexToCheck] = HashNode(k, v);
            return true;
        }
        indexToCheck++;
        if (indexToCheck >= tablesize)
        {
            indexToCheck = 0;
        }
    }
    return false;
}

int HashTable::search(string k)
{
    int indexToCheck = hashFunction(k);

    for (int i = 0; i < tablesize; i++)
    {
        if (table[indexToCheck].getKey() == k)
        {
            //found it

            return indexToCheck;
        }
        indexToCheck++;
        if (indexToCheck >= tablesize)
        {
            indexToCheck = 0;
        }
    }
    return -1;
}

bool HashTable::update(string k, string v)
{
    int index = search(k);
    if (index == -1)
    {
        return false;
    }
    table[index].setValue(v);
    return true;
}

string HashTable::lookup(string k)
{
    int index = search(k);
    if (index == -1)
    {
        return "";
    }
    return table[index].getValue();
}

ostream &operator<<(ostream &output, const HashTable &ht)
{
    for (int i = 0; i < ht.tablesize; i++)
    {
        output << i << ": " << ht.table[i] << endl;
    }
    return output;
}
