//problem 1

#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int N;
vector<int> masks;  // allergies as bitmask for each person
int dp[21][1 << 20];  // dp[last_person][visited_mask]

int dfs(int last, int visited, int first) {
    if (visited == (1 << N) - 1) {
        // all placed, check first and last compatibility
        if ((masks[last] & masks[first]) == 0) return 1;
        else return 0;
    }
    
    if (dp[last][visited] != -1) return dp[last][visited];
    
    for (int next = 0; next < N; next++) {
        if (visited & (1 << next)) continue;
        if ((masks[last] & masks[next]) == 0) {
            if (dfs(next, visited | (1 << next), first)) {
                return dp[last][visited] = 1;
            }
        }
    }
    
    return dp[last][visited] = 0;
}

int main() {
    int T;
    cin >> T;
    
    while (T--) {
        cin >> N;
        masks.resize(N);
        
        for (int i = 0; i < N; i++) {
            int M;
            cin >> M;
            int mask = 0;
            for (int j = 0; j < M; j++) {
                int allergy;
                cin >> allergy;
                mask |= (1 << (allergy - 1));  // allergy IDs 1..30
            }
            masks[i] = mask;
        }
        
        // Special case: if only one person, always YES
        if (N == 1) {
            cout << "YES\n";
            continue;
        }
        
        memset(dp, -1, sizeof dp);
        
        // Fix person 0 as first
        if (dfs(0, 1 << 0, 0)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    
    return 0;
}