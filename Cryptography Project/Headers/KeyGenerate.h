#ifndef KEYGENERATE_H
#define KEYGENERATE_H
#include "Headers/MatrixMath.h"
#include <ctime>
using std::vector;


// Generates a random n x n invertible unimodular matrix, with a determinant of 1
// Randomly inverts and multiplies matrices from unimodMatrix together in 50-100 cycles
vector< vector<unsigned long long> > randomMatrix();

// Generate a unimodular matrix, multiplying L and U matrices together
vector< vector<unsigned long long> > unimodMatrix();

// Generates a random lower-triangular matrix
vector< vector<unsigned long long> > randomL();

// Generates a random upper-triangular matrix
vector< vector<unsigned long long> > randomU();


#endif