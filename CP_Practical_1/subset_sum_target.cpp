// Problem 10 — Count Subsets with Sum Equal to Target

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

    int target;
    cout << "Enter target sum X: ";
    cin >> target;

    int totalSubsets = 1 << n;  // 2^n total subsets
    int count = 0;

    // Check every possible subset using bitmask
    for (int mask = 0; mask < totalSubsets; mask++) {
        int sum = 0;

        // Calculate the sum of the current subset
        for (int bit = 0; bit < n; bit++) {
            if ((mask >> bit) & 1) {
                sum += arr[bit];
            }
        }

        // If sum matches the target, count this subset
        if (sum == target) {
            count++;
        }
    }

    cout << "Number of subsets with sum equal to " << target << ": " << count << endl;

    return 0;
}
