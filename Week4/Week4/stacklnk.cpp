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
	if (top != 0)//top이 0일경우, 즉 stack이 비어있지 않을 경우에 pop을 한다. empty()를 이용하여도 된다.
	{
		item = top->element;
		tempPtr = top;
		top = top->next;
		delete tempPtr;
		return item;
	
	}
	else//stack이 비어있을 경우 stack이 비어 pop이 불가능하다고 알림.
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

	while (top != NULL)//top이 NULL이 아닐경우에 tempPtr에 top을 입력하고 top을 next로 옮긴다음에 tempPtr을 삭제하여 순차적으로 stack의 값을 모두 삭제
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
//stack이 비어있을 경우 1return 아닐경우 0return
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
	if (SJ == 0) return 0;//top 이 0인경우는 stack이 비어있을 경우도 있으므로 첫 조건으로 달아놓고 0을 return한다.
	else if(SJ->element==NULL)return 1;//stack이 꽉 차고 입력을 하면 새로운top은 할당이 되지만 그 안에 값을 입력할 수 없기때문에 element가 NULL일 경우에 꽉 찬 것으로 간주한다.
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
