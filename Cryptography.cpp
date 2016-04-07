#include "Headers/Cryptography.h"
#define VERSION 1.0

int main() {
	setFullscreen();
	setColors();
	
	

	while (true) {
		changeMode("Main Menu");
		cls();
		char choice;
		playSong(JAMES_BOND);
		resetErrors();
		isValidCharInput(choices(), { '1','2','3','4' }, choice);

		if (choice == '1') {
			encrypt();
			continue;
		}
		else if (choice == '2')
			decrypt();
		else if (choice == '3')
			toggleSound();
		else if (choice == '4') {
			changeMode("Exit Program");
			isValidCharInput("\tAre you sure you want to quit? (Y/N)\n", { 'y','n' }, choice);
			if (choice == 'y') {
				exitProgramSound();
				return 0;
			}

		}


	}
}

