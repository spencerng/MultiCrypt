#include<iostream>
#include <stdlib.h>
#include<windows.h>
using namespace std;
#include "Headers\MatrixMath.h"
#include "Headers\KeyGenerate.h"
#include "Headers\Conversions.h"
#include "Headers\IO.h"
#include "Headers\RSA.h"
#include "Headers\Conversions.h"
#include "Headers\FileIO.h"
#include "Headers\Encrypt.h"
#include "Headers\Decrypt.h"
#include "Headers\Sounds.h"

void debugMath();
//Allows user to input matrix to displays the result of transpose, cofactor, and inverse

void debugRandom();
// Generates a random unimodular matrix and displays it, along with debugMath functions

void debugEncrypt();
void debugDecrypt();

void debugMultiply();

//Further functions will be needed for file I/O. Main function will need a good user interface with additional features as necessary.

int main() {
	playSong('m');
	while (true) {
		
		printChoices();

		char choice = getChar();
		cls();
		selectChoiceSound();
		
		
		if (choice == '9')
			debugRandom();
		
		if (choice == '8'){
			
			
		}
		if (choice == '7') {
			
			debugMath();

		}
		if (choice == '6') {
			debugMultiply();
		}
		if (choice == '3') {
			debugEncrypt();
		}
		if (choice == '4') {
			debugDecrypt();
		}
		if (choice == '2') {
			string encryptedMessage;
			toNumbMatrix(stringToCharVec(encryptedMessage));
		}
		if (choice == '5') {
			exitProgramSound();
			return 1;
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
	exitProgramSound();
	pause();
	
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
	pause();
	
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

	pause();
	
}



void debugEncrypt() {
	cout << "Please enter your message.\n";

	string input = getString();

	vector<char> output = linearCipherEncrypt(stringToCharVec(input));
	cout << endl;
	printCharVec(output);
	cout << endl;
	pause();
	
}


void debugDecrypt() {
	cout << "Please enter your message.\n";

	string input = getString();

	vector<char> output = linearCipherDecrypt(stringToCharVec(input));
	cout << endl;
	printCharVec(output);
	cout << endl;

	pause();

}

