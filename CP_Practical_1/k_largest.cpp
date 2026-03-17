// Problem 6 — K Largest Elements

#include <iostream>
#include <vector>
#include <queue>  // for priority_queue
using namespace std;

int main() {
    int n, k;
    cout << "Enter N and K: ";
    cin >> n >> k;

    // Max-heap: the largest element is always at the top
    priority_queue<int> maxHeap;

    cout << "Enter " << n << " integers: ";
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        maxHeap.push(x);  // Push each element into the heap
    }

    // The top of a max-heap is always the largest element
    // Pop K times to get the K largest elements
    cout << "Top " << k << " largest elements: ";
    for (int i = 0; i < k; i++) {
        cout << maxHeap.top();  // Print the current max
        maxHeap.pop();          // Remove it so next max comes to top
        if (i != k - 1) cout << " ";
    }
    cout << endl;

    return 0;
}
