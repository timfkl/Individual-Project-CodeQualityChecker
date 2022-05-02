#include<iostream>
#include "HashNode.h"

HashNode::HashNode(){

	value = string();
	key = string();
}

HashNode::HashNode(string k, string v){

	value = string(v);
	key = string(k);
}

string HashNode::getKey() {

	return key;

}

void HashNode::setValue(string v){

	value = string(v);
}

string HashNode::getValue() {
	return value;
}

ostream& operator<<(ostream &output, const HashNode &hn) {

	output << hn.key << ":" << hn.value ;

	return output;
}


