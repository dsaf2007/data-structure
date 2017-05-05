//--------------------------------------------------------------------
//
//                                                          listarr.h
//
//  Class declaration for the array implementation of the List ADT
//
//--------------------------------------------------------------------
// #pragma warning( disable : 4290 )

#include <stdexcept>
#include <iostream>



using namespace std;

const int defMaxListSize = 10;   // Default maximum list size

typedef char DataType;

class List
{
public:

	// Constructor
	List(int maxNumber = defMaxListSize);

	// Destructor
	~List();


	
	void read()//read file
		throw (logic_error);
	void insert()  //insert entry
		throw (logic_error);
	void remove()    //remove entry                            
		throw (logic_error);

	void readtemp();//read temp.txt
       

	
	void checkMonth()       //count the monthes              
		throw (logic_error);
	void List::printMonth() // print the monthes
		throw (logic_error);
	void List::write() //write file
		throw (logic_error);

	// In-lab operations
	bool find(const DataType &searchDataItem)     // Find data item
		throw (logic_error);
	char *list[100][100];//������ �迭�� �����Ͽ� �� ��� \n���� �װ��� ���� ������
	int i = 0;//list�迭�� ���� ��Ÿ�� index
	int month[12];//���� ���������� ���ڸ� �� �迭
	

	
};

