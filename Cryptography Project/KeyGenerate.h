#ifndef KEYGENERATE_H_INCLUDED
#define KEYGENERATE_H_INCLUDED
#include<vector>
using std::vector;

vector< vector<int> > randomMatrix();
// Generates a random n x n invertible unimodular matrix, with a determinant of 1
// Allows for up to 7^9^15^2 possibilities

vector< vector<int> > unimodMatrix(int n);
// Generate a unimodular matrix based on a seed value and a set of predefined parameters.

#endif