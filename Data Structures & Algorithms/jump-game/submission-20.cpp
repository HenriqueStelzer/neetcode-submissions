class Solution {
public:
    bool canJump(vector<int>& nums, int i=0) {
        if (nums.size()-i <= 1) return true;
        for (int j = 1; j <= nums[i]; j++) {
            if (canJump(nums, i+j)) return true;
        }
        return false;
    }
};
