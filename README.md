# LinkedListImplementation
#include<iostream>

class List {

public:
	List* ptr;
	int value;
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
	void search(int value);
};

void LinkedList::addElementBack(int value) {
	List* newPtr = new List();
	newPtr->value = value;
	newPtr->ptr = NULL;


	if (head == NULL) {            // checking for no element is added before
		head = newPtr;
		tail = newPtr;
		std::cout << "Element added" << std::endl;
	}
	else {
		tail->ptr = newPtr;
		tail = newPtr;
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
		head = newPtr;
		std::cout << "Element added" << std::endl;
	}
}

void LinkedList::addAtIndex(int index, int value) {
	List* previous= new List();
	List* current= new List();
	current = head;

	List* newPtr = new List();       // creation of new list
	newPtr->value = value;
	newPtr->ptr = NULL;

	if (index < 1) {
		std::cout << "Index cannot be less than one" << std::endl;
	}
	else if(index==1){
		newPtr->ptr = head;
		head = newPtr;
		std::cout << "Element added at index"" " << index << std::endl;
	}
	else {
		for (int i = 1; i < index; i++) {
			previous = current;
			current = current->ptr;
			if (current == NULL) {
				std::cout << "Invalid position" << std::endl;
				return;
			}
		}
		previous->ptr = newPtr;
		newPtr->ptr = current;
	}
}

void LinkedList::print() {
	List* current;
	current = head;
	while (current != NULL) {
		std::cout << current->value << " " ;
		current = current->ptr;
	}
}

void LinkedList::search(int value) {
	List* current;
	current = head;

	while (current != NULL) {
		if (current->value == value) {
			std::cout << "\n Element " << value << " found" << std::endl;
			return;
		}
		current = current->ptr;
	}
	std::cout << "\n Element " << value << " not found" << std::endl;
}

int main() {

	LinkedList list;
	list.addElementBack(10);
	list.addElementBack(25);
	list.addElementFront(15);
	list.addElementFront(22);
	list.addAtIndex(4, 34);
	list.print();
	list.search(34);
}

