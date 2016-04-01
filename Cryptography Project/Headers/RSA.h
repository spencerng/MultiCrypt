#ifndef RSA_H
#define RSA_H
#include<string>
#include<vector>
#include <ctime>
#include <iostream>
#include<functional>
#include<cctype>
#include<conio.h>
#include <sstream>
#include "Crypto++/aes.h"
#include "Crypto++/modes.h"
#include "Crypto++/filters.h"
#include "Crypto++/cryptlib.h"
#include "Crypto++/pwdbased.h"
#include "Crypto++/eccrypto.h"
#include "Crypto++/md5.h"
#include "Crypto++/hex.h"
using std::vector;
using std::string;

void generatePrime(string&p, string&q);

int xGCD(int a, int b, int &x, int &y);

int gcd(int a, int b);
int lcm(int a, int b);


int multiInverse(int num, int base);

vector<char> linearCipherEncrypt(vector<char> message);
vector<char> linearCipherDecrypt(vector<char> message);

// Real "enter password" interface
// Allows user to input and delete characters with asterisks representing each character on screen
// Returns the actual password entered
string enterPassword();

string aesEncrypt(string plaintext, string password);
string aesDecrypt(string ciphertext, string password);

void generateKey(byte(&key)[32], byte(&iv)[16], string password);
void hashToByte(string hash, byte key[], int bytes);
string md5(string message);
#endif