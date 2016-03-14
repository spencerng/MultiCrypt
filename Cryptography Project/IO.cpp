#include<iostream>
#include<string>
#include <vector>
#include <iomanip>
#include <conio.h>
#include "IO.h"
using std::string;
using std::getline;
using std::cin;
using std::cout;
using std::vector;
using std::setprecision;
using std::setw;
using std::endl;

string getString() {
	string input;
	cin.ignore();
	getline(cin, input);
	return input;
}

void printChoices() {
	cls();
	cout << "(1) Encode a message\n";
	cout << "(2) Decode a message\n";
	cout << "(3) Generate an encryption key\n";
	cout << "(4) Generate a decryption key\n";
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

void printCharVec(vector<char> input) {
	for (int i = 0; i < input.size(); i++)
		cout << input[i];

}

void cls() {
	
	cout << "\x1B[2J\x1B[H";
}

void pause() {
	cout << "Press any key to continue.";
	
	_getch();

}
