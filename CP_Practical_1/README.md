# CP_Praticals_SS26 — CP_Practicals_1

**Course:** Competitive Programming  
**Practical:** 1  
**Topics Covered:** Vectors, Deque, Priority Queue, Bitmask Techniques

---

## Problems Overview

| # | Problem | Key Data Structure | Time Complexity |
|---|---------|-------------------|-----------------|
| 1 | Dynamic Array Basics | `vector` | O(n) |
| 2 | Reverse the Array | `vector` | O(n) |
| 3 | Remove Duplicates | `vector` + sort | O(n log n) |
| 4 | Sliding Window Maximum | `deque` | O(n) |
| 5 | Balanced Line Problem | `deque` | O(1) per op |
| 6 | K Largest Elements | `priority_queue` (max-heap) | O(n log n) |
| 7 | Running Median | Two `priority_queue`s | O(n log n) |
| 8 | Subset Generation | Bitmask | O(2^n × n) |
| 9 | Count Subsets with Even Sum | Bitmask | O(2^n × n) |
| 10 | Count Subsets with Sum = Target | Bitmask | O(2^n × n) |

---

## How to Compile and Run

```bash
g++ -o output filename.cpp
./output
```

Example for Problem 1:
```bash
g++ -o output dynamic_array_basics.cpp
./output
```

---

## Key Concepts Learned

### Vector
A dynamic array that grows automatically. Use `push_back()` to add elements.
```cpp
vector<int> v;
v.push_back(10);
```

### Deque
A double-ended queue — supports insert and delete from both front and back in O(1).
```cpp
deque<int> dq;
dq.push_front(1);
dq.push_back(2);
dq.pop_front();
dq.pop_back();
```

### Priority Queue (Heap)
By default a max-heap — the largest element is always at the top.
```cpp
priority_queue<int> maxHeap;       // max-heap
priority_queue<int, vector<int>, greater<int>> minHeap; // min-heap
maxHeap.push(5);
cout << maxHeap.top(); // prints 5
maxHeap.pop();
```

### Bitmask
Use an integer's binary bits to represent which elements are included in a subset.
```cpp
int totalSubsets = 1 << n; // 2^n
for (int mask = 0; mask < totalSubsets; mask++) {
    for (int bit = 0; bit < n; bit++) {
        if ((mask >> bit) & 1) {
            // element at index 'bit' is included
        }
    }
}
```

---

## References
- Problem 7: [HackerRank — Find the Running Median](https://www.hackerrank.com/challenges/find-the-running-median/problem)
- Problem 10: [GeeksForGeeks — Count of Subsets with Sum Equal to X](https://www.geeksforgeeks.org/dsa/count-of-subsets-with-sum-equal-to-x/)
