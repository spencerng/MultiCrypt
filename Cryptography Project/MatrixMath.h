#ifndef MATRIXMATH_H_INCLUDED
#define MATRIXMATH_H_INCLUDED
#include <vector>
using std::vector;

 vector< vector<int> > toMMatrix(vector< vector<int> > A, int row, int column);
// Creates the minor matrix of A across the first row and a given column
// Used in the det and toCofMatrix functions

int det(vector< vector<int> > A);
// Uses cofactor expansion (and the minor matrix) to return the determinant of a given n x n matrix. Is recursive, and requires n! multiplications
// Used to check if a given n x n is invertible. Also used in the toCofMatrix function

vector< vector<int> > multiply(vector< vector<int> > A, vector< vector<int> > B);
// Returns the product of a m x n matrix and a n x m matrix. Used to encrypt and decrypt messages	

vector< vector<double> > scalarMultiply(double scalar, vector < vector<double> >A);
// Used to multiply a m x n matrix by a scalar;

vector< vector<int> > scalarMultiplyInt(int scalar, vector < vector<int> >A);

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

vector< vector<double> > toFloatMatrix(vector < vector<int> >A);

int cofactor(vector< vector<int> > A, int row, int column);

void modEntries(vector<  vector<int> >& matrix, int base);

#endif