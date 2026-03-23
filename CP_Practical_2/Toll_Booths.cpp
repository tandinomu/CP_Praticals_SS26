#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main() {
    int N, M, K;
    cin >> N >> M >> K;
    
    vector<int> toll(N + 1);
    for (int i = 1; i <= N; i++) {
        cin >> toll[i];
    }
    
    const int INF = 1e9;
    
    // dp[i][s] = minimum coins used to reach booth i with exactly s skips
    vector<vector<int>> dp(N + 1, vector<int>(K + 1, INF));
    dp[1][0] = 0; // At booth 1, 0 skips, 0 coins used
    
    // Process booths 1 to N-1 (to move to booth N)
    for (int i = 1; i < N; i++) {
        for (int s = 0; s <= K; s++) {
            if (dp[i][s] == INF) continue;
            
            // Option 1: Pay at booth i to move to i+1
            int new_coins = dp[i][s] + toll[i];
            if (new_coins <= M) {
                dp[i + 1][s] = min(dp[i + 1][s], new_coins);
            }
            
            // Option 2: Skip booth i to move to i+1
            if (s + 1 <= K) {
                dp[i + 1][s + 1] = min(dp[i + 1][s + 1], dp[i][s]);
            }
        }
    }
    
    // Find minimum time
    int min_time = INF;
    for (int s = 0; s <= K; s++) {
        if (dp[N][s] <= M) {
            // Time = (paid booths) * 1 + (skipped booths) * 2
            // Paid booths = (N-1) - s
            // Total time = (N-1 - s) * 1 + s * 2 = N-1 + s
            int time = (N - 1) + s;
            min_time = min(min_time, time);
        }
    }
    
    if (min_time == INF) {
        cout << -1 << endl;
    } else {
        cout << min_time << endl;
    }
    
    return 0;
}