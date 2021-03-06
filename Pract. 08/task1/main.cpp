#include "pch.h"
#include "Student.h"
#include <iostream>

using namespace std;

bool isThereStudentBornOnCurrentYear(const Student& student,int year)
{
	return student.year == year;
}

int main()
{
	Student A, B, C;	
	A.enterData(); B.enterData(); C.enterData();

	const int size = 3;
	Student listOfStudent[size] = { A,B,C };

	const int year = 1999;

	for (size_t i = 0; i < size; i++)
	{
		if (isThereStudentBornOnCurrentYear(listOfStudent[i], year))
		{
			cout << "Student " << listOfStudent[i].name << " is born on: " << year << " as well." << endl;
			break;
		}
	}

	for (size_t i = 0; i < size; i++)
	{
		if (listOfStudent[i].checkBirthdate(year))
		{
			cout << listOfStudent[i].name << " " << listOfStudent[i].adress << endl;
		}
	}

	float worstGrade = 6;
	size_t indexOfStudent = -1;
	for (size_t i = 0; i < size; i++)
	{
		if (listOfStudent[i].GradeFirstTerm < worstGrade)
		{
			worstGrade = listOfStudent[i].GradeFirstTerm;
			indexOfStudent = i; //required for name afterwards
		}
	}
	cout << "Student: " << listOfStudent[indexOfStudent].name << " has the worst grades in his first term." << endl;

	float finalGrade = 2;
	float studentGrade = -1;
	for (size_t i = 0; i < size; i++)
	{
		studentGrade = listOfStudent[i].calculateFinalGrade();
		if (studentGrade > finalGrade)
		{
			finalGrade = studentGrade;
			indexOfStudent = i;
		}
	}
	cout << "Student: " << listOfStudent[indexOfStudent].name << " has the best grades" << endl;

	return 0;
}
