#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <string>
#include <ctime>
using namespace std;

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
	int determinant=0;

	if (A.size() == 2) 
		determinant = A[0][0] * A[1][1] - A[0][1] * A[1][0];
	
	else for (int j = 0; j < A.size(); j++) 
		determinant += pow(-1, j+2)*A[0][j] * (det(toMMatrix(A, j)));
	
	
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

vector< vector<int> > rref(vector< vector<int> > A) {
	vector< vector<int> > reducedMatrix(A.size(), vector<int>(A[0].size()));
	int index, temp;
	if (A.size() > A[0].size())
		index = A.size();
	else index = A[0].size();
	reducedMatrix = A;
	for (int i = 0; i < index; i++) {
		
		
		for (int k = 0; k < reducedMatrix.size()&& reducedMatrix[i][i] == 0; k++) {
			if (reducedMatrix[k][i] != 0) {
				for (int j = 0; j < reducedMatrix[0].size(); j++) {
					temp = reducedMatrix[i][j];
					reducedMatrix[i][j] = reducedMatrix[k][j];
					reducedMatrix[k][j] = temp;
				}
			}
		}
		
		if (reducedMatrix[i][i] != 1)
			for (int j = 0; j < reducedMatrix[0].size(); j++) 
				reducedMatrix[i][j] /= reducedMatrix[i][i];
		for (int k = 0; k < reducedMatrix.size(); k++) {
			if (reducedMatrix[k][j] != 0&&k!=i&&j!=i) {
				for (int j = 0; j < reducedMatrix[0].size(); j++)
					;
			}

		}
			
	}
		


	

	return reducedMatrix;

}
vector< vector<int> > inverse(vector< vector<int> > A) {
	vector< vector<int> > inverseMatrix(A.size(), vector<int>());

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

vector< char > toLowerCase (vector<char> charArray) {
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


	return encodedMatrix;
}

vector<char> stringToCharVec(string input) {
	vector<char> output(input.begin(), input.end());

	return output;

}

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