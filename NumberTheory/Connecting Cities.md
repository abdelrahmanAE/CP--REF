# Connecting Cities: Minimum Spanning Tree with GCD

## 📝 Problem Description
Given $N$ cities arranged in a circular layout (numbered $0$ to $N-1$) and $M$ types of bidirectional road constructions. The $k$-th type allows connecting any city $x$ to city $(x + A_k) \pmod N$ with a cost of $C_k$. We can use any type of construction any number of times. The goal is to find the **minimum total cost** to make all cities fully connected. If it's impossible, output `-1`.

### Constraints
* $2 \le N \le 10^9$
* $1 \le M \le 10^5$
* $1 \le A_k \le N-1$
* $1 \le C_k \le 10^9$

---

## 💡 Core Idea & Strategy

### 1. Why Graph Algorithms (BFS/Dijkstra) Fail
* **Scale:** $N \le 10^9$ makes building an explicit adjacency list or matrix impossible due to Memory Limit Exceeded (MLE) and Time Limit Exceeded (TLE).
* **Objective:** This is a **Minimum Spanning Tree (MST)** problem, not a Shortest Path problem. We need to connect the whole network greedily with the lowest overall cost.

### 2. The Greedy + Number Theory Approach
Instead of processing individual nodes, we process **Connected Components** globally using **Kruskal's Algorithm** logic combined with **Modular Arithmetic**:
1. **Sort** all available road types by their cost ($C_k$) in ascending order.
2. Maintain the current number of connected components, starting with $g = N$.
3. For each road type, calculate how many components it can merge using the `gcd` function.
4. If we reach $g = 1$, the graph is fully connected, and we can stop early.

---

## 📐 Mathematical Proof

### Theorem 1: The Number of Components after a Step
In a cyclic group of size $g$, walking in steps of size $i$ splits the cycle into exactly $\text{GCD}(g, i)$ disjoint components (cosets). Therefore, if we currently have $g$ components and introduce a road of step-size $i$, the new number of components will collapse to:
$$gc = \text{GCD}(g, i)$$

### Theorem 2: Number of Edges Used
In graph theory, to reduce the number of connected components from $g$ to $gc$ without forming redundant cycles (Greedy/Kruskal approach), the exact number of edges we need to add is:
$$\text{Edges Needed} = g - gc$$

Thus, the cost incurred in this step is:
$$\text{Step Cost} = (g - gc) \times C_k$$

---

## 🚀 Complexity Analysis

* **Time Complexity:** $\mathcal{O}(M \log M)$ due to sorting the $M$ road types. The `gcd` operation inside the loop takes logarithmic time $\mathcal{O}(\log N)$, leading to an efficient overall runtime well within the 1-second limit.
* **Space Complexity:** $\mathcal{O}(M)$ to store the road types array.

---

## 💻 C++ Source Code

```cpp
 // Coded  by Abdelrahman Elgammal
/*
بسم الله الرحمن الرحيم
وَأَن لَّيْسَ لِلْإِنسَانِ إِلَّا مَا سَعَىٰ وَأَنَّ سَعْيَهُ سَوْفَ يُرَىٰ ثُمَّ يُجْزَاهُ الْجَزَاءَ الْأَوْفَىٰ
 */#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const char el = '\n';

void solve() {
    int n, m;
    cin >> n >> m;
    
    // Vector of pairs: {Cost, Step Size}
    vector<pair<int, int>> roads;
    for (int i = 0, step, cost; i < m; i++) {
        cin >> step >> cost;
        roads.emplace_back(cost, step); 
    }
    
    // Sort roads from cheapest to most expensive (Kruskal's Logic)
    sort(roads.begin(), roads.end()); 
    
    ll total_cost = 0;
    ll current_components = n;
    
    for (auto &[cost, step] : roads) {
        ll next_components = gcd(current_components, step);      
        
        // Cost = (difference in components) * cost per road
        total_cost += 1LL * (current_components - next_components) * cost; 
        
        current_components = next_components; // Update component count
        
        if (current_components == 1) break; // Optimized early exit
    }
    
    // If current_components == 1, the graph is connected
    cout << (current_components == 1 ? total_cost : -1);
}

signed main() {
    // Optimize standard I/O operations for performance
    cin.tie(0)->sync_with_stdio(0);
    
    int t = 1;
    while (t--) {
        solve();
        cout << el;
    }
    return 0;
}
