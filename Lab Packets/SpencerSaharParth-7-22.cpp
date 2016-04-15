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
		cout << setw(15) << "Salesperson " << i << " |";
	cout << endl;
	for (int product = 0; product<5; product++) {
		cout << "Product " << product + 1 << ": |";
		double colSales = 0;
		for (int person = 0; person < 4; person++) {
			cout << setw(13) << "$" << setprecision(5) << sales[person].sales[product] << " | ";
			colSales += sales[person].sales[product];
		}
		cout << " $" << colSales << endl;
	}
	cout << "\t\t";
	for (int i = 0; i <4; i++)
		cout << setw(10) << setprecision(5) << "$" << sales[i].totalSales << " | ";
	cout << endl;
	return 0;
}