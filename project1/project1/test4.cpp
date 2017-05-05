//--------------------------------------------------------------------
//
//				                                          test4.cpp
//
//  Test program for the operations in the List ADT
//
//--------------------------------------------------------------------

#include <iostream>
#include "listarr.h"
#include <fstream>



using namespace std;

void main()
{
	List testList(8);		  // Test list
	char testElement;         // List element
	int n;                    // Position within list
	char cmd;                 // Input command
//	string filename;
	
	do
	{
		cout << endl << "Commands:" << endl;
		cout << "  R  : read the name of a file" << endl;
		cout << "  +  : add a new entry" << endl;
		cout << "  -  : remove an entry"<< endl;
		cout << "  W  : write to a file" << endl;
		cout << "  M  : select a month" << endl;
		cout << "  Q  : Quit the test program" << endl;
		cout << endl;


	/*	testList.showStructure();      */               // Output list

		cout << endl << "Command: ";                  // Read command
		cin >> cmd;
		if (cmd == 'R' ||cmd== 'r')
		{
			/*cout << "Enter the name of the File:";
			getline(cin, filename);
			filename = filename + ".txt";*/
		}
		//else if (cmd == '+' || cmd == '=' || cmd == '?')
		//	cin >> testElement;
		//else if (cmd == 'M' || cmd == 'm')
		//	cin >> n;

		switch (cmd)
		{
		case 'R':case 'r':
			testList.read();
			
			cout << "Number of birthdays is" << endl;
			testList.checkMonth();
			break;
		case '+':                                  // insert
			testList.insert();
			//cout << testList.list[3][3] << endl;
			
			break;

		case '-':                                  // remove
			testList.remove();
			
		/*	cout << testList.list[1][0] << endl;
			cout << testList.list[1][1] << endl;
			cout << testList.list[1][2] << endl;
			cout << testList.list[1][3] << endl;*/
			break;

		case 'M':case 'm':                                    // replace
			cout << "Select a Month: ";
			testList.printMonth();
			break;

		case 'W':case 'w':                                  // getCursor
			cout << "Enter the name of the file:";
				testList.write();

			break;

		case 'Q': case 'q':                   // Quit test program
			break;

		default:                               // Invalid command
			cout << "Inactive or invalid command" << endl;
		}
	} while (cmd != 'Q'  &&  cmd != 'q');
}