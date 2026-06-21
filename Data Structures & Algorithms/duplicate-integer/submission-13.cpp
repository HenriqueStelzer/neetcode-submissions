class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for (auto it = nums.begin() + 1; it < nums.end(); it++) {
            if (*it == *(it - 1)) {
                return true;
            }
        }
        return false;
    }
};