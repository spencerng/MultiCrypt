#include "Headers/Sounds.h"

// Global variable to tell if sound should be played at all
bool soundOn = true;

bool getMusicStatus() {
	
	return soundOn;

}

// Acts as a member function of a class
void toggleSound() {
	soundOn = !soundOn;

	if (soundOn)
		//Default sound in main menu
		playSong(JAMES_BOND);
	else muteSounds();
}

void playSong(int songTitle){
	muteSounds();
	
	if (soundOn) {
		if (songTitle == MISSION_IMPOSSIBLE)
			PlaySoundA("Audio Files/Mission Impossible.wav", NULL,
				SND_FILENAME | SND_ASYNC | SND_LOOP | SND_NODEFAULT); // Songs are looped through a flag
		else if (songTitle == JAMES_BOND)
			PlaySoundA("Audio Files/James Bond.wav",
				 NULL, SND_NODEFAULT | SND_ASYNC | SND_LOOP);
		else if (songTitle == PINK_PANTHER)
			PlaySoundA("Audio Files/Pink Panther.wav",
				NULL, SND_FILENAME | SND_ASYNC | SND_NODEFAULT | SND_LOOP);
	}
	
}

void muteSounds(){
	PlaySoundA(NULL, NULL, SND_FILENAME | SND_ASYNC);
	
}

void exitProgramSound(){
	if(soundOn)
		PlaySoundA("Audio Files/Blast.wav", NULL, SND_FILENAME | SND_ASYNC );
	
}

void errorSound(){
	
	PlaySoundA("SystemExclamation", NULL,SND_ASYNC );
}