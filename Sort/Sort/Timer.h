//--------------------------------------------------------------------
//
//  Laboratory 15                                            timer.h
//
//  Class declaration for the Timer ADT
//
//--------------------------------------------------------------------

#include <time.h>

class Timer
{
public:

	// Create a timer
	Timer();

	// Start and stop the timer
	void    start();
	void    stop();

	// Compute the elapsed time (in clock ticks)
	clock_t elapsedTime() const;

private:

	clock_t startTime,   // Time that the timer was started
		stopTime;    // Time that the timer was stopped
};