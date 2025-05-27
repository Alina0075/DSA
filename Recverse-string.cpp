#include <iostream>
using namespace std;

string reverse(string name, int start, int end) {
    if (start >= end) {
        return name;
    }

    char temp = name[start];
    name[start] = name[end];
    name[end] = temp;

    return reverse(name, start + 1, end - 1);
}

int main() {
    string name = "Alina";
    int count = 0, i = 0;
    while (name[i] != '\0') {
        count++;
        i++;
    }

    string reversedName = reverse(name, 0, count-1);

    cout << "Original string: " << name << endl; 
    cout << "Reversed string: " << reversedName << endl;

    return 0;
}
