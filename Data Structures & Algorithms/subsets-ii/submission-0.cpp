class Solution {
vector<int> cur;
vector<vector<int>> res = {{}};
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        backtrack(nums, 0);
        return res;
    }
private:
    void backtrack(const vector<int>&nums, int start) {
        for (int i = start; i < nums.size(); i++) {
            if (i > start && nums[i] == nums[i-1]) continue;
            cur.push_back(nums[i]);
            res.push_back(cur);
            backtrack(nums, i+1);
            cur.pop_back();
        }
    }
};
