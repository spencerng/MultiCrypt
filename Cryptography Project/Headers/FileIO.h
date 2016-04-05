#ifndef FILE_IO
#define FILE_IO
#include "HashAES.h"
#include "IO.h"
#include<iostream>
#include <cstdio>
#include <fstream>
#include<Windows.h>
#include<ShlObj.h>
using std::ifstream;
using std::ofstream;
using std::stringstream;
using std::endl;
using std::getline;


// Allows user to input a file name, returns "ERROR" if it is not valid
string getFileName();

string saveFile();

// Creates a popup Explorer window prompting the user to select a text file.
// Returns the path of the selected file (may not be a text file, however)
string selectFile();

// Creates a popup Explorer window prompting the user to select the folder to save the text file to.
// In this case, the user enters the file name in a separate function since the Windows API cannot easily detect invalid file names.
// Returns the path of the selected folder
string selectFolder();

// Creates a file if it does not exist
void createFile(string fileName);

// Checks if a file name contains illegal characters
bool validFileName(string file);

// Appends the ".txt" extension to a file if not present, retains the same string if it contains it - needs to be fixed
string extension(string);

// Passes the three essential lines of the program (has a password, key, message) by reading a file
void getFileProperties(string filename,bool& hasPassword, string & key, string& message);

// Appends a single line of text to a file
void outputLine(string filePath, string line);

// Checks if a file has been modified using a SHA-1 checksum and creating a temporary copy of the file
bool isValidFile(string filePath);

// Hashes a given file and appends the SHA-1 hash to the end of the file
void addHash(string filePath);

// Checks if a file has been successfully created
bool fileExists(string fileName);
#endif