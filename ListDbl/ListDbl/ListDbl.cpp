
#include <assert.h>
#include "ListDbl.h"

//--------------------------------------------------------------------

template < class LE >
ListNode<LE>::ListNode(const LE &elem, ListNode<LE> *priorPtr,
	ListNode<LE> *nextPtr)

	// element,prior,next �� �����͸� ���� �����Ѵ�.


	: element(elem),
	prior(priorPtr),
	next(nextPtr)
{}

//--------------------------------------------------------------------

template < class LE >
List<LE>::List(int ignored = 0)

// �� ����Ʈ ����

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

// Ŀ�� ������ġ�� newElement�� �ִ´�. �� ����Ʈ�� ��� ����Ʈ�� ù�κп� �ִ´�. ���� ��� ���
//���� ���� �Ŀ� newElement�� Ŀ���� �ű��.
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

//cursor�� �ִ� element�� �����ϰ� cursor�� �ϳ� �������� �ű��.

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

//cursor��ġ�� �ڷḦ newElement�� �ٲ۴�.

{
	if(empty()!=1)      //  Requires that the list is not empty
	cursor->element = newElement;
}

//--------------------------------------------------------------------

template < class LE >
void List<LE>::clear()

// �ڷḦ ��� ����

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

//���� ����
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

// �� ����Ʈ�� ��� 1return

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

// �� ����Ʈ�� �ƴ� ��� cursor�� �� ó������ �ű��

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

// �� ����Ʈ�� �ƴ� ��� cursor�� ���������� �ű��

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

//cursor�� ����Ʈ�� �������� �ִ� ���� �ƴѰ�� ���� ��ġ�� cursor�� �ű��.
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

//cursor�� ����Ʈ�� ó���� �ִ� ���� �ƴѰ�� ���� ��ġ�� cursor�� �ű��.

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

// cursor�� ����Ű�� �ڷḦ ����Ѵ�.

{
	assert(head != 0);      //  Requires that the list is not empty
	return cursor->element;
}

template < class LE >
int List<LE>::getPos()

//cursor�� ��ġ�� ����Ѵ�

{
	ListNode<LE> *p;
	p = head;

	int position = 0;
	if (empty() != 1)
	{
		do//list�� ó������ cursor�� ��ġ���� �ݺ����� ���� ++���ָ鼭 cursor�� ��ġ�� ����
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

// ����Ʈ�� ���̸� ����Ѵ�./

{
	ListNode<LE> *p;
	p = head;

	int position = 0;
	if (empty() != 1)//list�� ó������ ������ �ݺ��� �ϸ鼭 ++�Ͽ� �� ���� ����
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
