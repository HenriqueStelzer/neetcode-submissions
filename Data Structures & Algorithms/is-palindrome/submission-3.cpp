class Solution {
public:
    bool isPalindrome(string os) {
        string s = "";
        for (auto& it : os) if(isalpha(it) || isdigit(it)) s += tolower(it);
        
        int i = 0, j = s.length()-1;
        while (i < j) {
            if (s[i] != s[j]) return false;
            i++; j--;
        }
        return true;
    }
};
