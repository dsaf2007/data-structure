//--------------------------------------------------------------------
//
//  Laboratory 6                                        queueLnk.cpp
//
//  SOLUTION: Linked list implementation of the Queue ADT
//
//--------------------------------------------------------------------

#include <assert.h>
#include "queueLnk.h"

//--------------------------------------------------------------------

template < class QE >
QueueNode<QE>::QueueNode(const QE &elem, QueueNode<QE> *nextPtr)

// Creates a queue node containing element elem and next pointer
// nextPtr.

	: element(elem),
	next(nextPtr)
{}

//--------------------------------------------------------------------

template < class QE >
Queue<QE>::Queue(int ignored)

// Creates an empty queue. Parameter is provided for compatability
// with the array implementation and is ignored.

	: front(0),
	rear(0)
{}

//--------------------------------------------------------------------

template < class QE >
Queue<QE>:: ~Queue()

// Frees the memory used by a queue.
//clear()을 이용해  queue에 이용된 메모리를free한다.
{
	clear();
}

//--------------------------------------------------------------------

template < class QE >
void Queue<QE>::enqueue(const QE &newElement)

// Inserts newElement at the rear of a queue.
//queue의 rear에 새로운 값을 insert한다. linked queue이므로 full인지 확인하지 않는다.
{
	

		QueueNode<QE>* newNode;
		newNode = new QueueNode<QE>(newElement, rear);
		newNode->element = newElement;
		newNode->next = NULL;
		if (rear == NULL)//special case
		{
			front = newNode;
		}
		else
		{
			rear->next = newNode;
		}
			rear = newNode;
		
	

}

//--------------------------------------------------------------------

template < class QE >
QE Queue<QE>::dequeue()

// Removes the least recently (front) element from a queue and
// returns it.
//frunt에 있는 값을 삭제하고 그것을 return한다.

{
	QueueNode<QE>*temp;
	QE item;
	if (empty() == 0)
	{
		temp = front;
		item = front->element;
		front = front->next;
		if (front == NULL)//special case
			rear = NULL;
		delete temp;
		return item;
	}
	else return NULL;


}

//--------------------------------------------------------------------

template < class QE >
void Queue<QE>::clear()

// Removes all the elements from a queue.
//queue에 모든 원소를 삭제.
{
	QueueNode<QE>* temp;

	while (front != NULL)
	{
		temp = front;
		front = front->next;
		delete temp;
	}
	rear = NULL;

}


//--------------------------------------------------------------------

template < class QE >
int Queue<QE>::empty() const

// Returns 1 if a queue is empty. Otherwise, returns 0.
//queue가 비어있으면 1return
{
	return(front == NULL);

}

//--------------------------------------------------------------------

template < class QE >
void Queue<QE>::showStructure() const

// Linked list implementation. Outputs the elements in a queue. If
// the queue is empty, outputs "Empty queue". This operation is
// intended for testing and debugging purposes only.

{
	QueueNode<QE> *HH;
	HH = front;

	if (empty() == 1)
		cout << "Empty queue" << endl;
	else
	{
		for (HH = front; HH != NULL;HH=HH->next)
			cout << HH->element << "\t";
		
	}

}