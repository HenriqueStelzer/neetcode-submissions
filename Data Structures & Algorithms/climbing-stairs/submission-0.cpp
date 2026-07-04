class Solution {
public:
    int climbStairs(int n) {
        memo.assign(n+1, -1);
        return dp(n);
    }

private:
    vector<int> memo;
    int dp(int i) {
        if (i <= 1) return 1;
        if (memo[i] != -1) return memo[i];
        return memo[i] = dp(i-1) + dp(i-2);
    }
};
