#ifndef FILE_IO
#define FILE_IO
#include<vector>
#include <string>
#include <sstream>
#include <cstdio>
#include<iostream>
#include <fstream>
#include "RSA.h"
using namespace std;

// Allows user to input a file name to create or read from a file, eliminating extra spaces and allowing for input with or without .txt extension
string getFileName();

// Creates a popup Explorer window prompting the user to select a text file.
// Returns the path of the selected file (may not be a text file, however)
string selectFile();

// Creates a popup Explorer window prompting the user to select the folder to save the text file to.
// In this case, the user enters the file name in a separate function since the Windows API cannot easily detect invalid file names.
// Returns the path of the selected folder
string selectFolder();

// Creates a file if it does not exist
void createFile(string fileName);

// Given an encrypted numerical message in matrix form (after multiplication), output it to a file, using commas (,) to separate each value
void outputMessage(vector< vector<int> > message, string fileName);
void outputMessage(vector< vector<unsigned long long> > message, string fileName);

// Given the encryption key, output it to a file with comma separators
void outputKey(vector< vector<int> > key, string fileName);
void outputKey(vector< vector<unsigned long long> > key, string fileName);

// Reads the 3 x 3 encryption key from a file. 
vector< vector<int> > readKey(string fileName);

// Reads the 3 x m integer matrix that represents the encrypted message, returning it in integer matrix form
vector< vector<int> > readMessage(string fileName);

bool validFileName(string file);

string extension(string);

//Converts key to a space-separated string for easy output
string keyOutputString(vector< vector<unsigned long long> > input);

string messageOutputString(vector< vector<unsigned long long> > input);

void getFileProperties(string filename,bool& hasPassword, string & key, string& message);

vector<vector<unsigned long long>> keyInputMatrix(string input);
vector<vector<unsigned long long>> messageInputMatrix(string input);

void outputLine(string filePath, string line);

// Checks if a file has been modified using hashes
bool isValidFile(string filePath);
void addHash(string filePath);
#endif