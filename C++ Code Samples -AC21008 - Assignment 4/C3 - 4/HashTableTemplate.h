#include "HashTable.h"
#include<iostream>
using namespace std;

template <class T1, class T2>
HashTable<T1,T2>::HashTable() {
    tablesize = 10;
    table = new HashNode[10];
}

template <class T1, class T2>
HashTable<T1,T2>::HashTable(int size) {
    tablesize = size;
    //table = new HashNode[size];
}

template <class T1, class T2>
HashTable<T1,T2>::~HashTable() {
    delete [] table;
}

template <class T1, class T2>
int HashTable<T1,T2>::hashFunction(T1 k) {
    //checks to make sure that a valid key is given.
    if(k == "")
    {
        return 0;
    }

    //variable setup.
    int key = 0;
    int prime = 31;
    int power = 0;
    int sl = k.length();

    //steps through each character of the key.
    for(int i = sl-1; i > -1; i--)
    {
        //for each iteration, add to 'key' the ASCII value of the current letter multiplied by 31 to the power of 'power'.
        key = key + (int(k[i])*prime^power);
        //increase 'power' by 1 for the next iteration.
        power++;
    }
    //returns the remainder of 'key' divided by the size of the table.
    return (key%tablesize);
}

template <class T1, class T2>
bool HashTable<T1,T2>::insert(T1 k, T2 v){
    if(k == "" || v == "")
    {
        return false;
    }

    HashNode toAdd = HashNode(k, v);
    //Node toInsert = toAdd;
    int index = hashFunction(k);

    //if(table[index]. == "")
    //{
        table[index].insert(toAdd);
        //return true;
    /*}
    else
    {
        while(table[index].getKey() != "")
        {
            if(index == tablesize-1)
            {
                index = 0;
            }
            else
            {
                index++;
            }
        }
        table[index].insert(toAdd);
        //return true;
    }*/
    return true;
}

/*template <class T1, class T2>
bool HashTable<T1,T2>::update(T1 k, T2 v){
    return true;
}

template <class T1, class T2>
bool HashTable<T1,T2>::lookup(T1 k, T2 &v){
    return true;
}*/

template <class T1, class T2>
std::ostream& operator<<(std::ostream &output, const HashTable<T1,T2> &ht) {
    for(int k = 0; k < ht.tablesize; k++)
    {
        output << k << ":" << ht.table[k] << endl;
    }
    return output;
}
