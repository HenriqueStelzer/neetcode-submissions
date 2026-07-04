class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target, int max = 0, bool start = true) {
        if (target == 0) return {{}};
        if (start) max = target;
        vector<vector<int> > vv;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > target) continue;
            if (nums[i] > max) continue;
            for (auto it : combinationSum(nums, target-nums[i], nums[i], false)) {
                it.push_back(nums[i]);
                vv.push_back(it);
            }
        }
        return vv;
    }
};
