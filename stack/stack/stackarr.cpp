//--------------------------------------------------------------------
//
//  Laboratory 5                                        stackarr.cpp
//
//  SOLUTION: Array implementation of the Stack ADT
//
//--------------------------------------------------------------------

#include <assert.h>
#include "stackarr.h"

//--------------------------------------------------------------------

template < class SE >
Stack<SE>::Stack(int maxNumber)
// Creates an empty stack. Allocates enough memory for maxNumber
// elements (defaults to defMaxStackSize).
//SE type�� �迭 element�� �����Ҵ��ϰ� ����NULL�� �ʱ�ȭ�Ѵ�.
: maxSize(maxNumber), top(-1)
{
	element = new SE[maxSize];

	//for (int i = 0; i < maxSize; i++)
	//{
	//	element[i] = NULL;
	//}
}

//--------------------------------------------------------------------

template < class SE >
Stack<SE>:: ~Stack()
// Frees the memory used by a stack.
//���� �Ҵ��� �޸𸮸� ����
{
	

	delete[] element;


}

//--------------------------------------------------------------------

template < class SE >
void Stack<SE>::push(const SE &newElement)
// Inserts newElement onto the top of a stack.
//ó�� top�� ��ġ�� -1�̹Ƿ� top+1�� �ڸ��� newElement�� �ְ� top+1�� ���ش�.
{
	if (full() != 1)
	{
		element[top + 1] = newElement;
		top++;
	}
	else std::cout << "stack is full" << std::endl;
}

//--------------------------------------------------------------------

template < class SE >
SE Stack<SE>::pop()
// Removes the topmost element from a stack and returns it.
{
	//element[top] = NULL;
	if (empty() != 1)
	{
		top--;
		return element[top+1];
		
	}
	else return NULL;
}

//--------------------------------------------------------------------

template < class SE >
void Stack<SE>::clear()
// Removes all the elements from a stack.
{
	//for (int i = 0; i < maxSize; i++)
	//{
	//	element[i] = NULL;
	//}
	top = -1;

}

//--------------------------------------------------------------------

template < class SE >
int Stack<SE>::empty() const
// Returns 1 if a stack is empty. Otherwise, returns 0.
{
	if (top == -1)return 1;
	else return 0;
}

//--------------------------------------------------------------------

template < class SE >
int Stack<SE>::full() const
// Returns 1 if a stack is full. Otherwise, returns 0.
{
	if (top == maxSize - 1) return 1;
	else return 0;
}

//--------------------------------------------------------------------

template < class SE >
void Stack<SE>::showStructure() const
// Array implementation. Outputs the elements in a stack. If the
// stack is empty, outputs "Empty stack". This operation is intended
// for testing and debugging purposes only.
{
	
	std::cout << "Size of stack:" << top + 1 << std::endl;
	std::cout << "current top position:" << top << std::endl;
	std::cout << "Show all datas in the stack" << std::endl;


	if (empty() == 1)
	{
		std::cout << "Empty stack" << std::endl;
	}
	else
	{
		for (int i = 0; i < top + 1; i++)
		{
			std::cout << "element [" << i << "] = " << element[i] << std::endl;
		}
	}







}