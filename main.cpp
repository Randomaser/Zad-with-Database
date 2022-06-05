#include <iostream>
#include <iomanip>
#include <string>

#define INCLUDE_OPERATIONS
#define INCLUDE_IO_OPERATIONS
#define CONSOLE_UNICODE
//#define MAX_RECORD 1
#include "AHKETA.h"
#ifdef CONSOLE_UNICODE
#include <Windows.h>
#endif
using namespace std;

unsigned int menu()
{
	unsigned int ans;
	do
	{
		cout << "Select:\n"
			<< "1. Show\n"
			<< "2. Add record\n"
			<< "3. Delete record\n"
			<< "4. Sort by Surname\n"
			<< "5. Exit\n\n"
			<< "---> ";
		cin >> ans;
	} while ((ans < 1) || (ans > 6));
	return ans;
}

enum MENU_VAR {
	SHOW = 1,
	ADD,
	DEL,
	SORT,
	EXIT
};

int main()
{
	AHKETA Ank[MAX_RECORD];
	unsigned short records = 0;  // Количество введенных записей
	unsigned int i = 0;   // Счетчик записей
	unsigned int deln;  // Номер удаляемой записи
	string tmp;

#ifdef CONSOLE_UNICODE
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
#endif

	//While Not Exit

	for (;;)
	{
		switch (menu())
		{
		case SHOW: // Показ записей
			system("CLS");
			if (records > 0)
			{
				for (i = 0; i < records;i++)
				{
					cout << "_______________________________________" << endl;
					ShowRecord(Ank[i], i+1);
				}
			}
			else
				cout << "Database is empty!\n";
			pause();
			break;
			 
		case ADD: // Добавить запись
			system("CLS");
			if (records < MAX_RECORD)
			{
				AddRecord(&Ank[records], records + 1);
				records++;
			}
			else
				cout << "Error: the limit on the number of records in the database has been reached" << endl;
			pause();
			break;
			 
		case DEL: // Удалить запись
			{
				system("CLS");
				unsigned int rec_ind = -1;
				cout << "Index of record to delete: "; cin >> rec_ind;
				unsigned short old_rec = records;
				records = DelRecord(Ank, rec_ind-1, records);
				if (old_rec == records)
					cout << "Error when deliting record from Database!\n";
				else
					cout << "Delete has deleted succesfully!\n";
				pause();
			}
			break;
		case SORT: // Сортировка по фамилии
			system("CLS");
			if (SortRecords(Ank, records) == 0)
				cout << "Ankets has been sorted!" << endl;
			else
				cout << "Error! Ankets has not been sorted!" << endl;
			pause();
			break;

		case EXIT: // Выход
			return 0;
		} // end of switch
		cout << endl;
	} // end of for(;;)
	pause();
	return 0;
}