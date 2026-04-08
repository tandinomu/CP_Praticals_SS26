#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    
    int last = 0;
    int maxRounds = -1;
    
    for (int i = 1; i <= n; i++) {
        int a;
        cin >> a;
        
        int rounds = (a + m - 1) / m;  // ceil(a / m)
        
        if (rounds >= maxRounds) {
            maxRounds = rounds;
            last = i;
        }
    }
    
    cout << last << endl;
    
    return 0;
}
