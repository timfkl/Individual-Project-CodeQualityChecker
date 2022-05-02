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

/**
 * @brief Returns true if the list is empty
 * 
 * @tparam Type The data type stored in the list 
 * @return true If the list is empty
 * @return false If the list is not empty
 */
template <class Type> 
bool List <Type> :: empty() const
{
    // List is empty if Head pointer is nullptr
    return (Head == nullptr);
}

/**
 * @brief Removes an element from the list
 * 
 * @tparam Type The data type stored in the list
 * @param del_element Element matching the list element to be removed 
 * @return true If the element was removed successfully
 * @return false If the element could not be removed
 */
template <class Type> 
bool List <Type> :: remove(const Type& del_element)
{
    // Define node pointers
    Node* temp;
    Node* prev;

    // Check if list is empty
    if(empty()){
        // Nothing can be removed
        return false;
    }
    else{
        // Check if head is element to delete
        if(Head->Element == del_element){
            // Remove head
            temp = Head;
            Head = Head->Next;
            delete temp;
            return true;
        }
        
        prev = Head;
        temp = Head->Next;

        // Search for element or end of list
        while(temp != nullptr && temp->Element != del_element){
            prev = temp;
            temp = temp->Next;
        }

        // List exhausted
        if(temp == nullptr){
            return false;
        }

        // Element found in temp
        else{
            prev->Next = temp->Next;
            delete temp;
            return true;
        }
    }
}

/**
 * @brief Returns true if the element is found, otherwise returns false
 * 
 * @tparam Type The data typesstored in the list
 * @param search_element The value of search element (passed by reference) is set to the value of the found item
 * @return true If the element was found
 * @return false If the element was not found
 */
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

/**
 * @brief Inserts a new element at the beginning of the list
 * 
 * @tparam Type The data type stored in the list
 * @param new_element The element to add
 * @return true If the element was inserted successfully
 * @return false If the element could not be inserted 
 */
template <class Type> 
bool List <Type> :: insert(const Type& new_element)
{
    // Insert new node into list
    try{
        Node* newNode;
        newNode = new Node;
        newNode->Element = new_element;
        newNode->Next = Head;
        Head = newNode;
        return true;
    }
    // Catch exceptions (namely bad alloc exceptions)
    catch(const std::exception& e){
        return false;
    }
}

/**
 * @brief Overload declaration for the output operator
 * 
 * @tparam Type The data type of the list
 * @param out_stream The output stream that the output should be streamed to
 * @param out_list The list to output
 * @return ostream& The populated output stream
 */
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
