#ifndef RSA_H
#define RSA_H
#include <string>
#include<vector>
using std::vector;
using std::string;

int xGCD(int a, int b, int &x, int &y);

int gcd(int a, int b);
int lcm(int a, int b);

int multiInverse(int num, int base, int &x, int &y);
int multiInverse(int num, int base);
// Works if and only if num and base are coprime. That is, they share no common factors.

vector<char> intToCharArr(vector<int> input);
vector<int> charToIntArr(vector<char> input);

string getString();

vector<char> linearCipherEncrypt(vector<char> message);
vector<char> linearCipherDecrypt(vector<char> message);

int rsaEncrypt(string password);
#endif