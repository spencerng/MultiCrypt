#ifndef GRAPHICS
#define GRAPHICS
#include<string>
#include<vector>
#include<Windows.h>
using std::string;
using std::vector;
using std::endl;

// Simulates setting console to fullscreen with a buffer resize and Alt+Enter shortcut simulated keypress
void setFullscreen();

// Prints centered text, either as a string or stored in a string vector
// Uses windows.h to determine the size of the vertical console buffer
void printCenter(std::string);
void printCenter(std::vector<std::string>);

// Prints the centered graphic logo and author and version information
void printTitle();

// Prints a right-aligned string, based on the console size
void printRight(string s);

// Sets the console colors to a black background and bright white text, without a system call
void setColors();

// Shows or hides the console cursor if showFlag is true or hide, respectively
void showCursor(bool showFlag);
#endif
