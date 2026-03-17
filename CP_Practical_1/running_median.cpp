// Problem 7 — Running Median


#include <iostream>
#include <queue>
#include <iomanip>  // for fixed and setprecision
using namespace std;

int main() {
    // We use TWO heaps:
    // maxHeap → stores the SMALLER half of numbers (max at top)
    // minHeap → stores the LARGER half of numbers (min at top)
    // The median is always at the top of one of these heaps

    priority_queue<int> maxHeap;                           // max-heap (default)
    priority_queue<int, vector<int>, greater<int>> minHeap; // min-heap

    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    cout << fixed << setprecision(1);  // Print with 1 decimal place

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;

        // Step 1: Add new element to the correct heap
        // If x is smaller than or equal to current median, it belongs in maxHeap
        if (maxHeap.empty() || x <= maxHeap.top()) {
            maxHeap.push(x);
        } else {
            minHeap.push(x);
        }

        // Step 2: Balance the heaps
        // maxHeap can have at most 1 more element than minHeap
        if (maxHeap.size() > minHeap.size() + 1) {
            // Move top of maxHeap to minHeap
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        } else if (minHeap.size() > maxHeap.size()) {
            // Move top of minHeap to maxHeap
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }

        // Step 3: Find the median
        // If both heaps have same size → median = average of two tops
        // If maxHeap has one more → median = top of maxHeap
        if (maxHeap.size() == minHeap.size()) {
            double median = ((double)maxHeap.top() + minHeap.top()) / 2.0;
            cout << median << "\n";
        } else {
            cout << (double)maxHeap.top() << "\n";
        }
    }

    return 0;
}
