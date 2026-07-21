class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum=0, lo=0, mx=-1e3;
        for (int i = 0; i < nums.size(); i++) {
            lo = min(lo, sum);
            sum += nums[i];
            mx = max(mx, sum - lo);
        }
        
        return mx;
    }
};
