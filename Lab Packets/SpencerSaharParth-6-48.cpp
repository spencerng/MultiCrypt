// Write function distance that calculates the distance between two points (x1, y1) and
// (x2, y2). All numbers and return values should be of type double. 

#include <iostream>
#include <cmath>
using namespace std;

double distance(double, double, double, double);

int main()
{
	double x1, x2, y1, y2;
	cout << "Enter the first point: ";
	cin >> x1 >> y1;
	cout << "Enter the second point: ";
	cin >> x2 >> y2;
	cout << "The distance between (" << x1 << "," << y1 <<") and (" << x2 << "," << y2
		<< ") is " << distance(x1, y1, x2, y2) << endl;
}

double distance(double x1, double y1, double x2, double y2)
{
	return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}
