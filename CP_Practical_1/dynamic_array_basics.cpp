// Problem 1 — Dynamic Array Basics

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cout << "Enter N: ";
    cin >> n;

    // Create an empty vector to store the numbers
    vector<int> numbers;

    cout << "Enter " << n << " integers: ";
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        numbers.push_back(x);  // Add each number to the vector
    }

    // Find max and min manually
    int maxVal = numbers[0];
    int minVal = numbers[0];
    long long sum = 0;

    for (int i = 0; i < n; i++) {
        if (numbers[i] > maxVal) maxVal = numbers[i];
        if (numbers[i] < minVal) minVal = numbers[i];
        sum += numbers[i];
    }

    cout << "Maximum element: " << maxVal << endl;
    cout << "Minimum element: " << minVal << endl;
    cout << "Sum of elements: " << sum << endl;

    return 0;
}
