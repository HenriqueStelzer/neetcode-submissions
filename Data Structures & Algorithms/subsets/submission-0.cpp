class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> aws(1<<nums.size(), vector<int>{});
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 1<<i; j < 1<<nums.size(); j+= 1<<i) {
                int i2 = 1<<i; 
                while(i2--) {
                    aws[j].push_back(nums[i]);
                    j++;
                }
            }
        }
        return aws;
    }
};
