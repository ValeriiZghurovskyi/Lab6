#include <iostream>

template<typename T>
class DoublyLinkedList {
private:
    struct Node {
        T data;
        Node* prev;
        Node* next;
    };

    Node* head; // ������� ������
    int size; // ����� ������

public:

    DoublyLinkedList();
    ~DoublyLinkedList();

    int getSize(); // ��������� ������
    bool contains(T& value); //�������� �� ������� ������� � ����� ������
    int indexOf(T& value); // ������� ������� �������� � ������� ���������
    void insert(const T& value, int position); // �������� ����� ������� � ������� � ������� �������
    void clear(); // ����� ������


    
    class Iterator { // �������� ��� ������� �� �������� ������
    private:
        Node* current; // �������� �������

    public:
        Iterator() : current(nullptr) {}
        Iterator(Node* node);

        bool isEnd(); // ��������, �� ��������� ���� ������
        T& value(); // ������� �������� ��������� ��������
        void next(); // ������� �������� �� ��������� �������
        void previous(); // ������� �������� �� ��������� �������
        friend class DoublyLinkedList;
    };

    Iterator begin(){ // ������� ��������, ������������ �� ������� ������
        return Iterator(head);
    }
};

template<typename T>
DoublyLinkedList<T>::DoublyLinkedList() {
    head = nullptr;
    size = 0;
}

template<typename T>
DoublyLinkedList<T>::~DoublyLinkedList() {
    clear();
}

template<typename T>
int DoublyLinkedList<T>::getSize(){
    return size;
}

template<typename T>
bool DoublyLinkedList<T>::contains(T& value) {
    Node* current = head;

    if (current != nullptr) {
        do {
            if (current->data == value) {
                return true;
            }
            current = current->next;
        } while (current != head);
    }

    return false;
}


template<typename T>
int DoublyLinkedList<T>::indexOf(T& value) {
    Node* current = head;
    int index = 0;

    if (current != nullptr) {
        do {
            if (current->data == value) {
                return index;
            }
            current = current->next;
            index++;
        } while (current != head);
    }

    return -1;
}


template<typename T>
void DoublyLinkedList<T>::insert(const T& value, int position) {
    if (position < 0 || position > size) {
        throw std::out_of_range("Invalid position");
    }

    Node* newNode = new Node();
    newNode->data = value;

    if (head == nullptr) {
        newNode->prev = newNode;
        newNode->next = newNode;
        head = newNode;
    }
    else {
        Node* current = head;

        for (int i = 0; i < position - 1; i++) {
            current = current->next;
        }

        newNode->prev = current;
        newNode->next = current->next;
        current->next = newNode;
        newNode->next->prev = newNode;

        if (position == 0) {
            head = newNode;
        }
    }

    size++;
}


/*template<typename T>
void DoublyLinkedList<T>::insert(const T& value, int position) {
    if (position < 0 || position > size) {
        throw std::out_of_range("Invalid position");
    }

    Node* newNode = new Node();
    newNode->data = value;

    if (head == nullptr) {
        newNode->prev = newNode;
        newNode->next = newNode;
        head = newNode;
    }
    else {
        Node* current = head;

        for (int i = 0; i < position - 1; i++) {
            current = current->next;
        }

        newNode->prev = current;
        newNode->next = current->next;
        current->next = newNode;
        newNode->next->prev = newNode;

        if (position == 0) {
            head = newNode;
        }
    }
    size++;
}*/


template<typename T>
void DoublyLinkedList<T>::clear(){
    if (head != nullptr) {
        Node* current = head;
        Node* nextNode;

        do {
            nextNode = current->next;
            delete current;
            current = nextNode;
        } while (current != head);

        head = nullptr;
        size = 0;
    }
}


template<typename T>
DoublyLinkedList<T>::Iterator::Iterator(Node* node) {
    current = node;
}


template<typename T>
bool DoublyLinkedList<T>::Iterator::isEnd() {
    return current == head;
}


/* DoublyLinkedList<T>::Iterator::isEnd() {
    return current == nullptr;
}*/


template<typename T>
T& DoublyLinkedList<T>::Iterator::value(){
    if (current == nullptr) {
        throw std::out_of_range("Iterator is out of range");
    }

    return current->data;
}


template<typename T>
void DoublyLinkedList<T>::Iterator::next() {
    if (current != nullptr) {
        current = current->next;
    }
}


template<typename T>
void DoublyLinkedList<T>::Iterator::previous() {
    if (current != nullptr) {
        current = current->prev;
    }
}