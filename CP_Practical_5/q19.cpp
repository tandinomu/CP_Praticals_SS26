#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    const int MAX = 100005;
    vector<int> lastPos(MAX, -1);
    vector<int> diff(MAX, 0);
    vector<bool> valid(MAX, true);
    
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        
        if (lastPos[x] == -1) {
            // First occurrence
            lastPos[x] = i;
        }
        else if (diff[x] == 0) {
            // Second occurrence
            diff[x] = i - lastPos[x];
            lastPos[x] = i;
        }
        else {
            // Third or more
            if (i - lastPos[x] != diff[x]) {
                valid[x] = false;
            }
            lastPos[x] = i;
        }
    }
    
    // Collect results
    vector<pair<int, int>> result;
    for (int x = 1; x < MAX; x++) {
        if (lastPos[x] != -1 && valid[x]) {
            result.push_back({x, diff[x]});
        }
    }
    
    // Output
    cout << result.size() << endl;
    for (auto [x, px] : result) {
        cout << x << " " << px << endl;
    }
    
    return 0;
}