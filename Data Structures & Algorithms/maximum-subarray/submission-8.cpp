class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> pre(nums.size()+1);
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            pre[i+1] = sum;
        }

        int lo = 0, mx = -1e3;
        for (int i = 0; i < nums.size(); i++) {
            lo = min(lo, pre[i]);
            mx = max(mx, pre[i+1] - lo);
        }
        
        return mx;
    }
};
