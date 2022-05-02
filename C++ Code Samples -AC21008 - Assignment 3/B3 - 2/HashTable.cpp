#include "HashTable.h"
#include<iostream>
 #include<cmath>
 

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

   int  primeNumber = 31;
   

    int key = 0;

    for (int i = 0; i < k.length(); ++i)
    {
        key += (k[i] * (int)pow(primeNumber, i)) % tablesize;
    }

    

    return key % tablesize;


}

bool HashTable::insert(string k, string v){


        
    int index = hashFunction(k);

   

  for (int i = index; i < tablesize; ++i)
    {
        

        
        if (table[index].getValue().empty())
        {   
            table[i] = HashNode(k,v);
           
            table[i].setValue(v);
            

            
            return true ;

        }
        else{

            
            return false;
        }

        cout << HashTable();
    }
}


      



int HashTable::search(string k){

    int index = hashFunction(k);

    string value;

    

    if (table[index].getValue().empty())
    {
        return  -1;
    }
    else{
        

    return index;
    }

    

}

bool HashTable::update(string k, string v){

    int index = hashFunction(k);

    table[index].setValue(v);   

    return true;

}

string HashTable::lookup(string k){

    int node = search(k);
    if (node == -1)
    {
        return "error";
    }
    else{
        return table[node].getValue();
    }
}

ostream& operator<<(ostream &output, const HashTable &ht) {

    for (int i = 0; i < ht.tablesize; ++i)
    {
        output << i << ":" << ht.table[i] << endl;
    }

    return output;
}
