/*#include "functions.h"

template<typename T>
void workWithList(DoublyLinkedList<T>& list) {

	int choise = -1;
	do {
		cout << endl << "1. Check list size" << endl;
		cout << "2. Find element in list" << endl;
		cout << "3. Find element position in list" << endl;
		cout << "4. Add new element in list in chosen position" << endl;
		cout << "5. Print all list" << endl;
		cout << "6. Exit" << endl;
		cout << endl << "Enter your choice: ";
		cin >> choise;
		switch (choise){
		case 1:
			cout << "List size: " << list.getSize() << endl;
			break;
		case 2:
			cout << "Enter your element: ";
			T element;
			cin >> element;
			if (list.contains(element)) {
				cout << "This item was found in the list";
			}
			else {
				cout << "This item wasn`t found in the list";
			}
			break;
		case 3:
			cout << "Enter your element: ";
			T element;
			cin >> element;
			int index = list.indexOf(element);
			if (index != -1) {
				cout << "\"" << element << "\" index: " << index + 1;
			}
			break;
		case 4:
			cout << "Enter your element: ";
			T element;
			cin >> element;
			cout << "Enter position: ";
			int pos;
			cin >> pos;
			list.insert(element, pos);
			break;
		case 5:
			typename DoublyLinkedList<T>::Iterator it = list.begin();
			typename DoublyLinkedList<T>::Iterator end = list.begin();

			if (list.getSize() != 0) {
				end.previous();
			} // якщо список не порожн≥й, отримуЇмо к≥нцевий ≥тератор

			while (!it.isEnd()) {
				cout << it.value() << endl;
				it.next();

				if (it.isEnd() && it.value() == end.value()) {
					break;
				}
			}
			break;
		default:
			cout << "Invalid choise! Try again" << endl;
			break;
		}
	} while (choise != 5);
}*/
