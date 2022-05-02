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
    if(List* temp==NULL){
        return true;
    }else{
        return -1;
    }
}

// Delete

template <class Type> 
bool List <Type> :: remove(const Type& del_element)
{
    if (empty()){
        return false;
    }else{
      Node* temp=Head;
      while((temp->Element!=del_element)&& (temp->Next!=nullptr)) {
          temp=temp->Next;
      } 
        if (temp->Element==del_element){
            del_element=temp->Element;
            return true;
        }else{
            return false;
        }
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
      if (empty()){
        return false;
    }else{
        Node* temp = Head;
        
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
