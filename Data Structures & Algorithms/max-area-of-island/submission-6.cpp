class Solution {
vector<pair<int16_t, int16_t>> offsets = {{ {-1, 0}, {0, -1}, {1, 0}, {0, 1} }};
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int16_t n = grid.size(), m = grid[0].size();
        int16_t mx = 0;
        for (int16_t i = 0; i < n; i++) {
            for (int16_t j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    int16_t cnt = 0;
                    queue<pair<int16_t, int16_t>> que;
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
