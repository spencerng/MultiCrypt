#include "Headers/IO.h"

// define DOS for DOS-based OS (Windows) or UNIX (Linux, OS X, etc.)
#define DOS

int errors = 0;
string mode;
stringstream buffer;
string getString() {
	string input;
	getline(cin, input);
	return input;
}
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
bool isASCII(string s) {
	for (int i = 0; i < s.length(); i++)
		if (isASCII(s[i]) == false)
			return false;
	return true;
}

bool isASCII(char c) {
	if (c >= 32 && c < 127)
		return true;
	return false;


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

int error(string errorMessage, string fileName) {
	printf("\n\t%s\n\n", errorMessage.c_str());
	errors++;

	if (errors >= 3) {
		char choice;
		isValidCharInput("\tWould you like to (c)ontinue or (q)uit to the main menu?", { 'c','q' }, choice);
		if (choice == 'c') {
			cls();
			return CONTINUE;
		}
		else {
			remove(fileName.c_str());
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

//void inputMatrix(vector< vector<int> >& matrix) {
//	for (int i = 0; i < matrix.size(); i++)
//		for (int j = 0; j < matrix[0].size(); j++)
//			cin >> matrix[i][j];
//
//}
//
//void printMatrix(vector< vector<double> > A) {
//	for (int i = 0; i < A.size(); i++) {
//		cout << setprecision(3);
//		for (int j = 0; j < A[0].size(); j++)
//			cout << setw(15) << A[i][j];
//		cout << endl;
//	}
//}
//
//void printMatrix(vector< vector<int> > A) {
//	for (int i = 0; i < A.size(); i++) {
//		for (int j = 0; j < A[0].size(); j++)
//			cout << setw(10) << A[i][j];
//		cout << endl;
//	}
//	return;
//}
//
//void printMatrix(vector< vector<unsigned long long> > A) {
//	for (int i = 0; i < A.size(); i++) {
//		for (int j = 0; j < A[0].size(); j++)
//			cout << setw(40) << A[i][j];
//		cout << endl;
//	}
//	return;
//}

void cls() {
#ifdef DOS
	system("cls");
#endif
#ifdef UNIX
	system("clear");
#endif
	printTitle();
	printRight(mode);
	std::cout << buffer.str();

}

void passBuffer(stringstream input) {
	buffer.str(input.str());
}

void changeMode(string inMode) {
	mode = inMode;
}

void pause() {
	printf("\tPress any key to continue.");
	
	_getch();

}

//void print(const char* c) {
//	for (int i = 0; i < 4; i++)
//		cout << ' ';
//	cout << c;
//
//}

void isValidCharInput(string prompt, vector<char> validInputs, char &input) {
	bool incorrect = 0;
	while (1) {
		
		printf("%s\n", prompt.c_str());
		if (incorrect)
			printf("\tInvalid input detected. Please try again.\n");
		input = tolower(_getch());
		for (int i = 0; i < validInputs.size(); i++)
			if (input == validInputs[i])
				return;
		incorrect = 1;
		
		cls();
	}

}

void store(std::stringstream &ss, string text) {
	ss << text << endl;
}

void printStore(std::stringstream &ss, string text) {
	ss << text;
	printf("%s", text.c_str());
}

// Need to fix input for arrow/function/special keys, which also return an ASCII value
string enterPassword() {
	string password;
	int charsEntered = 0;
	printf("\t");
	unsigned char ch = _getch();
	while (ch != 10) { //character 10 is new line
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

		ch = _getch();
	}

	return password;
}

int restartCryptProgram() {
	playSong(JAMES_BOND);
	
	while (true) {
		changeMode("Main Menu");
		cls();
		char choice;
		errors = 0;
		playSong(JAMES_BOND);
		isValidCharInput(choices(), { '1','2','3','4' }, choice);

		if (choice == '1')

			encrypt();
		else if (choice == '2')
			decrypt();
		else if (choice == '3')
			toggleSound();
		else if (choice == '4') {
			changeMode("Exit Program");
			isValidCharInput("\tAre you sure you want to quit? (Y/N)\n", { 'y','n' }, choice);
			if (choice == 'y') {
				exitProgramSound();
				return 0;
			}
			
		}
		

	}

}