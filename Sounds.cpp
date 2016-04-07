#include "Headers/Sounds.h"


bool soundOn = true;

bool getMusicStatus() {
	
	return soundOn;

}

void playSong(int songTitle){
	muteSounds();
	
	if (soundOn) {
		if (songTitle == MISSION_IMPOSSIBLE)
			PlaySoundA("Audio Files/Mission Impossible.wav", NULL,
				SND_FILENAME | SND_ASYNC | SND_LOOP | SND_NODEFAULT);
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

void toggleSound() {
	soundOn = !soundOn;
	if (soundOn)
		playSong(JAMES_BOND);
	else muteSounds();
}

void selectChoiceSound(){
	
	PlaySoundA("Audio Files/Button.wav",
		NULL, SND_FILENAME | SND_ASYNC);
	
}

void exitProgramSound(){
	if(soundOn)
	PlaySoundA("Audio Files/Blast.wav",
		NULL, SND_FILENAME | SND_ASYNC );
	
}

void errorSound(){
	
	PlaySoundA("SystemExclamation", NULL,SND_ASYNC );
}