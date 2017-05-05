
#include <assert.h>
#include "ListDbl.h"

//--------------------------------------------------------------------

template < class LE >
ListNode<LE>::ListNode(const LE &elem, ListNode<LE> *priorPtr,
	ListNode<LE> *nextPtr)

	// element,prior,next 의 포인터를 각각 생성한다.


	: element(elem),
	prior(priorPtr),
	next(nextPtr)
{}

//--------------------------------------------------------------------

template < class LE >
List<LE>::List(int ignored = 0)

// 빈 리스트 생성

	: head(0),
	cursor(0)
{}

//--------------------------------------------------------------------

template < class LE >
List<LE>:: ~List()


{
	clear();
}

//--------------------------------------------------------------------

template < class LE >
void List<LE>::insert(const LE &newElement)

// 커서 다음위치에 newElement를 넣는다. 빈 리스트의 경우 리스트의 첫부분에 넣는다. 양쪽 경우 모두
//내용 삽입 후에 newElement로 커서를 옮긴다.
{
	ListNode<LE> *p;    // Pointer to inserted node
	p = new ListNode<LE>(newElement, 0, 0);
	if (empty())             // Empty list
	{
		
		
		p->next = p;
		p->prior = p;
		head = p;
	}
	else if (cursor->next == 0)
	{
		cursor->next = p;
		p->prior = cursor;
	}
	else                         // After cursor
	{
		//p = new ListNode<LE>(newElement, cursor, cursor->next);
		p->prior = cursor;
		p->next = cursor->next;
		cursor->next->prior = p;
		cursor->next = p;
	}
	cursor = p;
}

//--------------------------------------------------------------------

template < class LE >
void List<LE>::remove()

//cursor에 있는 element를 삭제하고 cursor을 하나 이전으로 옮긴다.

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

//cursor위치의 자료를 newElement로 바꾼다.

{
	if(empty()!=1)      //  Requires that the list is not empty
	cursor->element = newElement;
}

//--------------------------------------------------------------------

template < class LE >
void List<LE>::clear()

// 자료를 모두 삭제

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

//구현 못함
{
	ListNode<LE> *p,       // Points to successive nodes
		*tempP;  

	
		p = head; tempP=NULL;
		
		while (p != NULL)
		{
			tempP = p->prior;
			p->prior = p->next;
			p->next = tempP;
			p = p->prior;
		}
		 
		if(tempP !=NULL)
			head=tempP->prior;


}

template < class LE >
int List<LE>::empty() const

// 빈 리스트인 경우 1return

{
	return (head == 0);
}

//--------------------------------------------------------------------

template < class LE >
int List<LE>::full() const

{
	return 0;
}

//--------------------------------------------------------------------

template < class LE >
int List<LE>::gotoBeginning()

// 빈 리스트가 아닌 경우 cursor을 맨 처음으로 옮긴다

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

// 빈 리스트가 아닌 경우 cursor을 마지막으로 옮긴다

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

//cursor가 리스트의 마지막에 있는 것이 아닌경우 다음 위치로 cursor을 옮긴다.
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

//cursor가 리스트의 처음에 있는 것이 아닌경우 이전 위치로 cursor을 옮긴다.

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

// cursor가 가리키는 자료를 출력한다.

{
	assert(head != 0);      //  Requires that the list is not empty
	return cursor->element;
}

template < class LE >
int List<LE>::getPos()

//cursor의 위치를 출력한다

{
	ListNode<LE> *p;
	p = head;

	int position = 0;
	if (empty() != 1)
	{
		do//list의 처음부터 cursor의 위치까지 반복문을 돌려 ++해주면서 cursor의 위치를 구함
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

// 리스트의 길이를 출력한다./

{
	ListNode<LE> *p;
	p = head;

	int position = 0;
	if (empty() != 1)//list의 처음부터 끝까지 반복을 하면서 ++하여 총 길이 구함
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
