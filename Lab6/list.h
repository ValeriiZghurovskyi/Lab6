#include <iostream>


template<typename T>
class List {

	template<typename T>
	class Node {
	public:
		Node* pNext;
		Node* pPrev;
		T data;
		Node(T data = T(), Node* pNext = nullptr, Node* pPrev = nullptr) {
			this->data = data;
			this->pNext = pNext;
			this->pPrev = pPrev;
		}
	};

	Node<T> *head;
	int Size;


public:
	List();
	~List();
	int GetSize() {return this->Size;}
	void push_back(T data);
	void push_front(T data);
	void insert(T data, int pos);
	bool contains(T data);
	int find_pos(T data);

	class Iterator {
	private:
		Node<T>* current;
	public:
		Iterator() : current(nullptr){}
		Iterator(Node<T>* node) { current = node; }

		void setNode(Node<T>* node) { current = node; }
		Node<T>* getNode() { return current; }

		T& getValue() { return current->data; }

		Iterator operator++() { current = current->pNext; return *this; }
		Iterator operator--() { current = current->pPrev; return *this; }
		Iterator operator=(const Iterator& it) { current = it.current; return *this; }
		bool operator!=(const Iterator& it) { return this->current != it.current; }
	};

	Iterator begin() { return Iterator(head); }
	Iterator end() { return Iterator(head->pPrev); }
	void print();
};


template<typename T>
List<T>::List() {
	Size = 0;
	head = nullptr;
}

template<typename T>
List<T>::~List() {

}

template<typename T>
void List<T>::push_back(T data) {
	if (head == nullptr) {
		head = new Node<T>(data, head, head);
		head->pNext = head;
		head->pPrev = head;
	}
	else if (Size == 1){

		Node<T>* newNode = new Node<T>(data, head, head);
		head->pNext = newNode;
		head->pPrev = newNode;
	}
	else {
		Node<T>* last = head->pPrev;
		Node<T>* newNode = new Node<T>(data, head, last);
		head->pPrev = newNode;
		last->pNext = newNode;
	}
	Size++;
}


template<typename T>
void List<T>::push_front(T data) {
	head = new Node<T>(data, head, head->pPrev);
	Size++;
}


template<typename T>
void List<T>::insert(T data, int pos) {
	if (pos < 0) {
		std::cout << "Incorrect position!" << std::endl;
	}
	else if (pos == 0) {
		push_front(data);
	}
	else if (pos - 1 < Size){

		Node<T>* previous = this->head;

		for (int i = 0; i < pos - 1; i++) {
			previous = previous->pNext;
		}

		Node<T>* newNode = new Node<T>(data, previous->pNext, previous);
		previous->pNext = newNode;
		Size++;
	}
	else if (pos - 1 == Size) {
		push_back(data);
	}else {
		std::cout << "Incorrect position!" << std::endl;
	}
}



template<typename T>
bool List<T>::contains(T value) {
	if (Size == 0) {
		return false;
	} else {
		Node<T>* current = this->head;

		do {
			if (current->data == value) {
				return true;
			}
			current = current->pNext;
		} while (current->pNext != head);

		if (current->data == value) {
			return true;
		}

		return false;
	}
}


template<typename T>
int List<T>::find_pos(T value) {
	if (Size == 0) {
		return -1;
	}
	else {
		Node<T>* current = this->head;
		int pos = 0;

		do {
			if (current->data == value) {
				return pos;
			}
			current = current->pNext;
			pos++;
		} while (current->pNext != head);

		if (current->data == value) {
			return pos;
		}

		return -1;
	}
}



template<typename T>
void List<T>::print() {
	int counter = 1;
	for (auto it = begin(); it != end(); ++it) {
		std::cout << counter << ") " << it.getValue() << std::endl;
		counter++;
	}
	std::cout << counter << ") " << end().getValue() << std::endl;
}
