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
template < class HE >
void Heap<HE>::reheapDown()
{
	//int child;
	//int tmp = element[hole].pty();

	//for (; hole * 2 <= size; hole = child) {
	//	child = hole * 2;
	//	if (child != size && element[child + 1].pty() <element[child].pty())
	//		child++;
	//	if (element[child].pty() < tmp)
	//		element[hole] = element[child];
	//	else
	//		break;
	//}//end for
	//element[hole].setPty(tmp);
	reheapDownsub(0, size-1);
}

template <class HE>
void Heap<HE>::reheapDownsub(int root, int  bottom)
{
	int maxChild, rightChild, leftChild,temp = 0;

	leftChild = 2 * root + 1;
	rightChild = 2 * root + 2;

	if (leftChild <= bottom)
		if(leftChild==bottom)
	{
		maxChild = leftChild;
	}
		else
		{
			if (element[leftChild].pty() <= element[rightChild].pty())
				maxChild = rightChild;
			else
				maxChild = leftChild;
		}
	if (element[root].pty() < element[maxChild].pty())
	{
		temp = element[root].pty();
		element[root].setPty(element[maxChild].pty());
		element[maxChild].setPty(temp);
		reheapDownsub(maxChild, bottom);
	}
}




//Insert element
template < class HE >
void Heap<HE>::insert(const HE &newElement)
{
	int temp = 0;
	if (size == maxSize - 1)
	{
		cout << "full";
	}
	else if (size == 0)
	{
		element[0] = newElement;
		size++;
	}
	else
	{
		element[size] = newElement;
		for (int i = size++; newElement.pty() > element[i / 2].pty(); i /= 2)
		{
			temp = element[i / 2].pty();
			element[i / 2] = newElement;
			element[i].setPty(temp);
		}
	}
}

//Remove max pty element
template < class HE >
HE Heap<HE>::removeMax()
{
	HE item;
	int temp,maxChild,rightChild,leftChild=0;
	if (empty() == 1)
		cout << "Empty, Cannot Remove!!!\n";
	else
	{
		/*element[0].setPty(element[size].pty());
		size--;
		reheapDown(size);
		return *element;*/
		item = element[0];
		element[0].setPty(element[size - 1].pty());
		size--;
		for (int j = 0; j < size  / 2; j++)
		{
			leftChild = 2 * j + 1;
			rightChild = 2 * j + 2;

			if (leftChild <= size)
				if (leftChild == size)
					maxChild = leftChild;
				else
				{
					if (element[leftChild].pty() <= element[rightChild].pty())
						maxChild = rightChild;
					else
						maxChild = leftChild;
				}

			for (int i = size; element[j].pty() < element[maxChild].pty(); i / 2)
			{
				temp = element[j].pty();
				element[j].setPty(element[maxChild].pty());
				element[j].setPty(temp);
			}

		}

		return item;
	}
}

//Clear heap
template < class HE >
void Heap<HE>::clear()
{
	for (int i = 0; i < maxSize - 1; i++)
		removeMax();
}

/* Heap status operations */

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
	if(size == defMaxHeapSize)
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
