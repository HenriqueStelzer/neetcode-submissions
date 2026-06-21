class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string> > m;
        const string kDefHash(26, '\0'); // limit is 127 equal charachters. from there, there are colision risks - but low.
        for (auto& it : strs) {
            string a = kDefHash;
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
