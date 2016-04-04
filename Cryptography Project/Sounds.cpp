#include "Headers/Sounds.h"


bool soundOn = true;

bool getMusicStatus() {
	
	return soundOn;

}

void playSong(char songTitle){
	
	if(songTitle=='m')
		PlaySoundA("Audio Files/Mission Impossible.wav", NULL,
			SND_FILENAME | SND_ASYNC | SND_LOOP );
	
	else if(songTitle=='j')
		PlaySoundA("/Audio Files/James Bond.wav",
		NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
	else if(songTitle=='p')
		PlaySoundA("/Audio Files/Pink Panther.wav",
		NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
	
	
}

void muteSounds(){
	PlaySoundA(NULL, NULL, SND_FILENAME | SND_ASYNC);
	
}

void toggleSound() {
	soundOn = !soundOn;
	if (soundOn)
		playSong('m');
	else muteSounds();
}

void selectChoiceSound(){
	
	PlaySoundA("\Audio Files\Button.wav",
		NULL, SND_FILENAME | SND_ASYNC);
	
}

void exitProgramSound(){
	if(soundOn)
	PlaySoundA("Audio Files/Blast.wav",
		NULL, SND_FILENAME );
	
}

void errorSound(){
	
	PlaySoundA("b.wav", NULL, SND_FILENAME | SND_ASYNC );
}