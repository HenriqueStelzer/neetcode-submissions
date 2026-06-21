class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string> > m;
        for (auto& it : strs) {
            string a = "00000000000000000000000000";
            for (auto& jt : it) a[jt - 'a']++;
            m[a].push_back(it);
        }

        vector<vector<string> > v;
        for (auto& it : m) {
            v.push_back(it.second);
        }

        return v;
    }
};
