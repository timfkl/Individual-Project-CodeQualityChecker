#include <iostream>
#include "HashNode.h"

/**
 * @brief Construct a new Hash Node:: Hash Node object
 * 
 */
HashNode::HashNode()
{
    this->value = "";
    this->key = "";
}

/**
 * @brief Construct a new Hash Node:: Hash Node object
 * 
 * @param k 
 * @param v 
 */
HashNode::HashNode(string k, string v)
{
    this->key = k;
    this->value = v;
}

/**
 * @brief gets the key member
 * 
 * @return string 
 */
string HashNode::getKey()
{
    return this->key;
}

/**
 * @brief sets the value member
 * 
 * @param v 
 */
void HashNode::setValue(string v)
{
    this->value = v;
}

/**
 * @brief gets the value member
 * 
 * @return string 
 */
string HashNode::getValue()
{
    return this->value;
}

/**
 * @brief overloads the << operator for HashNodes
 * 
 * @param output 
 * @param hn 
 * @return ostream& 
 */
ostream &operator<<(ostream &output, const HashNode &hn)
{
    output << hn.key << ':' << hn.value;
    return output;
}
