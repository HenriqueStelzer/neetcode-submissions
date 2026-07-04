class Solution {
public:
    vector<int> memo;
    int rob(vector<int>& nums) {
        memo.assign(nums.size(), -1);
        return dp(nums, nums.size()-1);
    }
    private:
        int dp (vector<int>& nums, int i) {
            if (i < 0) return 0;
            if (memo[i] != -1) return memo[i];
            return memo[i] = max(nums[i] + dp(nums, i-2), dp(nums, i-1));
        }
};