#include "slist.h"
/*

Class Library File

*/

// Constructor
template <class T>
List<T>::List()
{
	Node* x = new Node(0);
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
		setCurrent(getCurrent()->next);
		delete temp;
	} 
}

// add(value)				//Adds a new value to the end of this list.
template <class T>
void List<T>::add(T value)
{
	Node* newData = new Node(value);
	while(getCurrent()->next != 0)
	{
		setCurrent(getCurrent()->next);
	}
	
	getCurrent()->next = newData;
}

// clear()					//Removes all elements from this list.
template <class T>
void List<T>::clear()
{
	setCurrent(getHead());
	
	Node* temp = getCurrent();
	
	while(temp->next != 0) // check for errors
	{
		temp = getCurrent();
		setCurrent(getCurrent()->next);
		delete temp;
	}
}

// equals(list)				//Returns true if the two lists contain the same elements in the same order.
template <class T>
boolean List<T>::equals(List* list)
{
	if(getHead()->data = list.getHead()->data)
		return true;
	else
		return false;
}

//get(index)				//Returns the element at the specified index in this list.
template <class T>
Node* List<T>::get(int index)
{
	Node* current = getHead();
	for(int i = 0; i < index; i++)
	{
		current = current->next;
	}
	return current;
}

//insert(index, value)		//Inserts the element into this list before the specified index.
template <class T>
void List<T>::insert(int index, T value)
{
	Node* previous = get(index - 1);
	Node* following = get(index);
	Node* addition = new Node(x);
	previous->next = addition;
	addition->next = following;
}

//exchg(index1, index2)		//Switches the payload data of specified indexex.
template <class T>
void List<T>::exchg(int index1, int index2)
{
	T data1 = get(index1);
	T data2 = get(index2);
	
	remove(index1);
	insert(index1, data2);
	remove(index2);
	insert(index2, data1);
}

// isEmpty()				//Returns true if this list contains no elements.
template <class T>
boolean List<T>::isEmpty()
{
	if(getHead()->data != NULL)
		return false;
	else
		return true;
}

// remove(index)			//Removes the element at the specified index from this list.
template <class T>
void List<T>::remove(int index)
{
	Node* previous = get(index - 1);
	Node* following = get(index);
	previous->next = following;
}

// set(index, value)		//Replaces the element at the specified index in this list with a new value.
template <class T>
void List<T>::set(int index, T value)
{
	get(index)->data = value;
}

// size()					//Returns the number of elements in this list.
template <class T>
int List<T>::size()
{
	int count = 0;
	Node* current = getHead();
	while(current->next != NULL)
	{
		current = current->next;
		count++;
	}
	return count;
}

// subList(start, length)	//Returns a new list containing elements from a sub-range of this list.
template <class T>
List* List<T>::subList(int start, int length)
{
	int count = 0;
	setHead(get(start))
	Node* current = getHead();
	for(int i = 0; i < length; i++)
	{
		current = current->next;
	}
	current->next = NULL;
}

int main()
{
	List<int> x;
}