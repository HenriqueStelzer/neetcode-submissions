class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char, int> start;
        int mx=0, i=0;
        for (int j = 0; j < s.size(); j++) {
            if (start[s[j]]) {
                i = max(i, start[s[j]]);
            }
            start[s[j]] = j + 1;
            cout << s[j] << ' ' << i << ' ' << j << '\n';   
            mx = max(mx, j-i+1);
        }
        return mx;
    }
};
