#pragma comment(lib, "winmm.lib")
#include<Windows.h>
#include "Headers\Sounds.h"

void playSong(char songTitle){
	if(songTitle=='m')
		PlaySoundA("\Audio Files\Mission Impossible.wav",
		NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
	else if(songTitle=='j')
		PlaySoundA("\Audio Files\James Bond.wav",
		NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
	else if(songTitle=='p')
		PlaySoundA("\Audio Files\Pink Panther.wav",
		NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
	
	
}

void muteSounds(){
	PlaySoundA(NULL, NULL, SND_FILENAME | SND_ASYNC);
	
}

void selectChoiceSound(){
	
	PlaySoundA("\Audio Files\Button.wav",
		NULL, SND_FILENAME | SND_ASYNC);
	
}

void exitProgramSound(){
	
	PlaySoundA("\Audio Files\Blast.wav",
		NULL, SND_FILENAME | SND_ASYNC);
	
}

void errorSound(){
	
	PlaySoundA("b.wav", NULL, SND_FILENAME | SND_ASYNC );
}