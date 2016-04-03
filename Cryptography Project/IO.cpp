#include<iostream>
#include <iomanip>

#include <conio.h>
#include <Windows.h>
#include "Headers/IO.h"
#include "Headers/Graphics.h"
using std::string;
using std::getline;
using std::cin;
using std::cout;
using std::vector;
using std::setprecision;
using std::setw;
using std::endl;
using std::setfill;

// define DOS for DOS-based OS (Windows) or UNIX (Linux, OS X, etc.)
#define DOS

string getString() {
	string input;
	getline(cin, input);
	return input;
}

bool isASCII(string s) {
	for (int i = 0; i < s.length(); i++)
		if (isASCII(s[i]) == false)
			return false;
	return true;
}

bool isASCII(char c) {
	if (c >= 32 && c < 127)
		return true;
	return false;


}

string choices() {
	std::stringstream buffer;
	buffer << "\t(1) Encrypt a message\n";
	buffer << "\t(2) Decrypt a message\n";
	buffer << "\t(3) Turn Music " << (getMusicStatus() ? ("Off") : ("On")) << endl;
	buffer << "\t(4) Exit the program\n";
	
	return buffer.str();
}

char getChar() {
	char input;
	cin >> input;
	return input;
}

void inputMatrix(vector< vector<int> >& matrix) {
	for (int i = 0; i < matrix.size(); i++)
		for (int j = 0; j < matrix[0].size(); j++)
			cin >> matrix[i][j];

}

void printMatrix(vector< vector<double> > A) {
	for (int i = 0; i < A.size(); i++) {
		cout << setprecision(3);
		for (int j = 0; j < A[0].size(); j++)
			cout << setw(15) << A[i][j];
		cout << endl;
	}
}

void printMatrix(vector< vector<int> > A) {
	for (int i = 0; i < A.size(); i++) {
		for (int j = 0; j < A[0].size(); j++)
			cout << setw(10) << A[i][j];
		cout << endl;
	}
	return;
}

void printMatrix(vector< vector<unsigned long long> > A) {
	for (int i = 0; i < A.size(); i++) {
		for (int j = 0; j < A[0].size(); j++)
			cout << setw(40) << A[i][j];
		cout << endl;
	}
	return;
}

void printCharVec(vector<char> input) {
	for (int i = 0; i < input.size(); i++)
		cout << input[i];

}

void printCenter(string s) {

	for (int i = 0; i < (((GetSystemMetrics(SM_CXSCREEN)/8)- s.length()) / 2); i++)
		cout << ' ';
	cout << s << endl;

}

void printCenter(vector<string> s) {

	for (int i = 0; i < s.size(); i++)
		printCenter(s[i]);

}

void cls() {
#ifdef DOS
	system("cls");
#endif
#ifdef UNIX
	system("clear");
#endif
	printTitle();

}

void pause() {
	cout << "Press any key to continue.";
	
	_getch();

}

void print(const char* c) {
	for (int i = 0; i < 4; i++)
		cout << ' ';
	cout << c;

}

void isValidCharInput(string prompt, vector<char> validInputs, char &input) {
	while (1) {
		cls();
		cout << prompt << endl;
		
		input = tolower(_getch());
		for (int i = 0; i < validInputs.size(); i++)
			if (input == validInputs[i])
				return;


		cout << "\tInvalid input detected. Please try again.\n\t";
		pause();
		for (int i = 0; i < 144; i++)
			cout << '\b';
		for (int i = 0; i < 72; i++)
			cout << ' ';
		for (int i = 0; i < 72; i++)
			cout << '\b';
		
	}

}

void store(std::stringstream &ss, string text) {
	ss << text << endl;
}

void printStore(std::stringstream &ss, string text) {
	ss << text;
	cout << text;
}
