class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int mult = 1, zero = 0;
        for (auto& it : nums) {
            if (it != 0) mult *= it;
            else zero++;
        }
        vector<int> aws;
        for (auto& it : nums) {
            if (it == 0) {
                if (zero == 1) aws.push_back(mult);
                else aws.push_back(0);
            }
            else {
                if (zero == 0) aws.push_back(mult/it);
                else aws.push_back(0);
            }
            
        }
        return aws;
    }
};
