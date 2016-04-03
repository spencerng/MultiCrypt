#include "Headers/RSA.h"
#include "Headers/IO.h"
#include "Headers/Conversions.h"
#pragma warning(disable:4996)
using std::vector;
using std::cout;
using std::endl;
using namespace CryptoPP;

string md5String(string message) {
	CryptoPP::MD5 hash;
	byte digest[CryptoPP::MD5::DIGESTSIZE];
	hash.CalculateDigest(digest, (byte*)message.c_str(), message.length());
	CryptoPP::HexEncoder encoder;
	string hashOutput;
	encoder.Attach(new CryptoPP::StringSink(hashOutput));
	encoder.Put(digest, sizeof(digest));
	encoder.MessageEnd();
	return hashOutput;

}

string shaFile(string filePath) {
	string result;
	CryptoPP::SHA1 hash;
	CryptoPP::FileSource(filePath.c_str(), true, new CryptoPP::HashFilter(hash, new CryptoPP::HexEncoder(new CryptoPP::StringSink(result), true)));
	return result;

}

void hashToByte(string hash, byte key[], int bytes) {
	std::stringstream ss(hash);
	int temp;
	for (int i = 0; i < bytes; i++) {
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

	int seed = 0;
	for (int i = 0; i < password.length(); i++)
		seed += (password[i] * 127) % (i + 23);
	srand(seed);

	string hash1 = insertSpace(md5String(password));
	
	hash1 += insertSpace(md5String(hash1));

	for (int i = 0; i < hash1.length(); i++) 
		if (isalpha(hash1[i]) && (rand() % 2))
			hash1[i] = tolower(hash1[i]);
	hashToByte(hash1, key, 32);

	int seed2 = 0;
	string hash2 = "";
	for (int i = 0; i < hash1.length(); i++)
		hash2 += password[rand() % password.length()]+rand();
	hash2 = insertSpace(md5String(hash2));
	
	hashToByte(hash2, iv, 16);


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
	
	CryptoPP::StreamTransformationFilter stfEncryptor(cbcEncryption, new CryptoPP::StringSink(ciphertext));
	stfEncryptor.Put(reinterpret_cast<const unsigned char*>(plaintext.c_str()), plaintext.length() + 1);
	stfEncryptor.MessageEnd();
	
	std::stringstream buffer;
	
	for (int i = 0; i < ciphertext.size(); i++)
	buffer << std::hex << (0xFF & static_cast<byte>(ciphertext[i])) << " ";
	
	ciphertext = buffer.str();

	return ciphertext;
	
}

string aesDecrypt(string input, string password) {

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
	
	string output;
	CryptoPP::AES::Decryption aesDecryption(key, 32);
	CryptoPP::CBC_Mode_ExternalCipher::Decryption cbcDecryption(aesDecryption, iv);
	CryptoPP::StreamTransformationFilter stfDecryptor(cbcDecryption, new CryptoPP::StringSink(output));
	stfDecryptor.Put(reinterpret_cast<const unsigned char*>(ciphertext.c_str()), ciphertext.size());
	stfDecryptor.MessageEnd();
	return output;

}


// Need to fix input for arrow/function/special keys, which also return an ASCII value
string enterPassword() {
	string password;
	int charsEntered = 0;
	cout << '\t';
	unsigned char ch = _getch();
	while (ch != 13) { //character 13 is enter
		while (ch == 8) { // character 8 is backspace
			if (charsEntered != 0) { // Checks if there is anything to delete
				password.pop_back();
				cout << '\b' << ' ' << '\b'; // Moves cursor backwards, enters a blank character, then moves the cursor backwards again to prepare for overwrite
				charsEntered--;
			}
			ch = getch();
		}
		if (ch == 13)
			break;
		
		if (isprint(ch)) {
			charsEntered++;
			password.push_back(ch);
			cout << '*';
		}
			
		ch = _getch();
	}

	return password;
}

