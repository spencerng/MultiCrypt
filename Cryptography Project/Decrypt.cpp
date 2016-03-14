#include <string>
#include <iostream>
using namespace std;
#include "Headers\IO.h"
#include "Headers\Decrypt.h"
#include "Headers\FileIO.h"
#include "Headers\Conversions.h"
#include "Headers\KeyGenerate.h"
#include "Headers\MatrixMath.h"

//Uncomment this when all of the function definitions are present

/*void decrypt() {

	// This is how the function would be implemented, but feel free to change it.
	string fileName;
	do {
		fileName = getFileName();
	} while (fileExists(fileName)==false);
	vector<vector<int>> key = readKey(fileName);
	vector < vector<int> > matrixMessage = readMessage(fileName);
	vector< vector<int> > decryptedMessage = multiply(inverseInt(key), matrixMessage);
	cout << matrixToString(decryptedMessage) << endl;
	return;

}*/
