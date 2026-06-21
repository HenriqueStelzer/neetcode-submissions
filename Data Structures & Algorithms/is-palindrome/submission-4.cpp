class Solution {
public:
    bool isPalindrome(string os) {
        string s = ""; for (auto& it : os) if (isalnum(it)) s += tolower(it); // id do that on read time in obi
    
        int i = 0, j = s.length()-1;
        while (i < j) {
            if (s[i] != s[j]) return false;
            i++; j--;
        }
        return true;
    }
};
