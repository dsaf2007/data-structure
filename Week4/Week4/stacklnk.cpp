//--------------------------------------------------------------------
//
//  Laboratory 5                                        stacklnk.cpp
//
//  SOLUTION: Linked list implementation of the Stack ADT
//
//--------------------------------------------------------------------

#include <assert.h>
// #include <alloc.h>
#include "stacklnk.h"

//--------------------------------------------------------------------

template < class SE >
StackNode<SE>::StackNode(const SE &elem, StackNode<SE> *nextPtr)
// Creates a stack node containing element elem and next pointer
// nextPtr.
: element(elem),
next(nextPtr)
{

}

//--------------------------------------------------------------------

template < class SE >
Stack<SE>::Stack(int ignored)
// Creates an empty stack. The parameter is provided for compatability
// with the array implementation and is ignored.
: top(0)
{

}

//--------------------------------------------------------------------

template < class SE >
Stack<SE>:: ~Stack()
// Frees the memory used by a stack.
{
	clear();
}

//--------------------------------------------------------------------

template < class SE >
void Stack<SE>::push(const SE &newElement)
// Inserts newElement onto the top of a stack.
{
	StackNode<SE> *SJ;
	SJ = top;
	if (full()==0)//Inserts newElement when the stack is not full
	{
		StackNode<SE>* location;
		location = new StackNode<SE>(newElement, top);
		location->element = newElement;
		location->next = top;
		top = location;
	}
	else std::cout << "stack is full" << std::endl;//print stack is full when the stack is full.
	
}

//--------------------------------------------------------------------

template < class SE >
SE Stack<SE>::pop()
// Removes the topmost element from a stack and returns it.
{
	SE item;
	StackNode<SE>* tempPtr;
	if (top != 0)//top�� 0�ϰ��, �� stack�� ������� ���� ��쿡 pop�� �Ѵ�. empty()�� �̿��Ͽ��� �ȴ�.
	{
		item = top->element;
		tempPtr = top;
		top = top->next;
		delete tempPtr;
		return item;
	
	}
	else//stack�� ������� ��� stack�� ��� pop�� �Ұ����ϴٰ� �˸�.
	{
		std::cout << "cannot pop becasue stack is empty" << std::endl;
		return NULL;
	}

	

}

//--------------------------------------------------------------------

template < class SE >
void Stack<SE>::clear()
// Removes all the elements from a stack.
{
	
	StackNode<SE>* tempPtr;

	while (top != NULL)//top�� NULL�� �ƴҰ�쿡 tempPtr�� top�� �Է��ϰ� top�� next�� �ű������ tempPtr�� �����Ͽ� ���������� stack�� ���� ��� ����
	{
		tempPtr = top;
		top = top->next;
		delete tempPtr;
	}

}

//--------------------------------------------------------------------

template < class SE >
int Stack<SE>::empty() const
// Returns 1 if a stack is empty. Otherwise, returns 0.
//stack�� ������� ��� 1return �ƴҰ�� 0return
{
	return (top == NULL);
}

//--------------------------------------------------------------------

template < class SE >
int Stack<SE>::full() const
// Returns 1 if a stack is full. Otherwise, returns 0. Cannot be
// done cleanly in generic C++ because there is sometimes overhead
// associated with a memory allocation.
{

	StackNode<SE> *SJ;
	SJ = top;
	if (SJ == 0) return 0;//top �� 0�ΰ��� stack�� ������� ��쵵 �����Ƿ� ù �������� �޾Ƴ��� 0�� return�Ѵ�.
	else if(SJ->element==NULL)return 1;//stack�� �� ���� �Է��� �ϸ� ���ο�top�� �Ҵ��� ������ �� �ȿ� ���� �Է��� �� ���⶧���� element�� NULL�� ��쿡 �� �� ������ �����Ѵ�.
	else return 0;
}

//--------------------------------------------------------------------

template < class SE >
void Stack<SE>::showStructure() const
// Linked list implementation. Outputs the elements in a stack. If
// the stack is empty, outputs "Empty stack". This operation is
// intended for testing and debugging purposes only.
{
	StackNode<SE> *SJ;

	

	if (top == 0)
		std::cout << "Empty Stack" << std::endl;
	else
	{

		for (SJ = top; SJ != 0; SJ = SJ->next)
			std::cout << SJ->element << ":";
	}


}
