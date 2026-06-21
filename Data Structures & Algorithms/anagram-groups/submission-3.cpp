class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        constexpr int kInf = 1000000007;
        unordered_map<int, vector<int>> m;
        set<int> s;
        for (int i = 0; i < strs.size(); i++) {
            int hash = 1;
            for (auto& jt : strs[i]) hash *= jt;
            hash %= kInf;
            m[hash].push_back(i);
            s.insert(hash);
        }

        vector<vector<string> > awns(m.size(), vector<string> {});
        int i = 0;
        for (auto it : s) {
            for (auto& jt : m[it]) awns[i].push_back(strs[jt]);
            i++;
        }

        return awns;
    }
};
