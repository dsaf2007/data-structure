//--------------------------------------------------------------------
//
//  Laboratory 15, In-lab Exercise 2                        sort.cpp
//
//  Implementation of a set of sorting routines
//
//--------------------------------------------------------------------
using namespace std;
template < class LE >
void selectionSort ( LE keyList [], int numKeys )

//선택정렬
//주어진 리스트 중에 최솟값을 찾는다.
//그 값을 맨 앞에 위치한 값과 교체한다(패스(pass)).
//맨 처음 위치를 뺀 나머지 리스트를 같은 방법으로 교체한다.
//n^2의 time complexity를 가진다.
{
	LE temp;     

	int minPt,   //최소 key의 index

		j, k;   



	for (j = 0; j < numKeys - 1; j++)

	{

		minPt = j;

		for (k = j + 1; k < numKeys; k++)

			if (keyList[k] < keyList[minPt])

				minPt = k;//최소값 찾기

		temp = keyList[j];//맨 앞의 위치와 교체

		keyList[j] = keyList[minPt];

		keyList[minPt] = temp;

	}

}

//--------------------------------------------------------------------

template < class LE >
void quickSort ( LE keyList [], int numKeys )

//퀵 정렬
//평균적으로 nlogn,최악의 경우 n^2의 timecomplexity를 가진다.

{
    quickPartition(keyList,numKeys,0,numKeys-1);
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

template < class LE >
void quickPartition ( LE keyList [], int numKeys,
                      int left, int right         )

//퀵정렬의 재귀함수.
//리스트 가운데서 하나의 원소를 고른다.이렇게 고른 원소를 피벗이라고 한다.
//피벗 앞에는 피벗보다 값이 작은 모든 원소들이 오고, 피벗 뒤에는 피벗보다 값이 큰 모든 원소들이 오도록 피벗을 기준으로 리스트를 둘로 나눈다.
//이렇게 리스트를 둘로 나누는 것을 분할이라고 한다.분할을 마친 뒤에 피벗은 더 이상 움직이지 않는다.
//분할된 두 개의 작은 리스트에 대해 재귀(Recursion)적으로 이 과정을 반복한다.재귀는 리스트의 크기가 0이나 1이 될 때까지 반복된다.

{
	LE pivot,   // 피벗

		temp;        

	int pivotLeft,      //  keyList[left..splitL-1]<=pivot 

		pivotRight;      // keyList[splitR+1..right] > pivot



	pivot = keyList[(left + right) / 2];



	pivotLeft = left;    // left에서 시작해서 right로 이동

	pivotRight = right;   //right에서 시작해서 left로 이동



	do

	{

		// keyList[pivotLeft]>=pivot일 때까지 right로
		while (keyList[pivotLeft] < pivot) pivotLeft++;

		// keyList[pivotLeft]>=pivot일 때까지 left로

		while (pivot < keyList[pivotRight]) pivotRight--;



		if (pivotLeft <= pivotRight)

		{

			temp = keyList[pivotLeft];   

			keyList[pivotLeft] = keyList[pivotRight];   

			keyList[pivotRight] = temp;

			pivotLeft++;                            // Continue

			pivotRight--;                            // partitioning

		}

	}

	while (pivotLeft <= pivotRight);



	//각subarray 정렬



	if (left < pivotRight)

		quickPartition(keyList, numKeys, left, pivotRight);

	if (pivotLeft < right)

		quickPartition(keyList, numKeys, pivotLeft, right);

}

//--------------------------------------------------------------------

template < class LE >
void unknownSort ( LE keyList [], int numKeys )

// Unknown sort routine. Sorts the first numKeys keys in keyList into
// ascending order.
//insert sort 삽입정렬
//자료 배열의 모든 요소를 앞에서부터 차례대로 이미 정렬된 배열 부분과 비교하여, 자신의 위치를 찾아 삽입
//최악의 경우 time complexity는 n^2이다.

{
	int i, j, temp;
	for (i = 1; i < numKeys; i++)
	{
		temp = keyList[(j = i)];
		while (--j >= 0 && temp < keyList[j])//정렬된 부분까지 비교
			keyList[j + 1] = keyList[j];//j+1과 j의 key를 swap
		keyList[j + 1] = temp;

	}


}