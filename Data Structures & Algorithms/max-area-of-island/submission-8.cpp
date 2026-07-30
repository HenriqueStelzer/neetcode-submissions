class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        array<pair<int, int>, 4> offsets = {{ {-1, 0}, {0, -1}, {1, 0}, {0, 1} }};
        int n = grid.size(), m = grid[0].size();
        int mx = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    int cnt = 0;
                    queue<pair<int, int>> que;
                    que.push({i, j});
                    grid[i][j] = 0;
                    while (!que.empty()) {
                        auto [x, y] = que.front(); que.pop();
                        cnt++;
                        for (auto& [a, b] : offsets) {
                            if (x+a < 0 || x+a >= n || y+b < 0 || y+b >= m) continue;
                            if (grid[x+a][y+b] == 1) {
                                grid[x+a][y+b] = 0;
                                que.push({x+a, y+b});
                            }
                        }
                    }
                    mx = max(mx, cnt);
                }
            }
        }
        return mx;
    }
};
