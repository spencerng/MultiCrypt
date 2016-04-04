#ifndef CONVERSIONS_H
#define CONVERSIONS_H
#include<vector>
#include <string>
#include<sstream>
using std::vector;
using std::string;

vector<char> stringToCharVec(string input);

vector<int> charVecToInt(vector<char>);

vector<char> intVecToChar(vector<int>);

//Converts a string to a 3 x m integer matrix, based on its ASCII values
vector< vector<int> > toNumbMatrix(vector<char> message);

// Converts a 3 x m integer matrix to a string based on its ASCII values
string matrixToString(vector< vector<int> > input);
string matrixToString(vector< vector<unsigned long long> > input);

//Converts key to a space-separated string for easy output
string keyOutputString(vector< vector<unsigned long long> > input);

// Converts the encrypted message to a space-separated string
string messageOutputString(vector< vector<unsigned long long> > input);

// Converts the (decrypted) key from a string into a matrix using stringstreams
vector<vector<unsigned long long>> keyInputMatrix(string input);

// Converts the encrypted message into a matrix from a string
vector<vector<unsigned long long>> messageInputMatrix(string input);


vector< char > toLowerCase(vector<char> charArray);

#endif