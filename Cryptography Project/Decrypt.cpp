#include <string>
#include <iostream>
using namespace std;
#include "Headers/IO.h"
#include "Headers/Decrypt.h"
#include "Headers/FileIO.h"
#include "Headers/Conversions.h"
#include "Headers/KeyGenerate.h"
#include "Headers/MatrixMath.h"

//Uncomment this when all of the function definitions are present

void decrypt() {
	string fileName;
	selectValidFile(fileName);
	
	bool hasPassword;
	string keyString, messageString;
	getFileProperties(fileName, hasPassword, keyString, messageString);
	bool retry = false;
	if (hasPassword)
		decryptPassword(keyString);
	
	string decryptMessage = matrixToString(multiply(inverseInt(keyInputMatrix(keyString)), messageInputMatrix(messageString)));
	cout << "\n\n\tYour decrypted message is:\n\t" << decryptMessage << "\n\n\t";
	pause();
}

void decryptPassword(string& keyString) {
	bool retry = false;

    do {
        try {
            cls();
            cout << "\tThe file is encrypted using a password.\n\tEnter password: ";
            string password = enterPassword();
            keyString = aesDecrypt(keyString, password);
            retry = false;
        }
        catch (...) {
            cout << "\n\tIncorrect password. Please try again.\n\n\t";
            pause();
            retry = true;

        }
    } while (retry);
    

}

void selectValidFile(string& fileName) {
	do {
		cout << "\tPlease select a text file.\n\n";
		fileName = selectFile();
		if (/*!isTextFile(fileName) ||*/ !isValidFile(fileName)) {
			/*if (!isTextFile(fileName))
			cout << "\t" << fileName << " is not a path to a text file.\n\n";

			else*/ cout << "\t" << fileName << " is not a valid file created by this program. Are you sure it has not been modified?\n\n";
		cout << "\tPlease select a new text file.\n\t";
		pause();

		}
		cls();

	} while (!isValidFile(fileName) /*|| !isTextFile(fileName)*/);

}