// (Pythagorean Triples) A right triangle can have sides that are all integers. A set of
// three integer values for the sides of a right triangle is called a Pythagorean triple.
// These three sides must satisfy the relationship that the sum of the squares of two of
// the sides is equal to the square of the hypotenuse. Find all Pythagorean triples for
// side1, side2 and hypotenuse all no larger than 500. Use a triple-nested for loop that
// tries all possibilities. This is an example of brute force computing. You will learn in
// more advanced computer-science courses that there are many interesting problems
// for which there is no known algorithmic approach other than sheer brute force. 

#include <iostream>
#include <cmath>
using namespace std;

#define MAX 500

int main()
{
	int side1, side2, hypo;
	for (side1 = 1; side1 <= MAX; side1++)
		for (side2 = 1; side2 <= MAX; side2++)
			for (hypo = 1; hypo <= MAX; hypo++)
				if (pow(side1, 2) + pow(side2, 2) == pow(hypo, 2) && side1 < side2)
					cout << side1 << "," << side2 << "," << hypo << endl;
}
