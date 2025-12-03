#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (1LL<<60);

// Input: N nodes (1..N), times vector of (u,v,w), start K
int networkDelayTime(int N, const vector<vector<int>>& times, int K) {
    // build adjacency list
    vector<vector<pair<int,int>>> adj(N+1);
    for (const auto &t : times) {
        int u = t[0], v = t[1], w = t[2];
        adj[u].push_back({v,w});
    }

    // Dijkstra
    vector<ll> dist(N+1, INF);
    dist[K] = 0;
    using T = pair<ll,int>; // (distance, node)
    priority_queue<T, vector<T>, greater<T>> pq;
    pq.push({0, K});

    while (!pq.empty()) {
        auto [d,u] = pq.top(); pq.pop();
        if (d > dist[u]) continue; // stale
        for (auto &edge : adj[u]) {
            int v = edge.first;
            int w = edge.second;
            ll nd = d + (ll)w;
            if (nd < dist[v]) {
                dist[v] = nd;
                pq.push({nd, v});
            }
        }
    }

    ll ans = 0;
    for (int i = 1; i <= N; ++i) {
        if (dist[i] == INF) return -1;
        ans = max(ans, dist[i]);
    }
    return (int)ans;
}

// Demo main for testing
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Example: N=4, K=2, times=[[2,1,1],[2,3,1],[3,4,1]]
    int N = 4, K = 2;
    vector<vector<int>> times = {{2,1,1},{2,3,1},{3,4,1}};

    int result = networkDelayTime(N, times, K);
    cout << result << "\n"; // expected 2
    return 0;
}

