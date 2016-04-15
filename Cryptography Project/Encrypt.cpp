#include "Headers/Encrypt.h"

void encrypt() {
	playSong(PINK_PANTHER);
	changeMode("Encrypt");
	cls();
	
	string fileName;
	if (getPathInterface(fileName))
		// ABORT is returned from getPathInterface
		return;

	printf("\tPlease save the output file: %s\n", fileName.c_str());
	
	changeMode("Encrypt - Enter Message");
	cls();

	printf("\n\tPlease enter the message to encrypt. Press enter twice to end the message:\n\n\t");

	string message = multiLineInput();

	// Computations need to be done at this stage since the key may be encrypted
	vector< vector<int> > matrixMessage = toNumbMatrix(message);
	vector< vector<unsigned long long> > key = randomMatrix();
	
	
	char input;
	isValidCharInput("\n\tWould you like to encrypt using a password? (Y/N)\n\n", { 'y', 'n' }, input);
	
	if (input == 'y') {
		if (passwordPromptOutput(fileName, key))
			return;
	}
		
	
	else {
		// Outputs the password flag and the plaintext key as a string
		outputLine(fileName, "No");
		outputLine(fileName, keyOutputString(key));
	}
	
	vector< vector<unsigned long long> > encryptedMessage = multiply(key, matrixMessage);

	outputLine(fileName, messageOutputString(encryptedMessage));

	// Hashes the current file and appends the hash to the end
	addHash(fileName);

	changeMode("Encrypt - Done");
	cls();
	printf("\n\n\tFile successfully created.\n"); // User feedback
	pause();
	

}

int getPathInterface(string&fileName) {
	do {
		changeMode("Encrypt - Save File");
		cls();
		
		// Gets save directory
		fileName = saveFile();
		
		if (fileName == "1")
			return ABORT;

		createFile(fileName);
		if (!fileExists(fileName))
			if (error("File could not be created. Could not obtain permissions. Please select a new directory."))
				return ABORT;


	} while (!fileExists(fileName)); // While the file cannot be created for some reason
	return CONTINUE;
}

int passwordPromptOutput(string fileName, vector<vector<unsigned long long>> key) {
	string password, temp;
	do {
		changeMode("Encrypt - Enter Password");
		cls();
		capsLockWarning();
		printf("\tEnter password: ");

		// Initializes the interface for input
		password = enterPassword();

		printf("\n\tConfirm your password: ");
		temp = enterPassword();

		if (password != temp)
			if (error("\n\n\tPasswords mismatch. Please try again.")) {
				remove(fileName.c_str()); // Deletes the file in progress and exits to the main menu
				return ABORT;
			}

		
	} while (password != temp);

	// Outputs the flag and the encrypted key to the file
	outputLine(fileName, "Yes");
	outputLine(fileName, aesEncrypt(keyOutputString(key), password));

	return CONTINUE;
}