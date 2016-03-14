#include<string>
#include <ctime>
#include <vector>
#include <iostream>
#include "RSA.h"
using namespace std;

vector<char> linearCipherEncrypt(vector<char>message) {
	vector<int> plaintext = charToIntArr(message);
	cout << "\nEnter password:\n";
	string password = getString();
	int product=1, sum=0;
	unsigned long long pos;
	for (int i = 0; i < password.length(); i++) {
		product *= password[i];
		sum += password[i];
	}
	
	
	
	for (int i = 0; i < message.size(); i++) {
		plaintext[i] +=product;
		plaintext[i] %= 128;
		
		cout << plaintext[i] << " ";
		
	}

	return intToCharArr(plaintext);
}

vector<char> linearCipherDecrypt(vector<char>message) {
	cout << "\nEnter password:\n";
	string password = getString();
	int product = 1, sum = 0;
	for (int i = 0; i < password.length(); i++) {
		product *= password[i];
		sum += password[i];
	}
	
	int pos;
	for (int i = 0; i < message.size(); i++) {

		pos = message[i];
		pos -= product;
		
		
		message[i] = pos;
		

	}

	return message;
}

	int xGCD(int a, int b, int &x, int &y) {
		if (b == 0) {
			x = 1;
			y = 0;
			return a;
		}

		int x1, y1, gcd = xGCD(b, a % b, x1, y1);
		x = y1;
		y = x1 - (a / b) * y1;
		return gcd;
	}

int gcd(int a, int b) {
	if (b == 0)
		return a;
	return gcd(b, a%b);

}

int lcm(int a, int b) {
	return (a*b) / gcd(a, b);

}

int multiInverse(int num, int base, int &x, int &y) {
	if (base == 0) {
		x = 1;
		y = 0;
		return num;
	}

	int x1, y1, gcd = xGCD(base, num % base, x1, y1);
	x = y1;
	y = x1 - (num / base) * y1;
	return x;
}

int multiInverse(int num, int base) {
	int x, y;
	if (base == 0) {
		x = 1;
		y = 0;
		return num;
	}

	int x1, y1, gcd = xGCD(base, num % base, x1, y1);
	x = y1;
	y = x1 - (num / base) * y1;
	return x;
}

/*int rsaEncrypt(string password) {
	srand(time(NULL));

	vector<bool> isPrime(4294967296, true);
	vector<int> listOfPrimes;
	listOfPrimes.push_back(2);
	for (int i = 2; i < 4294967296; i += 2) {
			if (isPrime[i] == true) {
			listOfPrimes.push_back(i + 1);
			for (int j = i + i + 1; j < 4294967296 && j != 1; j += i + 1) {
				isPrime[j] = false;
			}
		}
	}
	int p = listOfPrimes[rand() % 50000 + 50000];
	int q = listOfPrimes[rand() % 50000 + 50000];
	unsigned long long n = p*q;
	int a = multiInverse()
}*/
