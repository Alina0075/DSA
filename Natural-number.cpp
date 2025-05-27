#include<iostream>
using namespace std;

void Natural(int n) {
	if (n > 0) {
		Natural(n - 1);
		cout << n << " ";
	}

	if (n == 0) {
		return;
	}
}

int main() {
	int n;
	cout << "Enter Number: ";
	cin >> n;
	Natural(n);
	cout << endl;
	return 0;
}