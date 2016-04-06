#ifndef GRAPHICS
#define GRAPHICS
#include<string>
#include<vector>
#include<Windows.h>
using std::string;
using std::vector;
using std::endl;

// Simulates setting console to fullscreen with a buffer resize and Alt+Enter combo
void setFullscreen();

// Prints centered text, either as a string or stored in a string array
void printCenter(std::string);
void printCenter(std::vector<std::string>);

// Prints some kind of centered header to the project
void printTitle();

void printRight(string s);
void setColors();
#endif
