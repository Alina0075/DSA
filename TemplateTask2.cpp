#include<iostream>
#include<string>

using namespace std;

template<typename Type>
class list {
protected:
	Type* arr;
	int maxSize;
	int currentSize;

public:
	list(int);
	list(list& obj);
	virtual void addElementAtFirstIndex(Type value) = 0;
	// Should add the element at the first position of the List

	virtual void addElementAtLastIndex(Type value) = 0;
	// Should add the element at the last position of the List

	virtual Type removeElementFromEnd() = 0;
	// Should remove the element from the last position of the List

	virtual void removeElementFromStart() = 0;
	//Should remove the element from the first position of the List

	//destructor
	~list() {
		delete[]arr;
		arr = nullptr;
	}
};

template<typename Type>
list<Type>::list(int size) {
	maxSize = size;
	currentSize = 0;
	arr = new Type[size];
}

template<typename Type>
list<Type>::list(list& obj) {
	maxSize = obj.maxSize;
	currentSize = obj.currentSize;
	arr = new Type[maxSize];
	for (int i = 0; i < currentSize; i++) {
		arr[i] = obj.arr[i];
	}
}
#include "list.h"
template<typename Type>
class Mylist :public list<Type> {
public:
	Mylist(int size);
	void addElementAtFirstIndex(Type);
	void addElementAtLastIndex(Type);
	Type removeElementFromEnd();
	void removeElementFromStart();
	bool empty();
	bool full();
	int size();
	bool insertAt(int index, Type value);
	Type last();
	bool search(Type);
	void display();
	~Mylist() {}
};

template<typename Type>
Mylist<Type>::Mylist(int size) :list<Type>(size) {}

template<typename Type>
void Mylist<Type>::addElementAtFirstIndex(Type value) {
	list<Type>::arr[list<Type>::currentSize] = value;
	list<Type>::currentSize++;
}

template<typename Type>
void Mylist<Type>::addElementAtLastIndex(Type value) {
	list<Type>::arr[list<Type>::maxSize - 1] = value;
	list<Type>::currentSize++;
}

template<typename Type>
Type Mylist<Type>::removeElementFromEnd() {
	list<Type>::currentSize--;
	return list<Type>::arr[list<Type>::currentSize];
}

template<typename Type>
void Mylist<Type>::removeElementFromStart() {
	for (int i = 0; i < list<Type>::currentSize; i++) {
		list<Type>::arr[i] = list<Type>::arr[i + 1];
	}
	list<Type>::currentSize;
}

template<typename Type>
void Mylist<Type>::display() {
	for (int i = 0; i < list<Type>::currentSize; i++) {
		cout << list<Type>::arr[i] << " ";
	}
}

template<typename Type>
bool Mylist<Type>::empty() {
	if (list<Type>::currentSize == 0) {
		return true;
	}
	else {
		return false;
	}
}

template<typename Type>
bool Mylist<Type>::full() {
	if (list<Type>::currentSize == list<Type>::maxSize) {
		return true;
	}
	else {
		return false;
	}
}

template<typename Type>
int Mylist<Type>::size() {
	return list<Type>::currentSize;
}

template<typename Type>
bool Mylist<Type>::insertAt(int index, Type value) {
	if (index < list<Type>::maxSize) {
		list<Type>::arr[index] = value;
		return true;
	}
	else {
		return false;
	}
}

template<typename Type>
Type Mylist<Type>::last() {
	return list<Type>::list<Type>::arr[list<Type>::currentSize - 1];
}

template<typename Type>
bool Mylist<Type>::search(Type value) {
	for (int i = 0; i < list<Type>::currentSize; i++) {
		if (list<Type>::arr[i] == value) {
			return true;
		}
	}
	return false;
}
#include "Mylist.h"

void displayMenu() {
    cout << "Choose an option:" << endl;
    cout << "1. Add Element at First Index" << endl;
    cout << "2. Add Element at Last Index" << endl;
    cout << "3. Display Elements" << endl;
    cout << "4. Check if Array is Empty" << endl;
    cout << "5. Check if Array is Full" << endl;
    cout << "6. Get Current Size of Array" << endl;
    cout << "7. Insert Element at Specific Index" << endl;
    cout << "8. Get Last Element" << endl;
    cout << "9. Search for an Element" << endl;
    cout << "10. Remove Element from End" << endl;
    cout << "11. Remove Element from Start" << endl;
    cout << "0. Exit" << endl;
}

int main() {
	Mylist <int>obj1(5);
	int choice;
	do {
		displayMenu();
		cout << "Enter your choice: ";
		cin >> choice;

		switch (choice) {
		case 1:{
			obj1.addElementAtFirstIndex(1);
			obj1.addElementAtFirstIndex(2);
			obj1.addElementAtFirstIndex(3);
			obj1.addElementAtFirstIndex(4);
			obj1.addElementAtLastIndex(5);
			cout << "Adding the values at first and last index in array: " << endl;
			obj1.display();
			cout << endl << endl;
			break;
		}
		case 2:{
			bool ifempty;
			ifempty = obj1.empty();
			if (ifempty) {
				cout << "Array is empty" << endl;
			}
			else {
				cout << "Array is not empty" << endl;
			}
			break;
		}
		case 3:{
			bool iffull;
			iffull = obj1.full();
			if (iffull) {
				cout << "Array is full" << endl << endl;
			}
			break;
		}
		case 4:{
			cout << "The current size of array is: ";
			int size = obj1.size();
			cout << size << endl << endl;
			break;
		}
		case 5:{
			cout << "Entering the value to insert at index if it is present: ";
			bool ifound;
			ifound = obj1.insertAt(2, 9);
			if (ifound) {
				cout << "Index is present" << endl;
				obj1.display();
			}
			else {
				cout << "Index not found";
			}
			cout << endl << endl;
			break;
		}
		case 6:
		{
			int lastelement;
			lastelement = obj1.last();
			cout << "The last element of array is: " << lastelement;
			cout << endl << endl;
			break;
		}
		case 7:
		{
			bool searchfound;
			searchfound = obj1.search(10);
			if (searchfound) {
				cout << "Value is present";
			}
			else {
				cout << "Value is not present";
			}
			cout << endl << endl;
			break;
		}
		case 8:
		{
			cout << "Array after deleting the last value: " << endl;
			int value; //to save up the deleted value
			value = obj1.removeElementFromEnd();
			obj1.display();
			cout << endl << endl;
			break;
		}
		
		case 9: {

			cout << "Array after deleting the first value: " << endl;
			obj1.removeElementFromStart();
			obj1.display();
			cout << endl << endl;
			break;
		}
		}
		
	} while (choice != 0);

	return 0;}
