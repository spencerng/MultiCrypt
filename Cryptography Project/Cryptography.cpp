#include "Headers/Cryptography.h"

int main() {
	setFullscreen();
	
	playSong('m');
	while (true) {
		
		char choice;
		
		isValidCharInput(choices(), { '1','2','3','4' }, choice);	
		
		if (choice == '1')
			
			encrypt();
		else if (choice == '2')
			decrypt();
		else if (choice == '3')
			toggleSound();
		else if (choice == '4') {
			exitProgramSound();
			return 0;
		}
			
	}

	return 666;
}

