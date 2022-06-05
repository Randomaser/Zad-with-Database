#pragma once
#include <iostream>
#include <string>
using namespace std;

#ifndef MAX_RECORD
#define MAX_RECORD 50
#endif

typedef struct Men
{
	unsigned int age = 0 , w = 0, h = 0; // Возраст, вес, рост
	string Surname = ""; // Фамилия
	string Name = "";    // Имя
} AHKETA;


void pause(void)
{
	cout << "_______________________________________" << endl;
	system("pause");
	system("CLS");
}

#ifdef INCLUDE_OPERATIONS
int AddRecord(AHKETA *A, int number)
{
	bool AllGood = true;
	do
	{
		system("CLS");
		cout << "       №: " << number << endl;
		cout << " Surname: "; cin >> A->Surname;
		cout << "    Name: "; cin >> A->Name;
		cout << "     Age: "; cin >> A->age;
		cout << "  Weight: "; cin >> A->w;
		cout << "  Height: "; cin >> A->h;
		AllGood = (A->Surname != "" && A->Name != "" && A->age > 0 && A->age < 200 && A->w > 0 && A->w < 500 && A->h > 0 && A->h < 500);
		if (!AllGood)
		{
			cout << "_______________________________________" << endl;
			cout << "Information is not correct!\nTry again!\n";
			system("pause");
		}
	} while (!AllGood);
	return 0;
}
int ShowRecord(AHKETA A, int number)
{
	cout << "       №: " << number << endl;
	cout << " Surname: " << A.Surname << endl;
	cout << "    Name: " << A.Name << endl;
	cout << "     Age: " << A.age << endl;
	cout << "  Weight: " << A.w << endl;
	cout << "  Height: " << A.h << endl;
	return 0;
}
int SortRecords(AHKETA *A, int length)
{
	int i;
	for (i = 0; i < length - 1; i++)
		for (int j = i+1; j < length;j++)
		{
			if (A[i].Surname > A[j].Surname)
			{
				//ShowRecord(A[i], i);
				//ShowRecord(A[j], j);
				AHKETA tmp = A[i];
				A[i] = A[j];
				A[j] = tmp;
			}
	}
	if (i < length - 2)
	{
		return 1;
	}
	return 0;
}
int DelRecord(AHKETA *A, unsigned int index, unsigned int length)
{
	int i = -1;
	if (length >= index && length > 0)
	{
		for (i = index; i < length - 1; i++)
			A[i] = A[i + 1];
		length = length - 1;
		if (i < index && i < length - 1)
			return length + 1;
	}
	return length;
}
#endif