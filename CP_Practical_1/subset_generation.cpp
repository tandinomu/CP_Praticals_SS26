// Problem 8 — Subset Generation

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

    // Total number of subsets = 2^N
    // For N=3, total = 8 subsets (including empty set)
    int totalSubsets = 1 << n;  // This is 2^n using bit shift

    cout << "\nAll subsets:\n";

    // Each number from 0 to (2^n - 1) represents a subset
    // The bits in the number tell us which elements to include
    // Example for N=3:
    //   000 = {}        (no elements)
    //   001 = {arr[0]}  (bit 0 is set)
    //   010 = {arr[1]}  (bit 1 is set)
    //   011 = {arr[0], arr[1]}  (bits 0 and 1 are set)
    //   ... and so on

    for (int mask = 0; mask < totalSubsets; mask++) {
        cout << "{";
        bool first = true;

        for (int bit = 0; bit < n; bit++) {
            // Check if the bit-th bit is set in 'mask'
            // (mask >> bit) shifts the bit to position 0
            // & 1 checks if that bit is 1
            if ((mask >> bit) & 1) {
                if (!first) cout << " ";
                cout << arr[bit];
                first = false;
            }
        }
        cout << "}\n";
    }

    return 0;
}
