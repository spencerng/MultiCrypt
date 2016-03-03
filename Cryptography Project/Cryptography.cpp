#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <string>
#include <ctime>
using namespace std;

//Functions used for general matrix multiplication
	
	vector< vector<int> > toMMatrix(vector< vector<int> > A, int column);
	// Creates the minor matrix of A across the first row and a given column
	// Used in the det and toCofMatrix functions

	int det(vector< vector<int> > A);
	// Uses cofactor expansion (and the minor matrix) to return the determinant of a given n x n matrix. Is recursive, and requires n! multiplications
	// Used to check if a given n x n is invertible. Also used in the toCofMatrix function

	vector< vector<int> > multiply(vector< vector<int> > A, vector< vector<int> > B);
	// Returns the product of a m x n matrix and a n x m matrix. Used to encrypt and decrypt messages

	vector< vector<int> > transpose(vector< vector<int> > A);
	// Returns the transpose of a m x n matrix, has not been written yet. Will be used in the toAdjMatrix function.

	vector < vector<int > > toCofMatrix(vector< vector<int> > A);
	// Returns the cofactor matrix of a given matrix, utilizing determinant and minor matrix with a definition for a 2 x 2.
	// Used for the adjugate matrix, not yet written.

	vector< vector<int> > toAdjMatrix(vector< vector<int> > A);
	// Calculates the adjugate matrix, or the transpose of the cofactor matrix. Not yet written.

	vector< vector<int> > inverse(vector< vector<int> > A);
	// Calculates the inverse of a matrix, equal to Adj(A) * (1/det(A)). Not yet written.


vector< vector<int> > randomMatrix(int size);
// Generates a random n x n invertible matrix. Could be optimized for a determinant of 1 to eliminate error.

vector< char > toLowerCase(vector<char> charArray);
// Converts a given char vector with mixed case letters to all lowercase

vector< vector<int> > toNumbMatrix(vector<char> message);
// Converts a char array to a 3 x k matrix to represent a message in numerical form. Partially written.

vector<char> stringToCharVec(string input);
// Converts a string to a vector filled with char entries. Has not been tested.

void printMatrix(vector< vector<int> > A);
// Prints any given matrix, with formatting.

//Further functions will be needed for file I/O. Main function will need a good user interface with additional features as necessary.

int main() {
	
	while (true) {
		cout << "(1) Encode a message\n";
		cout << "(2) Decode a message\n";
		cout << "(3) Generate an encryption key\n";
		cout << "(4) Generate a decryption key\n";
		cout << "(5) Exit the program";
		cout << "(6) Calculate the determinant of a matrix\n";
		char choice;
		cin >> choice;
		system("cls");
		int sizeI, sizeJ, size, entry;
		
		
		
		if (choice == '1')
		{
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

			int element;
			cout << "Please enter the number of columns in your encryption key: ";
			cin >> size;
			cout << "\n Enter your encryption key, in " << size << " rows of " << size << " numbers, each followed by a space.\n";
			vector< vector<int> > encryptionMatrix;
			for (int i = 0; i < size; i++) {
				for (int j = 0; j < size; j++) {
					cin >> element;
					encryptionMatrix[i][j] = element;
				}

			}

			vector< vector<int> > decryptionMatrix = inverse(encryptionMatrix);
			system("cls");

			cout << "Decryption Matrix: \n\n";
			for (int i = 0; i < size; i++) {
				for (int j = 0; j < size; j++) {
					
					cout << decryptionMatrix[i][j] << " ";
				}
				cout << endl;
			}

			do {
				cout << "\nWould you like to decrypt a matrix using this key? (Y/N)\n\n";
				cin >> choice;
				if (choice != 'y' && choice != 'Y' && choice != 'n' && choice != 'N')
					cout << "Invalid choice. Please try again.\n";
				system("pause");
				system("cls");


			} while (choice != 'y' && choice != 'Y' && choice != 'n' && choice != 'N');
			if (choice == 'n' || choice == 'N')
				;
		}
		if (choice == '2') {
			string encryptedMessage;
			toNumbMatrix(stringToCharVec(encryptedMessage));
		}
		if (choice == '5') {
			return 0;
		}
		else {
			cout << "Invalid input. Please try again.\n\n";
			system("pause");
		}

		
	}

	return 0;
}

vector< vector<int> > toMMatrix(vector< vector<int> > A, int column) {
	int m = 0, n = 0;
	vector< vector<int> > mMatrix(A.size() - 1, vector<int>(A.size() - 1));
	for (int i = 1; i < A.size(); i++) {
		for (int j = 0; j < A.size(); j++) {
			if (j != column) {
				mMatrix[m][n] = A[i][j];
				n++;
			}
		}
		m++;
		n = 0;
	}
	return mMatrix;
}

int det(vector< vector<int> > A) {
	int determinant = 0;

	if (A.size() == 2)
		determinant = A[0][0] * A[1][1] - A[0][1] * A[1][0];

	else for (int j = 0; j < A.size(); j++)
		determinant += pow(-1, j + 2)*A[0][j] * (det(toMMatrix(A, j)));


	return determinant;
}

vector< vector<int> > multiply(vector< vector<int> > A, vector< vector<int> > B) {
	vector< vector<int> > productMatrix(A.size(), vector<int>(B[0].size(), 0));
	int m = 0, n = 0;

	for (int i = 0; i < A.size(); i++)
		for (int j = 0; j < B[0].size(); j++)
			for (int m = 0; m < A[0].size(); m++)
				productMatrix[i][j] += A[i][m] * B[m][j];

	return productMatrix;
}

vector< vector<int> > inverse(vector< vector<int> > A) {
	vector< vector<int> > inverseMatrix(A.size(), vector<int>());

	//Needs to be done, will be based on rref

	return inverseMatrix;
}

vector< vector<int> > randomMatrix(int size) {
	srand(time(NULL));
	vector< vector<int> > randomM(size, vector<int>(size));
	do {

		for (int i = 0; i < size; i++)
			for (int j = 0; j < size; j++)
				randomM[i][j] = rand() % 100 + 1;
	} while (det(randomM) == 0);
	return randomM;
}
vector< char > toLowerCase(vector<char> charArray) {
	vector<char> output = charArray;
	for (int i = 0; i < charArray.size(); i++) {
		if (output[i] >= 'A' && output[i] <= 'Z')
			output[i] = tolower(output[i]);
	}

	return output;
}
vector< vector<int> > toNumbMatrix(vector<char> message) {
	int dimension = message.size();
	while (dimension % 3 != 0)
		dimension++;
	vector< vector<int> > encodedMatrix(3, vector<int>(dimension));

	message = toLowerCase(message);
	char alphabet[27] = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z',' ' };

	// Incomplete. Needs to substitute each character in message for a number (index position?) and construct an appropriate 3 x m matrix
	return encodedMatrix;
}

// I believe this works. Not sure, however.
vector<char> stringToCharVec(string input) {
	vector<char> output(input.begin(), input.end());

	return output;

}

void printMatrix(vector< vector<int> > A) {
	for (int i = 0; i < A.size(); i++) {
		for (int j = 0; j < A[0].size(); j++)
			cout << setw(3) << A[i][j];
		cout << endl;
	}

}