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

/*void encrypt() {
	// This is how the functions would be implemented, but feel free to change it.
	
	stringstream log;
	printStore(log, "Please enter the message to encrypt:\n");

	string message = getString();
	store(log, message);
	vector< vector<int> > matrixMessage = toNumbMatrix(stringToCharVec(message));
	vector< vector<unsigned long long> > key = randomMatrix();
	string keyOutput;

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
		keyOutput = aesEncrypt(keyMatrixToString(key), password);

	}
	else 
		keyOutput = keyMatrixToString(key);

	
	cls();
	string fileName = getFileName();
	createFile(fileName);
	outputKey(key, fileName);
	vector< vector<unsigned long long> > encryptedMessage = multiply(key, matrixMessage);
	outputMessage(encryptedMessage, fileName);
	addHash(fileName);
	return;

}*/


