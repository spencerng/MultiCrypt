/*(Recursive Greatest Common Divisor) The greatest common divisor of integers x and y is
the largest integer that evenly divides both x and y. Write a recursive function gcd that
returns the greatest common divisor of x and y, defined recursively as follows: If y is
equal to 0, then gcd( x, y ) is x; otherwise, gcd( x, y ) is gcd( y, x % y ), where % is
the modulus operator. [Note: For this algorithm, x must be larger than y.]  */


#include<iostream>
using namespace std;

int gcd(int, int);

int main() {

	int num1, num2;
	cout << "Please enter two space-separated numbers:" << endl;
	cin >> num1 >> num2;
	cout << "The greatest common divisor of " << num1 << " and " << num2 << " is " << gcd(num1, num2) << '.' << endl;



	return 0;
}

int gcd(int a, int b) {
	if (b == 0)
		return a;
	return gcd(b, a%b);

}