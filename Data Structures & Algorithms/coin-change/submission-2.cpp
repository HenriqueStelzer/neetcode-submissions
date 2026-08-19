constexpr int INF = 1e9+7;
constexpr int MAX = 10 + 1;
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if (amount == 0) return 0;
        int res = dp(coins, amount, coins.size()-1);
        if (res == INF) return -1;
        return res;
    }

private:
    array<unordered_map<int, int>, MAX> memo;
    int dp(vector<int>& coins, int target, int top) {
        if (memo[top][target] != 0) return memo[top][target];
        int mn = INF;
        for (int i = 0; i <= top; i++) {
            if (target == coins[i]) return memo[top][target] = 1;
            if (target < coins[i]) continue;
            mn = min(mn, dp(coins, target - coins[i], i) + 1);
        }
        return memo[top][target] = mn;
    }
};
