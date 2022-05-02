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
    if(Head == NULL){
        return true;
    }
    return false;
}

// Delete

template <class Type> 
bool List <Type> :: remove(const Type& del_element)
{
    // if(search(del_element) == false){
    //     return false;
    // }

    if(Head == NULL){
        return false;
    }
    
    if(Head->Element == del_element){
    
        if(Head->Next == NULL){
            Head = NULL;
            return true;
        }else{
            Head->Next = Head;
            return true;
        }
        
    }

    Node* prev = Head;
    Node* curr = Head->Next;
        while ((curr->Element != del_element) && (curr->Next != nullptr)){
            prev = curr;
            curr = prev->Next;
        }
        if(curr->Element == del_element){
            prev->Next = curr->Next;
            return true;
        }else{
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
    // if(new_element == nullptr){
    //     return false;
    // }
    Node* newNode = new Node();
    newNode->Element = new_element;
    newNode->Next = Head;
    Head = newNode;
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