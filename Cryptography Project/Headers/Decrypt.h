#ifndef DECRYPT_H
#define DECRYPT_H
#include "IO.h"
#include "FileIO.h"
#include "Conversions.h"
#include "MatrixMath.h"

//Main function to decrypt a message
void decrypt();

// Function that prompts to input a valid text file
// Returns 1 if the process is aborted, 0 if it is successful
int selectValidFile(string& fileName);

// Decrypts key using password with prompts with automated system shutdown and file deletion with over 3 incorrect tries
// Returns 1 if the process is aborted, 0 if it is successful
int decryptPassword(string& keyString);

#endif DECRYPT_H