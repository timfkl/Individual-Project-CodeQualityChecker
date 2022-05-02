#include<iostream>
#include "HashNode.h"

//Constructor
template <class T1, class T2>
HashNode<T1, T2>::HashNode(){
}

//Parameterised constructor
template <class T1, class T2>
HashNode<T1, T2>::HashNode(T1 k, T2 v){
	//Set the fields to the given values
	key =k;
	value = v;
}

//Overload the operator ==
template <class T1, class T2>
bool HashNode<T1, T2>::operator==(const HashNode<T1,T2>& oldnode){

	//If the keys are equal return true
	if (oldnode.key==key)
	{
		return true;
	}
	//if they are not equal return false
	else
	{
		return false;
	}
}

//Overload the operator !=
template <class T1, class T2>
bool HashNode<T1, T2>::operator!=(const HashNode<T1,T2>& oldnode){

	//If the keys are not equal return true
	if (oldnode.key!=key)
	{
		return true;
	}
	//if they are equal return false
	else
	{
		return false;
	}
}

//function to get the key value
template <class T1, class T2>
T1 HashNode<T1, T2>::getKey() {
	//return key
	return key;
}

//function to set the value parameter to the given value
template <class T1, class T2>
void HashNode<T1, T2>::setValue(T2 v){

	//set the value parameter
	value= v;
}

//function to get the value
template <class T1, class T2>
T2 HashNode<T1, T2>::getValue() {
	//return value
	return value;
}

//Output overload
template <class T1, class T2>
std::ostream& operator<<(std::ostream &output, const HashNode<T1,T2> &hn) {
	//overload the output
	output << hn.key << ":" << hn.value;

	//return the overloaded output
	return output;
}
