#ifndef DECRYPT_H
#define DECRYPT_H
#include "IO.h"
#include "FileIO.h"
#include "Conversions.h"
#include "MatrixMath.h"

void decrypt();
//Main function to decrypt a message

// Function that prompts to input a valid text file
int selectValidFile(string& fileName);

// Decrypts key using password
int decryptPassword(string& keyString);

#endif DECRYPT_H