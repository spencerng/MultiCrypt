// Use a two-dimensional array to solve the following problem. A company has four
// salespeople (1 to 4) who sell five different products (1 to 5). Once a day, each
// salesperson passes in a slip for each different type of product sold. Each slip
// contains the following:
// a. The salesperson number
// b. The product number
// c. The total dollar value of that product sold that day
// Thus, each salesperson passes in between 0 and 5 sales slips per day. Assume that
// the information from all of the slips for last month is available. Write a program that
// will read all this information for last month's sales and summarize the total sales by
// salesperson by product. All totals should be stored in the two-dimensional array
// sales. After processing all the information for last month, print the results in tabular
// format with each of the columns representing a particular salesperson and each of
// the rows representing a particular product. Cross total each row to get the total
// sales of each product for last month; cross total each column to get the total sales
// by salesperson for last month. Your tabular printout should include these cross totals
// to the right of the totaled rows and to the bottom of the totaled columns. 

#include<iostream>
#include<vector>
#include<iomanip>
using namespace std;

class Salesperson {

public:
	double sales[5];
	double totalSales;
	void sellItem(int itemNumber, double value) {
		sales[itemNumber - 1] += value;
	}

	void sumSales() {
		totalSales = 0;
		for (int i = 0; i < 5; i++)
			totalSales += sales[i];
	}
};

int main() {
	vector<Salesperson> sales(4, Salesperson());
	char choice;
	int salesNumber, productNumber;
	double value;
	do {
		cout << "What is the salesperson number? (1-4)\n";
		cin >> salesNumber;
		cout << "\nWhat is the product number? (1-5)\n";
		cin >> productNumber;
		cout << "\nWhat is the total dollar value of product " << productNumber << " sold that day?\n";
		cin >> value;

		sales[salesNumber - 1].sellItem(productNumber, value);

		cout << "\nWould you like to create a new salesslip? (Y/N)\n";
		cin >> choice;
		system("cls");
	} while (tolower(choice) == 'y');

	for (int i = 0; i < 4; i++)
		sales[i].sumSales();

	cout << "\t     ";
	for (int i = 1; i <= 4; i++)
		cout << setw(15) << "Salesperson " << i << " | ";
	cout << endl;
	for (int product = 0; product<5; product++) {
		cout << "Product " << product + 1 << ": |";
		double colSales = 0;
		for (int person = 0; person < 4; person++) {
			cout << setw(12) << "$" << setprecision(2) << fixed << sales[person].sales[product] << "  |";
			colSales += sales[person].sales[product];
		}
		cout << " $" << colSales << endl;
	}
	cout << "\t\t";
	/*for (int i = 0; i <4; i++)
		cout << setw(8) << setprecision(2) << fixed << "$" << sales[i].totalSales << " | ";
	cout << endl;*/
	return 0;
}
