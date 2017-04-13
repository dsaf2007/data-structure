//--------------------------------------------------------------------
//
//  Laboratory 8                                         listdbl.cpp
//
//  SOLUTION: Circular, doubly linked list implementation of the
//            List ADT
//
//--------------------------------------------------------------------

#include <assert.h>
#include "ListDbl.h"

//--------------------------------------------------------------------

template < class LE >
ListNode<LE>::ListNode(const LE &elem, ListNode<LE> *priorPtr,
	ListNode<LE> *nextPtr)

	// Creates a list node containing element elem, next pointer nextPtr,
	// and prior pointer priorPtr.

	: element(elem),
	prior(priorPtr),
	next(nextPtr)
{}

//--------------------------------------------------------------------

template < class LE >
List<LE>::List(int ignored = 0)

// Creates an empty list.

	: head(0),
	cursor(0)
{}

//--------------------------------------------------------------------

template < class LE >
List<LE>:: ~List()

// Frees the memory used by a list.

{
	clear();
}

//--------------------------------------------------------------------

template < class LE >
void List<LE>::insert(const LE &newElement)

// Inserts newElement after the cursor. If the list is empty, then
// newElement is inserted as the first (and only) element in the list.
// In either case, moves the cursor to newElement.

{
	ListNode<LE> *p;    // Pointer to inserted node

	if (head == 0)             // Empty list
	{
		p = new ListNode<LE>(newElement, 0, 0);
		assert(p != 0);
		p->next = p;
		p->prior = p;
		head = p;
	}
	else                         // After cursor
	{
		p = new ListNode<LE>(newElement, cursor, cursor->next);
		assert(p != 0);
		cursor->next->prior = p;
		cursor->next = p;
	}
	cursor = p;
}

//--------------------------------------------------------------------

template < class LE >
void List<LE>::remove()

// Removes the element marked by the cursor from a list. Moves the
// cursor to the next element in the list. Assumes that the first list
// element "follows" the last list element.

{
	ListNode<LE> *p;   // Pointer to removed node
	p = cursor;
	if (empty() != 1)     // Requires that the list is not empty

	{
		if (head->next == head)   // Remove only element in list
		{
			head = 0;
			cursor = 0;
		}
		else
		{
			cursor->prior->next = cursor->next;
			cursor->next->prior = cursor->prior;
			if (head == cursor)
				head = cursor->next;
			cursor = cursor->prior;
		}
	}

	delete p;
}

//--------------------------------------------------------------------

template < class LE >
void List<LE>::replace(const LE &newElement)

// Replaces the element marked by the cursor with newElement and
// leaves the cursor at newElement.

{
	assert(head != 0);      //  Requires that the list is not empty
	cursor->element = newElement;
}

//--------------------------------------------------------------------

template < class LE >
void List<LE>::clear()

// Removes all the elements from a list.

{
	ListNode<LE> *p,       // Points to successive nodes
		*nextP;   // Points to next node

	if (head != 0)
	{
		p = head;
		do
		{
			nextP = p->next;
			delete p;
			p = nextP;
		} while (p != head);

		head = 0;
		cursor = 0;
	}
}

//--------------------------------------------------------------------

template < class LE >
void List<LE>::reverse()

// Removes all the elements from a list.

{
	ListNode<LE> *p,       // Points to successive nodes
		*tempP;  

	if (head != 0)
	{
		p = head; tempP=NULL;
		
		do
		{
			tempP = p->prior;
			p->prior= p->next;
			p->next= tempP;
			p = p->prior;
		} while (p != head);
		if(tempP !=NULL)
			head=tempP->prior;

		/*do
		{
			tempP = new ListNode<LE>(p->element, cursor, cursor->next);
			tempP=tempP->next;
			p = p->prior;
		} while (p != head);
		
		do
		{
			p->element = tempP->element;
			tempP = tempP->prior;
			p = p-> next;
		} while (tempP != head);

		head = 0;*/
		cursor = p;
	}
	
	delete tempP;
	delete p;


}

template < class LE >
int List<LE>::empty() const

// Returns 1 if a list is empty. Otherwise, returns 0.

{
	return (head == 0);
}

//--------------------------------------------------------------------

template < class LE >
int List<LE>::full() const

// Returns 1 if a list is full. Otherwise, returns 0. Cannot be
// done cleanly in generic C++ because there is sometimes overhead
// associated with a memory allocation.

{
	return 0;
}

//--------------------------------------------------------------------

template < class LE >
int List<LE>::gotoBeginning()

// If a list is not empty, then moves the cursor to the beginning of
// the list and returns 1. Otherwise, returns 0.

{
	int result;   // Result returned

	if (head != 0)
	{
		cursor = head;
		result = 1;
	}
	else
		result = 0;

	return result;
}

//--------------------------------------------------------------------

template < class LE >
int List<LE>::gotoEnd()

// If a list is not empty, then moves the cursor to the end of the
// list and returns 1. Otherwise, returns 0.

{
	int result;   // Result returned

	if (head != 0)
	{
		cursor = head->prior;
		result = 1;
	}
	else
		result = 0;

	return result;
}

//--------------------------------------------------------------------

template < class LE >
int List<LE>::gotoNext()

// If the cursor is not at the end of a list, then moves the
// cursor to the next element in the list and returns 1. Otherwise,
// returns 0.

{
	int result;   // Result returned

	if (cursor->next != head)
	{
		cursor = cursor->next;
		result = 1;
	}
	else
		result = 0;

	return result;
}

//--------------------------------------------------------------------

template < class LE >
int List<LE>::gotoPrior()

// If the cursor is not at the beginning of a list, then moves the
// cursor to the preceeding element in the list and returns 1.
// Otherwise, returns 0.

{
	ListNode<LE> *p;   // Pointer to prior node
	int result;        // Result returned

	if (cursor != head)
	{
		cursor = cursor->prior;
		result = 1;
	}
	else
		result = 0;

	return result;
}

//--------------------------------------------------------------------

template < class LE >
LE List<LE>::getCursor() const

// Returns the element marked by the cursor.

{
	assert(head != 0);      //  Requires that the list is not empty
	return cursor->element;
}

template < class LE >
int List<LE>::getPos()

// Returns the element marked by the cursor.

{
	ListNode<LE> *p;
	p = head;

	int position = 0;
	if (empty() != 1)
	{
		do
		{
			if (p == cursor)
				return ++position;
			else
			position++;
			p = p->next;
		} while (p != head);
		
	}
}
template < class LE >
int List<LE>::length()

// Returns the element marked by the cursor.

{
	ListNode<LE> *p;
	p = head;

	int position = 0;
	if (empty() != 1)
	{
		do
		{
			position++;
			p = p->next;
		} while (p != head);
		
	}
	return position;
}

//--------------------------------------------------------------------

template < class LE >
void List<LE>::showStructure() const

// Outputs the elements in a list. If the list is empty, outputs
// "Empty list". This operation is intended for testing and
// debugging purposes only.

{
	ListNode<LE> *p;   // Iterates through the list

	if (head == 0)
		cout << "Empty list" << endl;
	else
	{
		p = head;

	
		do
		{
			if (p == cursor)
				cout  << p->element << ":";
			else
				cout << p->element << ":";
			p = p->next;
		}while (p != head);
		cout<<endl;
		do
		{
			if (p == cursor)
				cout << "^";
			else
				cout<<"  ";
			p = p->next;
		} while (p != head);
		cout << endl;
	}
}
