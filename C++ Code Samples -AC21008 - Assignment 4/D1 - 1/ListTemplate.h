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
  return (Head == nullptr);
}

// Delete

template <class Type>
bool List <Type> :: remove(const Type& del_element)
{

  Node* temp = Head;
  // empty list
  if (temp == nullptr) {
    return false;
  }

  // case first node
  if (temp->Element == del_element) {
    Head = temp->Next;
    delete temp;
    return true;
  }

  // case not first node
  while(temp->Next != nullptr) {
    if (temp->Next->Element == del_element) {
      // jump over links
      Node* del = temp->Next;
      temp->Next = temp->Next->Next;
      // delete unused element
      delete del;
      // success
      return true;
    }
    temp = temp->Next;
  }

  return false;
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
  // Node *newNode = (Node*) malloc(sizeof(Node));
  // newNode->Next = Head;
  // // segfult on this line
  // newNode->Element = new_element;
  // this->Head = newNode;
  // return true;

  Node *temp = Head;
  Head = new Node(new_element, temp);
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
