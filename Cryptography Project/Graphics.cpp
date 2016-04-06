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

	SetConsoleTitle("Cryptography");
}



void printTitle() {
	//Replace this later
	printf("\n\n\n");
	vector<string> s = {

" $$.    $$$            $$    $$     $$   +++  .+.                          ++     ",
" $$$.  I$$$            $$    $$         ++         . ....     .. .. .,     ++     ",
" $$$$ .$,$$  $$   $$   $$  $$$$$Z   $$  ++.       +==, . +. .~+  ++=  ++.,++++++  ",
" $$ $$$$.$$  $$   $$   $$    $$     $$ .++.       ++     ++  +=  ++    +   ++     ",
" $$  $$  $$  $$   $$   $$    $$     $$  ++        ++     .+.++.  ++    +.  ++     ",
" $$      $$  $$$ Z$$   $$    Z$     $$   ++=.. ,  ++      :++.   ++.  ++   ++ .   ",
"                              $$I          ,++= . ,,       +~    ++ =+..   .:++   ",
"                                                          ++     ++               ",
"                                                          +      ++               " };
	printCenter(s);
	printf("\n\n");
	printCenter("Spencer Ng, Sahar Sami, Parth Savla");
	
	printf( "\n");
	printCenter("Version 1.0 - RELEASE");
	printf("\n\n");

}

void printCenter(string s) {
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	HANDLE hand = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleScreenBufferInfo(hand, &csbi);
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

	printf("%*s\n", csbi.dwMaximumWindowSize.X - s.length()-10,s.c_str());

}

void setColors() {
	WORD wColor = ((0 & 0x0F) << 4) + (15 & 0x0F);
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(handle, wColor);
}