#include "Headers/Cryptography.h"
#define VERSION 0.2

int main() {
	setFullscreen();
	playSong('m');
	if (restartCryptProgram() == 0)
		return 0;

	return 666;
}

