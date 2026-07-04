class Solution {
public:
    int change(int amount, vector<int>& coins) {
        if (amount == 0) return 1;
        memo.assign(amount+1, vector<int>(amount+1, -1));
        return dp(amount, amount, coins);
    }

private:
    vector<vector<int> > memo;
    int dp(int amount, int hi, vector<int>& coins) {
        if (memo[amount][hi] != -1) return memo[amount][hi];
        int count = 0;
        for (auto& it : coins) {
            if (it > hi) continue;
            if (amount - it < 0) continue;
            if (amount == it) {
                count++;
                continue;
            }
            count += dp(amount-it, it, coins);
        }
        return memo[amount][hi] = count;
    }
};
