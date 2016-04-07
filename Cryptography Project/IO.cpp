#include "Headers/IO.h"

// define DOS for DOS-based OS (Windows) or UNIX (Linux, OS X, etc.)
#define DOS

int errors = 0;
string mode;

string multiLineInput() {
	string input = "";
	char lastCh = ' ';
	int lineLength = 0;
	char ch;
	while (1) {
		ch = _getch();
		if (ch == 13) {
			if (lastCh == 13)
				break;
			input += "\n\t";
			printf("\n\t");
			lineLength = 0;

		}
		else if (ch == 8) {
			if (lineLength != 0) {
				printf("\b \b");
				input.pop_back();
				lineLength--;
			}
			
		}
		else {
			printf("%c", ch);
			input.push_back(ch);
			lineLength++;
		}
		lastCh = ch;
	}
	input.pop_back();
	input.pop_back();
	return input;
}


void capsLockWarning(){
	if (GetKeyState(VK_CAPITAL))
		printf("\tWarning: Caps Lock is currently on.\n\n");
	
}

int error(string errorMessage) {
	printf("\n\t%s\n\n", errorMessage.c_str());
	errors++;
	
	if (errors >= 3) {
		char choice;
		isValidCharInput("\tWould you like to (c)ontinue or (q)uit to the main menu?\n", { 'c','q' }, choice);
		if (choice == 'c') {
			cls();
			return CONTINUE;
		}
		else {
			return ABORT;
		}
	}
	pause();
	
	cls();
	return CONTINUE;

}

string choices() {
	std::stringstream buffer;
	buffer << "\t(1) Encrypt a message\n";
	buffer << "\t(2) Decrypt a message\n";
	buffer << "\t(3) Turn Music " << (getMusicStatus() ? ("Off") : ("On")) << endl;
	buffer << "\t(4) Exit the program\n";
	
	return buffer.str();
}

void cls() {
#ifdef DOS
	system("cls");
#endif
#ifdef UNIX
	system("clear");
#endif
	printTitle();
	printRight(mode);
	

}

void resetErrors() {
	errors = 0;
}

void changeMode(string inMode) {
	mode = inMode;
}

void pause() {
	printf("\tPress any key to continue.");
	
	_getch();

}

void isValidCharInput(string prompt, vector<char> validInputs, char &input) {
	bool incorrect = 0;
	while (1) {
		if (incorrect)
			printf("\tInvalid input detected. Please try again.\n\n");
		printf("%s\n", prompt.c_str());
		showCursor(0);
		input = tolower(_getch());
		for (int i = 0; i < validInputs.size(); i++)
			if (input == validInputs[i]) {
				showCursor(1);
				return;
			}
		incorrect = 1;
		
		cls();
	}

}

// Need to fix input for arrow/function/special keys, which also return an ASCII value
string enterPassword() {
	string password;
	int charsEntered = 0;
	printf("\t");
	char ch;
	do { 
		ch = _getch();
		
		while (ch == 8) { // character 8 is backspace
			if (charsEntered != 0) { // Checks if there is anything to delete
				password.pop_back();
				printf("\b \b");
				charsEntered--;
			}
			ch = getch();
		}
		if (ch == 13)
			break;
		
		if (isprint(ch)) {
			charsEntered++;
			password.push_back(ch);
			printf("*");
		}

		
		
	} while (ch != 13);//character 10 is new line

	return password;
}