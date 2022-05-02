#include<iostream>
#include "HashNode.h"

template <class T1, class T2>
HashNode<T1, T2>::HashNode(){
}

/*
* Sets key and value to given variables
*/
template <class T1, class T2>
HashNode<T1, T2>::HashNode(T1 k, T2 v){
  key = k;
  value = v;
}

// Should return true if the keys are
// the same for both HashNode objects, otherwise false
template <class T1, class T2>
bool HashNode<T1, T2>::operator==(const HashNode<T1,T2>& oldnode){
  return (oldnode.key == key) ? true : false;
}

// Should return false if the keys are
// the same for both HashNode objects, otherwise false
template <class T1, class T2>
bool HashNode<T1, T2>::operator!=(const HashNode<T1,T2>& oldnode){
  return (oldnode.key == key) ? false : true;
}

//Getter for key
template <class T1, class T2>
T1 HashNode<T1, T2>::getKey() {
  return key;
}

//Sets value to given variable
template <class T1, class T2>
void HashNode<T1, T2>::setValue(T2 v){
  value = v;
}

//Getter for value
template <class T1, class T2>
T2 HashNode<T1, T2>::getValue() {
  return value;
}

//Display Function
template <class T1, class T2>
std::ostream& operator<<(std::ostream &output, const HashNode<T1,T2> &hn) {
  output << hn.key << " : " << hn.value;
  return output;
}
