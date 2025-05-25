#include <iostream>
#include <string>
using namespace std;
template <typename t>
int LinearSearch(t array[], t key) {
	for (int i = 0; i < 6; i++) {
		if (array[i] == key) {
			return i;
		}
	}
}
template<typename t>
void printSearchResult(int a, t b) {
	cout << b << " is found at " << a << endl;
}
int main() {
	// Test with an integer array of size 5
	int intArray[5] = { 64, 25, 12, 22, 11 };
	int intKey = 11;
	int intIndex = LinearSearch(intArray, intKey);
	printSearchResult(intIndex, intKey);

	// Test with a float array of size 4
	float floatArray[4] = { 3.14, 2.71, 1.62, 0.57 };
	float floatKey = 0.57;
	int floatIndex = LinearSearch(floatArray, floatKey);
	printSearchResult(floatIndex, floatKey);
	// Test with a string array of size 4
	string stringArray[4] = { "apple", "orange", "banana", "grape" };
	string stringKey = "apple";
	int stringIndex = LinearSearch(stringArray, stringKey);
	printSearchResult(stringIndex, stringKey);

	return 0;

}	
