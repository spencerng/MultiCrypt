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

// Definitions that signal if a function should be immediately aborted to the main menu
#define CONTINUE 0
#define ABORT	 1

// define DOS for DOS-based OS (Windows) or UNIX (Linux, OS X, etc.)
#define DOS

// Displays an error message, calling pause afterwards
// Increments global variable errors by 1
// If errors >= 3, prompts to abort the function
// Returns ABORT if aborted, CONTINUE otherwise
int error(string errorMessage);

//Returns the text of the main menu of the program 
string choices();

// Invokes system("clear") or system("cls") depending on the OS defined above
// Calls printTitle afterwards to reset the console buffer
void cls();

//Uses the _getc() function to ask for input, replacing the system function call. 
void pause();

// Prints the prompt, then asks for one of the character inputs in validInputs, not necessary to press enter
// All entries in validInputs must be lowercase
// Retries if the character input is not valid
// Passes the selected character by reference, which is lowercase
void isValidCharInput(string prompt, vector<char> validInputs, char &input);

// A password input interface
// Allows user to input and delete characters with asterisks representing each character on screen
// Returns the actual password entered
string enterPassword();

// Changes the global string variable mode, which is printed after the screen is cleared with printTitle
void changeMode(string inMode);

// Displays a warning on screen if caps lock is currently on
// Called when attempting to enter a password
void capsLockWarning();

// Sets global int variable errors to 0
// Called at the main menu
void resetErrors();

// Allows for multiple line input, terminating after enter is pressed twice
// Returns the inputted string, with the new line escape character representing each enter
string multiLineInput();

#endif