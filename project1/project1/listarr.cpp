//--------------------------------------------------------------------
//
//                                                       listarr.cpp
//
//  SOLUTION: Array implementation of the List ADT
//
//--------------------------------------------------------------------


#include "listarr.h"
#include "algorithm"
#include <fstream>
#include <string>


using namespace std;

//--------------------------------------------------------------------jxxx

List::List(int maxNumber)

//생성자

{
	//list에 NULL을 넣어 초기화
	for (int i = 0; i < 100; i++)
		for(int j=0;j<100;j++)
	{
			list[i][j] = NULL;
	}
}

//--------------------------------------------------------------------

List:: ~List()

// Frees the memory used by a list.

{

}

//--------------------------------------------------------------------

void List::readtemp()
//temp.txt를 읽어온다.
//읽어온 후 list배열에 자료를 채우고 각 월별 생일인 사람의 수를 측정한다.
{
	ifstream inFile("temp.txt");
	char input[100][100];
	for (int j = 0; j<100; j++)
		for (int i = 0; i < 100; i++)
		{
			input[j][i] = NULL;
			month[i] = NULL;
		}
	int s = 0;
	while (!inFile.eof())//파일이 끝날때까지 루프
	{

		inFile.getline(input[s], 100);
		s++;
	}s = s / 4;//배열의 index수를 맞추기위해 이용. 한 entry당 공백 포함 4개의 줄을 가지므로 4로 나눠준다.
	char arr[2];
	for (int k = 0; k<s; k++)
		for (int j = 0; j <4; j++)
		{
			list[k][j] = input[k * 4 + j];
		}
	
		
		for (int k = 0; k < 12; k++)
		{
			month[k] = 0;
		}
		char num[10] = { 0,1,2,3,4,5,6,7,8,9 };
		for (int k = 0; k < i; k++)// list[k][2]가 entry에 등록된 생일이고 그중 list[k][2][0]과list[k][2][1]이 생일을 나타내는 두자리수이므로 이를 비교.
		{
			if (list[k][2][0] == '0')//십의자리수가 0일때 1의자리수가 일치하면 month[k]++
			{
				if (list[k][2][1] == '1')
				{
					month[0]=month[0]+1;
				
				}
				else if (list[k][2][1]=='2')
					month[1]++;
				else if (list[k][2][1] =='3')
					month[2]++;
				else if (list[k][2][1] == '4')
					month[3]++;
				else if (list[k][2][1] == '5')
					month[4]++;
				else if (list[k][2][1] =='6')
					month[5]++;
				else if (list[k][2][1] =='7')
					month[6]++;
				else if (list[k][2][1] == '8')
					month[7]++;
				else if (list[k][2][1] == '9')
					month[8]++;
			}
			else//십의자리수가 1일때 1의자리수가 일치하면 month[k]++
			{
				if (list[k][2][1] == '0')
					month[9]++;
				else if (list[k][2][1] == '1')
					month[10]++;
				else if (list[k][2][1] == '2')
					month[11]++;
			}
		}
	
		
	inFile.close();
	i = s;//클래스 내에 index를 나타낼 i=s를 해준다
}
void List::read()throw (logic_error)
//파일명을 입력받아 그 파일을 불러온다.(txt파일만)
{

	string filename;//불러올 파일명
	cout << "Enter the name of the File:";
	cin >> filename;
	filename = filename + ".txt";
	

	std::ifstream inFile(filename);
	char input[100][100];
	for (int j = 0; j<100; j++)
		for (int i = 0; i < 100; i++)
		{
			input[j][i] = NULL;
		}
	int i = 0;
	while (!inFile.eof())
	{

		inFile.getline(input[i], 100);
		i++;
	}i = i / 4;
	
	for (int k = 0; k<i; k++)
		for (int j = 0; j <4; j++)
		{
			list[k][j] = input[k * 4 + j];
		}

	inFile.close();
	//불러들여 list에 저장한후, list를 temp.txt.에 붙여쓴다. 
	ofstream outFile("temp.txt");
	for (int k = 0; k < i; k++)
		for (int j = 0; j <4; j++)
		{
			outFile << list[k][j] << endl;
		}
	cout << "Total Number of Entries is the list:" << i << endl<<endl;
	checkMonth();
}
void List::write()throw (logic_error)
//파일을 쓴다.(txt형식)
{
	readtemp();
	string filename;
	//생성할 파일명
	cin >> filename;
	cout << "The list is Written into " << filename << endl;
	filename = filename + ".txt";
	ofstream outFile(filename);
	for (int k = 0; k < i; k++)
		for (int j = 0; j <4; j++)
		{
			outFile << list[k][j] << endl;
		}

}
void List::insert()
throw (logic_error)
//temp.txt를 불러오고 자료를 추가한다.
{
	//
	readtemp();
	char a[3][100];
	
	cout << "Add an entry:" << endl;

	cin.getline(a[0], 100);
	cout << "Name :";
	 cin.getline(a[0], 100);
	
	 list[i][0] = a[0];//list가 NULL로 초기화 되어있기 때문에 i인덱스에 자료를 기입하면 된다.

	cout << "Phone :"; cin.getline(a[1], 100);

	list[i][1] = a[1];

	cout << "Birthday :"; cin.getline(a[2], 100);

	list[i][2] = a[2];

	list[i][3] = "\n";
	i++;//기입을 마친후 i++


	ofstream outFile("temp.txt");//list를 temp.txt에 덮어쓴다.
	for (int k = 0; k < i; k++)
		for (int j = 0; j <4; j++)
	{
			outFile << list[k][j] << endl;
	}
	cout << "Total Number of Entries is the list:" << i << endl<<endl;
	checkMonth();
}

//--------------------------------------------------------------------

void List::remove() throw (logic_error)
//temp.txt를 불러와 그 안의 자료를 삭제


{
	readtemp();

	cout << "remove an entry:" << endl;
	char a[100];
	cin.getline(a, 100);//이름을 입력받는다
	cout << "Name :"; cin.getline(a, 100);
	int check = 0;//입력받은 사람이 존재하는지 확인할 변수
	for (int k = 0; k < i; k++)
	{
		if (strcmp(list[k][0], a) == 0)//strcmp를 이용하여 이름이 list[k][0]즉 저장된 이름과 일치하면 list[k]를 초기화 한다.
		{
			check++;
			for (int j = 0; j < 4; j++)
			{
				list[k][j] = NULL;
			}
			for(int s=k;s<i-1;s++)//list[k]뒤의 자료들의 index를 -1하여 한칸씩 앞당긴다.
				for (int j = 0; j < 4; j++)
				{
					list[s][j] = list[s + 1][j];
				}
			for (int j = 0; j < 4; j++)
			{
				list[i][j] = NULL;
			}
			i--; break;//총 자료수가 -1되었으므로 index를 나타내는 i도 --해준다.
		}
	}
	if (check == 0)
	{
		cout << a << " is not in the entry";
	}
	ofstream outFile("temp.txt");//temp.txt list를 출력
	for (int k = 0; k < i; k++)
		for (int j = 0; j <4; j++)
		{
			outFile << list[k][j] << endl;
		}
	cout << endl;
	cout << "Total Number of Entries is the list:" << i << endl << endl;
	checkMonth();
}

//--------------------------------------------------------------------


void List::checkMonth()throw (logic_error)
//각 월별 생일자가 몇명인지 확인하는 함수

{
	
	readtemp();
	
	if (month[0] != 0)// readtemp에서 센 월별 생일자 수가 0이 아닐경우 그 배열을 나타내는 월과 숫자를 출력
	{cout << "\tJanuary: " << month[0] << endl << endl;
	}
	if (month[1] != 0)
		cout << "\tFebuary: " << month[1] << endl << endl;
	if (month[2] != 0)
		cout << "\tMarch: " << month[2] << endl << endl;
	if (month[3] != 0)
		cout << "\tApril: " << month[3] << endl << endl;
	if (month[4] != 0)
		cout << "\tMay: " << month[4] << endl << endl;
	if (month[5] != 0)
		cout << "\tJune: " << month[5] << endl << endl;
	if (month[6] != 0)
		cout << "\tJuly: " << month[6] << endl << endl;
	if (month[7] != 0)
		cout << "\tAugust: " << month[7] << endl << endl;
	if (month[8] != 0)
		cout << "\tSeptember: " << month[8] << endl << endl;
	if (month[9] != 0)
		cout << "\tOctober: " << month[9] << endl << endl;
	if (month[10] != 0)
		cout << "\tNovember: " << month[10] << endl << endl;
	if (month[11] != 0)
		cout << "\tDecember: " << month[11] << endl << endl;
	

}
void List::printMonth()throw (logic_error)
//월이름을 입력받고 그 월에 생일인 사람의 수와 생일인 사람의 entry를 출력
{
	string birthdayArray[12] = { "January", "Febuary", "March", "April", "May", "June", "July", "August",
		"September", "October", "November", "December" };// 입력받은 월과 비교할 월명
	string monthdata;//입력받을 월

	readtemp();
	cin >> monthdata;
	
	if (birthdayArray[0] == monthdata)//입력받은 이름이 일치할경우
	{
		if (month[0] == 0)
			cout << "No person born in " << monthdata << endl;
		else
		{
			cout << "Totla number of birthdays in January: " << month[0] << endl;//월 이름과 생일인사람 숫자를 출력
			for (int k = 0; k < i; k++)// entry상에서 생일이 일치하는 사람의 entry를 전체 출력
			{
				if (list[k][2][0] == '0')
					if (list[k][2][1] == '1')
					{
						for (int s = 0; s < 4; s++)
							cout << list[k][s] << endl;
					}
			}
		}
	}
	if (birthdayArray[1] == monthdata)
	{
		if (month[1] == 0)
			cout << "No person born in " << monthdata << endl;
		else
		{
			cout << "Totla number of birthdays in Febuary: " << month[1] << endl;
			for (int k = 0; k < i; k++)
			{
				if (list[k][2][0] == '0')
					if (list[k][2][1] == '2')
					{
						for (int s = 0; s < 4; s++)
							cout << list[k][s] << endl;
					}
			}
		}
	}
	if (birthdayArray[2] == monthdata)
	{
		if (month[2] == 0)
			cout << "No person born in " << monthdata << endl;
		else
		{
			cout << "Totla number of birthdays in March: " << month[2] << endl;
			for (int k = 0; k < i; k++)
			{
				if (list[k][2][0] == '0')
					if (list[k][2][1] == '3')
					{
						for (int s = 0; s < 4; s++)
							cout << list[k][s] << endl;

					}
			}
		}
	}
	if (birthdayArray[3] == monthdata)
	{
		if (month[3] == 0)
			cout << "No person born in " << monthdata << endl;
		else
		{
			cout << "Totla number of birthdays in April: " << month[3] << endl;
			for (int k = 0; k < i; k++)
			{
				if (list[k][2][0] == '0')
					if (list[k][2][1] == '4')
					{
						for (int s = 0; s < 4; s++)
							cout << list[k][s] << endl;
					}
			}
		}
	}
	if (birthdayArray[4] == monthdata)
	{
		if (month[4] == 0)
			cout << "No person born in " << monthdata << endl;
		else
		{
			cout << "Totla number of birthdays in May: " << month[4] << endl;
			for (int k = 0; k < i; k++)
			{
				if (list[k][2][0] == '0')
					if (list[k][2][1] == '5')
					{
						for (int s = 0; s < 4; s++)
							cout << list[k][s] << endl;
					}
			}
		}
	}
	if (birthdayArray[5] == monthdata)
	{
		if (month[5] == 0)
			cout << "No person born in " << monthdata << endl;
		else
		{
			cout << "Totla number of birthdays in June: " << month[5] << endl;
			for (int k = 0; k < i; k++)
			{
				if (list[k][2][0] == '0')
					if (list[k][2][1] == '6')
					{
						for (int s = 0; s < 4; s++)
							cout << list[k][s] << endl;
					}
			}
		}
	}
	if (birthdayArray[6] == monthdata)
	{
		if (month[6] == 0)
			cout << "No person born in " << monthdata << endl;
		else
		{
			cout << "Totla number of birthdays in July: " << month[6] << endl;
			for (int k = 0; k < i; k++)
			{
				if (list[k][2][0] == '0')
					if (list[k][2][1] == '7')
					{
						for (int s = 0; s < 4; s++)
							cout << list[k][s] << endl;
					}
			}
		}
	}
	if (birthdayArray[7] == monthdata)
	{
		if (month[7] == 0)
			cout << "No person born in " << monthdata << endl;
		else
		{
			cout << "Totla number of birthdays in August: " << month[7] << endl;
			for (int k = 0; k < i; k++)
			{
				if (list[k][2][0] == '0')
					if (list[k][2][1] == '8')
					{
						for (int s = 0; s < 4; s++)
							cout << list[k][s] << endl;
					}
			}
		}
	}
	if (birthdayArray[8] == monthdata)
	{
		if (month[8] == 0)
			cout << "No person born in " << monthdata << endl;
		else
		{
			cout << "Totla number of birthdays in September: " << month[8] << endl;
			for (int k = 0; k < i; k++)
			{
				if (list[k][2][0] == '0')
					if (list[k][2][1] == '9')
					{
						for (int s = 0; s < 4; s++)
							cout << list[k][s] << endl;
					}
			}
		}
	}
	if (birthdayArray[9] == monthdata)
	{
		if (month[9] == 0)
			cout << "No person born in " << monthdata << endl;
		else
		{
			cout << "Totla number of birthdays in October: " << month[9] << endl;
			for (int k = 0; k < i; k++)
			{
				if (list[k][2][0] == '1')
					if (list[k][2][1] == '0')
					{
						for (int s = 0; s < 4; s++)
							cout << list[k][s] << endl;
					}
			}
		}
	}
	if (birthdayArray[10] == monthdata)
	{
		if (month[10] == 0)
			cout << "No person born in " << monthdata << endl;
		else
		{
			cout << "Totla number of birthdays in November: " << month[10] << endl;
			for (int k = 0; k < i; k++)
			{
				if (list[k][2][0] == '1')
					if (list[k][2][1] == '1')
					{
						for (int s = 0; s < 4; s++)
							cout << list[k][s] << endl;
					}
			}
		}
	}
	if (birthdayArray[11] == monthdata)
	{
		if (month[11] == 0)
			cout << "No person born in " << monthdata << endl;
		else
		{
			cout << "Totla number of birthdays in December: " << month[11] << endl;
			for (int k = 0; k < i; k++)
			{
				if (list[k][2][0] == '1')
					if (list[k][2][1] == '2')
					{
						for (int s = 0; s < 4; s++)
							cout << list[k][s] << endl;

					}
			}
		}
	}


}
//--------------------------------------------------------------------

