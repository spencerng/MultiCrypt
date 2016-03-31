#ifndef CONVERSIONS_H
#define CONVERSIONS_H
#include<vector>
#include <string>

vector<char> stringToCharVec(string input);

string charVecToString(vector<char>);


vector<int> charVecToInt(vector<char>);


vector<char> intVecToChar(vector<int>);

//Converts a string to a 3 x m integer matrix, based on its ASCII values
vector< vector<int> > toNumbMatrix(vector<char> message);

// Converts a 3 x m integer matrix to a string based on its ASCII values
string matrixToString(vector< vector<int> > input);


vector< char > toLowerCase(vector<char> charArray);

#endif