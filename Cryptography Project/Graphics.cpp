#include <Windows.h>
#include "Headers/Graphics.h"
#include "Headers/IO.h"
using std::string;
using std::vector;

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
	std::cout << "\n";
	vector<string> s;
	s.push_back(" _________                        __                                    .__            ");
	s.push_back(" \\_   ___ \\_______ ___.__._______/  |_  ____   ________________  ______ |  |__ ___.__. ");
	s.push_back(" /    \\  \\/\\_  __ <   |  |\\____ \\   __\\/  _ \\ / ___\\_  __ \\__  \\ \\____ \\|  |  <   |  | ");
	s.push_back(" \\     \\____|  | \\/\\___  ||  |_> >  | (  <_> ) /_/  >  | \\// __ \\|  |_> >   Y  \\___  | ");
	s.push_back("  \\______  /|__|   / ____||   __/|__|  \\____/\\___  /|__|  (____  /   __/|___|  / ____| ");
	s.push_back("         \\/        \\/     |__|              /_____/            \\/|__|        \\/\\/      ");
	printCenter(s);
	std::cout << "\n\n";
	printCenter("by Spencer Ng, Sahar Sami, Parth Savla");
	std::cout << "\n";
	printCenter("Version 0.1 - ALPHA");
	printf("\n\n");

}