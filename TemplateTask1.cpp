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
	arr = new Type [size];
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
#include"list.h"

template<typename Type>
class Mylist :public list<Type> {
public:
	Mylist(int size);
	void addElementAtFirstIndex(Type);
	void addElementAtLastIndex(Type);
	Type removeElementFromEnd();
	void removeElementFromStart();
	void display();
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
	list<Type>::arr[list<Type>::maxSize-1] = value;
	list<Type>::currentSize++;
}

template<typename Type>
Type Mylist<Type>:: removeElementFromEnd() {
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


#include"Mylist.h"

int main() {
	Mylist <int>obj1(5);
	obj1.addElementAtFirstIndex(1);
	obj1.addElementAtFirstIndex(2);
	obj1.addElementAtFirstIndex(3);
	obj1.addElementAtFirstIndex(4);
	obj1.addElementAtLastIndex(5);
	cout << "Adding the values at first and last index in array: " << endl;
	obj1.display();
	cout << endl << endl;

	cout << "Array after deleting the last value: " << endl;
	int value; //to save up the deleted value
	value = obj1.removeElementFromEnd();
	obj1.display();
	cout << endl << endl;

	cout << "Array after deleting the first value: " << endl;
	obj1.removeElementFromStart();
	obj1.display();
	cout << endl << endl;

	Mylist<string>obj2(5);
	obj2.addElementAtFirstIndex("ITC");
	obj2.addElementAtFirstIndex("PF");
	obj2.addElementAtFirstIndex("OOP");
	obj2.addElementAtFirstIndex("DB");
	obj2.addElementAtLastIndex("DSA");
	cout << "Adding the values at first and last index in array: " << endl;
	obj2.display();
	cout << endl << endl;

	cout << "Array after deleting the last value: " << endl;
	string value2; //to save up the deleted value
	value2 = obj2.removeElementFromEnd();
	obj2.display();
	cout << endl << endl;

	cout << "Array after deleting the first value: " << endl;
	obj2.removeElementFromStart();
	obj2.display();
	cout << endl << endl;
	return 0;
}
