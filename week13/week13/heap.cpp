#include "heap.h"

//Constructor
template < class HE >
Heap<HE>::Heap(int maxNumber = defMaxHeapSize)
{
	element = new HE[defMaxHeapSize];
	size = 0;
	maxSize = defMaxHeapSize;

}

//Destructor
template < class HE >
Heap<HE>::~Heap()
{
	delete[] element;
}





//newElement삽입.
//삽입시에 가장 큰 수가 root에 오도록 한다.
template < class HE >
void Heap<HE>::insert(const HE &newElement)
{
	int temp = 0;// swap을 위한 변수
	if (full()==1)// heqp이 full일 경우insert불가
	{
		cout << "full";
	}
	else if (size == 0) //heap size가 0일 때 root에 insert
	{
		element[0] = newElement;
		size++;
	}
	else
	{
		element[size] = newElement;
		for (int i = size++; newElement.pty() > element[i / 2].pty(); i /= 2)//newElement가 root보다 클 경우 root와 swap.
		{
			temp = element[i / 2].pty();
			element[i / 2] = newElement;
			element[i].setPty(temp);
		}
	}
}

//maxElement(root)를 제거 하고 return한다
template < class HE >
HE Heap<HE>::removeMax()
{
	HE item,temp;
//	int temp=0;
	if (empty() == 1)// heap가 empty일 경우 작동하지 않는다.
		cout << "Empty, Cannot Remove!!!\n";
	else
	{
	
		item = element[0];//rooot저장
	
		temp = element[size - 1];//rightmost child저장

		bool stop = 0;//insertion point found
		int j = 1;//array index
		while(j<size&&!stop)
		{
			if (j < size - 1 && element[j].pty() < element[j + 1].pty())//j의 element보다 j+1의 element가 클경우 j++
				j++;
			if (temp.pty() >= element[j].pty())//rigthmost child가 가장 클경우 stop==1(loop탈출)
				stop = 1;
			else//index를 child로 옮긴다.
			{
				element[(j - 1) / 2] = element[j];
				j = 2 * j + 1;
			}
		}
		element[(j - 1) / 2] = temp;
		size--;
		return item;
	}
}

//Clear heap
template < class HE >
void Heap<HE>::clear()
{
	
	size = 0;
}

//Heap is empty
template < class HE >
int Heap<HE>::empty() const
{
	if (size == 0)
		return 1;
	else return 0;
	
}

//Heap is full
template < class HE >
int Heap<HE>::full() const
{
	if(size == defMaxHeapSize-1)
		return 1;
	else return 0;
		
}

// Output in level order

//showStructure Function
template < class HE >
void Heap<HE>::showStructure() const

// Outputs the priorities of the elements in a heap in both array
// and tree form. If the heap is empty, outputs "Empty heap". This
// operation is intended for testing/debugging purposes only.

{
	int j;   // Loop counter

	cout << endl;
	if (empty()==1)
		cout << "Empty heap" << endl;
	else
	{
		cout << "size = " << size << endl;       // Output array form
		for (j = 0; j < size; j++)
			cout << j << "\t";
		cout << endl;
		for (j = 0; j < size; j++)
			cout << element[j].pty() << "\t";
		cout << endl << endl;
		showSubtree(0, 0);                        // Output tree form
	}
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

template < class HE >
void Heap<HE>::showSubtree(int index, int level) const

// Recursive partner of the showStructure() function. Outputs the
// subtree (subheap) whose root is stored in element[index]. Argument
// level is the level of this element within the tree.

{
	int j;   // Loop counter

	if (index < size)
	{
		showSubtree(2 * index + 2, level + 1);        // Output right subtree
		for (j = 0; j < level; j++)        // Tab over to level
			cout << "\t";
		cout << " " << element[index].pty();   // Output element's pty
		if (2 * index + 2 < size)                // Output "connector"
			cout << "<";
		else if (2 * index + 1 < size)
			cout << "\\";
		cout << endl;
		showSubtree(2 * index + 1, level + 1);        // Output left subtree
	}
}
