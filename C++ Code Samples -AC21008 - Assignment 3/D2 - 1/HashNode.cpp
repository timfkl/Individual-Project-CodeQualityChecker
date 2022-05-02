
#include<iostream>
#include "HashNode.h"

HashNode::HashNode(){

     key = "";//empty string
     value = "";//empty string

}

HashNode::HashNode(string k, string v){
    value = v;//storing v in value
    key = k;//storing k in key
}

string HashNode::getKey() {
    return key;//return key
}

void HashNode::setValue(string v){
    v = value;//storing value in v
}

string HashNode::getValue() {
    return value;//return value
}

ostream& operator<<(ostream &output, const HashNode &hn) {
    return output <<hn.key<<":"<<hn.value;
}
