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


vector<char> intVecToChar(vector<int>);


vector< vector<int> > toNumbMatrix(vector<char> message);
//Not finished

vector< char > toLowerCase(vector<char> charArray);

#endif