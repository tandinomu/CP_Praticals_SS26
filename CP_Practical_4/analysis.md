# Reflection -nGraph Algorithms

## Floyd-Warshall

![2](./images%20/fw.png)
This algorithm the easiest of the three to understand. The idea is simple:
for every possible "middle stop" vertex `k`, check if going *through* `k` gives a
shorter path from `i` to `j`. Three nested loops, one table.

What helped me understand it was thinking of it like a road trip. If you want to go
from city A to city C, maybe it's faster to stop at city B on the way. Floyd-Warshall
checks every possible stopover for every pair of cities.

The downside is it checks **every** combination, which is why it is O(V³) slow for
very large graphs, but perfectly fine for small ones.


## Johnson's Algorithm

![1](./images%20/jh.png)
This algorithm is harder to grasp at first because it combines **two** algorithms
(Bellman-Ford and Dijkstra) and introduces the idea of *reweighting* edges.

The key problem it solves: Dijkstra is fast but breaks on negative edge weights.
Bellman-Ford handles negatives but is slow. Johnson's uses the best of both:

1. Run Bellman-Ford **once** from a fake extra vertex to get "potentials" for each vertex.
2. Use those potentials to shift all edge weights so they become non-negative.
3. Run Dijkstra (the fast one) from every vertex safely.
4. Undo the shift at the end to get the real distances.

The tricky part for me was understanding *why* the reweighting works without changing
which path is actually shortest. The answer is that the shift cancels out perfectly
along any complete path - only the individual edge weights change, not the path totals
relative to each other.



## Boruvka's Algorithm

![3](./images%20/br.png)
Boruvka's algorithm is the most visual and intuitive. We start with every vertex alone in its own little island, and in each phase every island reaches out and grabs the cheapest bridge to a neighbouring island. After a few phases, all islands merge into one and that collection of bridges is  MST.

What I found clever is that because every phase at least **halves** the number of
components, the algorithm only needs O(log V) phases. It does not process one edge at a
time like Kruskal's — it processes many edges simultaneously, which is why it works
well in parallel systems.

Using Union-Find to track which vertices belong to the same component was a new concept
for me, but once I understood path compression (shortcuts to the root) and union by rank
(keep the tree flat), it made sense why it is so fast.


## Overall Takeaway

All three algorithms solve graph problems, but each fits a different situation:

| Algorithm      | Solves          | Best for                  |
|----------------|-----------------|---------------------------|
| Floyd-Warshall | All-pairs paths | Small or dense graphs     |
| Johnson's      | All-pairs paths | Sparse graphs, negatives  |
| Boruvka's      | MST             | Parallel / large graphs   |

The biggest lesson was that there is no single "best" algorithm the right choice
depends on the size of the graph, whether negative weights exist, and whether you need
shortest paths or a spanning tree.