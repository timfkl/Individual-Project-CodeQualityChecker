
#include<iostream>
#include "HashNode.h"

template <class T1, class T2>
HashNode<T1, T2>::HashNode(){
}

template <class T1, class T2>
HashNode<T1, T2>::HashNode(T1 k, T2 v){
	key = k;
	value = v;
}

template <class T1, class T2>
bool HashNode<T1, T2>::operator==(const HashNode<T1,T2>& oldnode){
	//cout << key << " " << oldnode.key << key == oldnode.key << endl;
	if (key == oldnode.key)
	{
		return true;
	}
	return false;
}

template <class T1, class T2>
bool HashNode<T1, T2>::operator!=(const HashNode<T1,T2>& oldnode){
	//cout << key << " " << oldnode.key << endl;
	if (key == oldnode.key)
	{
		return false;
	}
	return true;
}

template <class T1, class T2>
T1 HashNode<T1, T2>::getKey() {
	return key;
}

template <class T1, class T2>
void HashNode<T1, T2>::setValue(T2 v){
	value = v;
}

template <class T1, class T2>
T2 HashNode<T1, T2>::getValue() {
	return value;
}

template <class T1, class T2>
std::ostream& operator<<(std::ostream &output, const HashNode<T1,T2> &hn) {
	output << hn.key << ":"<<hn.value;
	return output;
}
