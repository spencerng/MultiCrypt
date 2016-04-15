#include "Headers/MatrixMath.h"
#pragma warning(disable:4018)

vector< vector<unsigned long long> > toMMatrix(vector< vector<unsigned long long> > A, int row, int column) {
	int m = 0, n = 0;
	vector< vector<unsigned long long> > mMatrix(A.size() - 1, vector<unsigned long long>(A.size() - 1));

	
	for (int i = 0; i < A.size(); i++) {
		if (i != row) {
			for (int j = 0; j < A.size(); j++) {
				if (j != column) {
					mMatrix[m][n] = A[i][j];
					n++;
				}
			}

			// Increments position in output matrix while the row/column is not in the input
			m++;
			n = 0;

		}

	}
	return mMatrix;
}


int det(vector< vector<unsigned long long> > A) {
	unsigned int determinant = 0;

	if (A.size() == 2)
		determinant = int(A[0][0] * A[1][1] - A[0][1] * A[1][0]);

	else for (int j = 0; j < A.size(); j++)
		determinant +=(int) A[0][j] * (unsigned)cofactor(A, 0, j);


	return determinant;
}


int cofactor(vector< vector<unsigned long long> > A, int row, int column) {
	int cof = int(pow(-1, row + column + 2)) * det(toMMatrix(A, row, column));
	return cof;
}

vector < vector<unsigned long long > > toCofMatrix(vector< vector<unsigned long long> > A) {
	vector< vector<unsigned long long> > cofMatrix(A.size(), vector<unsigned long long>(A[0].size()));

	for (int i = 0; i < cofMatrix.size(); i++)
		for (int j = 0; j < cofMatrix[0].size(); j++)
			cofMatrix[i][j] = cofactor(A, i, j);

	return cofMatrix;
}

vector< vector<unsigned long long> > toAdjMatrix(vector< vector<unsigned long long> > A) {

	return transpose(toCofMatrix(A));

}

vector< vector<unsigned long long> > inverseInt(vector< vector<unsigned long long> > A) {
	vector< vector<unsigned long long> > result = A;

	// Definition of 2 x 2
	if (A.size() == 2) {
		result[0][0] = A[1][1];
		result[0][1] = -1 * A[0][1];
		result[1][0] = -1 * A[1][0];
		result[1][1] = A[0][0];
	}

	// Recursive step
	else {
		result = toAdjMatrix(A);

		result = scalarMultiplyInt((1 / det(A)), result);

		return result;
	}

}

vector< vector<unsigned long long> > multiply(vector< vector<unsigned long long> > A, vector< vector<int> > B) {
	vector< vector<unsigned long long> > productMatrix(A.size(), vector<unsigned long long>(B[0].size(), 0));


	for (int i = 0; i < A.size(); i++)
		for (int j = 0; j < B[0].size(); j++)
			for (int m = 0; m < A[0].size(); m++)
				productMatrix[i][j] += A[i][m] * B[m][j];

	return productMatrix;
}

vector< vector<unsigned long long> > multiply(vector< vector<unsigned long long> > A, vector< vector<unsigned long long> > B) {
	vector< vector<unsigned long long> > productMatrix(A.size(), vector<unsigned long long>(B[0].size(), 0));


	for (int i = 0; i < A.size(); i++)
		for (int j = 0; j < B[0].size(); j++)
			for (int m = 0; m < A[0].size(); m++)
				productMatrix[i][j] += A[i][m] * B[m][j];

	return productMatrix;
}

vector< vector<unsigned long long> > transpose(vector< vector<unsigned long long> > A) {
	vector< vector<unsigned long long> > transMatrix(A[0].size(), vector<unsigned long long>(A.size()));
	for (int i = 0; i < transMatrix.size(); i++)
		for (int j = 0; j < transMatrix[0].size(); j++)
			transMatrix[i][j] = A[j][i];
	return transMatrix;
}

vector< vector<double> > scalarMultiply(double scalar, vector < vector<double> >A) {
	vector< vector<double> > product = A;
	for (int i = 0; i < product.size(); i++)
		for (int j = 0; j < product[0].size(); j++)
			product[i][j] *= scalar;
	return product;

}

vector< vector<unsigned long long> > scalarMultiplyInt(int scalar, vector < vector<unsigned long long> >A) {
	vector< vector<unsigned long long> > product = A;
	for (int i = 0; i < product.size(); i++)
		for (int j = 0; j < product[0].size(); j++)
			product[i][j] *= scalar;
	return product;

}
