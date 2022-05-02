#include <iostream>
#include "HashNode.h"

/**
 * @brief Construct a new Hash Node< T 1,  T 2>:: Hash Node object
 *
 * @tparam T1
 * @tparam T2
 */
template <class T1, class T2>
HashNode<T1, T2>::HashNode()
{
}

/**
 * @brief Construct a new Hash Node< T 1,  T 2>:: Hash Node object
 *
 * @tparam T1
 * @tparam T2
 * @param k
 * @param v
 */
template <class T1, class T2>
HashNode<T1, T2>::HashNode(T1 k, T2 v)
{
    this->value = v;
    this->key = k;
}

/**
 * @brief Overloads the '==' comparitor for hashnodes
 *
 * @tparam T1
 * @tparam T2
 * @param oldnode
 * @return true
 * @return false
 */
template <class T1, class T2>
bool HashNode<T1, T2>::operator==(const HashNode<T1, T2> &oldnode)
{
    if (this->getKey() == oldnode.key)
    {
        return true;
    }
    else
    {
        return false;
    }
}

/**
 * @brief Overloads the '!=' for hash nodes
 *
 * @tparam T1
 * @tparam T2
 * @param oldnode
 * @return true
 * @return false
 */
template <class T1, class T2>
bool HashNode<T1, T2>::operator!=(const HashNode<T1, T2> &oldnode)
{
    if (this->getKey() == oldnode.key)
    {
        return false;
    }
    else
    {
        return true;
    }
}

/**
 * @brief Getter for key member
 *
 * @tparam T1
 * @tparam T2
 * @return T1
 */
template <class T1, class T2>
T1 HashNode<T1, T2>::getKey()
{
    return this->key;
}

/**
 * @brief Setter for value member
 *
 * @tparam T1
 * @tparam T2
 * @param v
 */
template <class T1, class T2>
void HashNode<T1, T2>::setValue(T2 v)
{
    this->value = v;
}

/**
 * @brief getter for value member
 *
 * @tparam T1
 * @tparam T2
 * @return T2
 */
template <class T1, class T2>
T2 HashNode<T1, T2>::getValue()
{
    return this->value;
}

/**
 * @brief Overloads '<<' operator for Hash nodes
 *
 * @tparam T1
 * @tparam T2
 * @param output
 * @param hn
 * @return std::ostream&
 */
template <class T1, class T2>
std::ostream &operator<<(std::ostream &output, const HashNode<T1, T2> &hn)
{
    return output << hn.key << ":" << hn.value;
}
