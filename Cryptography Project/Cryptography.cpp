#include<iostream>
#include <stdlib.h>
#include<windows.h>
#include<WinUser.h>
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

//To do:
//Better graphics (GUI?)
//Sounds
//Introduct to program


void debugMath();
//Allows user to input matrix to displays the result of transpose, cofactor, and inverse

void debugRandom();
// Generates a random unimodular matrix and displays it, along with debugMath functions

void debugEncrypt();
void debugDecrypt();

void debugMultiply();
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

void selectFile() {
	// This is not the preferred method, but it will work.
	// (You should preferably use the SHGetFolderPath() function instead.)
	string mydocuments = "C:\\Users\\sng\\Documents";

	// This is where the filename your user selects will go.
	// Make sure it is long enough. (Especially if you start playing with the OFN_ALLOWMULTISELECT flag.)
	string filename(MAX_PATH, '\0');

	// This structure tells Windows how you want the Open File Dialog to appear.
	OPENFILENAME ofn;
	ZeroMemory(&ofn, sizeof(OPENFILENAME));
	ofn.lStructSize = sizeof(OPENFILENAME);

	// We'll add filters for text files (*.txt) and any file (*.*).
	// If you don't want any filters, just comment out this line (== set it to NULL).
	ofn.lpstrFilter = L"*.TXT";

	// Where to put the filename the user selects
	ofn.lpstrFile = LPWSTR(filename.c_str());
	ofn.nMaxFile = filename.size();

	// Folder to start in
	ofn.lpstrInitialDir = LPCWSTR(mydocuments.c_str());

	// Title of the dialog
	ofn.lpstrTitle = L"Demo -- Choose any file -- nothing will happen.";

	// There are many more options, but right now we just want the user to 
	// select a file that actually exists.
	ofn.Flags = OFN_FILEMUSTEXIST | OFN_PATHMUSTEXIST;

	// Show the dialog!
	if (GetOpenFileName(&ofn))
	{
		// Success! Yaaaay!
		filename.resize(filename.find('\0'));
		cout << "You chose the file: " << filename << "\n";
	}
	else
	{
		// Bummer. Failure, dude.
		cout << "You chose to cancel the file operation.\n";
	}
}
	
int main() {
	setFullscreen();
	
	playSong('m');
	while (true) {
		cls();
		printTitle();
		printChoices();
		selectFile();
		
		vector<string> s;
		s.push_back("");

		printCenter(s);
		char choice = getChar();
		cls();
		selectChoiceSound();
		
		
		if (choice == '9')
			debugRandom();
		
		if (choice == '8'){
			
			
		}
		if (choice == '7') {
			debugToNumbMatrix();
			//debugMath();

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

