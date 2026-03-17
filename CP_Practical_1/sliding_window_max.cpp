// Problem 4 — Sliding Window Maximum

#include <iostream>
#include <vector>
#include <deque>  // double-ended queue
using namespace std;

int main() {
    int n, k;
    cout << "Enter N and K: ";
    cin >> n >> k;

    vector<int> arr(n);
    cout << "Enter " << n << " integers: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Deque stores INDICES of useful elements (not the values directly)
    // We keep indices in decreasing order of their array values
    deque<int> dq;

    cout << "Sliding window maximums: ";

    for (int i = 0; i < n; i++) {
        // Step 1: Remove indices from the FRONT that are outside the window
        // The window starts at (i - k + 1)
        if (!dq.empty() && dq.front() < i - k + 1) {
            dq.pop_front();
        }

        // Step 2: Remove indices from the BACK that have smaller values
        // They can never be the maximum, so they are useless
        while (!dq.empty() && arr[dq.back()] <= arr[i]) {
            dq.pop_back();
        }

        // Step 3: Add current index to the back
        dq.push_back(i);

        // Step 4: Once we have at least K elements, print the maximum
        // The maximum is always at the front of the deque
        if (i >= k - 1) {
            cout << arr[dq.front()];
            if (i != n - 1) cout << " ";
        }
    }
    cout << endl;

    return 0;
}
