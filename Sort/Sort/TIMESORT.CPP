//--------------------------------------------------------------------
//
//  Laboratory 15, In-lab Exercise 2                    timesort.cpp
//
//  Timing program for a set of sorting routines
//
//--------------------------------------------------------------------

// Computes the length of time that it takes to execute a given
// sorting routine on an array containing numKeys integers.

#include <iostream>
#include <stdlib.h>     // For exit()
#include "timer.h"
#include "sort.cpp"

//--------------------------------------------------------------------

const int numRepetitions = 10;   // Number of times to repeat each
                                 //   sort -- several repetitions
                                 //   may be needed in order to
                                 //   produce a meaningful timing

//--------------------------------------------------------------------

void main ()
{
    Timer copyTimer,      // Timer for array copy
          sortTimer;      // Timer for sorting routine

    int *masterKeyList,   // Master array of integer keys
        *keyList,         // Array of integer keys to be sorted
        numKeys,          // Number of array entries
        j, k;             // Loop counters

    double timeForCopy,   // Time to copy array numRepetitions times
           timePerSort;   // Time to sort array once

    // Get the number of keys.

    cout << endl << "Enter the number of keys : ";
    cin >> numKeys;

    // Allocate both arrays of keys.

    masterKeyList = new int [numKeys];
    keyList       = new int [numKeys];
    if ( masterKeyList == 0  ||  keyList == 0 )
    {
       cout << "Cannot allocate enough memory for that many keys"
            << endl;
       exit(1);
    }

    // Initialize the master array of keys.

    for ( j = 0 ; j < numKeys ; j++ )
        masterKeyList[j] = rand();

    // Compute the time it takes to create numRepetitions copies of
    // masterKeyList.

    copyTimer.start();
    for ( j = 0 ; j < numRepetitions ; j++ )
        for ( k = 0 ; k < numKeys ; k++ )
            keyList[k] = masterKeyList[k];
    copyTimer.stop();
    timeForCopy = copyTimer.elapsedTime();

    // Output header

    cout << endl;
    cout << "     Sort          Time per sort (secs.)" << endl;
    cout << "--------------    -----------------------" << endl;

    // Selection sort --
    // Time numRepetitions calls to the selectionSort routine.

    sortTimer.start();
    for ( j = 0 ; j < numRepetitions ; j++ )
    {
        for ( k = 0 ; k < numKeys ; k++ )    // Copy keys
            keyList[k] = masterKeyList[k];
        selectionSort(keyList,numKeys);      // Sort key list
    }
    sortTimer.stop();

    timePerSort =
           ( sortTimer.elapsedTime() - timeForCopy ) / numRepetitions;

    cout << "selectionSort           " << timePerSort << endl;

    // QuickSort --
    // Time numRepetitions calls to the quickSort routine.

    sortTimer.start();
    for ( j = 0 ; j < numRepetitions ; j++ )
    {
        for ( k = 0 ; k < numKeys ; k++ )    // Copy keys
            keyList[k] = masterKeyList[k];
        quickSort(keyList,numKeys);          // Sort key list
    }
    sortTimer.stop();

    timePerSort =
           ( sortTimer.elapsedTime() - timeForCopy ) / numRepetitions;

    cout << "quickSort               " << timePerSort << endl;

    // Unknown sort --
    // Time numRepetitions calls to the unknownSort routine.

    sortTimer.start();
    for ( j = 0 ; j < numRepetitions ; j++ )
    {
        for ( k = 0 ; k < numKeys ; k++ )    // Copy keys
            keyList[k] = masterKeyList[k];
        unknownSort(keyList,numKeys);        // Sort key list
    }
    sortTimer.stop();

    timePerSort =
           ( sortTimer.elapsedTime() - timeForCopy ) / numRepetitions;

    cout << "unknownSort             " << timePerSort << endl;
}