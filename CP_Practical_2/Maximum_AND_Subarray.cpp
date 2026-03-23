// problem 2

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int T;
    cin >> T;
    
    while (T--) {
        int N, K;
        cin >> N >> K;
        vector<int> A(N);
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }
        
        int ans = 0;
        
        // Check bits from 31 down to 0
        for (int bit = 31; bit >= 0; bit--) {
            int candidate = ans | (1 << bit);
            
            // Check if there's a subarray of length K where all have candidate bits set
            int count = 0;
            bool found = false;
            for (int i = 0; i < N; i++) {
                if ((A[i] & candidate) == candidate) {
                    count++;
                    if (count >= K) {
                        found = true;
                        break;
                    }
                } else {
                    count = 0;
                }
            }
            
            if (found) {
                ans = candidate;
            }
        }
        
        cout << ans << "\n";
    }
    
    return 0;
}