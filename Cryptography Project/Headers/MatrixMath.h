#ifndef MATRIXMATH_H_INCLUDED
#define MATRIXMATH_H_INCLUDED
#include <vector>
using std::vector;

vector< vector<unsigned long long> > toMMatrix(vector< vector<unsigned long long> > A, int row, int column);
// Creates the minor matrix of A across the first row and a given column
// Used in the det and toCofMatrix functions

int det(vector< vector<int> > A);
int det(vector< vector<unsigned long long> > A);
// Uses cofactor expansion (and the minor matrix) to return the determinant of a given n x n matrix. Is recursive, and requires n! multiplications
// Used to check if a given n x n is invertible. Also used in the toCofMatrix function

vector< vector<unsigned long long> > multiply(vector< vector<unsigned long long> > A, vector< vector<int> > B);
vector< vector<unsigned long long> > multiply(vector< vector<unsigned long long> > A, vector< vector<unsigned long long> > B);
// Returns the product of a m x n matrix and a n x m matrix. Used to encrypt and decrypt messages	

// Used to multiply a m x n matrix by a scalar;
vector< vector<unsigned long long> > scalarMultiplyInt(int scalar, vector < vector<unsigned long long> >A);

vector< vector<unsigned long long> > transpose(vector< vector<unsigned long long> > A);
// Returns the transpose of a m x n matrix. Will be used in the toAdjMatrix function.

vector < vector<unsigned long long > > toCofMatrix(vector< vector<unsigned long long> > A);
// Returns the cofactor matrix of a given matrix, utilizing determinant and minor matrix with a definition for a 2 x 2.
// Used for the adjugate matrix. 

vector< vector<int> > toAdjMatrix(vector< vector<int> > A);
// Calculates the adjugate matrix, or the transpose of the cofactor matrix.  



// Calculates the inverse of a matrix, equal to Adj(A) * (1/det(A)).  
vector< vector<unsigned long long> > inverseInt(vector< vector<unsigned long long> > A);

int cofactor(vector< vector<unsigned long long> > A, int row, int column);


#endif