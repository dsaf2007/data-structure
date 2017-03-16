//--------------------------------------------------------------------
//
//                                                       listarr.cpp
//
//  SOLUTION: Array implementation of the List ADT
//
//--------------------------------------------------------------------


#include "listarr.h"
#include "algorithm"

using namespace std;

//--------------------------------------------------------------------

List::List(int maxNumber)

// Creates an empty list. Allocates enough memory for maxNumber
// data items (defaults to defMaxListSize).

: maxSize(maxNumber),
size(0),
cursor(-1)
//
{
	dataItems = new char[maxSize];
	for (int i = 0; i < maxSize; i++)
	{
		dataItems[i] = NULL;
	}
}

//--------------------------------------------------------------------

List:: ~List()

// Frees the memory used by a list.

{
	delete[] dataItems;
}

//--------------------------------------------------------------------

void List::insert(const DataType &newDataItem)
throw (logic_error)

// Inserts newDataItem after the cursor. If the list is empty, then
// newDataItem is inserted as the first (and only) data items in the
// list. In either case, moves the cursor to newDataItem.

{
	if (cursor == -1)
	{
		dataItems[0]=newDataItem;
		cursor = 0;

	}
	else
	{
		
		dataItems[cursor+1] = newDataItem;
		cursor++;
	}





}

//--------------------------------------------------------------------

void List::remove() throw (logic_error)

// Removes the data items  marked by the cursor from a list. Moves the
// cursor to the next data item item in the list. Assumes that the
// first list data items "follows" the last list data item.

{
	/*for (int i = 0; i < maxSize; i++)
	{
		if (dataItems[i] != NULL)
		{
			size++;
		}
	}
	dataItems[cursor] = NULL;
	for (int i=cursor; i <size; i++)
	{
		dataItems[i] = dataItems[i + 1];
	}
	for (int i = size; i < maxSize; i++)
	{
		dataItems[i] = NULL;
	}*/
	dataItems[cursor] = NULL;
	if(cursor==maxSize-1)
	{ 
		cursor = 0;
	}
	else
	{
		cursor++;
	}

	


}

//--------------------------------------------------------------------

void List::replace(const DataType &newDataItem)
throw (logic_error)

// Replaces the item marked by the cursor with newDataItem and
// leaves the cursor at newDataItem.

{
	// Requires that the list is not empty
	dataItems[cursor] = newDataItem;


}

//--------------------------------------------------------------------

void List::clear()

// Removes all the data items from a list.

{
	for (int i = 0; i < maxSize; i++)
	{
		dataItems[i] = NULL;
	}
	cursor = -1;
}

//--------------------------------------------------------------------

bool List::isEmpty() const

// Returns 1 if a list is empty. Otherwise, returns 0.

{
	for (int i = 0; i < maxSize; i++)
	{
		if (dataItems[i] == NULL)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
}

//--------------------------------------------------------------------

bool List::isFull() const

// Returns 1 if a list is full. Otherwise, returns 0.

{

	for (int i = 0; i < maxSize; i++)
	{
		if (dataItems[maxSize-1] == NULL)
		{
			return 0;
		}
		else
		{
			return 1;
		}
	}
}

//--------------------------------------------------------------------
 
int List::gotoBeginning() throw (logic_error)

// Moves the cursor to the beginning of the list.

{
	// pre-lab

	return cursor = 0;

}



//--------------------------------------------------------------------

int List::gotoEnd() throw (logic_error)

// Moves the cursor to the end of the list.

{
	// pre-lab




	return cursor = maxSize-1;


}

//--------------------------------------------------------------------

bool List::gotoNext() throw (logic_error)

// If the cursor is not at the end of a list, then moves the
// cursor to the next item in the list and returns true. Otherwise,
// returns false.

{
	if (cursor != maxSize-1)
	{
		cursor++;
		return true;
	}
	else
	{
		return false;
	}




}

//--------------------------------------------------------------------

bool List::gotoPrior() throw (logic_error)

// If the cursor is not at the beginning of a list, then moves the
// cursor to the preceeding item in the list and returns true.
// Otherwise, returns false.

{
	
	if (cursor != -1)
	{
		cursor--;
		return true;
	}
	else
	{
		return false;
	}

	


}

//--------------------------------------------------------------------

DataType List::getCursor() const throw (logic_error)

// Returns the item marked by the cursor.

{
	// pre-lab


	return dataItems[cursor];
}

//--------------------------------------------------------------------

void List::showStructure() const

// Outputs the data items in a list. If the list is empty, outputs
// "Empty list". This operation is intended for testing/debugging
// purposes only.

{
	
	int size = 0;
	for (int i = 0; i < maxSize; i++)
	{
		if (dataItems[i] != NULL)
		{
			size++;
		}
	}
	sort(dataItems, dataItems + size);
	cout << "size of List:" << size << endl;
	cout << "current location of cursor" << cursor << endl;
	cout << "---Outputs All data items in a list---" << endl;
	int a = 0;
	for (int i = 0; i < maxSize; i++)
	{
		
		if (dataItems[i] != NULL)
		{
			cout << a << "-data:" << dataItems[i] << endl; a++;
		}
	}
}
 