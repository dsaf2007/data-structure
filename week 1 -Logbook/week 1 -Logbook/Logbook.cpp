// Logbook.cpp: implementation of the Logbook class.
//
//////////////////////////////////////////////////////////////////////

#include "Logbook.h"
#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;


//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

Logbook::Logbook()
{
	setCurrentTime();			 
	initEntry();				 
}

Logbook::~Logbook()
{

}

Logbook::Logbook(int month, int year)
{
	setCurrentTime();		

	// Implementation here

 
	initEntry();			 
}

void Logbook::putEntry(int day, int value)
{
	// Implementation here
}

int Logbook::getEntry(int day) const
{
	// Implementation here
}

int Logbook::getMonth() const
{
	// Implementation here
}

int Logbook::getYear() const
{
	// Implementation here
}

int Logbook::getDaysInMonth() const	
{
	// Implementation here
}

int Logbook::isLeapYear(int year) const
{
	if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))
		return 1;		// Leap year
	else
		return 0;		// Normal years
}


void Logbook::putEntry(int value)		 
{
	entries[(currentTime->tm_mday - 1)] = value;
}

void Logbook::setCurrentTime()
{	
	// tm structure Used by asctime, gmtime, localtime, mktime, 
	// and strftime to store and retrieve time information.  

	// tm은 구조체로 시간 정보를 저장하고 불러오기 위해 asctime, gmtime, localtime, mktime,
	// 그리고 strftime 에 의해서 사용됩니다.

	time_t		now;
	time(&now);
	currentTime = localtime(&now);		

	logYear = currentTime->tm_year + 1900;
	logMonth = currentTime->tm_mon + 1;
}

void Logbook::initEntry()
{
	int iDays = getDaysInMonth();
	for (int i = 0; i < iDays; i++)
		entries[i] = 0;
}


void Logbook::displayCalendar() const
{
	int szScreen = 80;

	printf("%35d / %d\n\n", getMonth(), getYear());

	for (int i = 0; i < 7; i++)
	{
		printf("%4c %-6s", ' ', NameOfDay[i]);
	}
	cout << endl;

	int posDay = getDayOfWeek(1);			
	int lastDays = getDaysInMonth();		

	for (int m = 0; m < posDay; m++)		
	{
		printf("%11c", ' ');
	}

	printf("%4c%2d %-3d ", ' ', 1, entries[0]);	

	for (int j = 1; j < lastDays; j++)			
	{
		if ((++posDay) < 7)						
		{
			printf("%4c%2d %-3d ", ' ', j + 1, entries[j]);
		}
		else
		{
			cout << endl;
			posDay = 0;
			printf("%4c%2d %-3d ", ' ', j + 1, entries[j]);
		}
	}
	cout << endl;
}

int Logbook::getDayOfWeek(int day) const
{
	tm		when;
	time_t	result;

	when = *currentTime;
	when.tm_mday = day;

	if ((result = mktime(&when)) != (time_t)-1)
	{
		// Implementation here	
	}
	else
	{
		// Implementation here
	}
}
