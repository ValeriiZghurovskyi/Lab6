#pragma once
#include <iostream>
#include "list.h"


using namespace std;

template<typename T>
void workWithList(List<T>& list) {

	int choise = -1;
	do {
		cout << endl << "1. Check list size" << endl;
		cout << "2. Push back new element" << endl;
		cout << "3. Push front new element" << endl;
		cout << "4. Add new element in list in chosen position" << endl;
		cout << "5. Find element in list" << endl;
		cout << "6. Find element position in list" << endl;
		cout << "7. Print all list" << endl;
		cout << "8. Exit" << endl;
		cout << endl << "Enter your choice: ";
		cin >> choise;
		T element;
		int pos;
		int index;
		typename List<T>::Iterator it;
		switch (choise) {
		case 1:
			cout << "List size: " << list.GetSize() << endl;
			break;
		case 2:
			cout << "Enter your element: ";
			cin >> element;
			list.push_back(element);
			break;
		case 3:
			cout << "Enter your element: ";
			cin >> element;
			list.push_front(element);
			break;
		case 4:
			cout << "Enter your element: ";
			cin >> element;
			cout << "Enter position: ";
			cin >> pos;
			list.insert(element, pos);
			break;
		case 5:
			cout << "Enter your element: ";
			cin >> element;
			if (list.contains(element)) {
				cout << "Our list contains your element" << endl;
			}
			else {
				cout << "Your element wasn`t find in list" << endl;
			}
			break;
		case 6:
			cout << "Enter your element: ";
			cin >> element;
			if (list.contains(element)) {
				cout << "Your element in " << list.find_pos(element) + 1 << " position" << endl;
			}
			else {
				cout << "Your element wasn`t find in list" << endl;
			}
			break;

		case 7:
			list.print();
			break;

		case 8:
			cout << "Have a nice day!";
			break;
		default:
			cout << "Invalid choise! Try again" << endl;
			break;
		}
	} while (choise != 8);
}
