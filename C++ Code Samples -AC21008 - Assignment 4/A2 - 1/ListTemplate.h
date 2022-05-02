

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
    if(Head == nullptr)
    {
        return true;
    }

    return false;
}

// Delete

template <class Type> 
bool List <Type> :: remove(const Type& del_element)
{
    if (empty())
        return false;

    else
    {
        Node* temp = Head;

        // Go through list till node with del_element is found.
        while ((temp->Element != del_element) && (temp->Next != nullptr))
        {
            temp = temp->Next;
        }

        if(temp->Element == del_element)
        {
            // Remove node if it's the only node in the list
            if(temp == Head && temp->Next == nullptr)
            {
                Head = Head->Next;
                return true;
            }

            // Override node to delete with contents of the next node and point Next to the rest of the list 
            if (temp->Next != nullptr)
            {
                temp->Element = temp->Next->Element;
                temp->Next = temp->Next->Next;
            }
            else
            {   
                // Remove node if it's last on the list
                // Get the second last node of the list and delete the Next node
                Node* currentNode = Head;
                while(currentNode->Next != nullptr && currentNode->Next->Next != nullptr)
                {
                    currentNode = currentNode->Next;
                }
                delete currentNode->Next;
                currentNode->Next = nullptr;
            }
            
            return true;
        }
        else{
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
    //cout << "Adding element: " << new_element << ". To list." << endl;

    Node* temp = new Node;
    if(empty())
    {
        temp->Element = new_element;
        temp->Next = nullptr;
        Head = temp;
        //cout << "Added to head: " << Head->Element << endl;

        return true;
    }
    temp->Element = new_element;
    temp->Next = Head;
    Head = temp;


    //cout << "Added to head: " << Head->Element << ". And pushed the rest down." << endl;

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
