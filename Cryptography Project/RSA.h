#ifndef RSA_H
#define RSA_H
#include <string>
using std::string;

int xGCD(int a, int b, int &x, int &y);

int gcd(int a, int b);
int lcm(int a, int b);

int multiInverse(int num, int base, int &x, int &y);


int rsaEncrypt(string password);
#endif