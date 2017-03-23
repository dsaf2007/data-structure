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
//SE type의 배열 element를 동적할당하고 값을NULL로 초기화한다.
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
//동적 할당한 메모리를 삭제
{
	

	delete[] element;


}

//--------------------------------------------------------------------

template < class SE >
void Stack<SE>::push(const SE &newElement)
// Inserts newElement onto the top of a stack.
//처음 top의 위치가 -1이므로 top+1의 자리에 newElement를 넣고 top+1을 해준다.
//stack이 가득차지 않았을 경우에만
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
//stack이 비어있지 않으면 top위치의 값을 return하고 아니면 NULL return
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
//top을-1로 옮겨 실제로 값을 지우지는 않지만 모두 clear된 것 처럼 출력한다.
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
//stack이 비어있으면 1을 return하고 아니면 0return;
{
	if (top == -1)return 1;
	else return 0;
}

//--------------------------------------------------------------------

template < class SE >
int Stack<SE>::full() const
// Returns 1 if a stack is full. Otherwise, returns 0.
//stack이 가득 차 있을 경우 1을 return하고 아닌경우 0return
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


	if (empty() == 1)//stack이 비어있는 경우 Empty stack을 출력
	{
		std::cout << "Empty stack" << std::endl;
	}
	else // 아닌경우에 stack의 값을 차례대로 출력.
	{
		for (int i = 0; i < top + 1; i++)
		{
			std::cout << "element [" << i << "] = " << element[i] << std::endl;
		}
	}







}