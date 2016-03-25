// Input an integer containing only 0s and 1s (i.e., a "binary" integer) and print its
// decimal equivalent. Use the modulus and division operators to pick off the "binary"
// number's digits one at a time from right to left. Much as in the decimal number
// system, where the rightmost digit has a positional value of 1, the next digit left has
// a positional value of 10, then 100, then 1000, and so on, in the binary number
// system the rightmost digit has a positional value of 1, the next digit left has a
// positional value of 2, then 4, then 8, and so on. Thus the decimal number 234 can
// be interpreted as 2 * 100 + 3 * 10 + 4 * 1. The decimal equivalent of binary 1101 is
// 1 * 1 + 0 * 2 + 1 * 4 + 1 * 8 or 1 + 0 + 4 + 8, or 13. 

#include<iostream>
using namespace std;

int binToDec(unsigned long long);

int main(){
	unsigned long long bin;
	cout << "Please enter a binary number: ";
	cin >> bin;
	cout << bin << " as a decimal number is " << binToDec(bin) << "." << endl;
	
	
	return 0;
}

int binToDec(unsigned long long binIn) {
	long long decOut = 0;
	int power = 0;

	while (binIn != 0) {
		decOut += pow(2, power) * (binIn % 10);
		binIn /= 10;

		power++;
	}
	return decOut;
}