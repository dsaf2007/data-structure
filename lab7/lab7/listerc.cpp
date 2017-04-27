
#include <assert.h>
#include "listrec.h"
#include "stacklnk.cpp"

//--------------------------------------------------------------------
//
// Insert your singly linked list implementations (from Laboratory 7)
// of the following functions:
//
//   - The ListNode class constructor
//
//   - The List class constructor, destructor, insert(), clear(), and
//     showstructure() functions.
//
//--------------------------------------------------------------------
template < class LE >
ListNode<LE>::ListNode(const LE &elem, ListNode<LE> *nextPtr)

// Creates a list node containing element elem and next pointer
// nextPtr.

	: element(elem),
	next(nextPtr)
{}

//--------------------------------------------------------------------

template < class LE >
List<LE>::List(int ignored)

// Creates an empty list. The argument is included for compatibility
// with the array implementation and is ignored.

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
	if (head == 0)             // Empty list
	{
		head = new ListNode<LE>(newElement, 0);
		assert(head != 0);
		cursor = head;
	}
	else                         // After cursor
	{
		cursor->next = new ListNode<LE>(newElement, cursor->next);
		assert(cursor->next != 0);
		cursor = cursor->next;
	}
}

//--------------------------------------------------------------------

template < class LE >
void List<LE>::clear()

// Removes all the elements from a list.

{
	ListNode<LE> *p,      // Points to successive nodes
		*nextP;  // Points to next node
	p = head;
	while (p != 0)
	{
		nextP = p->next;
		delete p;
		p = nextP;
	}

	head = 0;
	cursor = 0;
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
		for (p = head; p != 0; p = p->next)
			if (p == cursor)
				cout<< p->element<<" ";
			else
				cout << p->element<<" ";
		cout << endl;
	}
}



//--------------------------------------------------------------------
//
// Recursively implemented linked list functions used in the Prelab
// Exercise
//
//--------------------------------------------------------------------

template < class LE >
void List<LE>::write() const

// Outputs the elements in a list from beginning to end. Assumes that
// objects of type LE can be output to the cout stream.

{
	cout << "List : ";
	writeSub(head);
	cout << endl;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

template < class LE >
void List<LE>::writeSub(ListNode<LE> *p) const

// Recursive partner of the write() function. Processes the sublist
// that begins with the node pointed to by p.

{
	if (p != 0)
	{
		cout << p->element;   // Output element
		writeSub(p->next);    // Continue with next node
	}
}

//--------------------------------------------------------------------

template < class LE >
void List<LE>::insertEnd(const LE &newElement)

// Inserts newElement at the end of a list. Moves the cursor to
// newElement.

{
	insertEndSub(head, newElement);
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

template < class LE >
void List<LE>::insertEndSub(ListNode<LE> *&p,
	const LE &newElement)

	// Recursive partner of the insertEnd() function. Processes the
	// sublist that begins with the node pointed to by p.

{
	if (p != 0)
		return insertEndSub(p->next, newElement);    // Continue searching for
	else                                    // end of list
	{
		return insert(newElement);   // Insert new node
	}
}

//--------------------------------------------------------------------

template < class LE >
void List<LE>::writeMirror() const

// Outputs the elements in a list from beginning to end and back
// again. Assumes that objects of type LE can be output to the cout
// stream.

{
	cout << "Mirror : ";
	writeMirrorSub(head);
	cout << endl;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

template < class LE >
void List<LE>::writeMirrorSub(ListNode<LE> *p) const

// Recursive partner of the writeMirror() function. Processes the
// sublist that begins with the node pointed to by p.

{
	if (p != 0)
	{
		cout << p->element;        // Output element (forward)
		writeMirrorSub(p->next);   // Continue with next node
		cout << p->element;        // Output element (backward)
	}
}

//--------------------------------------------------------------------

template < class LE >
void List<LE>::reverse()

// Reverses the order of the elements in a list.

{
	reverseSub(0, head);
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

template < class LE >
void List<LE>::reverseSub(ListNode<LE> *p, ListNode<LE> *nextP)

// Recursive partner of the reverse() function. Processes the sublist
// that begins with the node pointed to by nextP.

{
	if (nextP != 0)
	{
		reverseSub(nextP, nextP->next);   // Continue with next node
		nextP->next = p;                 // Reverse link
	}
	else
		head = p;                        // Move head to end of list
}

//--------------------------------------------------------------------

template < class LE >
void List<LE>::deleteEnd()

// Deletes the element at the end of a list. Moves the cursor to the
// beginning of the list.

{
	deleteEndSub(head);
	cursor = head;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

template < class LE >
void List<LE>::deleteEndSub(ListNode<LE> *&p)

// Recursive partner of the deleteEnd() function. Processes the
// sublist that begins with the node pointed to by p.

{
	if (p->next != 0)
		deleteEndSub(p->next);   // Continue looking for the last node
	else
	{
		delete p;                // Delete node
		p = 0;                   // Set p (link or head) to null
	}
}

//--------------------------------------------------------------------

template < class LE >
int List<LE>::length() const

// Returns the number of elements in a list.

{
	return lengthSub(head);
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

template < class LE >
int List<LE>::lengthSub(ListNode<LE> *p) const

// Recursive partner of the length() function. Processes the sublist
// that begins with the node pointed to by p.

{
	int result;   // Result returned

	if (p == 0)
		result = 0;                            // End of list reached
	else
		result = (lengthSub(p->next) + 1);   // Number of nodes after
											 // this one + 1
	return result;
}

//--------------------------------------------------------------------
//
// "Unknown" operations used in the Bridge Exercise
//
//--------------------------------------------------------------------

template < class LE >
void List<LE>::unknown1() const

// Unknown function 1.

{
	unknown1Sub(head);
	cout << endl;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

template < class LE >
void List<LE>::unknown1Sub(ListNode<LE> *p) const

// Recursive partner of the unknown1() function.

{
	if (p != 0)
	{
		cout << p->element;
		if (p->next != 0)
		{
			unknown1Sub(p->next->next);
			cout << p->next->element;
		}
	}
}

//--------------------------------------------------------------------

template < class LE >
void List<LE>::unknown2()

// Unknown function 2.

{
	unknown2Sub(head);
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

template < class LE >
void List<LE>::unknown2Sub(ListNode<LE> *&p)

// Recursive partner of the unknown2() function.

{
	ListNode<LE> *q;

	if (p != 0 && p->next != 0)
	{
		q = p;
		p = p->next;
		q->next = p->next;
		p->next = q;
		unknown2Sub(q->next);
	}
}
template <class LE>
void List<LE>::iterReverse()
{
	int length = this->length();

	LE *array = new LE[length];
	LE *reverse = new LE[length];
	ListNode<LE> *p;

	p = head;
	for (int i = 0; i < length; i++)
	{
		array[i] = p->element;
		p = p->next;
	}
	for (int i = 0; i < length; i++)
	{
		reverse[i] = array[length - i - 1];
	}

	p = head;
	for (int i = 0; i < length; i++)
	{
		p->element = reverse[i];
		p = p->next;
	}

}


template <class LE>
void List<LE>::stackWriteMirror() const
{
	Stack<LE> stack;
	ListNode<LE>*p;

	p = head;
	cout << "Mirror : ";
	
	
	while (p != 0)
	{
		stack.push(p->element);
		cout << p->element;
		p = p->next;
	}

	
	while (stack.empty()!=1)
	{
		cout << stack.pop();
	}
	cout << endl;
}

