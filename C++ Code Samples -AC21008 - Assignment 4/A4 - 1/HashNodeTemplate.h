#include<iostream>
#include "HashNode.h"

// Default constructor
template <class T1, class T2>
HashNode<T1, T2>::HashNode(){
}

// Parameterised constructor
template <class T1, class T2>
HashNode<T1, T2>::HashNode(T1 k, T2 v){

	// set key to k
	key = k;

	// set value to v 
    value = v; 
}

// Returns true if the keys are the same for both HashNode objects, otherwise false
template <class T1, class T2>
bool HashNode<T1, T2>::operator==(const HashNode<T1,T2>& oldnode){

    if (oldnode.key == key)
    {
    	// return true if keys are same 
        return true; 
    }
    else
    {
    	// return false if the keys are not same 
        return false; 
    }
}

// returns false if the keys are the same for both HashNode objects, otherwise true 
template <class T1, class T2>
bool HashNode<T1, T2>::operator!=(const HashNode<T1,T2>& oldnode){

	if (oldnode.key == key)
    {
    	// return false if the keys are same
        return false; 
    }
    else 
    {
    	// return true if the keys are not same
        return true; 
    }
}

// return the value of key
template <class T1, class T2>
T1 HashNode<T1, T2>::getKey(){

	// return value of key
    return key; 
}

// set the value of value to v
template <class T1, class T2>
void HashNode<T1, T2>::setValue(T2 v){

	// set value of value to v
	value = v; 
}

// return the value of value 
template <class T1, class T2>
T2 HashNode<T1, T2>::getValue() {

	// return value of value
    return value; 
}

// overloading of the output operator for a HashNode. Should print the key and value separated by a ':' with no newline. 
template <class T1, class T2>
std::ostream& operator<<(std::ostream &output, const HashNode<T1,T2> &hn) {

	// print key and value
	output << hn.key << ":" << hn.value;

	// return ouput
    return output;
}
