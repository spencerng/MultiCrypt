/*(Cryptography) A company wants to transmit data over the telephone, but is
concerned that its phones could be tapped. All of the data are transmitted as fourdigit
integers. The company has asked you to write a program that encrypts the data
so that it can be transmitted more securely. Your program should read a four-digit
integer and encrypt it as follows: Replace each digit by (the sum of that digit plus 7)
modulus 10. Then, swap the first digit with the third, swap the second digit with the
fourth and print the encrypted integer. Write a separate program that inputs an
encrypted fourdigit integer and decrypts it to form the original number. */
//Encryption

#include <iostream>
using namespace std;

int main()
{
	int num;
	cout << "Enter a 4-digit integer: ";
	cin >> num;
	int digit1 = num % 10;
	int digit2 = ((num - digit1) % 100) / 10;
	int digit3 = ((num - digit1 - (digit2 * 10)) % 1000) / 100;
	int digit4 = num / 1000;
	

	digit1 = (digit1 + 7) % 10;
	digit2 = (digit2 + 7) % 10;
	digit3 = (digit3 + 7) % 10;
	digit4 = (digit4 + 7) % 10;

	int enc1 = digit3;
	int enc2 = digit4;
	int enc3 = digit1;
	int enc4 = digit2;
	
	int encnum = enc1 + 10 * enc2 + 100 * enc3 + 1000 * enc4;
	cout << "The encrypted number is: " << encnum << endl;
}
