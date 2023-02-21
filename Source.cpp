#include<iostream>

class List {

public:
	List* ptr;
	int value;

	List() {


	}
};


class LinkedList {
public:
	List* head;
	List* tail;

	LinkedList() {
		head = NULL; 
		tail = NULL;

	}

	void addElementBack(int value);
	void addElementFront(int value);
	void addAtIndex(int index, int value);
	void print();

};


void LinkedList::addElementBack(int value) {
	List* newPtr = new List();
	newPtr->value = value;
	newPtr->ptr = NULL;


	if (head == NULL) {            // chacking for no element is added before
		head = newPtr;
		tail = head;
		std::cout << "Element added" << std::endl;
	}
	else {
		tail->ptr = newPtr;
		tail = newPtr->ptr;
		std::cout << "Element added" << std::endl;
		return;
	}


}

void LinkedList::addElementFront(int value) {
	List* newPtr = new List();
	newPtr->value = value;
	newPtr->ptr = NULL;

	if (head == NULL) {
		head = newPtr;
		tail = newPtr;
		std::cout << "Element added" << std::endl;
	}
	else {
		newPtr->ptr = head;
		head = newPtr->ptr;
		std::cout << "Element added" << std::endl;
	}
}


int main() {

	LinkedList list;
	list.addElementBack(10);
	list.addElementBack(25);
	list.addElementFront(3);
}

