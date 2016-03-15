#ifndef IO
#define IO
#include <string>
#include <vector>
using std::vector;
using std::string;

string getString();
//Returns a user inputted string

void printChoices();
//Prints the main menu of the program

char getChar();
//Returns a user inputted char

void inputMatrix(vector< vector<int> >& matrix);
//Allows user to replace all values of a matrix of any size. Used primarily for debugging

void printMatrix(vector< vector<double> > A);
void printMatrix(vector< vector<int> > A);
// Displays formatted matrices of either type int or type double.

void printCharVec(vector<char>);

void cls();
//Utilizes an ANSI escape sequence to clear the screen. Works only on 32-bit applications. Tested on Windows 10 but not in OSX or Linux

void pause();
//Uses the _getc() function to ask for input to replace the system function call. Tested only on Windows 10.


#endif