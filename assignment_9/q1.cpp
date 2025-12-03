// GraphAlgorithms.cpp
// Compile: g++ -std=c++17 GraphAlgorithms.cpp -O2 -o graph
// Run: ./graph
// Input format described below in main()

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (1LL<<60);

// ----------------------------
// Disjoint Set Union (for Kruskal)
// ----------------------------
struct DSU {
    int n;
    vector<int> parent, rankv;
    DSU(int n=0): n(n), parent(n), rankv(n,0) {
        for (int i=0;i<n;++i) parent[i]=i;
    }
    int find(int x) {
        if (parent[x]==x) return x;
        return parent[x]=find(parent[x]);
    }
    bool unite(int a,int b) {
        a = find(a); b = find(b);
        if (a==b) return false;
        if (rankv[a] < rankv[b]) swap(a,b);
        parent[b]=a;
        if (rankv[a]==rankv[b]) rankv[a]++;
        return true;
    }
};

// ----------------------------
// Graph representation
// We store: adjacency list with pairs (neighbor, weight)
// For unweighted BFS/DFS weight is ignored
// ----------------------------
struct Graph {
    int n; // number of vertices (0..n-1)
    vector<vector<pair<int,ll>>> adj;
    Graph(int n=0): n(n), adj(n) {}
    void addEdgeUndirected(int u,int v,ll w=1) {
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    void addEdgeDirected(int u,int v,ll w=1) {
        adj[u].push_back({v,w});
    }
};

// ----------------------------
// BFS (breadth-first search) - iterative
// Returns vector<int> parent: parent[src] = -1, unreachable have parent -1 too
// Produces the order of visiting nodes
// ----------------------------
vector<int> BFS(const Graph& G, int src, vector<int> &order) {
    vector<int> parent(G.n, -1);
    vector<int> vis(G.n, 0);
    queue<int> q;
    vis[src]=1;
    parent[src] = -1;
    q.push(src);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        order.push_back(u);
        for (auto &pr : G.adj[u]) {
            int v = pr.first; // weight ignored
            if (!vis[v]) {
                vis[v]=1;
                parent[v]=u;
                q.push(v);
            }
        }
    }
    return parent;
}

// ----------------------------
// DFS (depth-first search) - recursive
// Produces parent vector and visiting order (preorder)
// ----------------------------
void dfsRecHelper(const Graph& G, int u, vector<int>& vis, vector<int>& parent, vector<int>& order) {
    vis[u]=1;
    order.push_back(u); // preorder
    for (auto &pr : G.adj[u]) {
        int v = pr.first;
        if (!vis[v]) {
            parent[v]=u;
            dfsRecHelper(G, v, vis, parent, order);
        }
    }
}
vector<int> DFS_recursive(const Graph& G, int src, vector<int> &order) {
    vector<int> vis(G.n,0), parent(G.n,-1);
    dfsRecHelper(G, src, vis, parent, order);
    return parent;
}

// ----------------------------
// DFS iterative (using stack) - alternate
// ----------------------------
vector<int> DFS_iterative(const Graph& G, int src, vector<int>& order) {
    vector<int> parent(G.n,-1), vis(G.n,0);
    stack<int> st;
    st.push(src);
    parent[src] = -1;
    while (!st.empty()) {
        int u = st.top(); st.pop();
        if (vis[u]) continue;
        vis[u]=1;
        order.push_back(u);
        // push neighbors in reverse if you want deterministic order similar to recursive
        for (auto it = G.adj[u].rbegin(); it != G.adj[u].rend(); ++it) {
            int v = it->first;
            if (!vis[v]) {
                parent[v]=u;
                st.push(v);
            }
        }
    }
    return parent;
}

// ----------------------------
// Kruskal's Minimum Spanning Tree (returns total weight and list of edges in MST)
// Graph must be undirected
// ----------------------------
pair<ll, vector<tuple<int,int,ll>>> KruskalMST(const Graph& G) {
    vector<tuple<ll,int,int>> edges; // (w,u,v)
    for (int u=0; u<G.n; ++u) {
        for (auto &pr : G.adj[u]) {
            int v = pr.first; ll w = pr.second;
            if (u < v) // to avoid duplicates (since undirected edges appear twice)
                edges.push_back({w,u,v});
        }
    }
    sort(edges.begin(), edges.end()); // sort by weight ascending
    DSU dsu(G.n);
    ll total = 0;
    vector<tuple<int,int,ll>> mstEdges;
    for (auto &e : edges) {
        ll w; int u,v;
        tie(w,u,v) = e;
        if (dsu.unite(u,v)) {
            total += w;
            mstEdges.push_back({u,v,w});
        }
    }
    return {total, mstEdges};
}

// ----------------------------
// Prim's Minimum Spanning Tree (returns total weight and list of edges in MST)
// Using priority_queue (min-heap). Assumes graph is connected for MST to cover all nodes.
// ----------------------------
pair<ll, vector<tuple<int,int,ll>>> PrimMST(const Graph& G, int start=0) {
    vector<char> inMST(G.n, 0);
    vector<ll> key(G.n, INF);
    vector<int> parent(G.n, -1);
    // min-heap of (key, node)
    priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>> pq;
    key[start] = 0;
    pq.push({0, start});
    while (!pq.empty()) {
        auto [k,u] = pq.top(); pq.pop();
        if (inMST[u]) continue;
        inMST[u] = 1;
        for (auto &pr : G.adj[u]) {
            int v = pr.first; ll w = pr.second;
            if (!inMST[v] && w < key[v]) {
                key[v] = w;
                parent[v] = u;
                pq.push({key[v], v});
            }
        }
    }
    // collect result edges and weight
    ll total = 0;
    vector<tuple<int,int,ll>> mstEdges;
    for (int v=0; v<G.n; ++v) {
        if (parent[v] != -1) {
            // edge parent[v] - v with weight key[v]
            mstEdges.push_back({parent[v], v, key[v]});
            total += key[v];
        }
    }
    return {total, mstEdges};
}

// ----------------------------
// Dijkstra's shortest path (single-source)
// Returns distance vector and parent vector
// Works with non-negative weights
// ----------------------------
pair<vector<ll>, vector<int>> Dijkstra(const Graph& G, int src) {
    vector<ll> dist(G.n, INF);
    vector<int> parent(G.n, -1);
    dist[src] = 0;
    priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>> pq;
    pq.push({0, src});
    while (!pq.empty()) {
        auto [d,u] = pq.top(); pq.pop();
        if (d != dist[u]) continue; // stale
        for (auto &pr : G.adj[u]) {
            int v = pr.first; ll w = pr.second;
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                parent[v] = u;
                pq.push({dist[v], v});
            }
        }
    }
    return {dist, parent};
}

// ----------------------------
// Utility: print path using parent vector (for BFS/DFS/Dijkstra)
// ----------------------------
vector<int> buildPath(int tgt, const vector<int>& parent) {
    vector<int> path;
    for (int v = tgt; v != -1; v = parent[v]) path.push_back(v);
    reverse(path.begin(), path.end());
    return path;
}

// ----------------------------
// Demo: read graph and run algorithms
// Input format:
//   First line: n m   (n = number of vertices, nodes are 0..n-1)
//   Next m lines: u v w   (0-indexed u and v, weight w (integer))
// The program treats the graph as UNDIRECTED for MST (edges added undirected).
// For Dijkstra we also use the undirected edges (works fine).
// ----------------------------
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << "Enter n (vertices) and m (edges): ";
    int n, m;
    if (!(cin >> n >> m)) {
        cerr << "Invalid input\n";
        return 0;
    }
    Graph G(n);
    cout << "Enter " << m << " edges (u v w) with 0-based nodes:\n";
    for (int i=0;i<m;++i) {
        int u,v; ll w;
        cin >> u >> v >> w;
        // add undirected edge (use undirected for MST demonstration)
        G.addEdgeUndirected(u,v,w);
    }

    cout << "\n--- BFS from source 0 ---\n";
    vector<int> orderBFS;
    vector<int> parentBFS = BFS(G, 0, orderBFS);
    cout << "BFS order: ";
    for (int x : orderBFS) cout << x << " ";
    cout << "\nParent array (index:parent):\n";
    for (int i=0;i<n;++i) cout << i << ":" << parentBFS[i] << " ";
    cout << "\n";

    cout << "\n--- DFS (recursive) from source 0 ---\n";
    vector<int> orderDFS;
    vector<int> parentDFS = DFS_recursive(G, 0, orderDFS);
    cout << "DFS order (preorder): ";
    for (int x : orderDFS) cout << x << " ";
    cout << "\nParent array (index:parent):\n";
    for (int i=0;i<n;++i) cout << i << ":" << parentDFS[i] << " ";
    cout << "\n";

    cout << "\n--- Kruskal MST ---\n";
    auto kr = KruskalMST(G);
    cout << "Total MST weight (Kruskal) = " << kr.first << "\n";
    cout << "Edges in MST (u v w):\n";
    for (auto &t : kr.second) {
        int u,v; ll w;
        tie(u,v,w) = t;
        cout << u << " " << v << " " << w << "\n";
    }

    cout << "\n--- Prim MST (start=0) ---\n";
    auto pr = PrimMST(G, 0);
    cout << "Total MST weight (Prim) = " << pr.first << "\n";
    cout << "Edges in MST (parent child weight):\n";
    for (auto &t : pr.second) {
        int u,v; ll w; tie(u,v,w) = t;
        cout << u << " " << v << " " << w << "\n";
    }

    cout << "\n--- Dijkstra (source = 0) ---\n";
    auto dij = Dijkstra(G, 0);
    vector<ll> dist = dij.first;
    vector<int> parent = dij.second;
    cout << "Distances from 0:\n";
    for (int i=0;i<n;++i) {
        if (dist[i] >= INF/4) cout << i << ": INF\n";
        else cout << i << ": " << dist[i] << "\n";
    }
    cout << "Example: print shortest path to node " << (n-1) << " (if reachable):\n";
    if (dist[n-1] < INF/4) {
        auto path = buildPath(n-1, parent);
        for (size_t i=0;i<path.size();++i) {
            if (i) cout << " -> ";
            cout << path[i];
        }
        cout << "\n";
    } else {
        cout << "Node " << (n-1) << " not reachable from 0.\n";
    }

    return 0;
}
