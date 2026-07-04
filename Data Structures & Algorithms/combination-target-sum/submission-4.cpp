class Solution {
public:
    vector<vector<int32_t>> combinationSum(vector<int32_t>& nums, int32_t target, int32_t max = 0, bool start = true) {
        if (target == 0) return {{}};
        if (start) max = target;
        vector<vector<int32_t> > vv;
        for (int32_t i = 0; i < nums.size(); i++) {
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
