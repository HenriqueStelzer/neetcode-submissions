class Solution {
public:

    string encode(vector<string>& strs) {
        string res = "";
        for (auto& it : strs) {
            res += it + '\1';
        }
        return res;
    }

    vector<string> decode(string s) {
        vector<string> res;
        string cur="";
        for (auto& it : s) {
            if (it == '\1') {
                res.push_back(cur);
                cur = "";
            }
            else {
                cur += it;
            }
        }
        return res;
    }
};
