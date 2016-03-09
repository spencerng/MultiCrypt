#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <string>
#include <ctime>
using namespace std;

//Functions used for general matrix operations
	
	vector< vector<int> > toMMatrix(vector< vector<int> > A, int row, int column);
	// Creates the minor matrix of A across the first row and a given column
	// Used in the det and toCofMatrix functions

	int det(vector< vector<int> > A);
	// Uses cofactor expansion (and the minor matrix) to return the determinant of a given n x n matrix. Is recursive, and requires n! multiplications
	// Used to check if a given n x n is invertible. Also used in the toCofMatrix function

	vector< vector<int> > multiply(vector< vector<int> > A, vector< vector<int> > B);
	// Returns the product of a m x n matrix and a n x m matrix. Used to encrypt and decrypt messages	

	vector< vector<int> > scalarMultiply(double scalar, vector < vector<int> >A);
	// Used to multiply a m x n matrix by a scalar;
	

	vector< vector<int> > transpose(vector< vector<int> > A);
	// Returns the transpose of a m x n matrix. Will be used in the toAdjMatrix function.
	

	vector < vector<int > > toCofMatrix(vector< vector<int> > A);
	// Returns the cofactor matrix of a given matrix, utilizing determinant and minor matrix with a definition for a 2 x 2.
	// Used for the adjugate matrix. 

	vector< vector<int> > toAdjMatrix(vector< vector<int> > A);
	// Calculates the adjugate matrix, or the transpose of the cofactor matrix.  

	vector< vector<double> > inverse(vector< vector<int> > A);
	// Calculates the inverse of a matrix, equal to Adj(A) * (1/det(A)).  
	vector< vector<int> > inverseInt(vector< vector<int> > A);


vector< vector<int> > randomMatrix();
// Generates a random n x n invertible matrix. Could be optimized for a determinant of 1 to eliminate error.

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

char printChoices();
// Prompts for input at the beginning of the program

//Further functions will be needed for file I/O. Main function will need a good user interface with additional features as necessary.

int main() {
	
	while (true) {
		

		char choice = printChoices();
		system("cls");
		int sizeI, sizeJ, size, entry;
		
		if (choice == '9')
			debugRandom();
		
		if (choice == '8'){
			
			cout << "Please enter your message.";
			
			string input;
			
			getline(cin, input);
			vector<char> output = stringToCharVec(input);
			for (int i = 0; i < output.size(); i++)
				cout << input.size();
			system("pause");
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
		else {
			cout << "Invalid input. Please try again.\n\n";
			system("pause");
		}

		
	}

	return 0;
}

vector< vector<int> > toMMatrix(vector< vector<int> > A, int row, int column) {
	int m = 0, n = 0;
	vector< vector<int> > mMatrix(A.size() - 1, vector<int>(A.size() - 1));
	for (int i = 0; i < A.size(); i++) {
		if (i != row) {
			for (int j = 0; j < A.size(); j++) {
				if (j != column) {
					mMatrix[m][n] = A[i][j];
					n++;
				}
			}
			m++;
			n = 0;

		}
		
	}
	return mMatrix;
}

int cofactor(vector< vector<int> > A, int row, int column) {
	int cof = pow(-1, row + column + 2) * det(toMMatrix(A, row, column));
	return cof;
}

int det(vector< vector<int> > A) {
	int determinant = 0;

	if (A.size() == 2)
		determinant = A[0][0] * A[1][1] - A[0][1] * A[1][0];

	else for (int j = 0; j < A.size(); j++)
		determinant += A[0][j] * cofactor(A, 0, j);


	return determinant;
}

vector< vector<int> > multiply(vector< vector<int> > A, vector< vector<int> > B) {
	vector< vector<int> > productMatrix(A.size(), vector<int>(B[0].size(), 0));
	

	for (int i = 0; i < A.size(); i++)
		for (int j = 0; j < B[0].size(); j++)
			for (int m = 0; m < A[0].size(); m++)
				productMatrix[i][j] += A[i][m] * B[m][j];

	return productMatrix;
}

vector< vector<int> > randomMatrix() {
	srand(time(NULL));
	int n = rand() % 7 + 1;
	vector< vector<int> > randomM(3, vector<int>(3));
	randomM[0][0] = 8 * n*n + 8 * n;
	randomM[0][1] = 2 * n + 1;
	randomM[0][2] = 4 * n;
	randomM[1][0] = 4 * n*n + 4 * n;
	randomM[1][1] =  n + 1;
	randomM[1][2] = 2 * n + 1;
	randomM[2][0] = 4 * n*n + 4 * n + 1;
	randomM[2][1] = n;
	randomM[2][2] = 2*n - 1;
	
	return randomM;
}

vector< vector<int> > unimodMatrix(int n) {
	vector< vector<int> > randomM(3, vector<int>(3));
	randomM[0][0] = 8 * n*n + 8 * n;
	randomM[0][1] = 2 * n + 1;
	randomM[0][2] = 4 * n;
	randomM[1][0] = 4 * n*n + 4 * n;
	randomM[1][1] = n + 1;
	randomM[1][2] = 2 * n + 1;
	randomM[2][0] = 4 * n*n + 4 * n + 1;
	randomM[2][1] = n;
	randomM[2][2] = 2 * n - 1;

	return randomM;
}

void modEntries(vector<  vector<int> >& matrix,int base) {
	for (int i = 0; i < matrix.size(); i++)
		for (int j = 0; j < matrix[0].size(); j++)
			matrix[i][j] = matrix[i][j] % base;


}

vector< vector<int> > moreRandomMatrix() {
	srand(time(NULL));
	vector< vector<int> > randomM;
	do {
		randomM = randomMatrix();
		int iterations = rand() % 20 + 10;
		for (int i = 0; i < iterations; i++) {
			int isInverted = rand();
			if (isInverted % 2 == 0)
				randomM = inverseInt(randomM);
			randomM = multiply(randomM, randomMatrix());


		}
	} while (inverse(randomM)[0][0] > 1000000 || inverse(randomM)[0][0] < -1000000);
	

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

// I believe this works. Not sure, however.
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

vector< vector<int> > transpose(vector< vector<int> > A) {
	vector< vector<int> > transMatrix(A[0].size(), vector<int>(A.size()));
	for (int i = 0; i < transMatrix.size(); i++)
		for (int j = 0; j < transMatrix[0].size(); j++)
			transMatrix[i][j] = A[j][i];
	return transMatrix;
}

vector < vector<int > > toCofMatrix(vector< vector<int> > A) {
	vector< vector<int> > cofMatrix(A.size(), vector<int>(A[0].size()));

	for (int i = 0; i < cofMatrix.size(); i++)
		for (int j = 0; j < cofMatrix[0].size(); j++)
			cofMatrix[i][j] = cofactor(A, i, j);

	return cofMatrix;
}

vector< vector<double> > scalarMultiply(double scalar, vector < vector<double> >A) {
	vector< vector<double> > product = A;
	for (int i = 0; i < product.size(); i++)
		for (int j = 0; j < product[0].size(); j++)
			product[i][j] *= scalar;
	return product;

}

vector< vector<int> > scalarMultiplyInt(int scalar, vector < vector<int> >A) {
	vector< vector<int> > product = A;
	for (int i = 0; i < product.size(); i++)
		for (int j = 0; j < product[0].size(); j++)
			product[i][j] *= scalar;
	return product;

}

vector< vector<int> > toAdjMatrix(vector< vector<int> > A) {

	return transpose(toCofMatrix(A));

}

vector< vector<double> > toFloatMatrix(vector < vector<int> >A) {
	vector< vector<double> > result(A.size(), vector<double>(A[0].size()));
	for (int i = 0; i < A.size(); i++)
		for (int j = 0; j < A.size(); j++)
			result[i][j] = (double)A[i][j];
	return result;

}

vector< vector<double> > inverse(vector< vector<int> > A) {
	vector< vector<double> > result = toFloatMatrix(A);

	if (A.size() == 2) {
		result[0][0] = A[1][1];
		result[0][1] = -1 * A[0][1];
		result[1][0] = -1 * A[1][0];
		result[1][1] = A[0][0];
	}
	else result = toFloatMatrix(toAdjMatrix(A));

	result = scalarMultiply(((double)1 / det(A)), result);

	return result;

}
vector< vector<int> > inverseInt(vector< vector<int> > A) {
	vector< vector<int> > result = A;

	if (A.size() == 2) {
		result[0][0] = A[1][1];
		result[0][1] = -1 * A[0][1];
		result[1][0] = -1 * A[1][0];
		result[1][1] = A[0][0];
	}
	else result = toAdjMatrix(A);

	result = scalarMultiplyInt((1 / det(A)), result);

	return result;

}

void debugRandom(){
	
	vector< vector<int> > debugMatrix = moreRandomMatrix();
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
