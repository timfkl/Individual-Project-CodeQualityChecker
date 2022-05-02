#ifndef LLISTTEMPLATE_H
#define LLISTTEMPLATE_H
#include "List.h"

// Constructor
template <class Type>
List <Type> :: List() : Head(nullptr){
}

// Destructor
template <class Type>
List <Type> :: ~List(){
  Node* temp;
  while (Head != nullptr)
  {
    temp = Head;
    Head = Head -> Next;
    delete temp;
  }
}

// Empty
// Returns true if the list is empty, or false otherwise
template <class Type> 
bool List <Type> :: empty() const{

    // return true if list is empty
        if (Head == nullptr)
    {
        return true;
    }
    else 
    {
        // return false if list is not empty 
        return false;
    }
}

// Delete
// Removes an element matching del_element from the list (matched using ==). Returns true it the item was removed, otherwise returns false.  
template <class Type> 
bool List <Type> :: remove(const Type& del_element){

    // create temp node
    Node* temp;

    // create previous node
    Node* previous;

    // return false if list is empty
    if (empty())
    {
        return false;
    }
    // delete element at the head of list 
    else if (Head->Element == del_element)
    {
        // set temp to head
        temp = Head;
        
        // set head to be head's next 
        Head = Head->Next;
        
        // delete temp 
        delete temp;

        // return true 
        return true; 
    }
    else if (Head->Next == nullptr)
    {
        // return false if head's next is null 
        return false;
    }
    else
    {
        // traverse list

        // set previous to head
        previous = Head;

        // set temp to head's next  
        temp = Head->Next; 

        // element to be deleted is not found and end of the list is not reached 
        while ((temp->Element != del_element) && (temp->Next != nullptr))
        {
            // set previous to temp
            previous = temp; 

            // set temp to temp's next
            temp = temp->Next; 
        }

        // if current element is element to delete
        if(temp->Element == del_element)
        {
            // set previous's next to temp's next
            previous->Next = temp->Next;

            // delete temp 
            delete temp;

            // return true 
            return true; 
        }
        else
        {
            // return false if element to be deleted was not found
            return false; 
        }
    }
}

// Search
// Returns true if the element is found, otherwise returns false
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
// Should insert a new element at the beginning or the list. Returns true if the item was added, otherwise returns false.
template <class Type> 
bool List <Type> :: insert(const Type& new_element){

    // creates new node 
    Node* newNode;

    // set newNode to new Node
    newNode = new Node;

    // set new Node's element to new element
    newNode->Element = new_element; 
    
    // set new node's next to head
    newNode->Next = Head; 

    // set head to new node
    Head = newNode; 

    // head is equal to new node 
    if (Head == newNode)
    {
        // return false
        return true;
    }
    else 
    {
        // return false
        return false; 
    }
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
