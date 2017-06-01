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

// Selection sort routine. Sorts the first numKeys keys in keyList
// into ascending order.

{
	LE temp;     // Temporary storage used in swapping

	int minPt,   // Index of the smallest key in the remaining entries

		j, k;    // Loop counters



	for (j = 0; j < numKeys - 1; j++)

	{

		minPt = j;

		for (k = j + 1; k < numKeys; k++)

			if (keyList[k] < keyList[minPt])

				minPt = k;

		temp = keyList[j];

		keyList[j] = keyList[minPt];

		keyList[minPt] = temp;

	}

}

//--------------------------------------------------------------------

template < class LE >
void quickSort ( LE keyList [], int numKeys )

// Quicksort routine. Sorts the first numKeys keys in keyList into
// ascending order.

{
    quickPartition(keyList,numKeys,0,numKeys-1);
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

template < class LE >
void quickPartition ( LE keyList [], int numKeys,
                      int left, int right         )

// Recursive partner of the quickSort routine. Partitions the array
// entries between left and right into two subarrays. One subarray
// contains the keys that are less than or equal to splitValue, and
// the other contains the keys that are greater than splitValue.
// Recursively sorts each of these subarrays.

{
	LE pivot,   // "Mid" value to use in splitting

		temp;        // Temporary storage used in swapping

	int pivotLeft,      // Keys in [left..splitL-1] are <= splitValue

		pivotRight;      // Keys in [splitR+1..right] are > splitValue



	pivot = keyList[(left + right) / 2];



	pivotLeft = left;    // Start at left and move toward right

	pivotRight = right;   // Start at right and move toward left



	do

	{

		// Go right until key >= splitValue found.

		while (keyList[pivotLeft] < pivot) pivotLeft++;

		// Go left until key <= splitValue found.

		while (pivot < keyList[pivotRight]) pivotRight--;



		if (pivotLeft <= pivotRight)

		{

			temp = keyList[pivotLeft];   // Swap keys

			keyList[pivotLeft] = keyList[pivotRight];   // at limits

			keyList[pivotRight] = temp;

			pivotLeft++;                            // Continue

			pivotRight--;                            // partitioning

		}

	}

	while (pivotLeft <= pivotRight);



	// Sort each subarray.



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
//insert sort

{
	int i, j, temp;
	for (i = 1; i < numKeys; i++)
	{
		temp = keyList[(j = i)];
		while (--j >= 0 && temp < data[j])
			keyList[j + 1] = keyList[j];
		keyList[j + 1] = temp;

	}


}