#ifndef HASH_AES_H
#define HASH_AES_H
#include <ctime>
#include<functional>
#include<cctype>
#include<conio.h>
#include <sstream>
#define CRYPTOPP_ENABLE_NAMESPACE_WEAK 1
#include "Crypto++/aes.h"
#include "Crypto++/modes.h"
#include "Crypto++/filters.h"
#include "Crypto++/cryptlib.h"
#include "Crypto++/pwdbased.h"
#include "Crypto++/eccrypto.h"
#include "Crypto++/md5.h"
#include "Crypto++/hex.h"
#include "Crypto++/files.h"


using std::vector;
using std::string;


string aesEncrypt(string plaintext, string password);
string aesDecrypt(string ciphertext, string password);

void generateKey(byte(&key)[32], byte(&iv)[16], string password);
void hashToByte(string hash, byte key[], int bytes);
string shaString(string message);
string shaFile(string filePath);
#endif