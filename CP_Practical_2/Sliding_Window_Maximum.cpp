//problem 3

#include <iostream>
#include <deque>
#include <vector>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    
    vector<long long> arr(N);
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    
    // Deque stores indices of array elements
    // Elements in deque are in decreasing order of their values
    deque<int> dq;
    
    // Process first K elements
    for (int i = 0; i < K; i++) {
        // Remove elements from back that are smaller than current element
        // Because they will never be maximum in any future window
        while (!dq.empty() && arr[dq.back()] <= arr[i]) {
            dq.pop_back();
        }
        dq.push_back(i);
    }
    
    // Print maximum for first window
    cout << arr[dq.front()];
    
    // Process remaining elements
    for (int i = K; i < N; i++) {
        // Remove elements that are out of current window
        // Current window is [i-K+1, i]
        if (!dq.empty() && dq.front() <= i - K) {
            dq.pop_front();
        }
        
        // Remove elements from back that are smaller than current element
        while (!dq.empty() && arr[dq.back()] <= arr[i]) {
            dq.pop_back();
        }
        
        // Add current element
        dq.push_back(i);
        
        // Print maximum for current window
        cout << " " << arr[dq.front()];
    }
    
    cout << endl;
    
    return 0;
}