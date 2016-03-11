#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <string>
#include <ctime>
#include "MatrixMath.h"
#include "KeyGenerate.h"
using namespace std;

vector< char > toLowerCase(vector<char> charArray);
// Converts a given char vector with mixed case letters to all lowercase

vector< vector<int> > toNumbMatrix(vector<char> message);
// Converts a char array to a 3 x k matrix to represent a message in numerical form. Partially written.

vector<char> stringToCharVec(string input);
// Converts a string to a vector filled with char entries. Has not been tested.

void printMatrix(vector< vector<int> > A);
void printMatrix(vector< vector<double> > A);
// Prints any given matrix, with formatting.

void inputMatrix(vector< vector<int> >& matrix);
// User inputs int values for any m x n matrix

void cls();
// Replaces the need for system call to clear the screen. Another function to replace system("pause") should be created

void debugMath();
//Allows user to input matrix to displays the result of transpose, cofactor, and inverse

void debugRandom();
// Generates a random unimodular matrix and displays it, along with debugMath functions

void debugString();

char printChoices();
// Prompts for input at the beginning of the program

string getString();

//Further functions will be needed for file I/O. Main function will need a good user interface with additional features as necessary.

int main() {
	
	while (true) {
		

		char choice = printChoices();
		system("cls");
		int sizeI, sizeJ, size, entry;
		
		if (choice == '9')
			debugRandom();
		
		if (choice == '8'){
			
			debugString();
		}
		if (choice == '7') {
			
			debugMath();

		}
		if (choice == '6') {
			cout << "Enter the size of the m x n matrix A: ";

			cin >> sizeI >> sizeJ;
			vector< vector<int> > A(sizeI, vector<int> (sizeJ));
			for (int i = 0; i < A.size(); i++) {
				for (int j = 0; j < A[0].size(); j++) {
					cin >> entry;
					
					// 
					A[i][j] = entry;

				}

			}
			cout << "Enter the size of B: ";
			cin >> sizeI >> sizeJ;
			vector< vector<int> > B(sizeI, vector<int>(sizeJ));
			for (int i = 0; i < B.size(); i++) {
				for (int j = 0; j <B[0].size(); j++) {
					cin >> entry;
					B[i][j] = entry;

				}

			}
			cout << endl << "A * B =\n\n";
			vector< vector<int> > product = multiply(A, B);
			for (int i = 0; i < product.size(); i++) {
				for (int j = 0; j < product[0].size(); j++) {
					cout << setw(4);
					cout << product[i][j] << " ";
					

				}
				cout << endl;

			}
			
			system("pause");
		}
		if (choice == '3') {
		}
		if (choice == '4') {

		}
		if (choice == '2') {
			string encryptedMessage;
			toNumbMatrix(stringToCharVec(encryptedMessage));
		}
		if (choice == '5') {
			return 0;
		}

		
	}

	return 0;
}

void modEntries(vector<  vector<int> >& matrix,int base) {
	for (int i = 0; i < matrix.size(); i++)
		for (int j = 0; j < matrix[0].size(); j++)
			matrix[i][j] = matrix[i][j] % base;


}

vector< char > toLowerCase(vector<char> charArray) {
	vector<char> output = charArray;
	for (int i = 0; i < charArray.size(); i++) {
		if (output[i] >= 'A' && output[i] <= 'Z')
			output[i] = tolower(output[i]);
	}

	return output;
}

//Not finished
vector< vector<int> > toNumbMatrix(vector<char> message) {
	int dimension = message.size();
	while (dimension % 3 != 0)
		dimension++;
	vector< vector<int> > encodedMatrix(3, vector<int>(dimension / 3));

	message = toLowerCase(message);
	char alphabet[27] = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z',' ' };
	int pos = 0;
	for (int i = 0; i < dimension / 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (pos >= message.size())
				encodedMatrix[j][i] = ' ';
			else {
				int alphPos = 0;
				do {

					alphPos++;
				} while (message[pos] != alphabet[alphPos]);
				encodedMatrix[j][i] = alphabet[alphPos];

			}

		}
		pos++;

	}
	
	return encodedMatrix;
}

vector<char> stringToCharVec(string input) {
	vector<char> output;
	for (int i = 0; i < input.size(); i++)
		output.push_back(input[i]);
	return output;

}

void inputMatrix(vector< vector<int> >& matrix) {
	for (int i = 0; i < matrix.size(); i++)
		for (int j = 0; j < matrix[0].size(); j++)
			cin >> matrix[i][j];

}

void printMatrix(vector< vector<int> > A) {
	for (int i = 0; i < A.size(); i++) {
		for (int j = 0; j < A[0].size(); j++)
			cout << setw(10) << A[i][j];
		cout << endl;
	}
	return;
}

void printMatrix(vector< vector<double> > A) {
	for (int i = 0; i < A.size(); i++) {
		cout << setprecision(3);
		for (int j = 0; j < A[0].size(); j++)
			cout << setw(15) << A[i][j];
		cout << endl;
	}

}

void cls() {
	int i = 100;
	while (i != 0) {
		cout << endl;
		i--;
	}


}

vector< vector<double> > toFloatMatrix(vector < vector<int> >A) {
	vector< vector<double> > result(A.size(), vector<double>(A[0].size()));
	for (int i = 0; i < A.size(); i++)
		for (int j = 0; j < A.size(); j++)
			result[i][j] = (double)A[i][j];
	return result;

}



void debugRandom(){
	
	vector< vector<int> > debugMatrix = randomMatrix();
	printMatrix(debugMatrix);
			

			

	cout << "Determinant: " << det(debugMatrix) << endl;
	cout << "Transpose: \n";
	printMatrix(transpose(debugMatrix));
	cout << endl;
	cout << "Cofactor: \n";
	printMatrix(toCofMatrix(debugMatrix));
	cout << endl;
	cout << "Inverse: \n";
	printMatrix(inverse(debugMatrix));
	
	
}

void debugMath() {
	cout << "Enter the size of an n x n matrix: ";
	int sizeI;
	cin >> sizeI;
	vector< vector<int> > debugMatrix(sizeI, vector<int>(sizeI));
	
	
	cout << "\nEnter the " << sizeI << " x " << sizeI << " matrix.\n";

	inputMatrix(debugMatrix);



	cout << "Determinant: " << det(debugMatrix) << endl;
	cout << "Transpose: \n";
	printMatrix(transpose(debugMatrix));
	cout << endl;
	cout << "Cofactor: \n";
	printMatrix(toCofMatrix(debugMatrix));
	cout << endl;
	cout << "Inverse: \n";
	printMatrix(inverse(debugMatrix));
	system("pause");

}

char printChoices() {
	cout << "(1) Encode a message\n";
	cout << "(2) Decode a message\n";
	cout << "(3) Generate an encryption key\n";
	cout << "(4) Generate a decryption key\n";
	cout << "(5) Exit the program\n";
	cout << "(6) Multiply two matrices\n";
	cout << "(7) Debug Math\n";
	cout << "(8) Debug String to Matrix\n";
	cout << "(9) Debug Random Matrix Generator\n";

	char choice = getchar();
	return choice;

}

void encodeMessage() {

}

void decodeMessage() {

}

string getString() {
	string input;
	cin.ignore();
	getline(cin, input);
	return input;
}

void debugString() {
	cout << "Please enter your message.\n";

	string input = getString();

	vector<char> output = stringToCharVec(input);
	for (int i = 0; i < output.size(); i++)
		cout << input[i];
	cout << endl;
	system("pause");

}
