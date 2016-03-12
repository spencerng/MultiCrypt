#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <string>
#include <ctime>
#include "MatrixMath.h"
#include "KeyGenerate.h"
#include "Conversions.h"
#include "IO.h"
using namespace std;

void debugMath();
//Allows user to input matrix to displays the result of transpose, cofactor, and inverse

void debugRandom();
// Generates a random unimodular matrix and displays it, along with debugMath functions

void debugString();

void debugMultiply();

//Further functions will be needed for file I/O. Main function will need a good user interface with additional features as necessary.

int main() {
	
	while (true) {
		system("cls");
		printChoices();

		char choice = getChar();
		system("cls");
		int sizeI, sizeJ, size, entry;
		
		if (choice == '9')
			debugRandom();
		
		if (choice == '8'){
			
			debugString();
		}
		if (choice == '7') {
			
			debugMath();

		}
		if (choice == '6') {
			debugMultiply();
		}
		if (choice == '3') {
		}
		if (choice == '4') {

		}
		if (choice == '2') {
			string encryptedMessage;
			toNumbMatrix(stringToCharVec(encryptedMessage));
		}
		if (choice == '5') {
			return 0;
		}

		
	}

	return 0;
}



void debugRandom(){
	
	vector< vector<int> > debugMatrix = randomMatrix();
	printMatrix(debugMatrix);
			

			

	cout << "Determinant: " << det(debugMatrix) << endl;
	cout << "Transpose: \n";
	printMatrix(transpose(debugMatrix));
	cout << endl;
	cout << "Cofactor: \n";
	printMatrix(toCofMatrix(debugMatrix));
	cout << endl;
	cout << "Inverse: \n";
	printMatrix(inverse(debugMatrix));
	
	system("pause");
}

void debugMath() {
	cout << "Enter the size of an n x n matrix: ";
	int sizeI;
	cin >> sizeI;
	vector< vector<int> > debugMatrix(sizeI, vector<int>(sizeI));
	
	
	cout << "\nEnter the " << sizeI << " x " << sizeI << " matrix.\n";

	inputMatrix(debugMatrix);



	cout << "Determinant: " << det(debugMatrix) << endl;
	cout << "Transpose: \n";
	printMatrix(transpose(debugMatrix));
	cout << endl;
	cout << "Cofactor: \n";
	printMatrix(toCofMatrix(debugMatrix));
	cout << endl;
	cout << "Inverse: \n";
	printMatrix(inverse(debugMatrix));
	system("pause");

}



void debugMultiply() {
	int sizeI, sizeJ;
	cout << "Enter the size of the m x n matrix A: ";

	cin >> sizeI >> sizeJ;
	vector< vector<int> > A(sizeI, vector<int>(sizeJ));
	inputMatrix(A);

	cout << "Enter the size of B: ";
	cin >> sizeI >> sizeJ;

	vector< vector<int> > B(sizeI, vector<int>(sizeJ));
	inputMatrix(B);

	cout << endl << "A * B =\n\n";
	vector< vector<int> > product = multiply(A, B);
	printMatrix(product);

	system("pause");

}



void debugString() {
	cout << "Please enter your message.\n";

	string input = getString();

	vector<char> output = stringToCharVec(input);
	for (int i = 0; i < output.size(); i++)
		cout << input[i];
	cout << endl;
	system("pause");

}


void encodeMessage() {

}

void decodeMessage() {

}



