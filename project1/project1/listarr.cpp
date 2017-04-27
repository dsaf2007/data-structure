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

//������

{
	//list�� NULL�� �־� �ʱ�ȭ
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
//temp.txt�� �о�´�.
//�о�� �� list�迭�� �ڷḦ ä��� �� ���� ������ ����� ���� �����Ѵ�.
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
	while (!inFile.eof())//������ ���������� ����
	{

		inFile.getline(input[s], 100);
		s++;
	}s = s / 4;//�迭�� index���� ���߱����� �̿�. �� entry�� ���� ���� 4���� ���� �����Ƿ� 4�� �����ش�.
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
		for (int k = 0; k < i; k++)// list[k][2]�� entry�� ��ϵ� �����̰� ���� list[k][2][0]��list[k][2][1]�� ������ ��Ÿ���� ���ڸ����̹Ƿ� �̸� ��.
		{
			if (list[k][2][0] == '0')//�����ڸ����� 0�϶� 1���ڸ����� ��ġ�ϸ� month[k]++
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
			else//�����ڸ����� 1�϶� 1���ڸ����� ��ġ�ϸ� month[k]++
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
	i = s;//Ŭ���� ���� index�� ��Ÿ�� i=s�� ���ش�
}
void List::read()throw (logic_error)
//���ϸ��� �Է¹޾� �� ������ �ҷ��´�.(txt���ϸ�)
{

	string filename;//�ҷ��� ���ϸ�
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
	//�ҷ��鿩 list�� ��������, list�� temp.txt.�� �ٿ�����. 
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
//������ ����.(txt����)
{
	readtemp();
	string filename;
	//������ ���ϸ�
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
//temp.txt�� �ҷ����� �ڷḦ �߰��Ѵ�.
{
	//
	readtemp();
	char a[3][100];
	
	cout << "Add an entry:" << endl;

	cin.getline(a[0], 100);
	cout << "Name :";
	 cin.getline(a[0], 100);
	
	 list[i][0] = a[0];//list�� NULL�� �ʱ�ȭ �Ǿ��ֱ� ������ i�ε����� �ڷḦ �����ϸ� �ȴ�.

	cout << "Phone :"; cin.getline(a[1], 100);

	list[i][1] = a[1];

	cout << "Birthday :"; cin.getline(a[2], 100);

	list[i][2] = a[2];

	list[i][3] = "\n";
	i++;//������ ��ģ�� i++


	ofstream outFile("temp.txt");//list�� temp.txt�� �����.
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
//temp.txt�� �ҷ��� �� ���� �ڷḦ ����


{
	readtemp();

	cout << "remove an entry:" << endl;
	char a[100];
	cin.getline(a, 100);//�̸��� �Է¹޴´�
	cout << "Name :"; cin.getline(a, 100);
	int check = 0;//�Է¹��� ����� �����ϴ��� Ȯ���� ����
	for (int k = 0; k < i; k++)
	{
		if (strcmp(list[k][0], a) == 0)//strcmp�� �̿��Ͽ� �̸��� list[k][0]�� ����� �̸��� ��ġ�ϸ� list[k]�� �ʱ�ȭ �Ѵ�.
		{
			check++;
			for (int j = 0; j < 4; j++)
			{
				list[k][j] = NULL;
			}
			for(int s=k;s<i-1;s++)//list[k]���� �ڷ���� index�� -1�Ͽ� ��ĭ�� �մ���.
				for (int j = 0; j < 4; j++)
				{
					list[s][j] = list[s + 1][j];
				}
			for (int j = 0; j < 4; j++)
			{
				list[i][j] = NULL;
			}
			i--; break;//�� �ڷ���� -1�Ǿ����Ƿ� index�� ��Ÿ���� i�� --���ش�.
		}
	}
	if (check == 0)
	{
		cout << a << " is not in the entry";
	}
	ofstream outFile("temp.txt");//temp.txt list�� ���
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
//�� ���� �����ڰ� ������� Ȯ���ϴ� �Լ�

{
	
	readtemp();
	
	if (month[0] != 0)// readtemp���� �� ���� ������ ���� 0�� �ƴҰ�� �� �迭�� ��Ÿ���� ���� ���ڸ� ���
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
//���̸��� �Է¹ް� �� ���� ������ ����� ���� ������ ����� entry�� ���
{
	string birthdayArray[12] = { "January", "Febuary", "March", "April", "May", "June", "July", "August",
		"September", "October", "November", "December" };// �Է¹��� ���� ���� ����
	string monthdata;//�Է¹��� ��

	readtemp();
	cin >> monthdata;
	
	if (birthdayArray[0] == monthdata)//�Է¹��� �̸��� ��ġ�Ұ��
	{
		if (month[0] == 0)
			cout << "No person born in " << monthdata << endl;
		else
		{
			cout << "Totla number of birthdays in January: " << month[0] << endl;//�� �̸��� �����λ�� ���ڸ� ���
			for (int k = 0; k < i; k++)// entry�󿡼� ������ ��ġ�ϴ� ����� entry�� ��ü ���
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

