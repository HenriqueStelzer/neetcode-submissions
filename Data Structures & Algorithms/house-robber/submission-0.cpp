class Solution {
public:
    vector<int>* v;
    vector<int> memo;
    int rob(vector<int>& nums) {
        v = &nums;
        memo.assign(nums.size(), -1);
        return dp(nums.size()-1);
    }
    int dp (int i) {
        if (i < 0) return 0;
        if (memo[i] != -1) return memo[i];
        return memo[i] = max((*v)[i] + dp(i-2), dp(i-1));
    }
};