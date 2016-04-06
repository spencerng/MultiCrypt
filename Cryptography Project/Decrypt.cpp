#include "Headers/Decrypt.h"


void decrypt() {
	playSong(MISSION_IMPOSSIBLE);
	string fileName;
	changeMode("Decrypt - Open File");
	selectValidFile(fileName);
	
	bool hasPassword;
	string keyString, messageString;
	getFileProperties(fileName, hasPassword, keyString, messageString);
	
	if (hasPassword)
		decryptPassword(keyString);
	
	string decryptMessage = matrixToString(multiply(inverseInt(keyInputMatrix(keyString)), messageInputMatrix(messageString)));
	printf("\n\n\tYour decrypted message is:\n\t%s\n\n", decryptMessage.c_str());
	pause();
}

void decryptPassword(string& keyString) {
	bool retry = false;
	int incorrectTimes = 0;
	changeMode("Decrypt - Enter Password");
    do {
        try {
            cls();
			printf("\tThe file is encrypted using a password.\n\tEnter password: ");
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
            error("Incorrect password. " + to_string(3-incorrectTimes) + " more tries remaining.");
			incorrectTimes++;
            retry = true;

        }
		
    } while (retry);
    

}

void selectValidFile(string& fileName) {
	do {
		
		fileName = selectFile();
		if (/*!isTextFile(fileName) ||*/ !isValidFile(fileName)) {
			/*if (!isTextFile(fileName))
			printf("\t%s is not a path to a text file.\n\n", fileName.c_str());

			else*/ printf("\t%s is not a valid file created by this program. Are you sure it has not been modified?\n\n", fileName.c_str());
			error("Please select a new text file.");

		}
		cls();

	} while (!isValidFile(fileName) /*|| !isTextFile(fileName)*/);

}