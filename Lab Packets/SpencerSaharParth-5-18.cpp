// Write a program that prints a table of the binary, octal and hexadecimal equivalents
// of the decimal numbers in the range 1 through 256. 

#include<iostream>
#include<iomanip>
#include<bitset>
using namespace std;


int main() {
	cout << setw(8) << "Decimal" << " | " << setw(8) << " Binary" << "  | " << setw(8) << "Octal" << " | " << setw(8) << "Hexadecimal" << endl;
	cout << setw(50) << setfill('-') << ' ' << endl;
	for (int i = 1; i <= 256; i++) {

		cout << setw(8) <<setfill(' ') << dec <<  i;
		cout << " | " << setw(8) << bitset<9>(i);
		cout << " | " << setw(8) << oct << i;
		cout << " | " << setw(8) << uppercase << hex << i << endl;
	}

	return 0;
}