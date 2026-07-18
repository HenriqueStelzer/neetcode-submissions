class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        unordered_map<long long, bool> mp;
        vector<vector<int>> aws;
        for (int i = 1; i < nums.size()-1; i++) {
            int j = 0, k = nums.size()-1;
            int target = -1 * nums[i];
            while (j < i && k > i) {
                if (nums[j] + nums[k] > target) k--;
                else if (nums[j] + nums[k] < target) j++;
                else {
                    if (!mp.contains(nums[i] + nums[j]*1e5 + nums[k]*1e10)) {
                        aws.push_back(vector<int> {nums[i], nums[j], nums[k]});
                        mp[nums[i] + nums[j]*1e5 + nums[k]*1e10] = true;
                    }
                    j++;
                    k--;
                }
            }
        }
        return aws;
    }
};
