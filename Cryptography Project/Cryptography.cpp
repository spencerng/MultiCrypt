#include "Headers/Cryptography.h"
#define VERSION 0.3

int main() {
	setFullscreen();
	setColors();
	
	if (restartCryptProgram() == 0)
		return 0;

	return 666;
}

