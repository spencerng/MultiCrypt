#ifndef SOUNDS_H
#define SOUNDS_H
#pragma comment(lib, "winmm.lib")
#define PINK_PANTHER 1
#define MISSION_IMPOSSIBLE 2
#define JAMES_BOND 3
#include<Windows.h>
#include<string>

void playSong(int songTitle);

void muteSounds();

void selectChoiceSound();

void exitProgramSound();

void errorSound();

bool getMusicStatus();

void toggleSound();

#endif SOUNDS_H
