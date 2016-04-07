#include "Headers/Encrypt.h"

void encrypt() {
	playSong(PINK_PANTHER);
	changeMode("Encrypt");
	cls();
	
	string fileName;
	if (getPathInterface(fileName))
		return;
	printf("\tPlease save the output file: %s\n", fileName.c_str());
	
	changeMode("Encrypt - Enter Message");
	cls();
	printf("\n\tPlease enter the message to encrypt. Press enter twice to end the message:\n\n\t");

	
	string message = multiLineInput();

	vector< vector<int> > matrixMessage = toNumbMatrix(message);
	vector< vector<unsigned long long> > key = randomMatrix();
	
	
	char input;
	isValidCharInput("\n\tWould you like to encrypt using a password? (Y/N)\n\n", { 'y', 'n' }, input);
	if (input == 'y') {
		if (passwordPromptOutput(fileName, key)) {

			return;
		}
	}
	else {
		outputLine(fileName, "No");
		outputLine(fileName, keyOutputString(key));

	}
	
	vector< vector<unsigned long long> > encryptedMessage = multiply(key, matrixMessage);
	outputLine(fileName, messageOutputString(encryptedMessage));
	addHash(fileName);
	changeMode("Encrypt - Done");
	cls();
	printf("\n\n\tFile successfully created.\n");
	pause();
	

}

int getPathInterface(string&fileName) {
	do {
		changeMode("Encrypt - Save File");
		cls();
		
		fileName = saveFile();
		if (fileName == "1")
			return ABORT;
		createFile(fileName);
		if (!fileExists(fileName))
			if (error("File could not be created. Could not obtain permissions. Please select a new directory."))
				return ABORT;


	} while (!fileExists(fileName));
	return CONTINUE;
}

int passwordPromptOutput(string fileName, vector<vector<unsigned long long>> key) {
	string password, temp;
	do {
		changeMode("Encrypt - Enter Password");
		cls();
		capsLockWarning();
		printf("\tEnter password: ");
		password = enterPassword();

		printf("\n\tConfirm your password: ");
		temp = enterPassword();
		if (password != temp)
			if (error("\n\n\tPasswords mismatch. Please try again.")) {
				remove(fileName.c_str());
				return ABORT;
			}

		
	} while (password != temp);
	outputLine(fileName, "Yes");
	outputLine(fileName, aesEncrypt(keyOutputString(key), password));

	return CONTINUE;
}