#include "Headers/Graphics.h"



void setFullscreen() {
	//Changes the window buffer size to exclude the scrollbar
	HANDLE hand = GetStdHandle(STD_OUTPUT_HANDLE);
	
	CONSOLE_SCREEN_BUFFER_INFO info;
	GetConsoleScreenBufferInfo(hand, &info);
	info.dwSize.X = info.dwMaximumWindowSize.X;
	info.dwSize.Y = info.dwMaximumWindowSize.Y;
	SetConsoleScreenBufferSize(hand, info.dwSize);
	
	//Simulates the Alt+Enter keypress to enter fullscreen console mode
	keybd_event(VK_MENU, 0x38, 0x0000, 0);
	keybd_event(VK_RETURN, 0x1c, 0x0000, 0);
	keybd_event(VK_RETURN, 0x1c, KEYEVENTF_KEYUP, 0);
	keybd_event(VK_MENU, 0x38, KEYEVENTF_KEYUP, 0);

	SetConsoleTitle("MultiCrypt");
	
}



void printTitle() {

	printf("\n\n\n");
	vector<string> title = {

		"$$.    $$$            $$    $$     $$   +++ ++.                           ++  ",
		"$$$.   $$$            $$    $$         ++         +++++      +  .....     ++  ",
		"$$$$ .$,$$  $$   $$   $$  $$$$$$   $$  ++        +==,  ++    +  ++=  ++ ++++++",
		"$$ $$$$.$$  $$   $$   $$    $$     $$  ++        ++     ++  +=  ++    +   ++  ",
		"$$  $$  $$  $$   $$   $$    $$     $$  ++        ++      +.++   ++    +   ++  ",
		"$$      $$  $$$ Z$$   $$    Z$     $$   ++=..    ++       ++.   ++.  ++   ++ .",
		"                             $$I           ++=   ,,       +~    ++ =+.    .:++",
		"                                                         ++     ++            ",
		"                                                         +      ++            " };

	printCenter(title);
	printf("\n\n");
	printCenter("Spencer Ng, Sahar Sami, Parth Savla");
	
	printf( "\n");
	printCenter("Version 1.1");
	printf("\n\n");

}
void showCursor(bool showFlag) {
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

	// Structure contains cursor properties
	CONSOLE_CURSOR_INFO cursorInfo;

	GetConsoleCursorInfo(out, &cursorInfo);
	cursorInfo.bVisible = showFlag; // set the cursor visibility
	SetConsoleCursorInfo(out, &cursorInfo);
}

void printCenter(string s) {
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	HANDLE hand = GetStdHandle(STD_OUTPUT_HANDLE);

	// Gets the size for the calculations and stores it into csbi
	GetConsoleScreenBufferInfo(hand, &csbi);

	// Essentially divides the buffer size into two to create a centered print
	for (int i = 0; i < ((csbi.dwMaximumWindowSize.X - s.length()) / 1.85); i++)
		printf(" ");
	printf("%s\n", s.c_str());

}

void printCenter(vector<string> s) {

	for (int i = 0; i < s.size(); i++)
		printCenter(s[i]);

}

void printRight(string s) {
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	HANDLE hand = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleScreenBufferInfo(hand, &csbi);

	// Sets a 10 character padding from the right margin
	printf("%*s\n", csbi.dwMaximumWindowSize.X - s.length()-10,s.c_str());

}

void setColors() {

	// First part indicates background, second indicates text color
	WORD wColor = ((0 & 0x0F) << 4) + (15 & 0x0F);
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(handle, wColor);
}