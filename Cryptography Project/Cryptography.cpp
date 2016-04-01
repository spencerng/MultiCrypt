#pragma comment(lib, "winmm.lib")
#include<iostream>
#include <stdlib.h>

using namespace std;
#include "Headers/MatrixMath.h"
#include "Headers/KeyGenerate.h"
#include "Headers/Conversions.h"
#include "Headers/IO.h"
#include "Headers/RSA.h"
#include "Headers/Conversions.h"
#include "Headers/FileIO.h"
#include "Headers/Encrypt.h"
#include "Headers/Decrypt.h"
#include "Headers/Sounds.h"
#include "Headers/Graphics.h"



void debugMath();
//Allows user to input matrix to displays the result of transpose, cofactor, and inverse

void debugRandom();
// Generates a random unimodular matrix and displays it, along with debugMath functions

void debugEncrypt();
void debugDecrypt();


void debugToNumbMatrix() {
	string input = getString();
	if (!(isASCII(input)))
		cout << "Not ASCII";
	vector<char> vec = stringToCharVec(input);
	printMatrix(toNumbMatrix(vec));
	cout << matrixToString(toNumbMatrix(vec));
	pause();


}

//Further functions will be needed for file I/O. Main function will need a good user interface with additional features as necessary.


	 
int main() {
	setFullscreen();
	
	playSong('m');
	while (true) {
		cls();
		
		printChoices();
		aesEncrypt("Hello");
		char choice = getChar();
		cls();
		selectChoiceSound();
		
		
		if (choice == '9')
			debugRandom();
		
		if (choice == '8'){
			cout << enterPassword();
			system("pause");
			
		}
		if (choice == '7') {
			debugToNumbMatrix();
			//debugMath();

		}
		if (choice == '6') {
			
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
		if (choice == '1');

			

		
	}

	return 0;
}



void debugRandom(){
	
	vector< vector<unsigned long long> > debugMatrix = randomMatrix();
	printMatrix(debugMatrix);
			

			

	cout << "Determinant: " << det(debugMatrix) << endl;
	cout << "Transpose: \n";
	printMatrix(transpose(debugMatrix));
	cout << endl;
	cout << "Cofactor: \n";
	printMatrix(toCofMatrix(debugMatrix));
	cout << endl;
	cout << "Inverse: \n";
	printMatrix(inverseInt(debugMatrix));
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







void debugEncrypt() {

	// This is how the functions would be implemented, but feel free to change it.
	string message = getString();
	vector< vector<int> > matrixMessage = toNumbMatrix(stringToCharVec(message));
	vector< vector<unsigned long long> > key = randomMatrix();
	vector< vector<unsigned long long> > encryptedMessage = multiply(key, matrixMessage);
	cout << matrixToString(encryptedMessage) << endl;
	vector< vector<unsigned long long> > decodedMessage = multiply(inverseInt(key), encryptedMessage);
	cout << matrixToString(decodedMessage);
	system("pause");
	return;

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

