class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        memo.assign(cost.size(), -1);
        return min(dp(cost, 0), dp(cost, 1));
    }

private:
    vector<int> memo;
    int dp(vector<int>& cost, int i) {
        if (i >= cost.size()) return 0;
        if (memo[i] != -1) return memo[i];
        return memo[i] = cost[i] + min(dp(cost, i+1), dp(cost, i+2));
    }
};
