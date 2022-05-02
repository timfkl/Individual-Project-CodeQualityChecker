#include<iostream>
#include "HashNode.h"

/*
HashNode();  Default  constructor  for  the  HashNode  class.  It  should  set  the  key  and  value  to
empty strings.
*/
HashNode::HashNode(){
  key="";
  value="";
}

/*
HashNode(string k, string v); Paramererised constructor for the HashNode class. It should set
the key  and value to the given values (k  and v).
*/
HashNode::HashNode(string k, string v){
  key = k;
  value = v;
}

/*
string getKey(); Should return the value of key.
*/
string HashNode::getKey() {
  return key;
}

/*
void setValue(string v); Should set the value of value to v.
*/
void HashNode::setValue(string v){
  value = v;
}

/*
string getValue(); Should return the value of value
*/
string HashNode::getValue() {
  return value;
}

/*
Displays the key with the paired value
*/
ostream& operator<<(ostream &output, const HashNode &hn) {
  output << hn.key << ":" << hn.value;
  return output;
}
