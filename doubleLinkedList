#include <stdio.h>
#include <stdlib.h>
#include <string.h>

class ListNode {
private:
	ListNode* prevLink;
	char* data;
	ListNode* nextLink;
public:
	ListNode(ListNode* prev, ListNode* next, const char* newData) {
		prevLink = prev;
		nextLink = next;
		data = (char*)newData;
	}
	void setPrev(ListNode* prev) {
		prevLink = prev;
	}
	void setNext(ListNode* next) {
		nextLink = next;
	}
	char* getData() {
		return data;
	}
	ListNode* getPrev() {
		return prevLink;
	}
	ListNode* getNext() {
		return nextLink;
	}
};

class DoubleLinkedList {
private:
	ListNode* HEAD;
	ListNode* TAIL;
public:
	DoubleLinkedList() {
		HEAD = NULL;
		TAIL = NULL;
	}
	void append(const char* data) {
		if (HEAD == NULL) {
			ListNode* newNode = new ListNode(NULL, NULL, data);
			HEAD = newNode;
			TAIL = newNode;
		}
		else {
			ListNode* newNode = new ListNode(TAIL, NULL, data);
			TAIL->setNext(newNode);
			TAIL = newNode;
		}
	}
	void insert(const char* data, ListNode* insertPoint) {
		if (insertPoint == NULL) return;
		if (insertPoint->getPrev() == NULL) {
			// When insertPoint is HEAD
			ListNode* newNode = new ListNode(NULL, insertPoint, data);
			insertPoint->setPrev(newNode);
			HEAD = newNode;

		}
		else {
			// Others
			ListNode* prev = insertPoint->getPrev();
			ListNode* newNode = new ListNode(prev, insertPoint, data);
			prev->setNext(newNode);
			insertPoint->setPrev(newNode);
		}
	}
	void remove(ListNode* removeNode) {
		if (removeNode == NULL) return;

		ListNode* prev = removeNode->getPrev();
		ListNode* next = removeNode->getNext();
		if (prev != NULL) {
			prev->setNext(next);
		}
		else {
			HEAD = next;
		}
		if (next != NULL) {
			next->setPrev(prev);
		}
		else {
			TAIL = prev;
		}
		delete removeNode;
	}
	ListNode* find(const char* data) {
		ListNode* current = HEAD;
		while (current->getNext() != NULL) {
			if (strcmp(data, current->getData()) == 0) {
				return current;
			}
			current = current->getNext();
		}
		if (strcmp(data, current->getData()) == 0) {
			return current;
		}
		return NULL;
	}
	char* get(int index) {
		if (index < 0) return (char*)"NULL";

		ListNode* current = HEAD;
		for (int i = 0; i < index; i++) {
			current = current->getNext();
		}
		char* result = current->getData();
		return result;
	}
	void printAll() {
		ListNode* current = HEAD;
		while (current->getNext() != NULL) {
			printf("%s ", current->getData());
			current = current->getNext();
		}
		printf("%s\n", current->getData());
	}
};

void main() {
	DoubleLinkedList myList = DoubleLinkedList();
	myList.append("Hello");
	myList.append("World");
	myList.append("Hi");
	myList.append("Poky");
	myList.append("Cookie");
	printf("%s\n", myList.get(3));
	myList.remove(myList.find("Cookie"));
	myList.printAll();
	myList.insert("Pretty", myList.find("World"));
	myList.printAll();
}
