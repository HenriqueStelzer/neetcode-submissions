class Solution {
public:
    int search(vector<int>& nums, int target) {
        int lo=0, hi=nums.size()-1;
        while (lo <= hi) {
            int md = lo + (hi - lo) / 2;
            if (nums[md] > target) hi = md-1;
            else if (nums[md] < target) lo = md+1;
            else return md;
        }
        return -1;
    }
};