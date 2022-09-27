#include <stdio.h>;
#include <stdlib.h>;
#include <stdbool.h>;

template <typename T>
class List {
private:
	T* init = (T *)malloc(sizeof(T) * length);
	int nextIndex = 0;
	int length;
public:
	List<T>(int n) {
		length = n;
	}
	void append(T value);
	void insert(T value, int index);
	void replace(T value, int index);
	void remove(int index);
	void printTable();
	T get(int index);
	int size();
	int find(T value);
	bool isEmpty();
};

template <typename T>
void List<T>::append(T value) {
	init[nextIndex] = value;
	nextIndex++;
}

template <typename T>
void List<T>::insert(T value, int index) {
	if (index > nextIndex || index < 0) return;
	for (int i = nextIndex - 1; i > index - 1; i--) {
		init[i + 1] = init[i];
	}
	init[index] = value;
	nextIndex++;
}

template <typename T>
void List<T>::replace(T value, int index) {
	if (index < 0 || index > nextIndex - 1) return;
	init[index] = value;
}

template <typename T>
void List<T>::remove(int index) {
	if (index > nextIndex || index < 0) return;
	for (int i = index; i < nextIndex; i++) {
		init[i] = init[i + 1];
	}
	nextIndex--;
}

template <typename T>
void List<T>::printTable() {
	printf("|");
	for (int i = 0; i < nextIndex; i++) {
		printf(" %d |", init[i]);
	}
	printf("\n");
}

template <typename T>
T List<T>::get(int index) {
	return init[index];
}

template <typename T>
int List<T>::size() {
	return nextIndex;
}

template <typename T>
int List<T>::find(T value) {
	int index = -1;
	for (int i = 0; i < nextIndex; i++) {
		T currentValue = init[i];
		if (currentValue == value) {
			index = i;
			break;
		}
	}
	return index;
}

template <typename T>
bool List<T>::isEmpty() {
	if (nextIndex == 0) return true;
	else false;
}

void main() {
	List<int> myList(10);

	// myList에 항목 추가하기 (append)
	myList.append(13);
	myList.append(55);
	myList.append(36);
	myList.append(77);
	myList.append(37);
	myList.printTable();

	// myList에 항목 끼워넣기 (insert)
	myList.insert(99, 2);
	myList.printTable();

	// myList값 중 99를 찾아서 10으로 바꾸기 (find, replace)
	myList.replace(10, myList.find(99));
	myList.printTable();

	// myList값 중 10을 찾아서 삭제하기 (find, remove)
	myList.remove(myList.find(10));
	myList.printTable();

	// myList값 중 특정 index의 값 가져오기 (get)
	printf("myList[2]: %d\n", myList.get(2));

	// myList의 전체 길이 가져오기 (size)
	printf("size: %d\n", myList.size());
}
