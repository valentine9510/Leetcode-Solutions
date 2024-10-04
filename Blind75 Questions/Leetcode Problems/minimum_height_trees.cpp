/**
 * @file minimum_height_trees.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2024-08-19
 * 
 * @copyright Copyright (c) 2024
 * 
 */

/*

A tree is an undirected graph in which any two vertices are connected by exactly one path. In other words, any connected graph without simple cycles is a tree.
Given a tree of n nodes labelled from 0 to n - 1, and an array of n - 1 edges where edges[i] = [ai, bi] indicates that there is an undirected edge between the two nodes ai and bi in the tree, 
you can choose any node of the tree as the root. When you select a node x as the root, the result tree has height h. Among all possible rooted trees, those with minimum height (i.e. min(h))  are called minimum height trees (MHTs).

Return a list of all MHTs' root labels. You can return the answer in any order.
The height of a rooted tree is the number of edges on the longest downward path between the root and a leaf.

 

Example 1:


Input: n = 4, edges = [[1,0],[1,2],[1,3]]
Output: [1]
Explanation: As shown, the height of the tree is 1 when the root is the node with label 1 which is the only MHT.
Example 2:


Input: n = 6, edges = [[3,0],[3,1],[3,2],[3,4],[5,4]]
Output: [3,4]
 

Constraints:

1 <= n <= 2 * 104
edges.length == n - 1
0 <= ai, bi < n
ai != bi
All the pairs (ai, bi) are distinct.
The given input is guaranteed to be a tree and there will be no repeated edges.

*/

/*
    Change to adjacency list

    For each node, check how deep you can go
        Keep the maximum depth
            Store the depth in an array of size in

*/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void edgeToAdjacencyList(unordered_map<int, vector<int>> &adjacency_list, const vector<vector<int>> &edges) {
        for (const auto &curr_edge : edges) {
            adjacency_list[curr_edge[0]].push_back(curr_edge[1]); 
            adjacency_list[curr_edge[1]].push_back(curr_edge[0]);
        }
    }

    int exploreDepth(unordered_map<int, vector<int>> &adjacency_list, unordered_set<int>& visit_set, int curr_node) {
        // Mark the current node as visited
        visit_set.insert(curr_node);

        int max_depth = 0;

        for (int neighbor : adjacency_list[curr_node]) {
            if (visit_set.find(neighbor) == visit_set.end()) {
                // Recursively calculate the depth
                int depth = exploreDepth(adjacency_list, visit_set, neighbor);
                max_depth = max(max_depth, depth);
            }
        }

        // The depth of the current node is the max depth found in its neighbors plus one
        return max_depth + 1;
    }

    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 1) return {0}; // Special case for a single node

        unordered_map<int, vector<int>> adjacency_list;
        edgeToAdjacencyList(adjacency_list, edges);

        int min_depth = INT_MAX;
        vector<int> result;

        // Calculate the height (depth) of each node when it is treated as a root
        for (int i = 0; i < n; ++i) {
            unordered_set<int> visit_set;
            int depth = exploreDepth(adjacency_list, visit_set, i);

            if (depth < min_depth) {
                min_depth = depth;
                result = {i};
            } else if (depth == min_depth) {
                result.push_back(i);
            }
        }

        return result;
    }
};


/*
    Chat GPT Solution
    Topological sort
*/
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 1) return {0}; // Special case: only one node

        // Build the adjacency list
        unordered_map<int, unordered_set<int>> adj;
        for (const auto& edge : edges) {
            adj[edge[0]].insert(edge[1]);
            adj[edge[1]].insert(edge[0]);
        }

        // Initialize the first layer of leaves
        vector<int> leaves;
        for (int i = 0; i < n; ++i) {
            if (adj[i].size() == 1) leaves.push_back(i);
        }

        // Trim the leaves until reaching the centroids
        while (n > 2) {
            n -= leaves.size();
            vector<int> newLeaves;
            for (int leaf : leaves) {
                int neighbor = *adj[leaf].begin();
                adj[neighbor].erase(leaf);
                if (adj[neighbor].size() == 1) newLeaves.push_back(neighbor);
            }
            leaves = newLeaves;
        }

        return leaves;
    }
};

/** Using BFS */

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 1) return {0}; // Special case: only one node

        // Build the adjacency list
        unordered_map<int, vector<int>> adj;
        for (const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        // Step 1: Find one endpoint of the diameter
        int nodeA = bfs(0, adj, n).first;

        // Step 2: Find the other endpoint of the diameter and the path length
        auto result = bfs(nodeA, adj, n);
        int nodeB = result.first;
        int diameter = result.second;

        // Step 3: Perform BFS again to get the path from nodeA to nodeB
        vector<int> dist(n, -1);
        queue<int> q;
        q.push(nodeA);
        dist[nodeA] = 0;

        vector<int> parent(n, -1);
        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (int neighbor : adj[node]) {
                if (dist[neighbor] == -1) { // If not visited
                    dist[neighbor] = dist[node] + 1;
                    parent[neighbor] = node;
                    q.push(neighbor);
                }
            }
        }

        // Step 4: Collect the middle node(s)
        vector<int> path;
        int currentNode = nodeB;
        while (currentNode != -1) {
            path.push_back(currentNode);
            currentNode = parent[currentNode];
        }

        int pathLength = path.size();
        if (pathLength % 2 == 0) {
            return {path[pathLength / 2 - 1], path[pathLength / 2]};
        } else {
            return {path[pathLength / 2]};
        }
    }

private:
    // BFS function that returns the farthest node from the start node and the distance to it
    pair<int, int> bfs(int start, const unordered_map<int, vector<int>>& adj, int n) {
        vector<int> dist(n, -1);
        queue<int> q;
        q.push(start);
        dist[start] = 0;

        int farthestNode = start;
        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (int neighbor : adj.at(node)) {
                if (dist[neighbor] == -1) { // If not visited
                    dist[neighbor] = dist[node] + 1;
                    q.push(neighbor);
                    if (dist[neighbor] > dist[farthestNode]) {
                        farthestNode = neighbor;
                    }
                }
            }
        }

        return {farthestNode, dist[farthestNode]};
    }
};


