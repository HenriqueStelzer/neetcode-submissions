class Solution {
int n, m;
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        int mx = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    mx = max(mx, dfs(grid, i, j));
                }
            }
        }
        return mx;
    }

private:
    array<pair<int, int>, 4> offsets = {{ {-1, 0}, {0, -1}, {1, 0}, {0, 1} }};
    int dfs(vector<vector<int>>& grid, int i, int j) {
        int cnt = 1;
        grid[i][j] = 0;
        for (auto& [x, y] : offsets) {
            if (i+x < 0 || i+x >= n || j+y < 0 || j+y >= m || grid[i+x][j+y] == 0) continue;
            cnt += dfs(grid, i+x, j+y);
        }
        return cnt;
    }
};
