// 5 Use a one-dimensional array to solve the following problem. Read in 20 numbers,
// each of which is between 10 and 100, inclusive. As each number is read, validate it
// and store it in the array only if it is not a duplicate of a number already read. After
// reading all the values, display only the unique values that the user entered. Provide
// for the "worst case" in which all 20 numbers are different. Use the smallest possible
// array to solve this problem. 

#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;

int main() {
	vector<int> numbers;
	int num;
	for (int i = 0; i < 20; i++) {
		cout << "Enter #" << i + 1 << ": ";
		cin >> num;
		if (find(numbers.begin(), numbers.end(), num) == numbers.end())
			numbers.push_back(num);
	}

	sort(numbers.begin(), numbers.end());

	cout << "\n\nThe unique values are:\n\n";
	for (int i = 0; i < numbers.size()-1; i++)
		cout << numbers[i] << ", ";

	cout << numbers[numbers.size() - 1] << endl << endl;

	return 0;
}
