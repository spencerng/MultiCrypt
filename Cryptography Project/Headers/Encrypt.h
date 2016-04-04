#ifndef ENCRYPT_H
#define ENCRYPT_H
#include "Headers/IO.h"
#include "Headers/FileIO.h"
#include "Headers/Conversions.h"
#include "Headers/KeyGenerate.h"
#include "Headers/MatrixMath.h"

void encrypt();


// Encrypt the key using a password with AES
void encryptPassword(string key);

#endif