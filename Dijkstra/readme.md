---
marp : true
---

C++ STL Priority Queue (Heap)
```C++
#include <queue>
using namespace std;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<int, int>> min_heap; // min heap
priority_queue<pair<int, int>, vector<pair<int, int>>, less<int, int>> max_heap; // max heap
```