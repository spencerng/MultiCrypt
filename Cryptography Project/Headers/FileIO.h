#ifndef FILE_IO
#define FILE_IO
#include "HashAES.h"
#include "IO.h"
#include <cstdio>
#include <fstream>
#include<Windows.h>
#include<ShlObj.h>
using std::ifstream;
using std::ofstream;
using std::stringstream;
using std::endl;
using std::getline;

// Creates a popup Explorer window prompting the user to save a text file, automatically appending the .txt extension if necessary
// Retries if the window is closed or a different file extension is selected and contains additional prompts
// Returns the path of the selected filepath
string saveFile();

// Creates a popup Explorer window prompting the user to select a text file.
// Retries if the window is closed
// Returns the path of the selected file (may not be a text file, however)
string selectFile();

// Deprecated by saveFile
// Creates a popup Explorer window prompting the user to select the folder to save the text file to.
// In this case, the user enters the file name in a separate function since the Windows API cannot easily detect invalid file names.
// Returns the path of the selected folder
string selectFolder();

// Creates a file if it does not exist
void createFile(string fileName);

// Deprecated by saveFile
// Appends the ".txt" extension to a file if not present, retains the same string if it contains it 
string extension(string);

// Reads the three essential lines of the program (password flag, key, message) from a file and passes them by reference
// File is ensured to be valid beforehand
void getFileProperties(string filename,bool& hasPassword, string & key, string& message);

// Appends a single line of text to a file, with an endl
void outputLine(string filePath, string line);

// Checks if a file has been modified using a SHA-1 checksum and creating a temporary copy of the file to its state before addHash is called
// Returns true if file is valid, false otherwise
bool isValidFile(string filePath);

// Hashes a given file and appends the SHA-1 hash to the end of the file
void addHash(string filePath);

// Checks if a file has been successfully created by creating an ifstream and attempting to read it
// Returns true if the file exists, false otherwise
bool fileExists(string fileName);
#endif