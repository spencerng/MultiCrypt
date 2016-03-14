#ifndef FILE_IO
#define FILE_IO
#include<vector>
#include <string>
#include <fstream>
using namespace std;

//Learn this from http://www.cplusplus.com/doc/tutorial/files/

string getFileName();
// Allows user to input a file name to create or read from a file, eliminating extra spaces and allowing for input with or without .txt extension

bool fileExists(string fileName);
// Given a filename, check if a file exists or not

void createFile(string fileName);
// Creates a file if it does not exist

void outputMessage(vector< vector<int> > message, string fileName);
// Given an encrypted numerical message in matrix form (after multiplication), output it to a file, using commas (,) to separate each value

void outputKey(vector< vector<int> > key, string fileName);
// Given the encryption key, output it to a file with comma separators

vector< vector<int> > readKey(string fileName);
// Reads the 3 x 3 encryption key from a file.

vector< vector<int> > readMessage(string fileName);
// Reads the 3 x m integer matrix that represents the encrypted message, returning it in integer matrix form

#endif