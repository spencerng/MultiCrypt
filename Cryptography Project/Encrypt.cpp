#include "Headers/Encrypt.h"

void encrypt() {
	changeMode("Encrypt");
	cls();
	stringstream buffer;
	string fileName;
	getPathInterface(fileName);
	
	printStore(buffer,"\n\tPlease enter the message to encrypt:\n\t");

	string message = getString();
	
	vector< vector<int> > matrixMessage = toNumbMatrix(message);
	vector< vector<unsigned long long> > key = randomMatrix();
	
	
	char input;
	isValidCharInput("\n\tWould you like to encrypt using a password? (Y/N)\n\n", { 'y', 'n' }, input);
	if (input == 'y') 
		passwordPromptOutput(fileName, key);

	
	else {
		outputLine(fileName, "No");
		outputLine(fileName, keyOutputString(key));

	}
	
	vector< vector<unsigned long long> > encryptedMessage = multiply(key, matrixMessage);
	outputLine(fileName, messageOutputString(encryptedMessage));
	addHash(fileName);
	changeMode("Encrypt - Done");
	printf("\n\n\tFile successfully created.\n");
	pause();
	return;

}

void getPathInterface(string&fileName) {
	do {
		changeMode("Encrypt - Save File");
		cls();
		
		fileName = saveFile();
		createFile(fileName);
		if (!fileExists(fileName))
			error("File could not be created. Could not obtain permissions. Please select a new directory.");


	} while (!fileExists(fileName));

}

void passwordPromptOutput(string fileName, vector<vector<unsigned long long>> key) {
	string password, temp;
	do {
		changeMode("Encrypt - Enter Password");
		cls();

		printf("\tEnter password: ");
		password = enterPassword();

		printf("\n\tConfirm your password: ");
		temp = enterPassword();
		if (password != temp) 
			error("\nPasswords mismatch. Please try again.", fileName);		

		
	} while (password != temp);
	outputLine(fileName, "Yes");
	outputLine(fileName, aesEncrypt(keyOutputString(key), password));


}