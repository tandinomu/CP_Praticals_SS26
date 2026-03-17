// Problem 3 — Remove Duplicates

#include <iostream>
#include <vector>
#include <algorithm>  // for sort()
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

    // Step 1: Sort the vector so duplicates are next to each other
    sort(numbers.begin(), numbers.end());

    // Step 2: Print each number only once
    // By checking if current number is same as previous, skip if yes
    cout << "Unique elements: ";
    for (int i = 0; i < n; i++) {
        // Print if it's the first element OR different from previous
        if (i == 0 || numbers[i] != numbers[i - 1]) {
            cout << numbers[i] << " ";
        }
    }
    cout << endl;

    return 0;
}
