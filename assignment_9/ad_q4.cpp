#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int M = grid.size();
        if (M == 0) return 0;
        int N = grid[0].size();

        vector<vector<bool>> visited(M, vector<bool>(N, false));
        int islands = 0;

        // Directions: up, down, left, right
        int dx[4] = {1, -1, 0, 0};
        int dy[4] = {0, 0, 1, -1};

        // BFS helper
        auto bfs = [&](int sx, int sy) {
            queue<pair<int,int>> q;
            visited[sx][sy] = true;
            q.push({sx, sy});

            while (!q.empty()) {
                auto [x, y] = q.front(); q.pop();
                for (int k = 0; k < 4; ++k) {
                    int nx = x + dx[k];
                    int ny = y + dy[k];
                    if (nx >= 0 && nx < M && ny >= 0 && ny < N &&
                        grid[nx][ny] == '1' && !visited[nx][ny]) 
                    {
                        visited[nx][ny] = true;
                        q.push({nx, ny});
                    }
                }
            }
        };

        // Traverse grid
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                if (grid[i][j] == '1' && !visited[i][j]) {
                    bfs(i, j);   // OR use dfs(i,j)
                    islands++;
                }
            }
        }

        return islands;
    }
};

int main() {
    vector<vector<char>> grid = {
        {'1','1','0'},
        {'0','1','0'},
        {'1','0','1'}
    };

    Solution s;
    cout << s.numIslands(grid) << endl;  // Output: 3
    return 0;
}
