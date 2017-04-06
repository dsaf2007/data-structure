//--------------------------------------------------------------------
//
//  Laboratory 6                                        queueArr.cpp
//
//  SOLUTION: Array implementation of the Queue ADT
//
//--------------------------------------------------------------------

#include <assert.h>
#include "queuearr.h"

//--------------------------------------------------------------------

template < class QE >
Queue<QE>::Queue(int maxNumber)

// Creates an empty queue. Allocates enough memory for maxNumber
// elements (defaults to defMaxQueueSize).

: maxSize(maxNumber),
front(-1),
rear(-1)
{
	element = new QE[maxSize];
}

//--------------------------------------------------------------------

template < class QE >
Queue<QE>:: ~Queue()

// Frees the memory used by a queue.

{
	delete[] element;
}

//--------------------------------------------------------------------

template < class QE >
void Queue<QE>::enqueue(const QE &newElement)

// Inserts newElement at the rear of a queue.

{
	
	if (full() !=1 )
	{
		
		element[(rear+1)%maxSize] = newElement;
		rear++;
		
	}
	else
	{
		std::cout << "queue is full" << std::endl;
	}


}

//--------------------------------------------------------------------

template < class QE >
QE Queue<QE>::dequeue()

// Removes the least recently added (front) element from a queue and
// returns it.

{

	QE temp;
	if (empty() != 1)
	{
		
		temp= element[(front+1)%maxSize];
		element[(front + 1) % maxSize] = NULL;
		front++;
		return temp;
	}
	else
	{
		std::cout << "queue is empty" << std::endl;
		return NULL;
	}



}

//--------------------------------------------------------------------

template < class QE >
void Queue<QE>::clear()

// Removes all the elements from a queue.

{
	front = -1;
	rear = -1;

}

//--------------------------------------------------------------------

template < class QE >
int Queue<QE>::empty() const

// Returns 1 if a queue is empty. Otherwise, returns 0.

{
	if (front == -1 && rear == -1)
	{
		return 1;
	}
	else return 0;
}

//--------------------------------------------------------------------

template < class QE >
int Queue<QE>::full() const

// Returns 1 if a queue is full. Otherwise, returns 0.

{
	return ((rear + 2) % maxSize == (front+1)%maxSize);
}

//--------------------------------------------------------------------

template < class QE >
void Queue<QE>::showStructure() const

// Array implementation. Outputs the elements in a queue. If the
// queue is empty, outputs "Empty queue". This operation is intended
// for testing and debugging purposes only.

{
	int j;   // Loop counter

	if (empty()==1)
		cout << "Empty queue" << endl;
	else
	{
		cout << "front = " << front << "  rear = " << rear%maxSize << endl;
		for (j = 0; j < maxSize; j++)
			cout << j << "\t";
		cout << endl;

		for (j = 0; j < maxSize;j++)
		{
			cout << element[j] << "\t";
			
		}
		cout << endl;

	}
}
