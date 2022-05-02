#ifndef LLISTTEMPLATE_H
#define LLISTTEMPLATE_H
#include "List.h"

// Constructor
template <class Type>
List <Type> :: List() : Head(nullptr)
{
}

// Destructor

template <class Type>
List <Type> :: ~List()
{
  Node* temp;
  while (Head != nullptr)
  {
    temp = Head;
    Head = Head -> Next;
    delete temp;
  }
}

// Empty

template <class Type> 
bool List <Type> :: empty() const
{
    if (Head == nullptr)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// Delete

template <class Type> 
bool List <Type> :: remove(const Type& del_element)
{
    Node* temp;
    Node* prev;
    
    if (empty())
    {
        return false;
    }
    else if (Head -> Element == del_element)
    {
        temp = Head;
        Head = Head -> Next;
        delete temp;
        return true;
    }
    else if (Head -> Next == nullptr)
    {
        return false;
    }
    else
    {
        temp = Head;
        do
        {
            prev = temp;
            temp = temp -> Next;
            if (temp -> Element == del_element)
            {
                prev -> Next = temp -> Next;
                delete temp;
                return true;
            }
        }while (temp -> Next != nullptr);
        return false;
    }
}

// Search

template <class Type>
bool List<Type>::search(Type& search_element){
    if (empty()){
        return false;
    }else{
        Node* temp = Head;
        while ((temp->Element != search_element) && (temp->Next != nullptr)){
            temp = temp->Next;
        }
        if(temp->Element == search_element){
            search_element = temp->Element;
            return true;
        }else{
            return false;
        }
    }
}

// Insert (simple insert at beginning)

template <class Type> 
bool List <Type> :: insert(const Type& new_element)
{
    Node* new_node;
    new_node = new Node;
    new_node -> Element = new_element;
    new_node -> Next = Head;
    Head = new_node;
    return true;
}

template <class Type>
ostream& operator<<(ostream& out_stream, const List<Type>& out_list) {
    typename List<Type>::Node* temp = out_list.Head;
    while (temp != nullptr) {
        out_stream << temp -> Element << " ";
        temp = temp -> Next;
    }
    return out_stream;
}
#endif
