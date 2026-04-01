#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// A large number meaning "no path / unreachable"
const int INF = 99999;

// ── Step 1: Bellman-Ford ────────────────────────────────────────
// Finds shortest distances from one source; handles negatives.
// Returns false if a negative cycle is found.
bool bellmanFord(int source, int totalVertices,
                 vector<tuple<int,int,int>>& edges,
                 vector<int>& dist) {

    dist.assign(totalVertices, INF);
    dist[source] = 0;

    // Relax all edges (totalVertices - 1) times
    for (int i = 0; i < totalVertices - 1; i++) {
        for (auto& [u, v, w] : edges) {
            if (dist[u] != INF && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }
        }
    }

    // One more pass — if anything still improves, negative cycle exists
    for (auto& [u, v, w] : edges) {
        if (dist[u] != INF && dist[u] + w < dist[v]) {
            return false; // negative cycle!
        }
    }
    return true;
}

// ── Step 2: Dijkstra ────────────────────────────────────────────
// Finds shortest distances from source on NON-NEGATIVE graph.
vector<int> dijkstra(int source, int V,
                     vector<vector<pair<int,int>>>& adj) {

    vector<int> dist(V, INF);
    dist[source] = 0;

    // Min-heap: {distance, vertex}
    priority_queue<pair<int,int>,
                   vector<pair<int,int>>,
                   greater<pair<int,int>>> pq;
    pq.push({0, source});

    while (!pq.empty()) {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        // Skip if we already found a shorter path
        if (d > dist[u]) continue;

        for (auto& [v, w] : adj[u]) {
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
    return dist;
}

int main() {

    int V = 4; // number of real vertices

    // Edges: {from, to, weight}  (negative weights allowed)
    vector<tuple<int,int,int>> edges = {
        {0, 1,  1},
        {0, 2,  4},
        {1, 2, -3},
        {1, 3,  2},
        {2, 3,  3}
    };

    // ── Step 1: Add fake vertex (index V) ───────────────────────
    // Connect fake vertex to every real vertex with weight 0
    vector<tuple<int,int,int>> augmented = edges;
    for (int i = 0; i < V; i++) {
        augmented.push_back({V, i, 0});
    }

    // ── Step 2: Bellman-Ford from fake vertex ────────────────────
    vector<int> h; // potentials
    if (!bellmanFord(V, V + 1, augmented, h)) {
        cout << "Negative cycle detected! Algorithm cannot proceed.\n";
        return 0;
    }

    cout << "Potentials (h values) from Bellman-Ford:\n";
    for (int i = 0; i < V; i++) {
        cout << "  h[" << i << "] = " << h[i] << "\n";
    }

    // ── Step 3: Reweight edges ───────────────────────────────────
    // New weight = old weight + h[u] - h[v]  (always >= 0)
    vector<vector<pair<int,int>>> adj(V);
    cout << "\nReweighted edges:\n";
    for (auto& [u, v, w] : edges) {
        int newW = w + h[u] - h[v];
        cout << "  " << u << " -> " << v
             << "  old=" << w << "  new=" << newW << "\n";
        adj[u].push_back({v, newW});
    }

    // ── Step 4 & 5: Dijkstra from each vertex, undo reweighting ──
    cout << "\nAll-pairs shortest distances:\n";
    cout << "     ";
    for (int j = 0; j < V; j++) cout << "  " << j << "  ";
    cout << "\n";

    for (int s = 0; s < V; s++) {
        vector<int> d = dijkstra(s, V, adj);
        cout << "  " << s << "  ";
        for (int t = 0; t < V; t++) {
            // Undo reweighting: true dist = d[t] - h[s] + h[t]
            int trueDist = (d[t] == INF) ? INF : d[t] - h[s] + h[t];
            if (trueDist == INF)
                cout << "  INF";
            else
                cout << "  " << trueDist << "  ";
        }
        cout << "\n";
    }

    return 0;
}