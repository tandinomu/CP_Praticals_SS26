// Problem 2 — Reverse the Array

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cout << "Enter N: ";
    cin >> n;

    vector<int> numbers;

    cout << "Enter " << n << " integers: ";
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        numbers.push_back(x);
    }

    cout << "Reversed array: ";
    // Start from the last index and go backwards
    for (int i = n - 1; i >= 0; i--) {
        cout << numbers[i];
        if (i != 0) cout << " ";
    }
    cout << endl;

    return 0;
}
