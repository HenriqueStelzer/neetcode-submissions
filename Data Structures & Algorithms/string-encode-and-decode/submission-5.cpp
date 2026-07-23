class Solution {
public:

    string encode(vector<string>& strs) {
        string res = "";
        for (auto& it : strs) {
            res += to_string(it.size());
            res += '#';
            res += it;
        }
        return res;
    }

    vector<string> decode(string s) {
        vector<string> res;
        string cur="";
        int j = 0;
        for (int i = 0; i < s.size(); i++) {
            if (j == 0) {
                if (i > 0) res.push_back(cur);
                while (s[i] != '#' && i < s.size()) {
                    j = j*10 + (s[i] - '0');
                    i++;
                    cout << 'O';
                }
                cur = "";
            }
            else {
                cur += s[i];
                j--;
                cout << 'o';
            }
        }
        if (s.size()) res.push_back(cur);
        return res;
    }
};
