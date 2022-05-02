#include<iostream>
#include "HashNode.h"

HashNode::HashNode(){

     string* key;
     string*value;

}

HashNode::HashNode(string k, string v){
}

string HashNode::getKey() {

    return key;
}

void HashNode::setValue(string v){

    HashNode::value = value;
}

string HashNode::getValue() {

    return value;
}

ostream& operator<<(ostream &output, const HashNode &hn) {
}
