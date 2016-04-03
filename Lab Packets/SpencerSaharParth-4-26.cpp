// A palindrome is a number or a text phrase that reads the same backwards as
// forwards. For example, each of the following five-digit integers is a palindrome:
// 12321, 55555, 45554 and 11611. Write a program that reads in a five-digit integer
// and determines whether it is a palindrome. 

#include<iostream>
using namespace std;

bool isPalindrome(int);

int main() {
	int numb;

	cout << "Please enter a five digit number: ";
	cin >> numb;
	cout << numb << " is" << (isPalindrome(numb) ? "" : " not") << " a palindrome." << endl;

	return 0;
}

bool isPalindrome(int input) {
	int reverse = 0;
	int n = input;
	while (input != 0) {
		reverse = (reverse * 10) + (input % 10);
		input /= 10;

	}
	if (reverse == n)
		return true;
	else return false;
}