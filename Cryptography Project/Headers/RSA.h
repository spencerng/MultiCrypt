#ifndef RSA_H
#define RSA_H
#include<string>
#include<vector>
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

int rsaEncrypt(string password);
#endif