
#include "HashTable.h"
#include<iostream>
//#include <string>
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

int HashTable::hashFunction(string k)
{
    int value = 25;//unique value to determing index with ASCII
	int size= 12;//size of array
	int mod;// to store answer of modulor
    //int j = (k.length - 1);


	for (string::size_type i = 0; i < k.length(); i++)
    {
       mod= (( 0 + k[i] + k[(k.length())-1] )+( value * i ))% size;
    }
    return mod;//return modulor value
}

bool HashTable::insert(string k, string v)
{
    HashNode newNode(k,v);

    int currentIndex;

    currentIndex=hashFunction(k);//store result from hashfunction in currentindex variable for use 
  
    
    //table[currentIndex]=newNode;

//loop to insert value into the table 
do{  
    table[currentIndex]=newNode;// make newNode the value of the currentindex position
    currentIndex++;//increment currentindex by 1
   currentIndex %= 12;
  }while (table[currentIndex].getKey() != "");
  

   
  
 
  return true;// return true
}

int HashTable::search(string k)
{
    int tableIndex=hashFunction(k);//store 
   //while the current tableindex is not empty
   while(table[tableIndex].getKey()!= "")
    {
        
     
        if (table[tableIndex].getKey()==k ||tableIndex==tablesize)
        {
            tableIndex=0;
            return tableIndex;//return table index
            break;//come out of loop
        }
        tableIndex ++;//increment tableindex
       
    }
return -1;
}

bool HashTable::update(string k, string v)
{
    int searchCopy;//a copy for the search function
    bool found;// logic variable to return true or false if an item is found after search is done

    searchCopy=search(k);//store search function value in searhcopy for use 
    found=false;//initialising found to false
    
//////////
    do{//loop to check the condition of searchCopy, returning true or false 
        table[searchCopy].setValue(v);
        found = true;//item found
        
        return found;//found
;
    }while(searchCopy !=-1);
    
        
        table[searchCopy].setValue(v);
        found=false;//not found
    

    
    
    return found;//return logic condition
}

string HashTable::lookup(string k)
{
    int searchCopy=search(k);//store search function value in searhcopy for use 
    do 
    {
       return table[searchCopy].getValue();
    }while(searchCopy!=-1);
    
     return "";//return an empty string beacuse no key is found
}

ostream& operator<<(ostream &output, const HashTable &ht)
{
 for (int i = 0; i < ht.tablesize; i++)
      {
        output<<i<<":"<<ht.table[i].getKey()<< ":"<<ht.table[i].getValue();
        
        cout << endl;//move to nextline after each loop cycle
        }
    return output;//return output
}
