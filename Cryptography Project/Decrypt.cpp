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

	string fileName = selectFile();
	/*if (!isTextFile(fileName))
		;*/
	if (!isValidFile(fileName))
		return;
	bool hasPassword;
	string keyString, messageString;
	getFileProperties(fileName, hasPassword, keyString, messageString);
	if (hasPassword) {
		cout << "Enter password: ";
		string password = enterPassword();
		keyString = aesDecrypt(keyString, password);
	}
	string decryptMessage = matrixToString(multiply(inverseInt(keyInputMatrix(keyString)), messageInputMatrix(messageString)));
	cout << decryptMessage;
	pause();
}
