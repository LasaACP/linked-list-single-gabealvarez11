/*

Header file for single linked list class library

*/

#ifndef LIST_H
#define SLIST_H

//single linked list
template <class T>
class List {
	struct Node {	
		T data;
		Node* next;
		
		Node(T x, Node* y = 0)
		{
			data = x;
			next = y;
		}
	};
	
	Node* head;
	Node* current;
	
	public:
		List();
		
		~List(); 
		
		Node* getHead() { return head; }
		void setHead(Node* x) { head = x; }
		Node* getCurrent() { return current; }
		void setCurrent(Node * x) { current = x; }
		
		add(T value);			//Adds a new value to the end of this list.

		clear();					//Removes all elements from this list.

		equals(List list);				//Returns true if the two lists contain the same elements in the same order.

		get(int index);				//Returns the element at the specified index in this list.

		insert(int index, T value);		//Inserts the element into this list before the specified index.

		exchg(int index1, int index2);		//Switches the payload data of specified indexex.

		isEmpty();				//Returns true if this list contains no elements.

		remove(int index);			//Removes the element at the specified index from this list.

		set(int index, T value);		//Replaces the element at the specified index in this list with a new value.

		size();					//Returns the number of elements in this list.

		subList(int start, int length);	//Returns a new list containing elements from a sub-range of this list.
};

#endif