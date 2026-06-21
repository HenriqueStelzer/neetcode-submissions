class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        map<int, bool> m;
        bool awns = false;
        for (auto& it : nums) {
            if (m.contains(it)) {
                awns = true;
                break;
            }
            else {
                m[it] = true;
            }
        }
        return awns;
    }
};