#include <iostream>
#include <vector>
#include <queue>
#include <iomanip>
#include <climits>
using namespace std;

typedef long double ld;
typedef pair<ld, int> pdi;

int main() {
    int N, M;
    cin >> N >> M;
    
    vector<vector<tuple<int, ld, ld>>> graph(N + 1);
    
    for (int i = 0; i < M; i++) {
        int u, v;
        ld a, b;
        cin >> u >> v >> a >> b;
        graph[u].push_back({v, a, b});
    }
    
    vector<ld> dist(N + 1, 1e18);
    priority_queue<pdi, vector<pdi>, greater<pdi>> pq;
    
    dist[1] = 0;
    pq.push({0, 1});
    
    while (!pq.empty()) {
        ld t = pq.top().first;
        int u = pq.top().second;
        pq.pop();
        
        if (t > dist[u] + 1e-9) continue;
        
        for (auto& edge : graph[u]) {
            int v = get<0>(edge);
            ld a = get<1>(edge);
            ld b = get<2>(edge);
            
            // Travel time = a*t + b
            // Arrival time = t + (a*t + b) = t*(a+1) + b
            ld arrival = t * (a + 1) + b;
            
            if (arrival < dist[v] - 1e-9) {
                dist[v] = arrival;
                pq.push({arrival, v});
            }
        }
    }
    
    if (dist[N] > 1e17) {
        cout << -1 << endl;
    } else {
        cout << fixed << setprecision(2) << dist[N] << endl;
    }
    
    return 0;
}