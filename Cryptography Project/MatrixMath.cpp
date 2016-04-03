#include "Headers/MatrixMath.h"
#include <cmath>
using std::vector;

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
			m++;
			n = 0;

		}

	}
	return mMatrix;
}


int det(vector< vector<int> > A) {
	int determinant = 0;

	if (A.size() == 2)
		determinant = A[0][0] * A[1][1] - A[0][1] * A[1][0];

	else for (int j = 0; j < A.size(); j++)
		determinant += A[0][j] * cofactor(A, 0, j);


	return determinant;
}

int det(vector< vector<unsigned long long> > A) {
	int determinant = 0;

	if (A.size() == 2)
		determinant = A[0][0] * A[1][1] - A[0][1] * A[1][0];

	else for (int j = 0; j < A.size(); j++)
		determinant += A[0][j] * cofactor(A, 0, j);


	return determinant;
}

int cofactor(vector< vector<int> > A, int row, int column) {
	int cof = pow(-1, row + column + 2) * det(toMMatrix(A, row, column));
	return cof;
}

int cofactor(vector< vector<unsigned long long> > A, int row, int column) {
	int cof = pow(-1, row + column + 2) * det(toMMatrix(A, row, column));
	return cof;
}

vector < vector<int > > toCofMatrix(vector< vector<int> > A) {
	vector< vector<int> > cofMatrix(A.size(), vector<int>(A[0].size()));

	for (int i = 0; i < cofMatrix.size(); i++)
		for (int j = 0; j < cofMatrix[0].size(); j++)
			cofMatrix[i][j] = cofactor(A, i, j);

	return cofMatrix;
}

vector < vector<unsigned long long > > toCofMatrix(vector< vector<unsigned long long> > A) {
	vector< vector<unsigned long long> > cofMatrix(A.size(), vector<unsigned long long>(A[0].size()));

	for (int i = 0; i < cofMatrix.size(); i++)
		for (int j = 0; j < cofMatrix[0].size(); j++)
			cofMatrix[i][j] = cofactor(A, i, j);

	return cofMatrix;
}


vector< vector<int> > toAdjMatrix(vector< vector<int> > A) {

	return transpose(toCofMatrix(A));

}

vector< vector<unsigned long long> > toAdjMatrix(vector< vector<unsigned long long> > A) {

	return transpose(toCofMatrix(A));

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

	result = scalarMultiply((double(1) / det(A)), result);

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

vector< vector<unsigned long long> > inverseInt(vector< vector<unsigned long long> > A) {
	vector< vector<unsigned long long> > result = A;

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

vector< vector<int> > multiply(vector< vector<int> > A, vector< vector<int> > B) {
	vector< vector<int> > productMatrix(A.size(), vector<int>(B[0].size(), 0));


	for (int i = 0; i < A.size(); i++)
		for (int j = 0; j < B[0].size(); j++)
			for (int m = 0; m < A[0].size(); m++)
				productMatrix[i][j] += A[i][m] * B[m][j];

	return productMatrix;
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

vector< vector<int> > transpose(vector< vector<int> > A) {
	vector< vector<int> > transMatrix(A[0].size(), vector<int>(A.size()));
	for (int i = 0; i < transMatrix.size(); i++)
		for (int j = 0; j < transMatrix[0].size(); j++)
			transMatrix[i][j] = A[j][i];
	return transMatrix;
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

vector< vector<int> > scalarMultiplyInt(int scalar, vector < vector<int> >A) {
	vector< vector<int> > product = A;
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

vector< vector<double> > toFloatMatrix(vector < vector<int> >A) {
	vector< vector<double> > result(A.size(), vector<double>(A[0].size()));
	for (int i = 0; i < A.size(); i++)
		for (int j = 0; j < A.size(); j++)
			result[i][j] = (double)A[i][j];
	return result;

}

void modEntries(vector<  vector<int> >& matrix, int base) {
	for (int i = 0; i < matrix.size(); i++)
		for (int j = 0; j < matrix[0].size(); j++)
			matrix[i][j] = matrix[i][j] % base;


}