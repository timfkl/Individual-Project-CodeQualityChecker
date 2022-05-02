#ifndef LLISTTEMPLATE_H
#define LLISTTEMPLATE_H
#include "List.h"

// Constructor
template <class Type>
List<Type>::List() : Head(nullptr)
{
}

// Destructor
template <class Type>
List<Type>::~List()
{
    Node *temp;
    while (Head != nullptr)
    {
        temp = Head;
        Head = Head->Next;
        delete temp;
    }
}

/**
 * @brief Checks if the linked list is empty
 *
 * @tparam Type
 * @return true
 * @return false
 */
template <class Type>
bool List<Type>::empty() const
{
    if (this->Head == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}

/**
 * @brief Deletes an element based on the Type parameter
 *
 * @tparam Type
 * @param del_element
 * @return true
 * @return false
 */
template <class Type>
bool List<Type>::remove(const Type &del_element)
{
    // init helper temp node pointers
    Node *nodeToDelete;
    Node *previous;

    // checking if the list is empty
    if (this->empty() == true)
    {
        return false;
    }
    else if (this->Head->Element == del_element)
    {
        // setting the temp ptr to the head of the lsit and moving the head along one element
        nodeToDelete = this->Head;
        this->Head = Head->Next;

        delete nodeToDelete;
        return true;
    }
    else
    {
        // setting the pointers to initial value
        previous = this->Head;
        nodeToDelete = this->Head->Next;

        while ((nodeToDelete->Element != del_element) && (nodeToDelete->Next != nullptr))
        {
            // iterating through the linked list
            previous = nodeToDelete;
            nodeToDelete = nodeToDelete->Next;
        }

        if (nodeToDelete->Element == del_element)
        {
            previous->Next = nodeToDelete->Next;
            delete nodeToDelete;
            return true;
        }
        else
        {
            // returning if not found
            return false;
        }
    }
}

// Search
template <class Type>
bool List<Type>::search(Type &search_element)
{
    if (empty())
    {
        return false;
    }
    else
    {
        Node *temp = Head;
        while ((temp->Element != search_element) && (temp->Next != nullptr))
        {
            temp = temp->Next;
        }
        if (temp->Element == search_element)
        {
            search_element = temp->Element;
            return true;
        }
        else
        {
            return false;
        }
    }
}

// Insert (simple insert at beginning)
template <class Type>
bool List<Type>::insert(const Type &new_element)
{
    // init new node (setting its next to current head)
    Node *nodeToInsert;
    nodeToInsert = new Node(new_element, this->Head);

    // setting head to the new node
    this->Head = nodeToInsert;

    // checking node was added
    if (this->Head == nodeToInsert)
    {
        return true;
    }
    else
    {
        return false;
    }
}

template <class Type>
ostream &operator<<(ostream &out_stream, const List<Type> &out_list)
{
    typename List<Type>::Node *temp = out_list.Head;
    while (temp != nullptr)
    {
        out_stream << temp->Element << " ";
        temp = temp->Next;
    }
    return out_stream;
}
#endif
