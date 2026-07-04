class Solution {
public:
    int change(int amount, vector<int>& coins) {
        memo.assign(amount+1, vector<int>(coins.size(), -1));
        return dp(amount, coins.size()-1, coins);
    }

private:
    vector<vector<int> > memo;
    int dp(int amount, int hi, vector<int>& coins) {
        if (amount == 0) return 1;
        if (memo[amount][hi] != -1) return memo[amount][hi];
        int count = 0;
        for (int i = 0; i <= hi; i++) {
            if (amount < coins[i]) continue;
            if (amount == coins[i]) {
                count++;
                continue;
            }
            count += dp(amount-coins[i], i, coins);
        }
        return memo[amount][hi] = count;
    }
};
