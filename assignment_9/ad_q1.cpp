#include <bits/stdc++.h>
using namespace std;

// BFS to mark all nodes in the same connected component
void bfs_mark(const vector<vector<int>>& adj, vector<char>& visited, int src) {
    queue<int> q;
    visited[src] = 1;
    q.push(src);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : adj[u]) {
            if (!visited[v]) {
                visited[v] = 1;
                q.push(v);
            }
        }
    }
}

// Optional: iterative DFS alternative
void dfs_mark(const vector<vector<int>>& adj, vector<char>& visited, int src) {
    stack<int> st;
    st.push(src);
    while (!st.empty()) {
        int u = st.top(); st.pop();
        if (visited[u]) continue;
        visited[u] = 1;
        for (int v : adj[u]) {
            if (!visited[v]) st.push(v);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int V, E;
    if (!(cin >> V >> E)) {
        cerr << "Invalid input\n";
        return 0;
    }

    vector<vector<int>> adj(V);
    for (int i = 0; i < E; ++i) {
        int u, v;
        cin >> u >> v;
        if (u < 0 || u >= V || v < 0 || v >= V) {
            cerr << "Edge contains invalid vertex: " << u << " " << v << "\n";
            return 0;
        }
        adj[u].push_back(v);
        adj[v].push_back(u); // undirected
    }

    vector<char> visited(V, 0);
    int components = 0;

    for (int u = 0; u < V; ++u) {
        if (!visited[u]) {
            // choose one: BFS or DFS. Using BFS here:
            bfs_mark(adj, visited, u);
            // dfs_mark(adj, visited, u); // alternative
            ++components;
        }
    }

    cout << components << "\n";
    return 0;
}
