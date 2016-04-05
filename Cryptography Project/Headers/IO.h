#ifndef IO
#define IO
#include "Sounds.h"
#include <string>
#include <iomanip>
#include <vector>
#include <sstream>
#include <iostream>
using std::vector;
using std::string;

string getString();
//Returns a user inputted string

bool isASCII(string);
bool isASCII(char);
// Defensive programming feature designed to check if an entered string will work with encryption and output to a text file.

string choices();
//Prints the main menu of the program

char getChar();
//Returns a user inputted char

void inputMatrix(vector< vector<int> >& matrix);
//Allows user to replace all values of a matrix of any size. Used primarily for debugging

void printMatrix(vector< vector<double> > A);
void printMatrix(vector< vector<int> > A);
void printMatrix(vector< vector<unsigned long long> > A);
// Displays formatted matrices of either type int or type double.

// Prints centered text, either as a string or stored in a string array
void printCenter(std::string);
void printCenter(std::vector<std::string>);

void printCharVec(vector<char>);

void cls();
//Utilizes an ANSI escape sequence to clear the screen. Works only on 32-bit applications. Preprocessor derivatives control output for DOS/UNIX OSes

void pause();
//Uses the _getc() function to ask for input to replace the system function call. 

void print(const char*);

void isValidCharInput(string prompt, vector<char> validInputs, char &input);

//Prints out text and stores it in a buffer to use later with isValidCharInput
void printStore(std::stringstream &ss, string text);

//Store text from cin into buffer
void store(std::stringstream &ss,  string);

#endif