#ifndef CONVERSIONS_H
#define CONVERSIONS_H
#include<vector>
#include <string>
using std::string;
using std::vector;

vector<char> stringToCharVec(string input);

string charVecToString(vector<char>);


vector<int> charVecToInt(vector<char>);


vector<char> intVecToChar(vector<int>);


vector< vector<int> > toNumbMatrix(vector<char> message);
//Not finished. Converts a string to a 3 x m integer matrix, based on its ASCII values

string matrixToString(vector< vector<int> > input);
// Not finished. Converts a 3 x m integer matrix to a string based on its ASCII values

vector< char > toLowerCase(vector<char> charArray);

#endif