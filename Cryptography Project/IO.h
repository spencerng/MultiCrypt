#ifndef DECRYPT_H
#define DECRYPT_H
#include <string>
#include <vector>
using std::string;
using std::vector;

string getString();

void printChoices();

char getChar();

void inputMatrix(vector< vector<int> >& matrix);

void printMatrix(vector< vector<double> > A);
void printMatrix(vector< vector<int> > A);

void cls();
//Doesn't work, but should be created as an alternative to system("cls")

void systemPause();
//Should be created, definition not present


#endif