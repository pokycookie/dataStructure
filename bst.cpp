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
	void traverse(Node* start, int level) {
		printf("[%d]%c ", level, start->getKey());
		level++;
		if (start->getLeft() != NULL) {
			traverse(start->getLeft(), level);
		}
		if (start->getRight() != NULL) {
			traverse(start->getRight(), level);
		}
	}
	void maxTraverse(Node* start, int level, int* max) {
		level++;
		if (level > *max) *max = level;
		if (start->getLeft() != NULL) maxTraverse(start->getLeft(), level, max);
		if (start->getRight() != NULL) maxTraverse(start->getRight(), level, max);
	}
public:
	// 생성자
	BST(char key) {
		root = new Node(key, NULL, NULL);
	};
	// key 삽입
	void insert(char key) {
		Node* tempNode = root;
		while (1) {
			// key값이 현재 노드값보다 작을 때
			if (key < tempNode->getKey()) {
				if (tempNode->getLeft() == NULL) {
					Node* newNode = new Node(key, NULL, NULL);
					printf("%c가 %c의 좌측에 삽입되었습니다.\n", key, tempNode->getKey());
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
					printf("%c가 %c의 우측에 삽입되었습니다.\n", key, tempNode->getKey());
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
	// key 삭제
	void remove(char key) {
		Node* parent = getParent(key);
		Node* target = search(key);

		// 삭제할 노드가 없음
		if (target == NULL || parent == NULL) {
			printf("%c는 존재하지 않습니다.\n", key);
			return;
		}
		// 삭제할 노드가 단말 노드
		if (target->getLeft() == NULL && target->getRight() == NULL) {
			if (parent->getLeft() == target) parent->setLeft(NULL);
			else parent->setRight(NULL);
			delete target;
		}
		// 삭제할 노드의 차수가 1
		else if (target->getLeft() == NULL || target->getRight() == NULL) {
			Node* child;
			if (target->getLeft() != NULL) child = target->getLeft();
			else child = target->getRight();
			
			if (parent->getLeft() == target) parent->setLeft(child);
			else parent->setRight(child);
			delete target;
		}
		// 삭제할 노드의 차수가 2
		else {
			// temp는 후계자
			Node* tempParent;
			Node* temp = target->getLeft();
			while (temp->getRight() != NULL) {
				tempParent = temp;
				temp = temp->getRight();
			}
			target->setKey(temp->getKey());
			if (temp->getLeft() == NULL) tempParent->setRight(NULL);
			else tempParent->setRight(temp->getLeft());
		}
	}
	// key 찾기
	Node* search(char key) {
		Node* tempNode = root;
		int level = 1;
		while (1) {
			if (key < tempNode->getKey()) {
				if (tempNode->getLeft() == NULL) break;
				tempNode = tempNode->getLeft();
			}
			else if (key > tempNode->getKey()) {
				if (tempNode->getRight() == NULL) break;
				tempNode = tempNode->getRight();
			}
			else {
				return tempNode;
			}
			level++;
		}
		return NULL;
	}
	// 부모 찾기
	Node* getParent(char key) {
		Node* parent = root;
		Node* tempNode = root;
		while (1) {
			if (key < tempNode->getKey()) {
				if (tempNode->getLeft() == NULL) break;
				tempNode = tempNode->getLeft();
			}
			else if (key > tempNode->getKey()) {
				if (tempNode->getRight() == NULL) break;
				tempNode = tempNode->getRight();
			}
			else {
				return tempNode;
			}
			parent = tempNode;
		}
		return NULL;
	}
	// 트리의 높이
	int getMaxLevel() {
		int max = 1;
		maxTraverse(root, 0, &max);
		return max;
	}
	// 트리구조 이미지화
	void printBST() {
		traverse(root, 1);
	}
};

int main() {
	BST myBST = BST('G');
	myBST.insert('Z');
	myBST.insert('D');
	myBST.insert('C');
	myBST.insert('F');
	myBST.insert('S');
	myBST.insert('A');
	myBST.insert('T');
	myBST.insert('K');
	myBST.printBST();
	myBST.search('A');
	myBST.search('M');
	return 0;
}
