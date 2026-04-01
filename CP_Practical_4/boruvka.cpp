#include <iostream>
#include <vector>
using namespace std;

// A large number meaning "no MST / disconnected"
const int INF = 99999;

// Find which group vertex x belongs to
int findGroup(vector<int>& parent, int x) {
    // Path compression: shortcut directly to the root
    if (parent[x] != x) {
        parent[x] = findGroup(parent, parent[x]);
    }
    return parent[x];
}

// Merge the groups of vertices a and b
// Returns false if they are already in the same group
bool mergeGroups(vector<int>& parent, vector<int>& rank_, int a, int b) {
    int rootA = findGroup(parent, a);
    int rootB = findGroup(parent, b);

    if (rootA == rootB) return false; // already same group

    // Union by rank: attach smaller tree under bigger tree
    if (rank_[rootA] < rank_[rootB]) swap(rootA, rootB);
    parent[rootB] = rootA;
    if (rank_[rootA] == rank_[rootB]) rank_[rootA]++;

    return true;
}
// ────────────────────────────────────────────────────────────────

// An edge connects two vertices with a weight
struct Edge {
    int u, v, w;
};

int main() {

    int V = 5; // number of vertices
    
    // List of all edges: {vertex1, vertex2, weight}
    vector<Edge> edges = {
        {0, 1, 2},
        {0, 3, 6},
        {1, 2, 3},
        {1, 3, 8},
        {1, 4, 5},
        {2, 4, 7},
        {3, 4, 9}
    };

    cout << "All edges in the graph:\n";
    for (auto& e : edges) {
        cout << "  " << e.u << " -- " << e.v << "  (weight=" << e.w << ")\n";
    }

    // ── Setup Union-Find ────────────────────────────────────────
    // Each vertex starts in its own group (parent of itself)
    vector<int> parent(V), rank_(V, 0);
    for (int i = 0; i < V; i++) parent[i] = i;

    int mstWeight = 0;        // total weight of MST
    vector<Edge> mstEdges;    // edges chosen for MST
    int components = V;       // number of groups (starts as V)

    // ── Main Loop: repeat until 1 group remains ─────────────────
    int phase = 1;
    while (components > 1) {
        cout << "\n--- Phase " << phase++ << " ---\n";
        cout << "Number of components: " << components << "\n";

        // cheapest[c] = index of the cheapest edge leaving component c
        // -1 means no cheap edge found yet
        vector<int> cheapest(V, -1);

        // Look at every edge, find the cheapest one for each component
        for (int i = 0; i < (int)edges.size(); i++) {
            int groupU = findGroup(parent, edges[i].u);
            int groupV = findGroup(parent, edges[i].v);

            // Skip if both endpoints are in the same group
            if (groupU == groupV) continue;

            // Update cheapest edge for groupU
            if (cheapest[groupU] == -1 ||
                edges[i].w < edges[cheapest[groupU]].w) {
                cheapest[groupU] = i;
            }
            // Update cheapest edge for groupV
            if (cheapest[groupV] == -1 ||
                edges[i].w < edges[cheapest[groupV]].w) {
                cheapest[groupV] = i;
            }
        }

        // Add all cheapest edges to MST (merge components)
        bool anyMerge = false;
        for (int c = 0; c < V; c++) {
            if (cheapest[c] == -1) continue;

            Edge& e = edges[cheapest[c]];
            if (mergeGroups(parent, rank_, e.u, e.v)) {
                mstWeight += e.w;
                mstEdges.push_back(e);
                components--;
                anyMerge = true;
                cout << "  Added edge: " << e.u << " -- " << e.v
                     << "  (weight=" << e.w << ")\n";
            }
        }

        if (!anyMerge) {
            cout << "Graph is disconnected — MST not possible.\n";
            return 0;
        }
    }

    // ── Result ──────────────────────────────────────────────────
    cout << "\n========== MST Result ==========\n";
    cout << "MST edges:\n";
    for (auto& e : mstEdges) {
        cout << "  " << e.u << " -- " << e.v << "  (weight=" << e.w << ")\n";
    }
    cout << "Total MST weight: " << mstWeight << "\n";

    return 0;
}