#include<iostream>
#include <iomanip>
#include<SDL.h>
#include <conio.h>
#include "Headers/IO.h"
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
	cin.ignore();
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

void printChoices() {
	
	print("(1) Encode a message\n");
	cout << '\t' << "(2) Decode a message\n";
	cout << "(3) Debug Encryption\n";
	cout << "(4) Debug Decryption\n";
	cout << "(5) Exit the program\n";
	cout << "(6) Multiply two matrices\n";
	cout << "(7) Debug Math\n";
	cout << "(8) Debug String to Matrix\n";
	cout << "(9) Debug Random Matrix Generator\n";
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

	for (int i = 0; i < ((240 - s.length()) / 2); i++)
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
