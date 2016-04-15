#ifndef ENCRYPT_H
#define ENCRYPT_H
#include "IO.h"
#include "FileIO.h"
#include "Conversions.h"
#include "KeyGenerate.h"


// Main driver function for encryption
void encrypt();

// Creates a prompt to get the save file path and attempts to save a file
// Returns 1 if the process is aborted, 0 if it is successful
int getPathInterface(string&fileName);

// If key encryption is selected, prompts for the password and confirmation
// Deletes the created file if it is aborted
// Returns 1 if the process is aborted, 0 if it is successful
int passwordPromptOutput(string fileName, vector<vector<unsigned long long>> key);

#endif