class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        return dp(nums);
    }

private:
    bitset<6> vis;
    vector<vector<int>> dp(vector<int>& nums) {
        vector<vector<int>> aws;
        for (int i = 0; i < nums.size(); i++) {
            if (vis[i]) continue;
            vis[i] = 1;
            vector<vector<int>> next = dp(nums);
            vis[i] = 0;
            if (next.size()) {
                for (auto& it : next) {
                    vector<int> inner;
                    inner.push_back(nums[i]);
                    for (auto& jt : it) {
                        inner.push_back(jt);
                    }
                    aws.push_back(inner);
                }
            }
            else aws.push_back(vector<int>{nums[i]});
        }
        return aws;
    }
};
