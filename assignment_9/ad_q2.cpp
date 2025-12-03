#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (1LL<<60);

// Dijkstra on grid, edge weight = cost of destination cell
ll shortestPathGrid(const vector<vector<int>>& grid) {
    int m = grid.size();
    if (m == 0) return 0;
    int n = grid[0].size();

    vector<vector<ll>> dist(m, vector<ll>(n, INF));
    // min-heap of (distance, i, j)
    using T = tuple<ll,int,int>;
    priority_queue<T, vector<T>, greater<T>> pq;

    dist[0][0] = grid[0][0];
    pq.push({dist[0][0], 0, 0});

    int dirs[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

    while (!pq.empty()) {
        auto [d, i, j] = pq.top(); pq.pop();
        if (d != dist[i][j]) continue; // stale
        if (i == m-1 && j == n-1) return d; // early exit

        for (auto &dir : dirs) {
            int ni = i + dir[0], nj = j + dir[1];
            if (ni >= 0 && ni < m && nj >= 0 && nj < n) {
                ll nd = d + grid[ni][nj];
                if (nd < dist[ni][nj]) {
                    dist[ni][nj] = nd;
                    pq.push({nd, ni, nj});
                }
            }
        }
    }
    return dist[m-1][n-1];
}

// Demo main: reads m n then m lines with n integers
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int m, n;
    if (!(cin >> m >> n)) {
        cerr << "Expected: m n\n";
        return 0;
    }
    vector<vector<int>> grid(m, vector<int>(n));
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
            cin >> grid[i][j];

    long long ans = shortestPathGrid(grid);
    cout << ans << "\n";
    return 0;
}
