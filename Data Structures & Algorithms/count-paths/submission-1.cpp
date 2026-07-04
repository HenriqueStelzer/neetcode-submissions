class Solution {
public:
    int uniquePaths(int m, int n) {
        memo.assign(m, vector<int>(n, -1));
        return dp(m-1, n-1);
    }

private:
    vector<vector<int> > memo;
    int dp(int i, int j) {
        if (i == 0 && j == 0) return 1;
        if (i < 0 || j < 0) return 0;
        if (memo[i][j] != -1) return memo[i][j];
        return memo[i][j] = dp(i-1, j) + dp(i, j-1);
    }
};
