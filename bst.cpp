#include <stdio.h>

class Node {
private:
	char key;
	Node* left;
	Node* right;
public:
	Node(char K, Node* L, Node* R) {
		key = K;
		left = L;
		right = R;
	}
	char getKey() {
		return key;
	}
	Node* getLeft() {
		return left;
	}
	Node* getRight() {
		return right;
	}
	void setKey(char K) {
		key = K;
	}
	void setLeft(Node* L) {
		left = L;
	}
	void setRight(Node* R) {
		right = R;
	}
};

class BST {
private:
	Node* root;
	void traverse(Node* start) {
		printf("%c ", start->getKey());
		if (start->getLeft() != NULL) traverse(start->getLeft());
		if (start->getRight() != NULL) traverse(start->getRight());
		
	}
public:
	// 생성자
	BST(char key) {
		root = new Node(key, NULL, NULL);
	};
	// 새로운 key값 삽입
	void insert(char key) {
		Node* tempNode = root;
		while (1) {
			// key값이 현재 노드값보다 작을 때
			if (key < tempNode->getKey()) {
				if (tempNode->getLeft() == NULL) {
					Node* newNode = new Node(key, NULL, NULL);
					tempNode->setLeft(newNode);
					break;
				}
				else {
					tempNode = tempNode->getLeft();
				}
			}
			// key값이 현재 노드값보다 클 때
			else if (key > tempNode->getKey()) {
				if (tempNode->getRight() == NULL) {
					Node* newNode = new Node(key, NULL, NULL);
					tempNode->setRight(newNode);
					break;
				}
				else {
					tempNode = tempNode->getRight();
				}
			}
			// key값이 현재 노드값과 동일할 때
			else {
				printf("\n같은 키가 이미 존재합니다.\n");
				break;
			}
		}
	}
	// 트리구조 이미지화
	void printBST() {
		Node* tempNode = root;
		traverse(root);
	}
};

int main() {
	BST myBST = BST('G');
	myBST.insert('Z');
	myBST.insert('D');
	myBST.insert('A');
	myBST.insert('S');
	myBST.insert('K');
	myBST.printBST();
	return 0;
}
