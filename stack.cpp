#include <stdio.h>
#include <string.h>

#define true 1
#define false 0

class LinkedList {
private:
	LinkedList* prev;
	char data;
public:
	LinkedList(LinkedList* initPrev, char initData) {
		prev = initPrev;
		data = initData;
	}
	LinkedList* getPrev() {
		return prev;
	}
	char getValue() {
		return data;
	}
};

class Stack {
private:
	LinkedList* TOP = NULL;
public:
	void push(char data) {
		LinkedList* newData = new LinkedList(TOP, data);
		TOP = newData;
	}
	char pop() {
		if (TOP != NULL) {
			LinkedList* tempTOP = TOP;
			TOP = TOP->getPrev();
			return tempTOP->getValue();
		}
	}
	int isEmpty() {
		if (TOP == NULL) return true;
		else return false;
	}
};

int checkPair(const char* str) {
	Stack pairStack = Stack();
	for (int i = 0; i < strlen(str); i++) {
		char value = str[i];
		switch (value) {
		case '(':
		case '{':
		case '[':
			pairStack.push(value);
			break;
		case ')':
		case '}':
		case ']':
			if (pairStack.isEmpty()) return false;
			char result = pairStack.pop();
			if (result == '(' && value != ')' || result == '{' && value != '}' || result == '[' && value != ']') return false;
			break;
		}
	}
	if (pairStack.isEmpty()) return true;
	else return false;
}

void main() {
	Stack myStack = Stack();
	myStack.push('A');
	myStack.push('B');
	myStack.push('C');
	myStack.push('D');
	myStack.push('E');
	printf("%c", myStack.pop());
	printf("%c", myStack.pop());
	printf("%c", myStack.pop());
	printf("%c", myStack.pop());
	printf("%c\n", myStack.pop());

	printf("%s\n", checkPair("({1234})+{42*(32+64)+14/2}") ? "true" : "false");
}
