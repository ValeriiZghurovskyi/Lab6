#include <iostream>
#include "functions.h"


using namespace std;

int main() {


	int choise = -1;
	cout << "1. Create list with int data type" << endl;
	cout << "2. Create list with float data type" << endl;
	cout << "3. Create list with double data type" << endl;
	cout << "4. Create list with char data type" << endl;
	cout << "5. Create list with string data type" << endl;

	do {
		cout << "Enter your choise: ";
		cin >> choise;
	} while (choise != 1 && choise != 2 && choise != 3 && choise != 4 && choise != 5);

	if (choise == 1) {
		List<int> list;
		workWithList(list);
	}
	else if (choise == 2) {
		List<float> list;
		workWithList(list);
	}
	else if (choise == 3) {
		List<double> list;
		workWithList(list);
	}
	else if (choise == 4) {
		List<char> list;
		workWithList(list);
	}
	else if (choise == 5) {
		List<string> list;
		workWithList(list);
	}
	return 0;
}
