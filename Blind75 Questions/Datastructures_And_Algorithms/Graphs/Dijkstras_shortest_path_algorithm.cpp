#include <bits/stdc++.h>
using namespace std;

/*
 * Dijkstra's Algorithm
 * Finds shortest distances from `src` to all nodes in a non-negative weighted graph.
 * Also stores a parent array to reconstruct shortest paths.
 *
 * Time:  O((V + E) * log V) using a min-heap
 * Space: O(V + E)
 */

struct Edge {
    int dest;   // destination node
    int wt;     // edge weight
};

// Dijkstra: shortest paths from src to all nodes
// output: parent array
// number of nodes
vector<long long> dijkstra(int n, const vector<vector<Edge>>& adj, int src, vector<int>& par) {
    const long long INF = LLONG_MAX / 4;
    vector<long long> dist(n, INF);
    par.assign(n, -1);

    // Min-heap of (distance, node)
    priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> pq;

    dist[src] = 0;
    pq.push({0, src});

    while (!pq.empty()) {
        auto [curDist, curNode] = pq.top(); 
        pq.pop();

        if (curDist != dist[curNode]) continue;  // stale entry

        for (auto& edge : adj[curNode]) {
            int nbrNode = edge.dest;
            long long nbrWt = edge.wt;

            if (dist[curNode] + nbrWt < dist[nbrNode]) {
                dist[nbrNode] = dist[curNode] + nbrWt;
                par[nbrNode] = curNode;
                pq.push({dist[nbrNode], nbrNode});
            }
        }
    }
    return dist;
}

// Reconstruct path from src to target
vector<int> getPath(int src, int tgt, const vector<int>& par) {
    vector<int> path;
    if (par[tgt] == -1 && src != tgt) return path; // no path
    for (int node = tgt; node != -1; node = par[node])
        path.push_back(node);
    reverse(path.begin(), path.end());
    return path;
}

// Example usage
int main() {
    int n, m; 
    cin >> n >> m;
    vector<vector<Edge>> adj(n);

    for (int i = 0; i < m; i++) {
        int from, to, wt;
        cin >> from >> to >> wt;
        adj[from].push_back({to, wt});
        // For undirected graph, also add:
        // adj[to].push_back({from, wt});
    }

    int src; cin >> src;

    vector<int> par;
    vector<long long> dist = dijkstra(n, adj, src, par);

    for (int node = 0; node < n; node++) {
        if (dist[node] >= LLONG_MAX / 4) 
            cout << "dist[" << node << "] = INF\n";
        else 
            cout << "dist[" << node << "] = " << dist[node] << "\n";
    }

    // Example: reconstruct path
    int tgt; 
    if (cin >> tgt) {
        auto path = getPath(src, tgt, par);
        if (path.empty()) cout << "No path from " << src << " to " << tgt << "\n";
        else {
            cout << "Path: ";
            for (int i = 0; i < path.size(); i++) {
                if (i) cout << " -> ";
                cout << path[i];
            }
            cout << "\n";
        }
    }
}


/* Version 2 */

// Build adjacency list from edge list
vector<vector<pair<int,int>>> buildAdj(const vector<vector<int>>& edges, int V) {
    vector<vector<pair<int,int>>> adj(V);
    for (auto& e : edges) {
        int u = e[0], v = e[1], wt = e[2];
        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt}); // remove this if graph is directed
    }
    return adj;
}

vector<int> dijkstra(int V, const vector<vector<int>>& edges, int src) {
    auto adj = buildAdj(edges, V);

    // Min-heap of (dist, node)
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

    vector<int> dist(V, INT_MAX);
    dist[src] = 0;
    pq.push({0, src});

    while (!pq.empty()) {
        auto [curDist, curNode] = pq.top();
        pq.pop();

        if (curDist > dist[curNode]) continue;

        for (auto [nbrNode, nbrWt] : adj[curNode]) {
            if (dist[curNode] + nbrWt < dist[nbrNode]) {
                dist[nbrNode] = dist[curNode] + nbrWt;
                pq.push({dist[nbrNode], nbrNode});
            }
        }
    }
    return dist;
}

int main2() {
    int V = 5, src = 0;
    vector<vector<int>> edges = {
        {0, 1, 4}, {0, 2, 8}, {1, 4, 6},
        {2, 3, 2}, {3, 4, 10}
    };

    auto result = dijkstra(V, edges, src);

    for (int d : result)
        cout << d << " ";
    cout << "\n";
}
