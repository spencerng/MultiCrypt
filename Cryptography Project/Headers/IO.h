#ifndef IO
#define IO
#include "Sounds.h"
#include "Graphics.h"
#include "Encrypt.h"
#include "Decrypt.h"
#include <iomanip>
#include <sstream>
#include <conio.h>
#pragma warning(disable:4996)

using std::getline;
using std::cin;
using std::setprecision;
using std::setw;
using std::endl;
using std::setfill;

void error(string errorMessage);
void error(string errorMessage, string fileName);

void passBuffer(stringstream input);

string getString();
//Returns a user inputted string

bool isASCII(string);
bool isASCII(char);
// Defensive programming feature designed to check if an entered string will work with encryption and output to a text file.

string choices();
//Prints the main menu of the program

/*void inputMatrix(vector< vector<int> >& matrix);
//Allows user to replace all values of a matrix of any size. Used primarily for debugging

void printMatrix(vector< vector<double> > A);
void printMatrix(vector< vector<int> > A);
void printMatrix(vector< vector<unsigned long long> > A);
// Displays formatted matrices of either type int or type double.*/

void cls();
//Utilizes an ANSI escape sequence to clear the screen. Works only on 32-bit applications. Preprocessor derivatives control output for DOS/UNIX OSes

void pause();
//Uses the _getc() function to ask for input to replace the system function call. 

void isValidCharInput(string prompt, vector<char> validInputs, char &input);

//Prints out text and stores it in a buffer to use later with isValidCharInput
void printStore(std::stringstream &ss, string text);

//Store text from cin into buffer
void store(std::stringstream &ss,  string);

// Real "enter password" interface
// Allows user to input and delete characters with asterisks representing each character on screen
// Returns the actual password entered
string enterPassword();


int restartCryptProgram();
void changeMode(string inMode);

#endif