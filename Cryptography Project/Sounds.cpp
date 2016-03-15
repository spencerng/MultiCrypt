#include<Windows.h>
#include "Headers\Sounds.h"

void playSong(char songTitle){
	if(songTitle=='m')
		PlaySound(TEXT("C:\\Users\\sng\\Documents\\Visual Studio 2015\\Projects\\Cryptography-Project\\Cryptography Project\\Audio Files\\Mission Impossible.wav"),
		NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
	else if(songTitle=='j')
		PlaySound(TEXT("C:\\Users\\sng\\Documents\\Visual Studio 2015\\Projects\\Cryptography-Project\\Cryptography Project\\Audio Files\\James Bond.wav"),
		NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
	else if(songTitle=='p')
		PlaySound(TEXT("C:\\Users\\sng\\Documents\\Visual Studio 2015\\Projects\\Cryptography-Project\\Cryptography Project\\Audio Files\\Pink Panther.wav"),
		NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
	
	
}

void muteSounds(){
	PlaySound(NULL, NULL, SND_FILENAME | SND_ASYNC);
	
}

void selectChoiceSound(){
	
	PlaySound(TEXT("C:\\Users\\sng\\Documents\\Visual Studio 2015\\Projects\\Cryptography-Project\\Cryptography Project\\Audio Files\\Button Press.wav"),
		NULL, SND_FILENAME | SND_ASYNC);
	
}

void exitProgramSound(){
	
	PlaySound(TEXT("C:\\Users\\sng\\Documents\\Visual Studio 2015\\Projects\\Cryptography-Project\\Cryptography Project\\Audio Files\\Blast.wav"),
		NULL, SND_FILENAME | SND_ASYNC);
	
}

void errorSound(){
	
	PlaySound(TEXT("C:\\"), NULL, SND_FILENAME | SND_ASYNC );
}