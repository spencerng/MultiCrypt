#ifndef CONVERSIONS_H
#define CONVERSIONS_H
#include<vector>
#include <string>
using std::string;
using std::vector;

vector<char> stringToCharVec(string input);

string charVecToString(vector<char>);
//Not defined

vector<int> charVecToInt(vector<char>);
//Not defined

vector<char> intVecToChar(vector<int>);
//Not defined

vector< vector<int> > toNumbMatrix(vector<char> message);
//Not finished

vector< char > toLowerCase(vector<char> charArray);

#endif