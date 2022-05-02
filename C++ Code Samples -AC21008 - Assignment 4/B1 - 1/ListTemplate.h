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
    //Check if head is null
    //if head is NULL the list is empty
    if(Head==NULL)
    {
        return true;
    }
    //if it is not NULL the list is not empty
    else
    {
        return false;
    }
}

// Delete

template <class Type> 
bool List <Type> :: remove(const Type& del_element)
{
    //If list is empty close the function straight away
    //as there is nothing to delete
    if (empty())
    {
        return false;
    }

    //If list is not empty continue with the function
    else
    {
        //Create tempporary variables to store 
        //the current node while looping through the list
        //and the previous one
        Node* tempPrevious = new Node;
        Node* tempCurrent = new Node;

        //set the temporary node at the head of the list to loop through the whole of it 
        tempCurrent = Head;

        //Check node by node untill the needed node is found
        while ((tempCurrent->Element != del_element) && (tempCurrent->Next != nullptr)){

            //Keep track of the node just checked in case the needed one is not found
            tempPrevious = tempCurrent;
            //Move to next node
            tempCurrent = tempCurrent->Next;
        }
        //When node is found check if it correspond to the given parameter
        if(tempCurrent->Element == del_element){
            //If it does then change the previous node to the 
            //next of the found node
            //in this way the found node is "skipped" in the list and basically it is removed
            tempPrevious->Next=tempCurrent->Next;

            //return true after all function is finished
            return true;
        }
        //if the node does not correspond to the given value then return false and close the function
        else
        {
            return false;
        }
    }
}

// Search

template <class Type>
bool List<Type>::search(Type& search_element){

    //If list is empty close the function as there is nothing to search
    if (empty()){
        return false;
    }
    //If not empty then continue with the fucntion
    else
    {   
        //Declare a temporary variable to loop through the List
        Node* temp = Head;

        //Loop thought each item untill the needed one if found
        while ((temp->Element != search_element) && (temp->Next != nullptr)){
            //If the needed node is not found then check next one
            temp = temp->Next;
        }
        //When the needed node is found
        //check if it correspond to the given value
        //if it does then return true
        if(temp->Element == search_element)
        {
            search_element = temp->Element;
            return true;
        }
        //If it does not match then return false
        else
        {
            return false;
        }
    }
}

// Insert (simple insert at beginning)

template <class Type> 
bool List <Type> :: insert(const Type& new_element)
{

    //Create a new variable where to store the new Node ot insert in the List
    Node* newElement = new Node;
    //Set parameter of the newly created Noed
    newElement->Element = new_element;
    //Set the node's next to point at the start of the List
    newElement->Next=Head;
    //Set the head of the list to be equal to the new Node
    Head=newElement;

    //Check whether or not the insertion was successful
    //checking if the head of the list is equal to the new Node
    if(Head->Element == new_element)
    {
        //True if it is
        return true;
    }
    else
    {
        //False if it is not
        return false;
    }

}

//Output overload function
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
