#ifndef LLISTTEMPLATE_H
#define LLISTTEMPLATE_H
#include "List.h"


template <class Type>
List <Type> :: List() : Head(nullptr)
{
}



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



/**template <class Type> 
bool List <Type> :: empty() const**/





template <class Type> 
bool List <Type> :: remove(const Type& del_element)
{
    Node *temp;
    Node *previous;

    if (empty()){
        return false;
    }
    else if (Head->Element == del_element)
    {
        temp = Head;
        Head = Head->Next;
        delete temp;
        return true;
    }
    else if (Head->Next == nullptr)
        return false;
    else
    {
        previous = Head;
        temp = Head->Next;
        while ((temp->Element != del_element) && (temp->Next != nullptr))
        {
            previous = temp;
            temp = temp->Next;
        }
        if (temp->Element == del_element)
        {
            previous->Next = temp->Next;
            delete temp;
            return true;
        }
        else{
            return false;
        }
    }
}



/**template <class Type>
bool List<Type>::search(Type& search_element){
    if (empty()){
    
}**/



template <class Type> 
bool List <Type> :: insert(const Type& new_element)
{
    Type temp = new_element;
    if(search(temp)){
        return false;
    }
    Node *new_node;
    new_node = new Node;
    new_node->Element = new_element;
    new_node->Next = Head;
    Head = new_node;
    return true;
}

template <class Type>
ostream& operator<<(ostream& out_stream, const List<Type>& out_list) {
    typename List<Type>::Node* temp = out_list.Head;
	while (temp != nullptr) {
		out_stream << temp -> Element ;
		
	}
	return out_stream;
}

