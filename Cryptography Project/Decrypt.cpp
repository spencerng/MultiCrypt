#include "Headers/Decrypt.h"


void decrypt() {
	playSong(MISSION_IMPOSSIBLE);
	
	changeMode("Decrypt - Open File");
	cls();

	string fileName;
	if (selectValidFile(fileName))
		// If ABORT is returned
		return;
	
	bool hasPassword;
	string keyString, messageString;
	getFileProperties(fileName, hasPassword, keyString, messageString);
	
	if (hasPassword)
		if (decryptPassword(keyString))
			return;
	
	/* Converts the string key and message to a matrix, computes the inverse of the key, 
	multiplies the two together, then converts the plaintext matrix to a string*/
	string decryptMessage = matrixToString(multiply(inverseInt(keyInputMatrix(keyString)), messageInputMatrix(messageString)));

	// %s signifies a (legacy) string variable 
	printf("\n\n\tYour decrypted message is:\n\n\t%s\n\n", decryptMessage.c_str());
	pause();
}

int decryptPassword(string& keyString) {
	bool retry = false;
	int incorrectTimes = 0;
	changeMode("Decrypt - Enter Password");
    do {
		// try-catch statement catches the exception throw when the password is incorrect
        try {
            cls();
			capsLockWarning();
			printf("\tThe file is encrypted using a password.\n\n\tEnter password: ");
            string password = enterPassword();
            keyString = aesDecrypt(keyString, password);
            retry = false;
        }

		// Ellipses catch all exceptions
        catch (...) {

			// Force-shut the system when the password is entered incorrectly 3 or more times
			if (incorrectTimes == 3) {
				printf("\n\n\tToo many guess attempts. Deleting file and shutting off computer...");
				exitProgramSound(); // Explosion
				Sleep(1000);
				remove(keyString.c_str()); // Deletes the file
				system("shutdown -s -f -t 00");
			}
			if (error("Incorrect password. " + to_string(3 - incorrectTimes) + " more tries remaining."))
				return ABORT;
			incorrectTimes++;
            retry = true;

        }
		
    } while (retry);
	return CONTINUE;

}

int selectValidFile(string& fileName) {
	do {
		
		fileName = selectFile();

		// selectFile's version of returning ABORT
		if (fileName == "1")
			return ABORT;
		if (!isValidFile(fileName)) {

			printf("\t%s is not a valid file created by this program. Are you sure it has not been modified?\n\n", fileName.c_str());
			if (error("Please select a new text file."))
				return ABORT;
		}
		cls();

	} while (!isValidFile(fileName));
	return CONTINUE;
}