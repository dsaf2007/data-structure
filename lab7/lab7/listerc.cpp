
#include <assert.h>
#include "listrec.h"
#include "stacklnk.cpp"


template < class LE >
ListNode<LE>::ListNode(const LE &elem, ListNode<LE> *nextPtr)

//constructor

	: element(elem),
	next(nextPtr)
{}

//--------------------------------------------------------------------

template < class LE >
List<LE>::List(int ignored)



	: head(0),
	cursor(0)
{}

//--------------------------------------------------------------------

template < class LE >
List<LE>:: ~List()

//destructor

{
	clear();
}

//--------------------------------------------------------------------

template < class LE >
void List<LE>::insert(const LE &newElement)

// cusor ������ġ�� newElement ����

{
	if (head == 0)             // list�� ����� ���
	{
		head = new ListNode<LE>(newElement, 0);
		assert(head != 0);
		cursor = head;
	}
	else                         // �ƴѰ��
	{
		cursor->next = new ListNode<LE>(newElement, cursor->next);
		assert(cursor->next != 0);
		cursor = cursor->next;
	}
}

//--------------------------------------------------------------------

template < class LE >
void List<LE>::clear()

// list�� ��� �ڷ� ����

{
	ListNode<LE> *p,     
		*nextP;  
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

//list�� ����� ��� "Empty list" �ƴҰ�� structure�� �����ش�
{
	ListNode<LE> *p;   

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




template < class LE >
void List<LE>::write() const

// list�� element�� ����Ѵ�
{
	cout << "List : ";
	writeSub(head);
	cout << endl;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

template < class LE >
void List<LE>::writeSub(ListNode<LE> *p) const

// write�Լ��� ���ȣ���� ���� �Լ�.(c++�� Ư�� ������ ���� �Լ��� �д�)

{
	if (p != 0)
	{
		cout << p->element;   //element ���
		writeSub(p->next);  
	}
}

//--------------------------------------------------------------------

template < class LE >
void List<LE>::insertEnd(const LE &newElement)

// list�� ���� newElement�� ����

{
	insertEndSub(head, newElement);
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

template < class LE >
void List<LE>::insertEndSub(ListNode<LE> *&p,
	const LE &newElement)

	// insertEnd�� ��͸� ���� �Լ�. node�� p���� ����

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

// list�� �ſ��� �� �� ���� ��µǰ� �Ѵ�.

{
	cout << "Mirror : ";
	writeMirrorSub(head);
	cout << endl;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

template < class LE >
void List<LE>::writeMirrorSub(ListNode<LE> *p) const


{
	if (p != 0)
	{
		cout << p->element;        // ����
		writeMirrorSub(p->next);   // �������� �Ѿ��
		cout << p->element;        // ����
	}
}

//--------------------------------------------------------------------

template < class LE >
void List<LE>::reverse()

//list�� �����´�

{
	reverseSub(0, head);
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

template < class LE >
void List<LE>::reverseSub(ListNode<LE> *p, ListNode<LE> *nextP)

{
	if (nextP != 0)
	{
		reverseSub(nextP, nextP->next); 
		nextP->next = p;                 // Reverse link
	}
	else
		head = p;                        // list�� head�� �̵�
}

//--------------------------------------------------------------------

template < class LE >
void List<LE>::deleteEnd()

//list�� ���� ������ element�� �����

{
	deleteEndSub(head);
	cursor = head;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

template < class LE >
void List<LE>::deleteEndSub(ListNode<LE> *&p)


{
	if (p->next != 0)
		deleteEndSub(p->next);   // list�� ���������� ����
	else
	{
		delete p;                // elemnet����
		p = 0;                   // p to null
	}
}

//--------------------------------------------------------------------

template < class LE >
int List<LE>::length() const

// list�� ���� return

{
	return lengthSub(head);
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

template < class LE >
int List<LE>::lengthSub(ListNode<LE> *p) const


{
	int result;   
	if (p == 0) //list�� ���� �ٴٸ��� ������ result ++
		result = 0;                           
	else
		result = (lengthSub(p->next) + 1);  
	return result;
}



template <class LE>
void List<LE>::iterReverse()
//list�� reverse
{
	int length = this->length();//list�� ���̸� ��Ÿ���� ����

	LE *array = new LE[length];//list�� ���̿� ���� ũ���� �迭 array�� reverse����
	LE *reverse = new LE[length];
	ListNode<LE> *p;

	p = head;
	for (int i = 0; i < length; i++)//array�� list����
	{
		array[i] = p->element;
		p = p->next;
	}
	for (int i = 0; i < length; i++)//reverse�� list �� reverse�ؼ� ����
	{
		reverse[i] = array[length - i - 1];
	}

	p = head;
	for (int i = 0; i < length; i++)//list�� reverse�� ���ʴ�� ����
	{
		p->element = reverse[i];
		p = p->next;
	}

	delete[] array;
	delete[] reverse;

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
		stack.push(p->element);//list�� element�� stack �� pusch
		cout << p->element;//element���
		p = p->next;
	}

	
	while (stack.empty()!=1)
	{
		cout << stack.pop();//stack�� element�� pop
	}
	cout << endl;
}

