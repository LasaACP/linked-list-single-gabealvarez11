#include "slist.h"
/*

Class Library File

*/

// Constructor
template <class T>
List<T>::List()
{
	Node x = new Node(0);
	head = x;
}

// Destructor
template <class T>
List<T>::~List()
{	
	setCurrent(getHead());
	
	Node* temp = getCurrent();
	
	while(temp->next != 0) // check for errors
	{
		temp = getCurrent();
		setCurrent(getCurrent()->pNext);
		delete temp;
	} 
}

// add(value)				//Adds a new value to the end of this list.
template <class T>
List<T>::add(T value)
{
	
}

// clear()					//Removes all elements from this list.

// equals(list)				//Returns true if the two lists contain the same elements in the same order.

//get(index)				//Returns the element at the specified index in this list.

//insert(index, value)		//Inserts the element into this list before the specified index.

//exchg(index1, index2)		//Switches the payload data of specified indexex.

// isEmpty()				//Returns true if this list contains no elements.

// remove(index)			//Removes the element at the specified index from this list.

// set(index, value)		//Replaces the element at the specified index in this list with a new value.

// size()					//Returns the number of elements in this list.

// subList(start, length)	//Returns a new list containing elements from a sub-range of this list.