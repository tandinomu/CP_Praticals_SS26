#include <iostream>
#include <vector>
using namespace std;

// A large number to represent "no path exists"
const int INF = 99999;

int main() {

    // Number of vertices in the graph
    int V = 4;

    // Create a 2D table to store distances between every pair
    // Start by assuming no path exists (INF) between different vertices
    vector<vector<int>> dist = {
        //  0     1     2     3
        {   0,    3,  INF,    7 },  // from vertex 0
        {   8,    0,    2,  INF },  // from vertex 1
        {   5,  INF,    0,    1 },  // from vertex 2
        {   2,  INF,  INF,    0 }   // from vertex 3
    };

    // dist[i][i] = 0 (distance from a vertex to itself is 0)
    // dist[i][j] = edge weight if edge exists, else INF

    cout << "Graph (Initial distances):\n";
    cout << "   0     1     2     3\n";
    for (int i = 0; i < V; i++) {
        cout << i << " ";
        for (int j = 0; j < V; j++) {
            if (dist[i][j] == INF)
                cout << "  INF";
            else
                cout << "  " << dist[i][j] << "  ";
        }
        cout << "\n";
    }

    // ── Core Algorithm ──────────────────────────────────────────
    // Try every vertex k as a "middle stop" between i and j
    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {

                // Can we go from i to j through k?
                // Only check if both i->k and k->j paths exist
                if (dist[i][k] != INF && dist[k][j] != INF) {

                    // If going through k is shorter, update
                    if (dist[i][k] + dist[k][j] < dist[i][j]) {
                        dist[i][j] = dist[i][k] + dist[k][j];
                    }
                }
            }
        }
    }

    cout << "\nShortest distances between every pair of vertices:\n";
    cout << "   0     1     2     3\n";
    for (int i = 0; i < V; i++) {
        cout << i << " ";
        for (int j = 0; j < V; j++) {
            if (dist[i][j] == INF)
                cout << "  INF";
            else
                cout << "  " << dist[i][j] << "  ";
        }
        cout << "\n";
    }

    // Check for negative cycles
    // If dist[i][i] is negative, there is a negative cycle
    bool negCycle = false;
    for (int i = 0; i < V; i++) {
        if (dist[i][i] < 0) {
            negCycle = true;
        }
    }
    if (negCycle)
        cout << "\nWarning: Negative cycle detected!\n";
    else
        cout << "\nNo negative cycle found.\n";

    return 0;
}