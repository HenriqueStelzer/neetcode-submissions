class Solution {
public:
    string longestPalindrome(string in) {
        string s = "#";
        for (auto& it : in) {
            s += it;
            s += '#';
        }

        vector<int> d(s.size());
        int c=0, r=0;

        int mxi = 0;
        for (int i = 0; i < s.size(); i++) {
            if (i < r) d[i] = min(r-i, d[2*c - i]);

            while (i+d[i]+1 < s.size() && i-d[i]-1 >= 0 && s[i+d[i]+1] == s[i-d[i]-1]) d[i]++;

            if (i + d[i] > r) {
                c = i;
                r = i + d[i];
            }

            if (d[mxi] <= d[i]) mxi = i;
        }

        string res = "";
        for (int i = mxi - d[mxi]; i < mxi + d[mxi]; i++) {
            if (s[i] != '#') res += s[i];
        }
        return res;
    }
};
