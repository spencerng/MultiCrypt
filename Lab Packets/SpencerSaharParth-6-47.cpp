/*6.47 Prompt:
Exercises 6.35 and 6.37 developed a computer-assisted instruction program to teach an
elementary school student multiplication. This exercise suggests enhancements to that
program.
	a. Modify the program to allow the user to enter a grade-level capability. A grade
	level of 1 means to use only single-digit numbers in the problems, a grade level of
	2 means to use numbers as large as two digits, etc. 
	
	b. Modify the program to allow the user to pick the type of arithmetic problems he or 
	she wishes to study. An option of 1 means addition problems only, 2 means
	subtraction problems only, 3 means multiplication problems only, 4 means division
	problems only and 5 means a random mix of problems of all these types. 
	
6.37 Prompt:
More sophisticated computer-aided instruction systems monitor the student's
performance over a period of time. The decision to begin a new topic often is based on
the student's success with previous topics. Modify the program of Exercise 6.36 to count
the number of correct and incorrect responses typed by the student. After the student
types 10 answers, your program should calculate the percentage of correct responses. If
the percentage is lower than 75 percent, your program should print "Please ask your
instructor for extra help" and terminate. 

6.36 Prompt:
(Computer Assisted Instruction) The use of computers in education is referred to as
computer-assisted instruction (CAI). One problem that develops in CAI environments is
student fatigue. This can be eliminated by varying the computer's dialogue to hold the
student's attention. Modify the program of Exercise 6.35 so the various comments are
printed for each correct answer and each incorrect answer as follows:
Responses to a correct answer
 Very good!
 Excellent!
 Nice work!
 Keep up the good work!
Responses to an incorrect answer
 No. Please try again.
 Wrong. Try once more.
 Don't give up!
 No. Keep trying.
Use the random number generator to choose a number from 1 to 4 to select an 
appropriate response to each answer. Use a switch statement to issue the responses. 

6.35 Prompt:
Computers in Education) Computers are playing an increasing role in education. Write a
program that helps an elementary school student learn multiplication. Use rand to
produce two positive one-digit integers. It should then type a question such as
How much is 6 times 7?
The student then types the answer. Your program checks the student's answer. If it is
correct, print "Very good!", then ask another multiplication question. If the answer is
wrong, print "No. Please try again.", then let the student try the same question
repeatedly until the student finally gets it right. */


#include <iostream>
#include <ctime>
using namespace std;

int percent(double, double);
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
	cout << "What grade level would you like to work on? Enter 1 for single digits\n"
		<< "and 2 for double digits. ";
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
	default:
		cout << "Not a valid choice. " << endl;
		break;
	}
	if (grade > 0 && grade < 3)
	{
		cout << "What type of arithmetic would you like to do? " << "Enter 1 for addition,\n"
			<< "2 for subtraction, 3 for multiplication, 4 for division, and 5 for a mix. ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			right = add(max, min);
			break;
		case 2:
			right = subtract(max, min);
			break;
		case 3:
			right = multi(max, min);
			break;
		case 4:
			right = divi(max, min);
			break;
		case 5:
			right = mix(max, min);
			break;
		default:
			cout << "Please enter a valid choice. " << endl;
			break;
		}
	}
	if (choice > 0 && choice < 6)
	{
		cout << "Your score is" << percent(10, right) << "%." << endl;
		if (percent(10, right) < 75)
			cout << "Please ask your instructor for extra help." << endl;
	}
}

int percent(double total, double right)
{
	return (right / total) * 100;
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
	int answer, right = 0, num1, num2;
	for (int i = 0; i < 10; i++)
	{
		num1 = rand() % max + min;
		num2 = rand() % max + min;
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
	}
	return right;
}

int subtract(int max, int min)
{
	int answer, right = 0, num1, num2;
	for (int i = 0; i < 10; i++)
	{
		num1 = rand() % max + min;
		num2 = rand() % max + min;
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
	}
	return right;
}

int multi(int max, int min)
{
	int answer, right = 0, num1, num2;
	for (int i = 0; i < 10; i++)
	{
		num1 = rand() % max + min;
		num2 = rand() % max + min;
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
	}
	return right;
}

int divi(int max, int min)
{
	
	int answer, right = 0, num1, num2;
	for (int i = 0; i < 10; i++)
	{
		do
		{
			num1 = rand() % max + min;
			num2 = rand() % max + (min + 1);
		} while (num1 % num2 != 0);
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
	}
	return right;
}

int mix(int max, int min)
{
	int answer, right = 0, rightans, num1, num2;
	for (int i = 0; i < 10; i++)
	{
		if ((rand() % 4 + 1) == 1)
		{
			num1 = rand() % max + min;
			num2 = rand() % max + min;
			rightans = num1 + num2;
			cout << "What is " << num1 << " + " << num2 << "? ";
		}
		else if ((rand() % 4 + 1) == 2)
		{
			num1 = rand() % max + min;
			num2 = rand() % max + min;
			rightans = num1 - num2;
			cout << "What is " << num1 << " - " << num2 << "? ";
		}
		else if ((rand() % 4 + 1) == 4)
		{
			num1 = rand() % max + min;
			num2 = rand() % max + min;
			rightans = num1 * num2;
			cout << "What is " << num1 << " * " << num2 << "? ";
		}
		else
		{
			do
			{
				num1 = rand() % max + min;
				num2 = rand() % max + (min + 1);
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
	}	
	return right;
}
