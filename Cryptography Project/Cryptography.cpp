#include "Headers/Cryptography.h"
#define VERSION 1.0

int main() {
	setFullscreen();
	setColors();
	
	if (restartCryptProgram() == 0)
		return 0;

	return 666;
}

