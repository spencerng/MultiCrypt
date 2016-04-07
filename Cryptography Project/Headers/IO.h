#ifndef IO
#define IO
#include "Sounds.h"
#include "Graphics.h"
#include <string>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <conio.h>
#pragma warning(disable:4996)

using std::setprecision;
using std::setw;
using std::endl;
using std::setfill;

#define CONTINUE 0
#define ABORT	 1

int error(string errorMessage);

string choices();
//Prints the main menu of the program

void cls();
//Utilizes an ANSI escape sequence to clear the screen. Works only on 32-bit applications. Preprocessor derivatives control output for DOS/UNIX OSes

void pause();
//Uses the _getc() function to ask for input to replace the system function call. 

void isValidCharInput(string prompt, vector<char> validInputs, char &input);

// Real "enter password" interface
// Allows user to input and delete characters with asterisks representing each character on screen
// Returns the actual password entered
string enterPassword();

void changeMode(string inMode);

void capsLockWarning();

void resetErrors();

string multiLineInput();

#endif