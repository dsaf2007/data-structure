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

//��������
//�־��� ����Ʈ �߿� �ּڰ��� ã�´�.
//�� ���� �� �տ� ��ġ�� ���� ��ü�Ѵ�(�н�(pass)).
//�� ó�� ��ġ�� �� ������ ����Ʈ�� ���� ������� ��ü�Ѵ�.
//n^2�� time complexity�� ������.
{
	LE temp;     

	int minPt,   //�ּ� key�� index

		j, k;   



	for (j = 0; j < numKeys - 1; j++)

	{

		minPt = j;

		for (k = j + 1; k < numKeys; k++)

			if (keyList[k] < keyList[minPt])

				minPt = k;//�ּҰ� ã��

		temp = keyList[j];//�� ���� ��ġ�� ��ü

		keyList[j] = keyList[minPt];

		keyList[minPt] = temp;

	}

}

//--------------------------------------------------------------------

template < class LE >
void quickSort ( LE keyList [], int numKeys )

//�� ����
//��������� nlogn,�־��� ��� n^2�� timecomplexity�� ������.

{
    quickPartition(keyList,numKeys,0,numKeys-1);
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

template < class LE >
void quickPartition ( LE keyList [], int numKeys,
                      int left, int right         )

//�������� ����Լ�.
//����Ʈ ����� �ϳ��� ���Ҹ� ����.�̷��� �� ���Ҹ� �ǹ��̶�� �Ѵ�.
//�ǹ� �տ��� �ǹ����� ���� ���� ��� ���ҵ��� ����, �ǹ� �ڿ��� �ǹ����� ���� ū ��� ���ҵ��� ������ �ǹ��� �������� ����Ʈ�� �ѷ� ������.
//�̷��� ����Ʈ�� �ѷ� ������ ���� �����̶�� �Ѵ�.������ ��ģ �ڿ� �ǹ��� �� �̻� �������� �ʴ´�.
//���ҵ� �� ���� ���� ����Ʈ�� ���� ���(Recursion)������ �� ������ �ݺ��Ѵ�.��ʹ� ����Ʈ�� ũ�Ⱑ 0�̳� 1�� �� ������ �ݺ��ȴ�.

{
	LE pivot,   // �ǹ�

		temp;        

	int pivotLeft,      //  keyList[left..splitL-1]<=pivot 

		pivotRight;      // keyList[splitR+1..right] > pivot



	pivot = keyList[(left + right) / 2];



	pivotLeft = left;    // left���� �����ؼ� right�� �̵�

	pivotRight = right;   //right���� �����ؼ� left�� �̵�



	do

	{

		// keyList[pivotLeft]>=pivot�� ������ right��
		while (keyList[pivotLeft] < pivot) pivotLeft++;

		// keyList[pivotLeft]>=pivot�� ������ left��

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



	//��subarray ����



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
//insert sort ��������
//�ڷ� �迭�� ��� ��Ҹ� �տ������� ���ʴ�� �̹� ���ĵ� �迭 �κа� ���Ͽ�, �ڽ��� ��ġ�� ã�� ����
//�־��� ��� time complexity�� n^2�̴�.

{
	int i, j, temp;
	for (i = 1; i < numKeys; i++)
	{
		temp = keyList[(j = i)];
		while (--j >= 0 && temp < keyList[j])//���ĵ� �κб��� ��
			keyList[j + 1] = keyList[j];//j+1�� j�� key�� swap
		keyList[j + 1] = temp;

	}


}