# CP_Practicals_2

## Overview
This repository contains solutions to 6 algorithmic problems focused on advanced data structures and algorithms including bitmasking, greedy algorithms, sliding window techniques, graph algorithms (Dijkstra), and dynamic programming. Each problem demonstrates different optimization strategies for handling constraints efficiently.


## How to Run

### Prerequisites
- C++ compiler (g++ recommended)
- Terminal/Command Prompt

### Compilation and Execution
For each problem, use the following commands:

```bash
# Compile
g++ ProblemName.cpp -o ProblemName

# Run
./ProblemName
```

## Problem Details

### Problem 1: Dinner Table Arrangements
**Description**: Arrange N friends around a circular table with allergy constraints. No two adjacent persons can share any common allergy. Determine if a valid arrangement exists.

**Key Concepts**: Bitmasking, DFS, Memoization, Circular Permutations

**Complexity**: O(N² × 2^N) time, O(N × 2^N) space

---

### Problem 2: Maximum AND Subarray
**Description**: Find the maximum possible AND value of any contiguous subarray of exactly length K.

**Key Concepts**: Greedy Bit Checking, Bit Manipulation, Sliding Window

**Complexity**: O(31 × N) time, O(N) space

---

### Problem 3: Sliding Window Maximum
**Description**: Given an array and window size K, find the maximum in each sliding window.

**Key Concepts**: Deque, Monotonic Queue, Sliding Window

**Complexity**: O(N) time, O(K) space

---

### Problem 4: Maximum in Sliding Window with Updates
**Description**: Process point updates and queries for maximum in sliding windows ending at given indices.

**Key Concepts**: Multiset, Sliding Window, Dynamic Updates

**Complexity**: O((N+Q) log K) time, O(K) space

---

### Problem 5: Network Latency
**Description**: Find the minimum latency (shortest path) from router 1 to router N in a weighted undirected graph.

**Key Concepts**: Dijkstra's Algorithm, Priority Queue, Graph Theory

**Complexity**: O((N+M) log N) time, O(N+M) space

---

### Problem 6: Toll Booths
**Description**: Navigate through N toll booths with coins and skip constraints, minimizing total travel time.

**Key Concepts**: Dynamic Programming, Optimization, State Tracking

**Complexity**: O(N × K) time, O(N × K) space



## Key Learnings

### Bitmasking
- Representing subsets using integers
- Checking bits with `(mask >> i) & 1`
- Setting bits with `mask | (1 << i)`
- Used in Problems 1 and 2

### Greedy Algorithms
- Building answer bit by bit (Problem 2)
- Always choosing optimal local decisions

### Deque Applications
- Maintaining monotonic queues for sliding window maximum (Problem 3)
- O(1) push/pop from both ends

### Graph Algorithms
- Dijkstra's algorithm for shortest path (Problem 5)
- Priority queue for efficient node selection

### Dynamic Programming
- State representation with skips and position (Problem 6)
- Optimization through mathematical transformation

### STL Containers Used
- `vector` - Dynamic arrays
- `deque` - Double-ended queue
- `multiset` - Ordered collection with duplicates
- `priority_queue` - Heap for Dijkstra's algorithm
