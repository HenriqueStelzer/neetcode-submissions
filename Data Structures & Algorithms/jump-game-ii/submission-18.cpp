class Solution {
   public:
    int jump(vector<int>& nums) {
        int res = 0, cur, last=0, mx = 0;
        for (int i = 0; i < nums.size()-1; i++) {
            cur = i + nums[i];
            if (cur > mx) {
                mx = cur;
            }
            if (i >= last) {
                res++;
                last = mx;
            }
        }
        return res;
    }
};
