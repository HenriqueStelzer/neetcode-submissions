class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vis.assign(nums.size(), false);
        return dp(nums);
    }

private:
    vector<bool> vis;
    vector<vector<int>> dp(vector<int>& nums) {
        vector<vector<int>> aws;
        for (int i = 0; i < nums.size(); i++) {
            if (vis[i]) continue;
            vis[i] = true;
            vector<vector<int>> next = dp(nums);
            vis[i] = false;
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
