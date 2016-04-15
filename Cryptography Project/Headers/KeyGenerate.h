#ifndef KEYGENERATE_H
#define KEYGENERATE_H
#include "Headers/MatrixMath.h"
#include <ctime>
using std::vector;


// Generates a random 3 x 3 invertible unimodular matrix, with a determinant of 1
// Randomly inverts and multiplies matrices from unimodMatrix together in 500-1000 cycles
// Returns the generated matrix
vector< vector<unsigned long long> > randomMatrix();

// Generate a unimodular matrix, multiplying L and U matrices together
// Returns the generated matrix
vector< vector<unsigned long long> > unimodMatrix();

// Generates a random lower-triangular matrix with values 1-1000000 and returns it
vector< vector<unsigned long long> > randomL();

// Generates a random upper-triangular matrix with values 1-1000000 and returns it
vector< vector<unsigned long long> > randomU();


#endif