
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

// cusor 다음위치에 newElement 삽입

{
	if (head == 0)             // list가 비었을 경우
	{
		head = new ListNode<LE>(newElement, 0);
		assert(head != 0);
		cursor = head;
	}
	else                         // 아닌경우
	{
		cursor->next = new ListNode<LE>(newElement, cursor->next);
		assert(cursor->next != 0);
		cursor = cursor->next;
	}
}

//--------------------------------------------------------------------

template < class LE >
void List<LE>::clear()

// list의 모든 자료 제거

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

//list가 비었을 경우 "Empty list" 아닐경우 structure을 보여준다
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

// list의 element를 출력한다
{
	cout << "List : ";
	writeSub(head);
	cout << endl;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

template < class LE >
void List<LE>::writeSub(ListNode<LE> *p) const

// write함수의 재귀호출을 위한 함수.(c++의 특성 때문에 따로 함수를 둔다)

{
	if (p != 0)
	{
		cout << p->element;   //element 출력
		writeSub(p->next);  
	}
}

//--------------------------------------------------------------------

template < class LE >
void List<LE>::insertEnd(const LE &newElement)

// list의 끝에 newElement를 삽입

{
	insertEndSub(head, newElement);
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

template < class LE >
void List<LE>::insertEndSub(ListNode<LE> *&p,
	const LE &newElement)

	// insertEnd의 재귀를 위한 함수. node가 p에서 시작

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

// list에 거울을 댄 것 같이 출력되게 한다.

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
		cout << p->element;        // 전행
		writeMirrorSub(p->next);   // 다음노드로 넘어간다
		cout << p->element;        // 후행
	}
}

//--------------------------------------------------------------------

template < class LE >
void List<LE>::reverse()

//list를 뒤집는다

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
		head = p;                        // list의 head로 이동
}

//--------------------------------------------------------------------

template < class LE >
void List<LE>::deleteEnd()

//list의 가장 마지막 element를 지운다

{
	deleteEndSub(head);
	cursor = head;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

template < class LE >
void List<LE>::deleteEndSub(ListNode<LE> *&p)


{
	if (p->next != 0)
		deleteEndSub(p->next);   // list의 마지막까지 진행
	else
	{
		delete p;                // elemnet삭제
		p = 0;                   // p to null
	}
}

//--------------------------------------------------------------------

template < class LE >
int List<LE>::length() const

// list의 길이 return

{
	return lengthSub(head);
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

template < class LE >
int List<LE>::lengthSub(ListNode<LE> *p) const


{
	int result;   
	if (p == 0) //list의 끝에 다다르기 전까지 result ++
		result = 0;                           
	else
		result = (lengthSub(p->next) + 1);  
	return result;
}



template <class LE>
void List<LE>::iterReverse()
//list를 reverse
{
	int length = this->length();//list의 길이를 나타내는 변수

	LE *array = new LE[length];//list의 길이와 같은 크기의 배열 array와 reverse선언
	LE *reverse = new LE[length];
	ListNode<LE> *p;

	p = head;
	for (int i = 0; i < length; i++)//array에 list저장
	{
		array[i] = p->element;
		p = p->next;
	}
	for (int i = 0; i < length; i++)//reverse에 list 를 reverse해서 저장
	{
		reverse[i] = array[length - i - 1];
	}

	p = head;
	for (int i = 0; i < length; i++)//list에 reverse를 차례대로 저장
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
		stack.push(p->element);//list의 element를 stack 에 pusch
		cout << p->element;//element출력
		p = p->next;
	}

	
	while (stack.empty()!=1)
	{
		cout << stack.pop();//stack의 element를 pop
	}
	cout << endl;
}

