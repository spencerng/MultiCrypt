#include "Headers/IO.h"

// define DOS for DOS-based OS (Windows) or UNIX (Linux, OS X, etc.)
#define DOS

string getString() {
	string input;
	getline(cin, input);
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

string choices() {
	std::stringstream buffer;
	buffer << "\t(1) Encrypt a message\n";
	buffer << "\t(2) Decrypt a message\n";
	buffer << "\t(3) Turn Music " << (getMusicStatus() ? ("Off") : ("On")) << endl;
	buffer << "\t(4) Exit the program\n";
	
	return buffer.str();
}

char getChar() {
	char input;
	cin >> input;
	return input;
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

}

void pause() {
	cout << "Press any key to continue.";
	
	_getch();

}

//void print(const char* c) {
//	for (int i = 0; i < 4; i++)
//		cout << ' ';
//	cout << c;
//
//}

void isValidCharInput(string prompt, vector<char> validInputs, char &input) {
	while (1) {
		cls();
		cout << prompt << endl;
		
		input = tolower(_getch());
		for (int i = 0; i < validInputs.size(); i++)
			if (input == validInputs[i])
				return;


		cout << "\tInvalid input detected. Please try again.\n\t";
		pause();
		for (int i = 0; i < 144; i++)
			cout << '\b';
		for (int i = 0; i < 72; i++)
			cout << ' ';
		for (int i = 0; i < 72; i++)
			cout << '\b';
		
	}

}

void store(std::stringstream &ss, string text) {
	ss << text << endl;
}

void printStore(std::stringstream &ss, string text) {
	ss << text;
	cout << text;
}

// Need to fix input for arrow/function/special keys, which also return an ASCII value
string enterPassword() {
	string password;
	int charsEntered = 0;
	cout << '\t';
	unsigned char ch = _getch();
	while (ch != 10) { //character 10 is new line
		while (ch == 8) { // character 8 is backspace
			if (charsEntered != 0) { // Checks if there is anything to delete
				password.pop_back();
				cout << '\b' << ' ' << '\b'; // Moves cursor backwards, enters a blank character, then moves the cursor backwards again to prepare for overwrite
				charsEntered--;
			}
			ch = getch();
		}
		if (ch == 13)
			break;

		if (isprint(ch)) {
			charsEntered++;
			password.push_back(ch);
			cout << '*';
		}

		ch = _getch();
	}

	return password;
}