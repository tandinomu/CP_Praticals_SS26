#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

typedef long long ll;
typedef pair<ll, int> pli;

int main() {
    int N, M;
    cin >> N >> M;
    
    vector<vector<pair<int, ll>>> graph(N + 1);
    
    for (int i = 0; i < M; i++) {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }
    
    vector<ll> dist(N + 1, LLONG_MAX);
    priority_queue<pli, vector<pli>, greater<pli>> pq;
    
    dist[1] = 0;
    pq.push({0, 1});
    
    while (!pq.empty()) {
        ll d = pq.top().first;
        int u = pq.top().second;
        pq.pop();
        
        if (d > dist[u]) continue;
        
        for (auto& edge : graph[u]) {
            int v = edge.first;
            ll w = edge.second;
            
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
    
    if (dist[N] == LLONG_MAX) {
        cout << -1 << endl;
    } else {
        cout << dist[N] << endl;
    }
    
    return 0;
}