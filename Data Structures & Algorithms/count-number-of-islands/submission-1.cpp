class Solution {
vector<vector<bool>> vis;
int n, m;
const array<pair<int, int>, 4> nexts = {pair{-1, 0}, pair{1, 0}, pair{0, -1}, pair{0, 1}};
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.size() == 0) return 0;
        n = grid.size();
        m = grid[0].size();

        vis.assign(n, vector<bool>(m, false));

        int res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (vis[i][j]) continue;
                vis[i][j] = true;
                if (grid[i][j] == '1') {
                    res++;
                    dfs(grid, i, j);
                }
            }
        }

        return res;
    }
private:
    void dfs(vector<vector<char>>& grid, int i, int j) {
        for (auto& it : nexts) {
            if (i + it.first < 0 || i + it.first >= n || j + it.second < 0 || j + it.second >= m) continue;
            if (vis[i+it.first][j+it.second]) continue;
            if (grid[i+it.first][j+it.second] == '0') continue;
            vis[i+it.first][j+it.second] = true;
            dfs(grid, i+it.first, j+it.second);
        }
    }
};
