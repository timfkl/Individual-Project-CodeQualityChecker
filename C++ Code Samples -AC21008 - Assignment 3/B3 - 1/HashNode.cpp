#include<iostream>
#include "HashNode.h"


/**
 * Default  constructor  for  the  HashNode  class.  
 * This will set the key and value to empty strings. 
 */
HashNode::HashNode()
{
    key = "";
    value = "";
}

/**
 * Paramererised constructor for the HashNode class. 
 * This will set the key and value to the given values 
 */
HashNode::HashNode(string k, string v)
{
    key = k;
    value = v;
}

/**
 * Will return the value of the key
 * @return the key string
 */
string HashNode::getKey() 
{
    return key;
}

/**
 * Will set the value of value to v. 
 * @param v The value to be set
 */
void HashNode::setValue(string v)
{
    value = v;
}


/**
 * Will return the value of the value
 * @return the value string
 */
string HashNode::getValue() 
{
    return value;
}


/**
 * Overloading of the output operator for a HashNode. 
 * Should print the key and value separated by a ‘:’ with no newline. 
 * @param output Getting the values for key and value line
 * @param hn Reference to the HashNode
 * @return The result
 */
ostream& operator<<(ostream &output, const HashNode &hn) 
{
    output << hn.key << " : " << hn.value ;
    return output;
}

