#include "HashTable.h"
#include<iostream>
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

int HashTable::hashFunction(string k) {
    
    //HashedValue is the variable to store the hash key
    int hashedValue = 0;
    
    //For i in range i < length of k
    for (unsigned long int i = 0; i < k.length(); i++) {

        //Adds ASCII values up
        hashedValue += int(k.at(i));
    
    }

    hashedValue = hashedValue % tablesize;

    //If it is out of bounds, displays error and calls the hashFunction again, passing hashedValue through
    if (hashedValue < 0 || hashedValue > tablesize) {
        //cout << "Error. Out of bounds. Rehashing..." << endl;
         string hashedValue;
         hashFunction(hashedValue);
    }

    //Else, returns hashed value
    else {

        return hashedValue;
    }
     
     //Returns hashedValue
     return hashedValue;

}

bool HashTable::insert(string k, string v){
    //The int hashed value- position to store in table
    int theHashedValue = hashFunction(k);

    //Temp hashedValue function
    int tempHashV = theHashedValue;

    //Boolean to hold found status, false by default
    bool foundPlace = false;

    //Integer timesFailed set to 0;
    int timesFailed = 0;
    
    //For c, while c < tablesize
    for (int c = 0; c < tablesize; c++) {

        //If table[c].getKey equals k or table[c].getKey equals k & table[c].getValue equals k
        if (table[c].getKey() == k ) {
            
            //Sends error message
            // cout << "An item with this key already exists in the table. Rejecting the item..." << endl;

            //Returns false
            return false;
        }
    }
    
    //If table[theHashedValue].getKey is empty then value is set and true is returned
    if (table[theHashedValue].getValue().empty())
    {
        //Sends message to the user saying node successfully added
        //cout << "This space is empty! Adding node..." << endl;

       //A new node is created containing k&v
        HashNode newNode(k, v);

        //At table[theHashedValue], set to new node.
        table[theHashedValue] = newNode;

        //FoundPlace is set to true
        foundPlace = true;

        //True is returned
        return true;
    }

    //Else
    else {

        //Sends error to user
        //cout << "The entry isn't empty! Trying to find a new place..." << endl;


        //while foundPlace is false
        while (foundPlace == false && timesFailed <= tablesize) {

            //TempHashV will increment for as long as it is under tablesize
            for (; tempHashV < 10 && timesFailed <= tablesize; tempHashV++) {

                //If getValue is empty at table[tempHashV]
                if (table[tempHashV].getValue().empty())
                {
                    //Sends success message
                    //cout << "Entry successfully added at position: " << tempHashV << endl;

                    //a New node has been created and set to contain varables k&v
                    HashNode newNode(k, v);

                    //At table[tempHashV]. is set to new node
                    table[tempHashV] = newNode;

                    //FoundPlace is set to true
                    foundPlace = true;

                    //Return true;
                    return true;
                }

                else {

                    //Increments timesFailed
                    timesFailed++;
                    

        
                }

    
            }

            //For tempHashV while tempHashV is over 0, it decrements
            for (; tempHashV > 0 && timesFailed <= tablesize; tempHashV--)
            {
                //If table[tempHashV].getValue is empty
                if (table[tempHashV].getValue().empty())
                {
                    //Sends success message
                    //cout << "Entry successfully added at position: " << tempHashV << endl;

                    
                    //a New node has been created and set to contain varables k&v
                    HashNode newNode(k, v);

                    //At table[tempHashV]. is set to new node
                    table[tempHashV] = newNode;

                    //Found place is set to true
                    foundPlace = true;

                    //Return true
                    return true;
                }

                else {
                    //Increments timesFailed
                    timesFailed++;

                }
            }

            }

            //If foundPlace is equal to false
            if (foundPlace == false && timesFailed > tablesize)
            {

                //Sends error message
                // cout << "Could not add entry. Table full" << endl;

                //Returns false;
                return false;
            }
        }
        
    return false;
}

int HashTable::search(string k){
    
    //The int hashed value- position to store in table
    int theHashedValue = hashFunction(k);

    //If table[theHashedValue].getKey equals k
    if (table[theHashedValue].getKey() == k) {

        //Return the hashedValue at which it's found
        return theHashedValue;
    }

    else {
        //Print & Return error message
        //cout << "Not found the key" << endl;
        return -1;
    }
}

bool HashTable::update(string k, string v){

    //If search(k) != -1 
    if (search(k) != -1) {

        //table[search(k)]'s value is set V;
        table[search(k)].setValue(v);

        //Returns true;
        return true;
        }

    else {
        //Sends not found
        // cout << "Not found!" << endl;

        //Return false;
        return false;
    }

    }


string HashTable::lookup(string k){

    //If search(k) is not equal to -1
    if (search(k) != -1) {
        
        //Return table[search(k)].getValue();s
        return table[search(k)].getValue();
        }

    else {
        return "";
    }
}

ostream& operator<<(ostream &output, const HashTable &ht) {
    for (int i = 0; i < ht.tablesize; i++) {
        output << i << ":" << ht.table[i].getKey() << ":" << ht.table[i].getValue() << endl;


    }
    return output;
}
