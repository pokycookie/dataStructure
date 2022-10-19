#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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
		if (TOP == NULL) return NULL;
		LinkedList* tempTOP = TOP;
		TOP = TOP->getPrev();
		return tempTOP->getValue();
	}
	int isEmpty() {
		if (TOP == NULL) return true;
		else return false;
	}
};

int checkSymbol(char symbol) {
	switch (symbol) {
	case '+':
	case '-':
	case '*':
	case '/':
	case '++':
	case '--':
	case '^':
	case '%':
		return true;
	default:
		return false;
	}
}

int checkPair(const char* str) {
	Stack pairStack = Stack();
	for (int i = 0; i < (int)strlen(str); i++) {
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

float caculator(char* exp) {
	// 괄호 체크
	if (!checkPair(exp)) return NULL;
	// 후위표기법으로 변환
	Stack expStack = Stack();
	char* value = (char*)"";
	for (int i = 0; i < (int)strlen(exp); i++) {
		char element = exp[i];
		if (!checkSymbol(element)) value[strlen(value)] = element;
		else printf("%f", atof(value));
	}
	printf("%s", value);
	return NULL;
}

int main() {
	// caculator((char*)"123.47 + 246.31");
	char* value = (char*)"123";
	char* element = (char*)'A';
	// strcat_s(value, strlen(element) + strlen(value) + 1, element);
	// strcat(value, element);
	printf("%s", value);

	return 0;
}
