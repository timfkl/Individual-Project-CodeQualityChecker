#include<iostream>
#include "HashNode.h"

HashNode::HashNode(){
    key = "";
    value = "";
}

HashNode::HashNode(string k, string v){
    // TODO Handle invalid inputs?
    key = k;
    value = v;
}

string HashNode::getKey() {
    return key;
}

void HashNode::setValue(string v){
    value = v;
}

string HashNode::getValue() {
    return value;
}

ostream& operator<<(ostream &output, const HashNode &hn) {
   return output << hn.key << ":" << hn.value;
}
