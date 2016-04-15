#ifndef SOUNDS_H
#define SOUNDS_H
#pragma comment(lib, "winmm.lib")
#define PINK_PANTHER 1
#define MISSION_IMPOSSIBLE 2
#define JAMES_BOND 3
#include<Windows.h>
#include<string>

//Plays the song as defined by the titles above
//Audio files must be in a folder called "Audio Files" in the same directory as the executable
void playSong(int songTitle);

//Plays a NULL sound file, muting all sounds
void muteSounds();

// Plays an explosion sound, for use when password is entered incorrectly >3 times
void exitProgramSound();

// Plays the default Windows error sound. Not used in the program but could be used. 
void errorSound();

// Returns the status of the global variable bool soundOn 
bool getMusicStatus();

// Changes the value of soundOn to its opposite
// If sound is currently on, muteSounds is called as well
// Otherwise, playSong(JAMES_BOND) is called
void toggleSound();

#endif SOUNDS_H
