#include <iostream>
#include "HashNode.h"

// default constructor
HashNode::HashNode() {

	key = "";
    value = "";
}

// parameterised constructor for the Hash Node class 
HashNode::HashNode(string k, string v) {


	// set key and value given to the given values (k and v)
    key = k;
    value = v;	
}

string HashNode::getKey() {

	// return key
	return key;

}

void HashNode::setValue(string v) {

	// set value of value
	value = v;

}

string HashNode::getValue() {

	// return value of value
	return value;

}

// overloading of output operator for a Hash Node 
ostream& operator<<(ostream &output, const HashNode &hn) {

	// Print key and value separated by a ':' with no new line
	output << hn.key << ":" << hn.value;

	// return output
	return output;  

}
