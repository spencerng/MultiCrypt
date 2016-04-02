#include <string>
#include<iostream>
using namespace std;
#include "Headers/IO.h"
#include "Headers/Encrypt.h"
#include "Headers/FileIO.h"
#include "Headers/Conversions.h"
#include "Headers/KeyGenerate.h"
#include "Headers/MatrixMath.h"

// Uncomment this when all of the function definitions are present

void encrypt() {
	// This is how the functions would be implemented, but feel free to change it.
	string fileName = selectFolder() + "\\" + getFileName();
	createFile(fileName);
	

	stringstream log;
	cout << "Please enter the message to encrypt:\n";

	string message = getString();
	
	vector< vector<int> > matrixMessage = toNumbMatrix(stringToCharVec(message));
	vector< vector<unsigned long long> > key = randomMatrix();
	

	char input;
	printStore(log, "Would you like to encrypt using a password? (Y/N)\n\n");
	isValidCharInput(log.str(), { 'y', 'n' }, input);
	if (input == 'y') {
		string password, temp;
		do {
			cls();
			log.str("");
			cout << "Enter password: ";
			password = enterPassword();

			printStore(log, "\nConfirm your password: ");
			temp = enterPassword();
			if (password != temp) {
				cout << "\n Passwords mismatch. Please try again.\n";
				pause();

			}
		} while (password != temp);
		outputLine(fileName, "Yes");
		outputLine(fileName, aesEncrypt(keyOutputString(key), password));

	}
	else {
		outputLine(fileName, "No");
		outputLine(fileName,keyOutputString(key));

	}
	

	vector< vector<unsigned long long> > encryptedMessage = multiply(key, matrixMessage);
	outputLine(fileName, messageOutputString(encryptedMessage));
	addHash(fileName);
	return;

};


