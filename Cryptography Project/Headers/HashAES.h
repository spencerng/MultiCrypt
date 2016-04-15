#ifndef HASH_AES_H
#define HASH_AES_H
#include <ctime>
#include<functional>
#include<cctype>
#include<conio.h>
#include <sstream>

// Disables a warning
#define CRYPTOPP_ENABLE_NAMESPACE_WEAK 1

// Includes from the Crypto++ library
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

// Main function for AES encryption, encrypting a string of text using a password
// Returns the encrypted string as a string of hex digits
string aesEncrypt(string plaintext, string password);

// Main function for AES decryption, decrypting using an asymetric password
// Takes in a string of hex digits for ciphertext
// Crypto++ library throws an exception if the ciphertext or the password is invalid
// Returns the decrypted ciphertext
string aesDecrypt(string ciphertext, string password);

// Derives a 256 bit key and 16 byte (128 bit) initialization vector from a password for AES encryption/decryption
// Uses a hash and custom algorithm
// Passes the computed bytes in an array structure by reference
void generateKey(byte(&key)[32], byte(&iv)[16], string password);

// Converts every two hex digits of a hash to a byte
// Stores the result in key, which is passed by reference
void hashToByte(string hash, byte key[], int bytes);

// Returns the SHA-1 hash of a string (160 bits, 40 hex digits)
string shaString(string message);

// Returns the SHA-1 hash of a designated file
string shaFile(string filePath);

//Inserts spaces, grouping two hex digits together from a hash
string insertSpace(string hashInput);
#endif