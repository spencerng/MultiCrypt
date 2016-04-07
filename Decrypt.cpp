#include "Headers/Decrypt.h"


void decrypt() {
	playSong(MISSION_IMPOSSIBLE);
	string fileName;
	changeMode("Decrypt - Open File");
	cls();
	if (selectValidFile(fileName))
		return;
	
	bool hasPassword;
	string keyString, messageString;
	getFileProperties(fileName, hasPassword, keyString, messageString);
	
	if (hasPassword)
		if (decryptPassword(keyString))
			return;
	
	string decryptMessage = matrixToString(multiply(inverseInt(keyInputMatrix(keyString)), messageInputMatrix(messageString)));
	printf("\n\n\tYour decrypted message is:\n\n\t%s\n\n", decryptMessage.c_str());
	pause();
}

int decryptPassword(string& keyString) {
	bool retry = false;
	int incorrectTimes = 0;
	changeMode("Decrypt - Enter Password");
    do {
        try {
            cls();
			capsLockWarning();
			printf("\tThe file is encrypted using a password.\n\n\tEnter password: ");
            string password = enterPassword();
            keyString = aesDecrypt(keyString, password);
            retry = false;
        }
        catch (...) {
			if (incorrectTimes == 3) {
				printf("\n\n\tToo many guess attempts. Deleting file and shutting off computer...");
				exitProgramSound();
				Sleep(1000);
				remove(keyString.c_str());
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
		if (fileName == "1")
			return ABORT;
		if (/*!isTextFile(fileName) ||*/ !isValidFile(fileName)) {
			/*if (!isTextFile(fileName))
			printf("\t%s is not a path to a text file.\n\n", fileName.c_str());

			else*/ printf("\t%s is not a valid file created by this program. Are you sure it has not been modified?\n\n", fileName.c_str());
		if (error("Please select a new text file."))
			return ABORT;

		}
		cls();

	} while (!isValidFile(fileName) /*|| !isTextFile(fileName)*/);
	return CONTINUE;
}