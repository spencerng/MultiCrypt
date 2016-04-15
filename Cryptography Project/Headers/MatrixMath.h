#ifndef MATRIXMATH_H_INCLUDED
#define MATRIXMATH_H_INCLUDED
#include <vector>
using std::vector;

// Creates the minor matrix of A across the first row and a given column and returns it
vector< vector<unsigned long long> > toMMatrix(vector< vector<unsigned long long> > A, int row, int column);

// Uses cofactor expansion to return the determinant of a given n x n matrix. Recursive, requires n! multiplications
// Used to check if a given n x n is invertible.
int det(vector< vector<int> > A);
int det(vector< vector<unsigned long long> > A);

// Returns the product of a m x n matrix and a n x m matrix. 
vector< vector<unsigned long long> > multiply(vector< vector<unsigned long long> > A, vector< vector<int> > B);
vector< vector<unsigned long long> > multiply(vector< vector<unsigned long long> > A, vector< vector<unsigned long long> > B);


// Used to multiply a m x n matrix by a scalar and returns it
vector< vector<unsigned long long> > scalarMultiplyInt(int scalar, vector < vector<unsigned long long> >A);

// Returns the transpose of a m x n matrix. 
vector< vector<unsigned long long> > transpose(vector< vector<unsigned long long> > A);

// Returns the cofactor matrix of a given matrix, utilizing determinant and minor matrix with a definition for a 2 x 2.
vector < vector<unsigned long long > > toCofMatrix(vector< vector<unsigned long long> > A);

// Calculates the adjugate matrix and returns it  
vector< vector<int> > toAdjMatrix(vector< vector<int> > A);

// Calculates the inverse of an n x n matrix and returns it, equal to Adj(A) * (1/det(A))
// Note that this function is for integer determinants only
vector< vector<unsigned long long> > inverseInt(vector< vector<unsigned long long> > A);

// Calculates the cofactor of an entry in an n x n matrix
int cofactor(vector< vector<unsigned long long> > A, int row, int column);


#endif