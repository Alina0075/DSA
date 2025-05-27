#include<iostream>
using namespace std;

int fact(int n) {
    if (n > 0) {
        return n * fact(n - 1);
    }
    if (n == 0) {
        return 1;
    }
}

int main() {
    int n;
    cout << "Enter Number: ";
    cin >> n;
    cout << "Factorical of the number is: " << fact(n);
    return 0;
}