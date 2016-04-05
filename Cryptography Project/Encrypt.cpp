#include "Headers/Encrypt.h"

void encrypt() {
	
	string file;
	do {
		cls();
		file = getFileName();
		if (file == "ERROR") {
			cout << "\tIllegal file name. Please try again.\n\n\t";
			pause();
		}

	} while (file == "ERROR");
	string fileName;
	do {
		cls();
		fileName = selectFolder() + "\\" + file;
		createFile(fileName);
		if (!fileExists(fileName)) {
			cout << "\tFile could not be created. Could not obtain permissions. Please select a new directory.\n\n\t";
			pause();
		}
	} while (!fileExists(fileName));
	

	stringstream log;
	cout << "\n\tPlease enter the message to encrypt:\n\t";

	string message = getString();
	
	vector< vector<int> > matrixMessage = toNumbMatrix(message);
	vector< vector<unsigned long long> > key = randomMatrix();
	

	char input;
	printStore(log, "\n\tWould you like to encrypt using a password? (Y/N)\n\n");
	isValidCharInput(log.str(), { 'y', 'n' }, input);
	if (input == 'y') {
		string password, temp;
		do {
			cls();
			log.str("");
			cout << "\tEnter password: ";
			password = enterPassword();

			printStore(log, "\n\tConfirm your password: ");
			temp = enterPassword();
			if (password != temp) {
				cout << "\n\n\tPasswords mismatch. Please try again.\n\n\t";
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

}
