#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
    int N, K, Q;
    cin >> N >> K >> Q;
    
    vector<long long> arr(N + 1);
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }
    
    multiset<long long> window;
    int left = 1, right = 0;
    
    for (int q = 0; q < Q; q++) {
        int type;
        cin >> type;
        
        if (type == 1) {
            int pos;
            long long val;
            cin >> pos >> val;
            
            // If position is in current window, update the window
            if (pos >= left && pos <= right) {
                window.erase(window.find(arr[pos]));
                window.insert(val);
            }
            arr[pos] = val;
        } 
        else if (type == 2) {
            int i;
            cin >> i;
            
            int new_left = max(1, i - K + 1);
            int new_right = i;
            
            // Remove elements left of new window
            while (left < new_left) {
                window.erase(window.find(arr[left]));
                left++;
            }
            
            // Add elements right of current window
            while (right < new_right) {
                right++;
                window.insert(arr[right]);
            }
            
            cout << *window.rbegin() << endl;
        }
    }
    
    return 0;
}