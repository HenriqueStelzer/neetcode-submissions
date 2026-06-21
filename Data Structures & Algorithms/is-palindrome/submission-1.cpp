class Solution {
public:
    bool isPalindrome(string os) {
        string s = "";
        for (auto& it : os) if(isalpha(it) || isdigit(it)) s += tolower(it);
        
        int i = 0;
        int n = s.length();
        while (i < n-1-i) {
            if (s[i] != s[n-1-i]) return false;
            i++;
        }
        return true;
    }
};
