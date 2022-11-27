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
		printf("[%c:%d] ", start->getKey(), level);
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
		if (level > * max) *max = level;
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
		// Root가 NULL일 때
		if (root->getKey() == NULL) {
			root->setKey(key);
			printf("%c가 루트로 삽입되었습니다.\n", key);
		}
		// Root가 NULL이 아닐 때
		else {
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
	}
	// key 삭제
	void remove(char key) {
		Node* parent = getParent(key);
		Node* target = search(key);

		if (parent == NULL) parent = root;
		
		// 삭제할 노드가 없음
		if (target == NULL) {
			printf("%c는 존재하지 않습니다.\n", key);
		}
		else {
			if (target == root) printf("루트 %c가 삭제되었습니다.\n", root->getKey());
			else printf("%c의 자식 %c가 삭제되었습니다.\n", parent->getKey(), target->getKey());
			// 삭제할 노드가 단말 노드
			if (target->getLeft() == NULL && target->getRight() == NULL) {
				if (parent->getLeft() == target) parent->setLeft(NULL);
				else parent->setRight(NULL);
			}
			// 삭제할 노드의 차수가 1
			else if (target->getLeft() == NULL || target->getRight() == NULL) {
				Node* child;
				if (target->getLeft() != NULL) child = target->getLeft();
				else child = target->getRight();

				if (parent->getLeft() == target) parent->setLeft(child);
				else parent->setRight(child);
			}
			// 삭제할 노드의 차수가 2
			else {
				// temp는 후계자, tempParent는 후계자의 부모
				// 왼쪽노드에서 후계자 선택
				Node* temp = target->getLeft();
				Node* tempParent = target;
			
				// 후계자 선택 (가장 우측의 노드)
				while (temp->getRight() != NULL) {
					tempParent = temp;
					temp = temp->getRight();
				}
			
				// 삭제할 노드의 key를 후계자의 key값으로 대체
				target->setKey(temp->getKey());

				// 후계자의 자식노드(왼쪽)가 없는 경우, 후계자 부모와 후계자의 연결 끊음
				if (temp->getLeft() == NULL) tempParent->setLeft(NULL);

				// 후계자의 자식노드(왼쪽)가 있는 경우, 후계자 부모와 후계자의 자식을 연결
				else tempParent->setLeft(temp->getLeft());
			}
		}
	}
	// key 찾기
	Node* search(char key) {
		Node* tempNode = root;
		while (tempNode != NULL) {
			if (key < tempNode->getKey()) tempNode = tempNode->getLeft();
			else if (key > tempNode->getKey()) tempNode = tempNode->getRight();
			else return tempNode;
		}
		return NULL;
	}
	// 부모 찾기
	Node* getParent(char key) {
		Node* parent = NULL;
		Node* tempNode = root;
		while (tempNode != NULL) {
			if (key < tempNode->getKey()) { parent = tempNode; tempNode = tempNode->getLeft(); }
			else if (key > tempNode->getKey()) { parent = tempNode; tempNode = tempNode->getRight(); }
			else return parent;
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
		printf("\n");
		if (root->getKey() == NULL) printf("트리가 비었습니다.");
		else traverse(root, 1);
	}
};

void printMenu() {
	printf("\n==============================================\n");
	printf("1: 삽입, 2: 삭제, 3: 전체 트리 확인, 4: 찾기");
}

int main() {
	BST myBST = BST(NULL);
	while (1) {
		printMenu();
		printf("\n[메뉴를 선택하세요]: ");
		char input = getchar();
		while (getchar() != '\n');
		char key;
		Node* result;
		switch (input)
		{
		case '1':
			printf("\n삽입할 key를 입력하세요: ");
			key = getchar();
			while (getchar() != '\n');
			printf("\n");
			myBST.insert(key);
			break;
		case '2':
			printf("\n삭제할 key를 입력하세요: ");
			key = getchar();
			while (getchar() != '\n');
			myBST.remove(key);
			break;
		case '3':
			myBST.printBST();
			printf("\n");
			break;
		case '4':
			printf("\n찾을 key를 입력하세요: ");
			key = getchar();
			while (getchar() != '\n');
			result = myBST.search(key);
			if (result) {
				printf("\n%c를 찾았습니다.\n", result->getKey());
			}
			else {
				printf("\n%c를 찾을 수 없습니다.\n", key);
			}
			break;
		default:
			break;
		}
	}
	return 0;
}
