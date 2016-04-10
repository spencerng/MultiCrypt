// ( Airline Reservations System) A small airline has just purchased a computer for its
// new automated reservations system. You have been asked to program the new
// system. You are to write a program to assign seats on each flight of the airline's only
// plane (capacity: 10 seats).
// Your program should display the following menu of alternativesPlease type 1 for
// "First Class" and Please type 2 for "Economy". If the person types 1, your program
// should assign a seat in the first class section (seats 1-5). If the person types 2, your
// program should assign a seat in the economy section (seats 6-10). Your program
// should print a boarding pass indicating the person's seat number and whether it is in
// the first class or economy section of the plane.
// Use a one-dimensional array to represent the seating chart of the plane. Initialize all
// the elements of the array to 0 to indicate that all seats are empty. As each seat is
// assigned, set the corresponding elements of the array to 1 to indicate that the seat
// is no longer available.
// Your program should, of course, never assign a seat that has already been assigned.
// When the first class section is full, your program should ask the person if it is
// acceptable to be placed in the economy section (and vice versa). If yes, then make
// the appropriate seat assignment. If no, then print the message "Next flight leaves
// in 3 hours". 

#include<iostream>
#include<vector>
#include<string>
#include <algorithm>
using namespace std;

void printPass(int seat, string status);

int main() {
	
	int firstPos = 0, ecoPos = 5;
	while (1) {
		system("cls");
		int choice;
		char chChoice;

		if (firstPos==5 && ecoPos==10) {
			cout << "All seats are now full. Goodbye.\n";
			system("pause");
			return 0;
		}

		cout << "Please type '1' for \"Economy\"\nPlease type '2' for \"First Class\"\nType -1 to quit\n";
		cin >> choice;
		cout << endl;
		if (choice == 1) {
			if (ecoPos != 10) {
				cout << "Your boarding pass is:\n";
				printPass(ecoPos++ + 1, "Economy");
			}
			else {
				cout << "All economy seats are full.\nIs it acceptable to be placed in first class? (Y/N)\n";
				cin >> chChoice;
				if (tolower(chChoice) == 'y'&&firstPos!=5) {
					cout << "Your boarding pass is:\n";
					printPass(firstPos++ + 1, "First Class");

				}
				else cout << "\nNext flight leaves in 3 hours.\n\n";
					
			}
		}
		else if (choice == 2) {
			if (firstPos != 5) {
				cout << "Your boarding pass is:\n";
				printPass(firstPos++ + 1, "First Class");
			}
			else {
				cout << "All seats in first class are full.\nIs it acceptable to be placed in the economy section? (Y/N)\n";
				cin >> chChoice;
				if (tolower(chChoice) == 'y'&&ecoPos != 10) {
					cout << "Your boarding pass is:\n";
					printPass(ecoPos++ + 1, "Economy");

				}
				else cout << "\nNext flight leaves in 3 hours.\n\n";

			}
		}
		else return 0;
		system("pause");
	}

}

void printPass(int seat, string status) {
	cout << " ______________________________________" << endl;
	cout << "|                                      |" << endl;
	cout << (seat==10 ? ("|               Seat " + to_string(seat) + "                |") : ("|               Seat " + to_string(seat) + "                 |")) << endl;
	cout << "|                                      |" << endl;
	cout << (status=="First Class" ? ("|             " + status + "              |" ):("|               " + status + "                |")) << endl;
	cout << "|                                      |" << endl;
	cout << "|______________________________________|" << endl;

}
