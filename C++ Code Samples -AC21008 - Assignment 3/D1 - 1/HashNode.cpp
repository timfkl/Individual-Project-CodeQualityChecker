#include<iostream>
#include "HashNode.h"

HashNode::HashNode(){
    //set key and value to empty strings
    key = "";
    value = "";

}

HashNode::HashNode(string k, string v){
    //set the key and value to given values(k & v)
    key = k;
    value = v;
}

string HashNode::getKey() {
    //return key
    return key;
}

void HashNode::setValue(string v){
    //set value to the value (v)
    value = v;
}

string HashNode::getValue() {
    //return value
    return value;
}

ostream& operator<<(ostream &output, const HashNode &hn) {
    //print like key and value seperated by ":" example: "Alice:0012"
    output << hn.key << ":" << hn.value << endl;
    return output;

}
