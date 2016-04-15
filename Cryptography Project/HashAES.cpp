#include "Headers/HashAES.h"

string shaString(string message) {

	CryptoPP::SHA1 sha1;
	std::string hash = "";

	// StringSink is a structure to deposit the generated hash into a string
	// HexEncoder converts the characters of the string to hex
	CryptoPP::StringSource(message, true, new CryptoPP::HashFilter(sha1, new CryptoPP::HexEncoder(new CryptoPP::StringSink(hash))));
	
	return hash;

}

string shaFile(string filePath) {
	string result;
	CryptoPP::SHA1 hash;
	
	// Same as shaString, except a FileSource is used
	CryptoPP::FileSource(filePath.c_str(), true, new CryptoPP::HashFilter(hash, new CryptoPP::HexEncoder(new CryptoPP::StringSink(result), true)));
	return result;

}

void hashToByte(string hash, byte key[], int bytes) {
	std::stringstream ss(hash);
	int temp;
	for (int i = 0; i < bytes; i++) {

		//Stringstream allows hex input to be cast to a char
		ss >> std::hex >> temp;
		key[i] = char(temp);
	}

}

string insertSpace(string s) {
	for (int i = 2; i < s.length(); i += 3)
		s.insert(i, 1, ' ');
	return s;
}

void generateKey(byte (&key)[32], byte (&iv)[16], string password) {
	// Generates a seed from the password - not intended to be a good hash function, but only a backup
	int seed = 0;
	for (int i = 0; i < password.length(); i++)
		seed += (password[i] * 127) % (i + 23);
	srand(seed);

	// Two hashes concatonated together due to one only having 20 bytes (40 hex digits)
	string hash1 = insertSpace(shaString(password));
	hash1 += insertSpace(shaString(hash1));

	hashToByte(hash1, key, 32);
	string hash2 = "";

	if (password.length() != 0) {
		
		for (int i = 0; i < hash1.length(); i++)
			// A random character concatonation based on the password
			hash2 += password[rand() % password.length()] + rand();
		hash2 = insertSpace(shaString(hash2)) + insertSpace(shaString(insertSpace(shaString(hash2))));
	}
	// Converts the contents of the hash string to the byte array
	hashToByte(hash2, iv, 16);
	return;
}

string aesEncrypt(string plaintext, string password) {
	string ciphertext;
	string output;
	// 256 bit key
	byte key[CryptoPP::AES::MAX_KEYLENGTH];

	// Initialization vector
	byte iv[16];
	generateKey(key, iv, password);
	
		CryptoPP::AES::Encryption aesEncryption(key, 32);
		CryptoPP::CBC_Mode_ExternalCipher::Encryption cbcEncryption(aesEncryption, iv);
	
	// Actual encryption
	CryptoPP::StreamTransformationFilter stfEncryptor(cbcEncryption, new CryptoPP::StringSink(ciphertext));
	stfEncryptor.Put(reinterpret_cast<const unsigned char*>(plaintext.c_str()), plaintext.length() + 1);
	stfEncryptor.MessageEnd();
	
	// Outputs encrypted string as a string of hex digits with a stringstream
	std::stringstream buffer;
	
	for (int i = 0; i < ciphertext.size(); i++)
	buffer << std::hex << (0xFF & static_cast<byte>(ciphertext[i])) << " ";
	
	ciphertext = buffer.str();

	return ciphertext;
	
}

string aesDecrypt(string input, string password) {
	// Input is a string of digits, so it's converted into a character
	std::stringstream buffer(input);
	int hexChar;
	string ciphertext = "";

	while (buffer >> std::hex >> hexChar)
		ciphertext += char(hexChar);
	

	// 256 bit key
	byte key[CryptoPP::AES::MAX_KEYLENGTH];

	// Initialization vector
	byte iv[16];
	generateKey(key, iv, password);

	// Proccess is symmetrical
	
	// Decryption
	string output;
	CryptoPP::AES::Decryption aesDecryption(key, 32);
	CryptoPP::CBC_Mode_ExternalCipher::Decryption cbcDecryption(aesDecryption, iv);
	CryptoPP::StreamTransformationFilter stfDecryptor(cbcDecryption, new CryptoPP::StringSink(output));

	// Put decrypted message to string
	stfDecryptor.Put(reinterpret_cast<const unsigned char*>(ciphertext.c_str()), ciphertext.size());
	stfDecryptor.MessageEnd();
	return output;

}