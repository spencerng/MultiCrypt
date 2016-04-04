#ifndef SOUNDS_H
#define SOUNDS_H
#pragma comment(lib, "winmm.lib")
#include<Windows.h>

void playSong(char songTitle);

void muteSounds();

void selectChoiceSound();

void exitProgramSound();

void errorSound();

bool getMusicStatus();

void toggleSound();

#endif SOUNDS_H
