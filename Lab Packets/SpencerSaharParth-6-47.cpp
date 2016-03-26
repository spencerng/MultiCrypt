/*
Exercises 6.35-6.37 developed a computer-assisted instruction program to teach an
elementary school student multiplication. This exercise suggests enhancements to that
program.
a. Modify the program to allow the user to enter a grade-level capability. A grade
level of 1 means to use only single-digit numbers in the problems, a grade level of
2 means to use numbers as large as two digits, etc.

b. Modify the program to allow the user to pick the type of arithmetic problems he or
she wishes to study.An option of 1 means addition problems only, 2 means
subtraction problems only, 3 means multiplication problems only, 4 means division
problems only and 5 means a random mix of problems of all these types.
*/

#include <iostream>
#include <ctime>
#include <Windows.h>
using namespace std;

int percent(int, int);
int add(int max, int min);
int subtract(int max, int min);
int multi(int max, int min);
int divi(int max, int min);
int mix(int max, int min);
void respright();
void respwrong();

int main()
{
	srand(time(NULL));
	int choice = 0, grade, max, min, right = 0;
	cout << "What grade level would you like to work on? Enter 1 for single digits,\n"
		<< "2 for double digits, and 3 for a mix. ";
	cin >> grade;
	switch (grade)
	{
	case 1:
		max = 9;
		min = 0;
		break;
	case 2:
		max = 100;
		min = 10;
		break;
	case 3:
		max = 100;
		min = 0;
		break;
	default:
		cout << "Not a valid choice. " << endl;
		break;
	}
	if (grade == 1 || grade == 2 || grade == 3)
	{
		system("cls");
		cout << "What type of arithmetic would you like to do? " << "Enter 1 for addition,\n"
			<< "2 for subtraction, 3 for multiplication, 4 for division, and 5 for a mix. ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			system("cls");
			right = add(max, min);
			break;
		case 2:
			system("cls");
			right = subtract(max, min);
			break;
		case 3:
			system("cls");
			right = multi(max, min);
			break;
		case 4:
			system("cls");
			right = divi(max, min);
			break;
		case 5:
			system("cls");
			right = mix(max, min);
			break;
		default:
			cout << "Please enter a valid choice. " << endl;
			break;
		}
	}
	if (choice == 1 || choice == 2 || choice == 3 || choice == 4 || choice == 5)
	{
		cout << "Your score is " << percent(10, right) << "%." << endl;
		if (percent(10, right) < 75)
			cout << "Please ask your instructor for extra help." << endl;
	}
}

int percent(int total, int right)
{
	return right * 100 / total;
}

void respwrong()
{
	switch (rand() % 4 + 1)
	{
	case 1:
		cout << "No. Please try again. ";
		break;
	case 2:
		cout << "Wrong. Try once more. ";
		break;
	case 3:
		cout << "Don't give up! ";
		break;
	case 4:
		cout << "No. Keep trying. ";
		break;
	}
}

void respright()
{
	switch (rand() % 4 + 1)
	{
	case 1:
		cout << "Very good!" << endl;
		break;
	case 2:
		cout << "Excellent!" << endl;
		break;
	case 3:
		cout << "Nice work!" << endl;
		break;
	case 4:
		cout << "Keep up the good work!" << endl;
		break;
	}
}

int add(int max, int min)
{
	float answer;
	int right = 0, num1, num2, posNeg;
	for (int i = 0; i < 10; i++)
	{
		if (rand() % 2)
			posNeg = 1;
		else
			posNeg = -1;
		num1 = (posNeg) * rand() % max + min;
		num2 = (posNeg) * rand() % max + min;
		cout << "What is " << num1 << " + " << num2 << "? ";
		cin >> answer;
		if (answer != num1 + num2)
		{
			do
			{
				respwrong();
				cin >> answer;
			} while (answer != num1 + num2);
		}
		else
		{
			++right;
			respright();
		}
		Sleep(1000);
		system("cls");
	}
	return right;
}

int subtract(int max, int min)
{
	float answer;
	int right = 0, num1, num2, posNeg;
	for (int i = 0; i < 10; i++)
	{
		if (rand() % 2)
			posNeg = 1;
		else
			posNeg = -1;
		num1 = (posNeg) * rand() % max + min;
		num2 = (posNeg) * rand() % max + min;
		cout << "What is " << num1 << " - " << num2 << "? ";
		cin >> answer;
		if (answer != num1 - num2)
		{
			do
			{
				respwrong();
				cin >> answer;
			} while (answer != num1 - num2);
		}
		else
		{
			++right;
			respright();
		}
		Sleep(1000);
		system("cls");
	}
	return right;
}

int multi(int max, int min)
{
	float answer;
	int right = 0, num1, num2, posNeg;
	for (int i = 0; i < 10; i++)
	{
		if (rand() % 2)
			posNeg = 1;
		else
			posNeg = -1;
		num1 = (posNeg) * rand() % max + min;
		num2 = (posNeg) * rand() % max + min;
		cout << "What is " << num1 << " * " << num2 << "? ";
		cin >> answer;
		if (answer != num1 * num2)
		{
			do
			{
				respwrong();
				cin >> answer;
			} while (answer != num1*num2);
		}
		else
		{
			++right;
			respright();
		}
		Sleep(1000);
		system("cls");
	}
	return right;
}

int divi(int max, int min)
{

	float answer;
	int right = 0, num1, num2, posNeg;
	for (int i = 0; i < 10; i++)
	{
		if (rand() % 2)
			posNeg = 1;
		else
			posNeg = -1;
		do
		{
			num1 = (posNeg) * rand() % max + min;
			num2 = (posNeg) * rand() % max + (min + 1);
		} while (num2 != 0 && num1 % num2 != 0);

		cout << "What is " << num1 << " / " << num2 << "? ";
		cin >> answer;
		if (answer != num1 / num2)
		{
			do
			{
				respwrong();
				cin >> answer;
			} while (answer != (num1) / num2);
		}
		else
		{
			++right;
			respright();
		}
		Sleep(1000);
		system("cls");
	}
	return right;
}

int mix(int max, int min)
{
	float answer;
	int right = 0, rightans, num1, num2, posNeg;
	for (int i = 0; i < 10; i++)
	{
		if (rand() % 2)
			posNeg = 1;
		else
			posNeg = -1;
		if ((rand() % 4 + 1) == 1)
		{
			num1 = (posNeg) * rand() % max + min;
			num2 = (posNeg) * rand() % max + min;
			rightans = num1 + num2;
			cout << "What is " << num1 << " + " << num2 << "? ";
		}
		else if ((rand() % 4 + 1) == 2)
		{
			num1 = (posNeg) * rand() % max + min;
			num2 = (posNeg) * rand() % max + min;
			rightans = num1 - num2;
			cout << "What is " << num1 << " - " << num2 << "? ";
		}
		else if ((rand() % 4 + 1) == 4)
		{
			num1 = (posNeg) * rand() % max + min;
			num2 = (posNeg) * rand() % max + min;
			rightans = num1 * num2;
			cout << "What is " << num1 << " * " << num2 << "? ";
		}
		else
		{
			do
			{
				num1 = (posNeg) * rand() % max + min;
				num2 = (posNeg) * rand() % max + (min + 1);
			} while (num1 % num2 != 0);
			rightans = num1 / num2;
			cout << "What is " << num1 << " / " << num2 << "? ";
		}
		cin >> answer;
		if (answer != rightans)
		{
			do
			{
				respwrong();
				cin >> answer;
			} while (answer != rightans);
		}

		else
		{
			++right;
			respright();
		}
		Sleep(1000);
		system("cls");
	}
	return right;
}







