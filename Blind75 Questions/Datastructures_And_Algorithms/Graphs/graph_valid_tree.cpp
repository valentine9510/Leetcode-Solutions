#include <bits/stdc++.h>

using namespace std;

/*
Graph Valid Tree
Given n nodes labeled from 0 to n - 1 and a list of undirected edges (each edge is a pair of nodes), write a function to check whether these edges make up a valid tree.

Example 1:

Input:
n = 5
edges = [[0, 1], [0, 2], [0, 3], [1, 4]]

Output:
true
Example 2:

Input:
n = 5
edges = [[0, 1], [1, 2], [2, 3], [1, 3], [1, 4]]

Output:
false
Note:

You can assume that no duplicate edges will appear in edges. Since all edges are undirected, [0, 1] is the same as [1, 0] and thus will not appear together in edges.
*/

/*
What’s being tested
Graph fundamentals: A (connected, undirected) graph is a tree iff (1) it’s connected and (2) it has no cycles. Equivalently: for n nodes, it must have exactly n − 1 edges and be connected.

Patterns:
Union–Find (Disjoint Set Union, DSU) to detect cycles + connectivity.

BFS/DFS traversal to check connectivity and (optionally) detect cycles.
Interview relevance: Trees come up everywhere (spanning trees, networks, dependency structures). This problem checks whether you reach for the right characterization and implement a clean linear solution.


Two go-to strategies
A) Union–Find (DSU) — my recommended primary solution
If edges.size() != n - 1 → return false.
Initialize DSU with n sets.
For each edge (u, v):
If find(u) == find(v), you found a cycle → return false.
Else union(u, v).
If you finish without cycles, with n-1 edges the graph is automatically connected → return true.
Why it’s great: O(E α(N)) ~ O(E) and very simple to prove correctness.

B) BFS/DFS connectivity check (+ edge count)
If edges.size() != n - 1 → return false.
Build adjacency list; BFS/DFS from node 0 and count visited nodes.
If visited count == n → connected → return true (no cycles possible with n-1 edges); otherwise false.
Why it’s great: Straightforward graph traversal; easy to write
*/





/* BFS Solution */
class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        // Must have n-1 edges for a tree
        if ((int)edges.size() != n - 1) return false;

        // Build adjacency list for undirected graph
        vector<vector<int>> adj(n);
        for (const auto& e : edges) {
            int u = e[0], v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        // BFS from node 0 to check connectivity
        vector<bool> visited(n, false);
        queue<int> q;
        q.push(0);
        visited[0] = true;
        int seen = 1;

        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (int v : adj[u]) {
                if (!visited[v]) {
                    visited[v] = true;
                    q.push(v);
                    ++seen;
                }
            }
        }

        // Connected iff we visited all nodes
        return seen == n;
    }
};

/* BFS with cycle detection */
class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        // --- Build adjacency list for an undirected graph ---
        vector<vector<int>> adj(n);
        adj.reserve(n);
        for (const auto& e : edges) {
            int u = e[0], v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        // --- BFS with parent tracking to detect cycles and to check connectivity ---
        vector<bool> visited(n, false);
        queue<pair<int,int>> q;          // {node, parent}
        q.push({0, -1});
        visited[0] = true;

        int seen = 1;                    // count how many nodes we reach

        while (!q.empty()) {
            auto [u, parent] = q.front(); q.pop();

            for (int v : adj[u]) {
                if (!visited[v]) {
                    // First time we see v → visit it and record parent=u
                    visited[v] = true;
                    ++seen;
                    q.push({v, u});
                } else if (v != parent) {
                    // We reached an already-visited neighbor that is not our parent.
                    // In an undirected graph, this indicates a cycle.
                    return false;        // cycle found → not a tree
                }
            }
        }

        // If we didn’t visit all nodes, the graph is disconnected → not a tree.
        return seen == n;
    }
};
