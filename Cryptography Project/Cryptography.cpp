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
		
		char choice;

		isValidCharInput(choices(), { '1','2','3','4' }, choice);
		
		
		if (choice == '1')
			;
			//encrypt();
		else if (choice == '2')
			;
			//decrypt();
		else if (choice == '3')
			toggleSound();
		else if (choice == '4') {
			exitProgramSound();
			return 0;
		}
			
	}

	return 666;
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



