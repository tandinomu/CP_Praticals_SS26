// Problem 9 — Count Subsets with Even Sum

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cout << "Enter N: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter " << n << " integers: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int totalSubsets = 1 << n;  // 2^n
    int count = 0;              // Count of subsets with even sum

    // Check every subset
    for (int mask = 0; mask < totalSubsets; mask++) {
        int sum = 0;

        // Calculate sum of this subset
        for (int bit = 0; bit < n; bit++) {
            if ((mask >> bit) & 1) {
                sum += arr[bit];
            }
        }

        // Check if the sum is even
        if (sum % 2 == 0) {
            count++;
        }
    }

    cout << "Number of subsets with even sum: " << count << endl;

    return 0;
}
