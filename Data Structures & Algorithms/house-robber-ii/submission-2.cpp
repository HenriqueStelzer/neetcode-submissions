class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        memo.assign(nums.size(), -1);
        n = nums.size();
        
        int first = dp(nums, 1);
        
        n--; memo.assign(nums.size(), -1);
        return max(first, dp(nums, 0));
    }

private:
    vector<int> memo;
    int n;
    int dp (vector<int>& nums, int i) {
        if (i >= n) return 0;
        if (memo[i] != -1) return memo[i];
        return memo[i] = max(nums[i] + dp(nums, i+2), dp(nums, i+1));
    }
};
