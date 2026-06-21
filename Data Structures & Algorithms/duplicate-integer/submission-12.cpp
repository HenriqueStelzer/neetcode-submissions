#include <ranges>

class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int prev = nums[0];
        for (auto& it : nums | ranges::views::drop(1)) {
            if (it == prev) {
                return true;
            }
            prev = it;
        }
        return false;
    }
};