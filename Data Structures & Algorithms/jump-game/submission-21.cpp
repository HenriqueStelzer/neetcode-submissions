class Solution {
public:
    bool canJump(vector<int>& nums) {
        memo.assign(nums.size(), false);
        vis.assign(nums.size(), false);
        return dp(nums, 0);
    }
private:
    vector<bool> memo;
    vector<bool> vis;
    bool dp(vector<int>&nums, int i) {
        if (nums.size()-i <= 1) return true;
        if (vis[i]) return memo[i];
        else {
            vis[i] = true;
            for (int j = 1; j <= nums[i]; j++) {
                if (dp(nums, i+j)) return memo[i] = true;
            }
            return memo[i] = false;
        }
    }
};
