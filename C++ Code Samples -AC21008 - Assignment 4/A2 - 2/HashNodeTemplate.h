#include<iostream>
#include "HashNode.h"

/**
 * @brief Constructor for a HashNode, no data specified
 * 
 * @tparam T1 The key parameter type
 * @tparam T2 The value parameter type 
 */
template <class T1, class T2>
HashNode<T1, T2>::HashNode(){
}

/**
 * @brief Constructor for a HashNode with key and value specified
 * 
 * @tparam T1 The key parameter type
 * @tparam T2 The value parameter type 
 * @param k The key
 * @param v The value
 */
template <class T1, class T2>
HashNode<T1, T2>::HashNode(T1 k, T2 v){
    key = k;
    value = v;
}

/**
 * @brief Overloaded equals operator definition
 * 
 * @tparam T1 The key parameter type
 * @tparam T2 The value parameter type 
 * @param oldnode The node to compare to
 * @return true If the keys are equal
 * @return false If the keys are not equal
 */
template <class T1, class T2>
bool HashNode<T1, T2>::operator==(const HashNode<T1,T2>& oldnode){
    return (oldnode.key == this->key);
}

/**
 * @brief Overloaded not-equals parameter
 * 
 * @tparam T1 The key parameter type
 * @tparam T2 The value parameter type 
 * @param oldnode The node to compare to
 * @return true If the keys are not equal
 * @return false If the keys are equal
 */
template <class T1, class T2>
bool HashNode<T1, T2>::operator!=(const HashNode<T1,T2>& oldnode){
    return (oldnode.key != this->key);
}

/**
 * @brief Get the key of a HashNode
 * 
 * @tparam T1 The key parameter type
 * @tparam T2 The value parameter type 
 * @return T1 The key of the HashNode
 */
template <class T1, class T2>
T1 HashNode<T1, T2>::getKey() {
    return key;
}

/**
 * @brief Set the value of a HashNode
 * 
 * @tparam T1 The key parameter type
 * @tparam T2 The value parameter type 
 * @param v The value to set v to
 */
template <class T1, class T2>
void HashNode<T1, T2>::setValue(T2 v){
    value = v;
}

/**
 * @brief Get the value of a HashNode
 * 
 * @tparam T1 The key parameter type
 * @tparam T2 The value parameter type 
 * @return T2 The value of the HashNode
 */
template <class T1, class T2>
T2 HashNode<T1, T2>::getValue() {
    return value;
}

/**
 * @brief Overloaded output operator
 * 
 * @tparam T1 The key parameter type
 * @tparam T2 The value parameter type 
 * @param output The output stream to stream the output to
 * @param hn The HashNode to output
 * @return std::ostream& The populated output stream
 */
template <class T1, class T2>
std::ostream& operator<<(std::ostream &output, const HashNode<T1,T2> &hn) {
    output << hn.key << ":" << hn.value;
    return output;
}
