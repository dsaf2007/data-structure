//--------------------------------------------------------------------
//
//  Laboratory 15                                          timer.cpp
//
//  SOLUTION: Implementation of the Timer ADT
//
//--------------------------------------------------------------------

#include <time.h>
#include <iostream>
#include "Timer.h"

//--------------------------------------------------------------------

Timer::Timer()

// Initializes the timer.

{
	startTime = 0;
	stopTime = 0;
}

//--------------------------------------------------------------------

void Timer::start()

// Starts the timer.

{
	startTime = clock();
}

//--------------------------------------------------------------------

void Timer::stop()

// Stops the timer.

{
	stopTime = clock();
}

//--------------------------------------------------------------------

clock_t Timer::elapsedTime() const

// Computes the length of the time interval from startTime to
// stopTime (in clock ticks).

{
	return  stopTime - startTime;
}